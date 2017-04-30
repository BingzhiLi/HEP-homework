#!/bin/bash
echo "请输入两个不同数字(Please enter two different numbers)："
read num1 
read num2
if [ `echo "$num1 >= $num2" | bc` -eq 1 ];then
    echo "The numbers are: $num2 < $num1"
else
    echo "The numbers are: $num1 < $num2"
fi



   
