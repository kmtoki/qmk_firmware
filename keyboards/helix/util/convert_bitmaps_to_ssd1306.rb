bitmaps = ["\
0000100000100000
0000010001000000
0000111111100000
0001101110110000
0011111111111000
0010111111101000
0010100000101000
0000011011000000
",
"\
0000100000100000
0010010001001000
0010111111101000
0011101110111000
0011111111111000
0001111111110000
0000100000100000
0001000000010000
"
]

code = sprintf "static const int8_t bitmaps[%d]", bitmaps.size

fst = true
bitmaps.each do |bitmap|
  b8s = bitmap.split("\n").each_slice(8).to_a

  if not fst then
    code += "  {\n"
  end

  b8s.each do |b8|
  
    bs = b8.map do |b|
      bs = b.split("")

      if fst then
        code += sprintf "[%d][%d] = {\n{\n", b8s.size, bs.size
        fst = false
      end

      bs
    end

    if not fst then
      code += "    {\n      "
    end
 
    bs.transpose.each do |bss|
      code += sprintf "0x%x,", ("0b" + bss.join).to_i(2)
      #code += "0b" + bss.join + ","
    end

    code += "\n    },\n"
  end

  code += "\n  },\n"
end

code += "};"

puts code
