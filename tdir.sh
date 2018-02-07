#!/bin/bash
echo "1.Add details"
echo "2.Update details"
echo "3.Delete record"
read  option
case $option in
'1') read -p "Enter name " name
     read -p "Enter phonenumber " pn
     read -p "Enter mailid " eid
     if [ $name \< 'K' ]
     then 
     filename="AJ.txt"
     elif [ $name \< 'U' ]
     then 
     filename="KT.txt"
     else
     filename="UZ.txt"
     fi
     if grep -q "$eid" $filename
     then 
	echo "Already present"
     else
	echo "$name|$pn|$eid" >> $filename
     fi ;;
'2') read -p "Enter email" eid
     read -p "Enter name" name
     read -p "Enter number" number
     if [ $name \< 'K' ]
     then 
     filename="AJ.txt"
     elif [ $name \< 'U' ]
     then
      filename="KT.txt"
     else
      filename="UZ.txt"
     fi
     if grep -q $eid $filename
     then
     read -p "Enter new email" ne
     read -p "Enter new name" nn
     read -p "Enter new number" nnum
     sed -i 's/'$name'|'$number'|'$eid'/'$nn'|'$nnum'|'$ne'/g' "$filename" 
     fi ;;
'3') read -p "Enter email" eid
     read -p "Enter name" ename
     read -p "Enter number" number
     if [ $ename \< 'K' ]
     then
     filename="AJ.txt"
     elif [ $ename \< 'U' ]
     then
     filename="KT.txt"
     else
     filename="UZ.txt"
     fi
     if grep -q "$eid" $filename
     then
     sed -i '/'$ename'\|'$number'\|'$eid'/d' $filename
     fi
     ;;	
esac
     	
