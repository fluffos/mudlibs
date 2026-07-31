
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"暗黑教会"NOR);
	set("long", HIM @LONG
这里是空荡荡的暗黑教会的走廊,四周的墙壁尽然是
用人骨做成，在些人骨有小孩的，妇女的。而且还在不
停的颤抖。处处都允满了鬼异可怕的声音。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
        set("outdoors", "migong");
	set("exits", ([
		"southwest" : __DIR__"dong12",
                "northeast" : __DIR__"dong12",
		"eastup" : __DIR__"dong35",
		"westdown" : __DIR__"dong11",
	]));
if (random(3)==0)
	set("exits", ([
		"southup" : __DIR__"dong12",
                "northdown" : __DIR__"dong35",
	]));
if (random(3)==0)
	set("exits", ([
		"westsouth" : __DIR__"dong11",
                "eastnorth" : __DIR__"dong35",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

