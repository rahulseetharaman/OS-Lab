#!/bin/bash
declare -A mat
declare -A mat2
declare -A sum
declare -A diff
declare -A mul
rows=3
cols=3
echo "Enter first matrix"

for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
read num
mat[$i,$j]=$num
done
done

echo "Enter second matrix"
for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
read num
mat2[$i,$j]=$num
done
done

echo "SUM"
for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
sum[$i,$j]=$((${mat[$i,$j]}+${mat2[$i,$j]}))
done
done

for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
echo ${sum[$i,$j]}
done
done

echo "DIFF"
for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
diff[$i,$j]=$((${mat[$i,$j]}-${mat2[$i,$j]}))
done
done

for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
echo ${diff[$i,$j]}
done
done

echo "Product"
for((i=1;i<=2;i++))
 do
   for((j=1;j<=2;j++))
     do
      mul[$i,$j]=0	
      for((k=1;k<=2;k++))
	do
         mul[$i,$j]=$((${mat[$i,$k]}*${mat2[$k,$j]}+${mul[$i,$j]}))
        done
   done
 done

for((i=1;i<=2;i++))
do
for((j=1;j<=2;j++))
do
echo ${mul[$i,$j]}
done
done
