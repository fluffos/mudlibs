#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"岳麓书院"NOR);
	set("long", @LONG
这里就是天下闻名的岳麓书院了，一个老学究坐镇这里讲解学问。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"shuyuan",
        "west" : __DIR__"shuyuan3",
        "east" : __DIR__"shuyuan4",
        "north" : __DIR__"shuyuan5",
	]));
    set("objects", ([
        __DIR__"npc/zhu" : 1,
		
	]));
    set("least_msg",1);
	setup();
	
}

