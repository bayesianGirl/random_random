import os

dir= os.getcwd()
for files in os.listdir(dir):
	if(files.endswith(".txt")):
		f= open(files, "r")
		contents= f.readlines()
		if(len(contents)==0):
			os.remove(files)
			image_name= files.split(".")[0]+".jpg"
			os.remove(image_name)
