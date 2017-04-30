#!/bin/bash 
echo "请输入两个不同数字(Please enter two different numbers)：" 
read num1
read num2
expr $num1 + 1 &> /dev/null 
if [ $? -eq 0 ];then #判断num1是否为数字
    expr $num2 + 1 &> /dev/null 
    if [ $? -eq 0 ];then #判断num2是否为数字
        if [ `expr $num1 \> $num2` -eq 1 ];then
            echo "The numbers are: $num2 < $num1"
        else
            echo "The numbers are: $num1 < $num2"
        fi
    else
        echo "num输入错误！"
    fi           
else
  echo "num输入错误！"
fi





