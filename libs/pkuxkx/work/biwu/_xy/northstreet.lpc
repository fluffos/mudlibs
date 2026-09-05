// Room: /clone/misc/northstreet.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "拱宸门内街");
	set("long", @LONG
这里位于襄阳城的北部，因为当时正对蒙古大军的兵锋。路上不仅挖出了深
浅不一的壕沟，楼边还有一架架废弃的拒马，所以格外的难行。
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
		"north" : __DIR__"northgate",
		"south" : __DIR__"northdoor",
	    "west" : __DIR__"shop",
		"east" : __DIR__"dahu",
		"northeast" : __DIR__"pool",
	    "northwest" : __DIR__"xx2",
	]));
	set("objects", ([
    ("/biwu/xy/npc/yexingren") : random(2),
    ]));
	set("no_clean_up", 0);
	setup();
}

