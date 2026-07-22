// /d/hmy/changlang4.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条长长的过道，左右两旁都是墙，每隔四五丈，墙上都点着一支明晃晃
的巨烛。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"shifang",
		"south" : __DIR__"changlang6",
		"west" : __DIR__"changlang3",
		"north" : __DIR__"xiuxishi",
	]));
	setup();
	
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("gender") != "女性" )
		return notify_fail("看清楚，那是女弟子休息室！！，要睡到厢房去！\n");
	return ::valid_leave(me, dir);
}
