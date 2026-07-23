// Room: /d/fuzhou/gushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "鼓山");
	set("long", @LONG
鼓山以山上有石形如鼓，扣之如擂鼓而得名，非只山势
如鼓覆地。山上苍松滴翠，岩秀谷幽，风景秀丽，四季如春。
有晋以来，即为“八闽二绝”之一。
LONG );
	set("exits", ([
                "north"    : __DIR__"yongquan",
                "westdown" : __DIR__"shulin",
	]));
	set("objects", ([
                "/d/wudang/npc/monkey": 1,
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

