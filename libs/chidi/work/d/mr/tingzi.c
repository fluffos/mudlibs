#include <room.h>
inherit ROOM;
void create()
{
         set("short","亭子");
         set ("long",@long
这是个很小的亭子，但是能够看到几乎全部的景色，远处有一片樱桃园。
湖中几条小舟在碧绿的湖面上往来穿梭，湖中有一座木桥通向湖中的亭子。
在水池的假山上有一个黑乎乎的洞穴。 
long);
         set("exits",([
             "westdown" : __DIR__"c14-1",
]));
         set("objects",([
             __DIR__"npc/wyy" : 1,
]));
         setup();
         replace_program(ROOM);
}
