//ROOM: /d/suzhou/szroad7.c
//by dwolf
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"大驿道"NOR);
	set("long", @LONG
你走在一条静谧的小道上，远处能否看到森林，依稀能听到猛兽的吼声。道路两旁
是整整齐齐的杨树林。东边就是苏州城了。路上可以看到一些去打猎的人。
LONG 
	);
	set("exits", ([   
		"north" : __DIR__"szroad8",
		"east" : __DIR__"szroad6",
		"west" : "/d/road/rjltosz1",
]));
	setup();
	replace_program(ROOM);
}
