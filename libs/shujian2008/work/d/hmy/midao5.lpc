// mg3.c
// Created by Numa 19991020

inherit ROOM;
#include "midao.h"

void create()
{

	set("short","地道");
	set("long",@LONG
这是一条阴森森的地道，墙上每隔几米就挂着一盏若隐若现的油灯，一股
寒气直袭而来。
LONG
	);
	set("exits",([
		"east" : __DIR__"midao" + random(7),
      		"west" : __DIR__"midao" + random(7),
      		"south" : __DIR__"midao" + random(7),
      		"north" : __DIR__"midao" + random(7),
  	]));

  	set("no_clean_up", 0);
  	setup();
}
