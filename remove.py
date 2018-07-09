import os

filename="data.txt"
file= open(filename, "r")
file1= open("new_data.txt", "w")
contents=file.readlines()
for line in contents:
	x=line.split()
	file1.write(x[1])
	file1.write(" ")
	file1.write(x[2])
	file1.write(" ")
	file1.write(x[3])
	file1.write(" ")
	file1.write(x[4])
	file1.write(" ")
	file1.write(x[5])
	file1.write("\n")