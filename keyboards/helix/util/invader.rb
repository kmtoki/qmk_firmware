text = "
00100000100
10010001001
10111111101
11101110111
11111111111
01111111110
00100000100
00000000000

00010001000
00010001000
00111111100
01101110110
11111111111
10111111101
00100000100
00000000000
"

bs = []
text.split("\n").each do |ts|
  i = 0
  ts.split("").each_slice(8) do |tss|
    if bs[i] == nil then
      bs[i] = [sprintf("0x%x", tss.reverse.join.to_i(2))]
    else
      bs[i].push(sprintf "0x%x", tss.reverse.join.to_i(2))
    end
    i += 1
  end
end

c = sprintf "static uint8_t invader[%d][%d] = {", bs.size, bs[0].size
bs.each do |bss|
  bss = bss.reverse
  c += "{"
  for i in 0 .. bs[0].size - 1
    if bss[i] == nil then
      c += "0x0,"
    else
      c += bss[i].to_s + ","
    end
  end
  c += "},"
end

c += "};"
puts c
