// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({-5,-50,0}));
	set("short", "淳风武馆大门");
	set("long",
"你现在正站在一间大宅院的入口，两只巨大的石狮镇守在大门的两侧，一阵阵吆喝与刀剑碰\n"
"撞的声音从院子中传来，通过大门往东可以望见许多身穿灰衣的汉子正在操练。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"school2",
]));
	set("outdoors", "ny");
          set_temp("light",1);
	set("objects", ([
		__DIR__"npc/guard": 1 ]) );



	setup();
	replace_program(ROOM);
}
