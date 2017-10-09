ARGV.each do |f|
  y = 0
  x = 0
  s = ""
  readline(f).split("\n").map { |t| t.split("") }.each_slice(8) do |ts|
    y += 1
    s += "{"
    x = ts.reverse.transpose.map {|tss| s += sprintf "0x%x,", ("0b" + tss.join).to_i(2) }.size
    s += "},"
  end
  printf "static const uint8_t graffiti[%d][%d] = {%s};\n", y, x, s
end
