#!/bin/ksh
mkdir tmp.$$
for i in r*.c
do
echo $i
cat $i | sed -f /home/mudadm/tmp/rep.sed > tmp.$$/$i
done
mv tmp.$$/* .
rm -rf tmp.$$
