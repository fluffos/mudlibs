// /u/beyond/mr/tingzi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"亭子"NOR);
         set ("long",@long
这是个很小的亭子，但是能够看到几乎全部的景色，远处有一片樱桃园。
湖中几条小舟在碧绿的湖面上往来穿梭，湖中有一座木桥通向湖中的亭子。
在水池的假山上有一个黑乎乎的洞穴。 
long);
         set("exits",([
             "westdown" : __DIR__"cl4-1",
]));
         setup();
         replace_program(ROOM);
}


