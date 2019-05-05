require 'pixels'
require 'mini_magick'

def act(orientation, color_right, pixel, row)  
    if orientation == "up"
        if color_right == true
            pixel -= 1
            orientation = "left"
        else 
            pixel += 1
            orientation = "right"
        end
    elsif orientation == "down"
        if color_right == true
            pixel += 1
            orientation = "right"
        else 
            pixel -= 1
            orientation = "left"
        end
    elsif orientation == "left"
        if color_right == true
            row -= 1
            orientation = "down"
        else 
            row += 1
            orientation = "up"
        end
    elsif orientation == "right"
        if color_right == true
            row += 1
            orientation = "up"
        else 
            row -= 1
            orientation = "down"
        end
    end 
    answer = Array.new 
    answer << orientation 
    answer << pixel 
    answer << row 
    return answer  
end

img = MiniMagick::Image.open("pic.png")
img.format("tga")
img.write "pic.tga"

input = Pixels.open_tga("pic.tga")
output = Pixels.create_tga("output_pic.tga", input.spec)
all_rows = Array.new

input.each_row_rgb do |in_row, y|
    all_rows.push in_row
end

which_row = 0
flag = 0
color = [255, 255, 255]
for a in all_rows
    which_row += 1
    which_pixel = 0 
    for i in a
        which_pixel += 1
        if i == color 
            puts "YES!"
            flag = 1
            break
        end 
    end
    if flag == 1
        break 
    end
end

orientation = "up" #when orientation is up => left is which_pixel--, right is which_pixel++
                   #when orientation is down, vice versa
                   #right => left is which_row++, right - which_row--
                   #left => vice versa
row = which_row-1
pixel = which_pixel-1
red_color = [255,0,0]
out_rows = Array.new
all_rows.each{|e| out_rows << e.dup} #deep copy of all_rows
loop do 
    answer = act(orientation, all_rows[row][pixel] == color, pixel, row)
    puts row.to_s + " " + pixel.to_s
    puts orientation
        
    orientation = answer[0]
    pixel = answer[1]
    row = answer[2] 
    out_rows[row][pixel] = red_color
    break if row == which_row-1 && pixel == which_pixel-1
end

for i in 0...out_rows.size
    output.put_row_rgb(i, out_rows[i])
end

puts "ROW: " + which_row.to_s + " PIXEL: " + which_pixel.to_s
puts all_rows[which_row-1][which_pixel-1]
output.close
input.close
