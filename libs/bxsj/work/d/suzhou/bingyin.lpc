// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
	这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，
有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视
着四周。看到你进来，他们全都向你包围了过来，形势看来不太妙。
LONG
	);

	set("exits", ([
//  "south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));

 set("objects", ([
//    __DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
 __DIR__"npc/bing" : 3,
	]));
	set("coor/x",100);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}


