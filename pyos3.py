import os
with open('test.txt','r') as rf:
	with open('test2.txt','w') as wf:
		for line in rf:
			wf.write(line)

# working with images
with open('United.jpeg','rb') as img:
	with open('Logo.jpg','wb') as img2:
		chunk_size=4096
		rf_chunk=img.read(chunk_size)
		while len(rf_chunk)>0:
			img2.write(rf_chunk)
			rf_chunk=img.read(chunk_size)
	
	
