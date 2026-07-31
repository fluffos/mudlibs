// /u/chen/murong/midong.c
// by chen

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short","秘洞");
         set("long",@long
这里土地潮湿，墙上有一束火把。
long);
         set("exits",([
             "south" : __DIR__"huandong",
             "north" : __DIR__"hhyuan",
]));
         setup();
	
}
