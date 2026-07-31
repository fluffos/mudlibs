
// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({-200,4770,10}));
	set("short", "辽东大营");
	set("long",
"你正站在一间大兵营的入口，两只巨大的石狮镇守在大门的两侧，一阵阵吆喝与刀剑碰撞的\n"
"声音从院子中传来，通过大门往东可以望见许多关宁铁骑正在操练。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"txyard",
  "northeast" : __DIR__"nroad7",
]));
	set("outdoors", "ny");
	set("objects", ([
  __DIR__"npc/wujiang" : 1,
  __DIR__"npc/bing" : 5,  	
		__DIR__"npc/txtrainer": 1]) ); 

	setup();
	replace_program(ROOM);
}
