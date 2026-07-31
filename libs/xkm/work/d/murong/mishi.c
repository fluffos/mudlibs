// /u/chen/murong/mishi.c
//by chen

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","秘室");
         set ("long",@long
这是一个秘室，里面住着一个人，你悄悄地走了过去。
long);
         set("exits",([
             "south" : __DIR__"midao-2",
]));
set("objects",([
	__DIR__"npc/murong-bo" : 1,
]));

set("no_fight",1);
         setup();
         
}