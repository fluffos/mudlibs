//houdian2.c	后殿
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","后殿");
	set("long",@LONG 
这里是成德殿的后殿，是教主休息的地方。教主如果和
长老们议事觉得累了或是练功累了就来这里休息一下。四周
都是静悄悄的，几个丫鬟正在打盹，你还是快点离开吧。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"xicedian2",
		"southeast" : __DIR__"dongce2",
	]));
        set("no_task", 1);
	setup();
}

