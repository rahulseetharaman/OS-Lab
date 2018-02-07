#!/bin/bash
read -p "1-Number 2-Matrix" mode
if [ $mode -eq 1 ]
then
read -p "Enter operand 1" a
read -p "Enter operand 2" b
read -p "Enter operand" operand
case $operand in
'+') echo $(($a+$b)) ;;
'-') echo $(($a-$b)) ;;
'/') if [ $b -eq 0 ]
     then 
     echo "Division by Zero error"
     else
     echo $(($a/$b)) 
     fi   ;;
'*') echo $(($a*$b)) ;;
'%') if [ $b -eq 0 ]
     then  
     echo "Modulo by zero error"
     else
     echo $(($a%$b))
     fi   ;;
'^') echo $(($a^$b)) ;;
'~') echo $((~$a)) ;;
'!') num=$a
     i=1
     while [ $i -le $a ]
     do
	i=$(($i*2))
     done
     i=$(($i-1))
     echo $(($a^$i)) ;;
'!!') num=$a
      i=1
	while [ $i -le $a ]
	do
	 i=$(($i*2))
        done
         echo $(($a^$i))
	;;
'&&') echo $(($a&&$b)) ;;

'log') read -p "Enter base" base
echo "l($a)/l($base)" | bc -l ;;
'tan') 
echo "Tan($a)"| bc -l ;;
'sin')
echo "Sin($a)" | bc -l;;
'cos')
echo "Cos($a)" | bc -l;;
'pow')
echo "$a^$b" | bc ;;
esac
else
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
fi
