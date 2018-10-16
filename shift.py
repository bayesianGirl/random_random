import os
import cv2

dir= os.getcwd()
switch_dir= '/home/ruchika/darknet/data/cars_dataset'
for files in os.listdir(dir):
	if(files.endswith('new.txt')):
		os.chdir(switch_dir)
		file_name= files.split('new.txt')[0]
		print(file_name)
		image_path= '/home/ruchika/BBox-Label-Tool-Multi-Class/Images/001/' + file_name + '.JPG'
		image= cv2.imread(image_path)
		cv2.imwrite(file_name + '.jpg', image)
