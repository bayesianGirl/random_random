import os

os.chdir("/home/ruchika/BBox-Label-Tool-Multi-Class/Images/001")
path= "/home/ruchika/BBox-Label-Tool-Multi-Class/Images/001"
for images in os.listdir(path):
	if(images.endswith('.jpg')):
		image_name= images.split('.')[0]
		new_name= image_name+ '.JPG'
		print(os.path.join(path, images))
		os.rename(os.path.join(path, images), os.path.join(path, new_name))