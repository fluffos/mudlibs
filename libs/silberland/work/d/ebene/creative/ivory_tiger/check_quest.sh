#!/bin/bash

usage() {
  echo "usage: $0 [prefix]"
  echo "prefix: prefix of quest defines"
}

if [ ! -f quest.h ] ; then
  usage
  echo
  echo "quest.h not found"
  exit 1
fi

if [ $# != 1 ] ; then
  usage
  exit 1
fi

QUEST_TASKS=`grep $1 quest.h | grep \/\/ | cut -d ' ' -f2`;

for i in $QUEST_TASKS ; do
  echo -n "quest task $i: "
  RESOLVED=`find . -type f -name '*.c' | xargs grep $i | grep -v status_q`
  echo $RESOLVED | grep set_flag > /dev/null
  if [ $? == 1 ] ; then
    echo -n "NOT "
    FOUND_IN=""
  else
    FOUND_IN=`echo $RESOLVED | cut -d':' -f1`
  fi
  echo "OK ($FOUND_IN)"
done

