for number in 0 1 2 3
do
cat > test${number}.txt << EOF
this is the $number txt file generated
EOF
done
for number in 0 1 2 3
do
if [ $number -eq 0 ]; then
cat test0.txt | sed 's/0/first/' > tmp.txt
cat tmp.txt
mv tmp.txt test0.txt
elif [ $number -eq 1 ]; then
cat test1.txt | sed 's/1/second/' > tmp.txt
cat tmp.txt
mv tmp.txt test1.txt
elif [ $number -eq 2 ]; then
cat test2.txt | sed 's/2/third/' > tmp.txt
cat tmp.txt
mv tmp.txt test2.txt
elif [ $number -eq 3 ]; then
cat test3.txt | sed 's/3/forth/' > tmp.txt
cat tmp.txt
mv tmp.txt test3.txt
fi
done
rm -f testc.txt
for number in 0 1 2 3
do
cat test${number}.txt >> testc.txt
done
echo
cat testc.txt
