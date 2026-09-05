// Room: /u/pingpang/room/mihun1.c
// Made by: pingpang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "迷魂阵");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  	"east":__DIR__"mihun"+random(1),
  	"south" : __DIR__"mihun"+random(3),
	"west" : __DIR__"mihun"+random(4),
        "north":__DIR__"mihun2",
]));
	set("no_clean_up", 0);
	set("no_newbie_task",1);
	setup();
	replace_program(ROOM);
}
