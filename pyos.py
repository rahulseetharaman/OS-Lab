import os
from datetime import datetime
print("The current working directory is "+os.getcwd())
#os.chdir("/home/rahul/Documents")
#print("Changed to "+os.getcwd())
print(os.listdir())
#os.mkdir('Sample')
#os.makedirs('Sample2/subsample')
#os.rename('/home/rahul/Documents/PyConAPAC.mp4','/home/rahul/Documents/PyCon.mp4')
#print(os.stat('../PyCon.mp4'))
#timestamp=os.stat('../PyCon.mp4').st_mtime
#print(datetime.fromtimestamp(timestamp))
for dirpath,dirnames,filenames in os.walk('..'):
	print('Directories :',dirnames)
	print('Dirpaths:',dirpath)
	print('filenames:',filenames)
print(os.environ.get('HOME'))
print(os.path.basename('/users/rahul/hello.txt'))
print(os.path.exists('/users/rahul/hello.txt'))
print(os.path.splitext('/users/rahul/hello.txt'))
