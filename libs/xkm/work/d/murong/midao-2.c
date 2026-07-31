// /u/chen/murong/midao.c
// by chen

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short","秘道");
         set("long",@long
这里土地潮湿，墙上有一束火把,不知通向何处。
long);
         set("exits",([
             "out" : __DIR__"mushi",
             "north" : __DIR__"mishi",
]));
         setup();
	
}
