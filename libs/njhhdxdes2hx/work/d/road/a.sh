#!/bin/ksh
mkdir tmp.$$
for i in r*.c
do
echo $i
cat $i | sed -f a.sed > tmp.$$/$i
done
mv tmp.$$/* .
rm -rf tmp.$$
