import os
from PIL import Image

dir= os.getcwd()
switch_dir= os.path.join(dir, 'new')
for files in os.listdir(dir):
	if(files.endswith('.txt')):
		file_name= files.split('.')[0]
		image_name= "/home/ruchika/BBox-Label-Tool-Multi-Class/Images/001/" + file_name+ '.JPG'
		file= open(files, 'r')
		print("file_name", file_name)
		contents= file.readlines()
		print(len(contents))
		file_new= open(file_name+ 'new'+ '.txt', 'w')
		for line in contents:
			# print("GEFIUGHWIULHRGIUHGLRI")
				# print(line.split(" "))
			im = Image.open(image_name)
			width = int(im.size[0])
			height = int(im.size[1])
			line_elem= line.split(" ")
			if(len(line_elem)>2):
				print("enetered")
				class_name= line.split(' ')[4]
				# print(class_name.split(' '))
				box0= float(line.split(' ')[0])
				box1= float(line.split(' ')[1])
				box2= float(line.split(' ')[2])
				box3= float(line.split(' ')[3])
				x = (box2 + box0) / 2.0
				y = (box3 + box1) / 2.0
				w = box2 - box0
				h = box3 - box1
				x = x/width
				w = w/width
				y = y/height
				h = h/height
				# print(os.getcwd())
				# print("yfkufyyf")
				# print(dtring1)
				# print(class_name.split(' ') is dtring1)
				if(class_name.startswith('f')):
					# print("I amdjgvuygswvyfkugk")
					file_new.write('0')
				if(class_name.startswith('s')):
					file_new.write('1')
				if(class_name.startswith('r')):
					file_new.write('2')
				file_new.write(' ')
				file_new.write(str(x))
				file_new.write(' ')
				file_new.write(str(y))
				file_new.write(' ')
				file_new.write(str(w))
				file_new.write(' ')
				file_new.write(str(h))
				file_new.write('\n')


