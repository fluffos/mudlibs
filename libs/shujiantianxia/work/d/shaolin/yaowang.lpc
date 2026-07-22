//yaowang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"药王院"NOR);
	set("long", @LONG
一进药王院，扑鼻而来的是浓郁的药香。房间内排满了装满各类药材的
大药柜，每个药柜都有上百个装药的抽屉贴满了各类药名。西边是一个巨大
红杉木柜，柜上贴着方丈印的封条。一位中年僧人正来回忙碌着指点众执役
僧称量药品，熬药煎汤。
LONG
	);

	set("exits", ([
		"west" : __DIR__ "songshu1",
       ]));
         set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
	]));

	
	set("coor/x",80);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}



