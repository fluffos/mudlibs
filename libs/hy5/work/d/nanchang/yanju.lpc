
#include <ansi.h>
inherit ROOM;

#define JOBNAME "南昌"

void create ()
{
  set ("short","魁星阁");
  set ("long", @LONG
魁星阁，在梦娘娘庙的不远。为两层四方塔形楼阁。
建于明代正德年间，古朴端庄。原来是一幢佛堂与僧房，
后来成了私塾学馆。传说清乾隆时大学士胡中藻（梦山附
近人）曾在这里读书，但他“读了三年书，读不清‘人之初
’”（注：指过去的启蒙读本《三字经》）。一天，他突然
昏倒在地，口吐鲜血，后苏醒过来，从此学业猛进，得中
进士，成为有名的大学士，由此人们就把这个房子称为“
魁星阁”。
LONG);

  set("exits", ([ 
 "west":__DIR__"beidajie2",
       ]));
  set("objects",([
	  "/clone/npc/man":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

