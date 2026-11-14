#!/bin/bash

DIR=`dirname $0`

URL="http://www.geocaching.com/track/details.aspx?id=2261877"

if [ -f $DIR/loc.txt ]
then
  cp $DIR/loc.txt $DIR/loc.txt.last
fi
NEWLOC=`lynx -dump $URL | grep -A1 "Recently Spotted" | tail -1 | sed -e 's/ \[.*\]In//g' | tr -s " "|cut -d: -f2 | tr -d "\n"`
echo $NEWLOC > $DIR/loc.txt

if [ `md5sum $DIR/loc.txt|awk '{print $1}'` != `md5sum $DIR/loc.txt.last|awk '{print $1}'` ]
then 
  touch $DIR/location_changed
  echo -n `date` >> $DIR/location_history
  echo "  new: $NEWLOC" >> $DIR/location_history
fi  
exit 0
