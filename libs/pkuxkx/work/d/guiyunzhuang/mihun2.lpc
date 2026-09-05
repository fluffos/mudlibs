// Room: /u/pingpang/mihun2.c
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
	"east":__DIR__"mihun"+random(3),
  	"south" : __DIR__"mihun"+random(6),
        "west" : __DIR__"mihun3",
	"north":__DIR__"mihun"+random(7),
]));
	set("no_clean_up", 0);
	set("no_newbie_task",1);
	setup();
	replace_program(ROOM);
}
