// Room: /u/pingpang/room/mihun4.c
// made by:pingpang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "迷魂阵");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"east":__DIR__"mihun"+random(7),
  	"south" : __DIR__"mihun"+random(5),
        "west" : __DIR__"mihun5",
	"north":__DIR__"mihun"+random(1),
]));
	set("no_clean_up", 0);
	set("no_newbie_task",1);
	setup();
	replace_program(ROOM);
}
