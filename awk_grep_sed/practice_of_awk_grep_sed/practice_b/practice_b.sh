#!/bin/bash
cat >> test.txt << EOF
/ is the root directory
bin is the system binary directory
usr bin is the user binary directory
home $USER is my home directory
home $USER bin is my binary directory
EOF
cat test.txt | sed 's/^bin/\/bin/' > tmp1.txt
cat tmp1.txt | sed 's/usr bin/\/usr\/bin/' > tmp2.txt
cat tmp2.txt | sed 's/home/\/home/' > tmp3.txt
cat tmp3.txt | sed 's/ '$USER'/\/'$USER'/' > tmp4.txt
cat tmp4.txt | sed 's/ bin/\/bin/g'


rm test.txt
rm tmp*.txt

#每次程序执行完毕之后，文件中的内容会堆积，执行次数越多，输出文本内容越多,故每次执行完更改命令后删除test.txt即可

# sed 's/ bin/\/bin/'只能更改了第一处" bin"后面的不能更改,应改为 sed 's/ bin/\/bin/g'
