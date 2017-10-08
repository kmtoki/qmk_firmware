# convert 1bit text to double width font. required text size is 11x7

ARGV.each do |f|
  readline(f).split("\n").select { |t| t != "" }.each_slice(7).each do |bitmap|
    font = ""
    bitmap.map { |b| b.split("") }.reverse.transpose.each do |bss|
      font += sprintf "0x%x,", ("0b" + bss.join).to_i(2)
    end
    puts font
  end
end
