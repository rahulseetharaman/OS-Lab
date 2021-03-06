#!/bin/bash
#1
#echo "S Grade and O Grade Students"
awk '$4=="S" || $4=="A" { printf("%s %s %s %s\n",$1,$2,$3,$4);}' marklist > "op1.txt"
#2
#echo "students with nn in their name"
awk '$2 ~ /nn/ {print }' marklist > "op2.txt"
#3
#echo "students with names that begin from a-k"
awk '$2 ~ /^[a-k]/ { print }' marklist > "op3.txt"
#4
#echo "Deleted Students who scored 40 or less marks"
sed '/[\s]*40[\s]*/d' marklist > "op4.txt"
#5
#echo "Replacing 09 with 10"
sed 's/09/10/g' marklist > "op5.txt"
#6
#echo "Displaying the rollno column"
awk '{if(NR!=1){print $1}}' marklist > "op6.txt"

