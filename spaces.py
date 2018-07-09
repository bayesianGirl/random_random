import re 

f1=open('file3.txt','w+')
with open('file.txt') as f:
	contents=f.read()
	file_contents=re.sub(r'\t', ' ',contents)
	f1.write(file_contents)


