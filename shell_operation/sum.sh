#!/bin/bash
echo "请输入两个不同数字(Please enter two different numbers)："
read num1 
read num2
SUM=`echo "$num1 + $num2" | bc`
echo "SUM=$SUM"
