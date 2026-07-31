// /u/beyond/mr/jingyinge.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",RED"静音阁"NOR);
         set("long",@long
这里是修身养性的好场所，这里静悄悄的，没有主人的吩咐，谁也
不能够随便出入这里，在墙上挂着一幅图。
long);
       
         set("exits",([
             "east" : __DIR__"neitang",
             "west" : __DIR__"cl6-2",
             "south" : __DIR__"cl6-5",
]));
         setup();
}

