#include <ansi.h>
#include <room.h>
#include "nodie.h"
#include "path.h"

inherit ROOM;
void create()
{
	set("short", CYN"地牢通道"NOR);
	set("long","一条狭窄而又阴暗的地牢通道，只能容一个人勉强通过。你忽然发\n现拐角处似乎挂着一个铃铛(bell)，也不知是什么用途。\n");
	set("exits", ([
		"west" : __DIR__"dilao3",
		"east" : __DIR__"dilao4",
	]));
	set("item_desc", ([
		"bell" : "一个小铃铛挂在墙角处，要摇摇它(shake bell)吗？\n",
	]));	
	setup();
}
