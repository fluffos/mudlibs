
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"north" : __DIR__"dong39",
                "east" : __DIR__"dong37",
		"south" : __DIR__"dong35",
                "west" : __DIR__"dong32",

	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong39",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong32",
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(4),
              __DIR__"npc/lev3" : 2,

         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

