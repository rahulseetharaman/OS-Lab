import os
f=open('test.txt','r')
print("The filename is "+f.name)
print("The mode is "+f.mode)
f.close()
# opening a file with a context manager
with open('test.txt','r') as f:
	#f is the file object variable
	#filecontents=f.read()
	#print(filecontents)
	#l=f.readlines()
	i=1
	#for lines in f:
	#	print(i,lines)
	#	i+=1
	#file_content=f.read(100)
	#print(file_content)
	f_contents=f.read(100)
	while len(f_contents)>0:
		print(f_contents)
		print("Currently at ",f.tell())
		f_contents=f.read(100)
	f.seek(0)
	print(f.read(10))
print(f.closed)

