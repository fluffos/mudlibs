//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "华乐殿");
set("long", @LONG
华乐殿 长梁雕龙，飞檐画凤。里面殿阁高大
雄伟，层层叠叠，琉璃瓦白玉掾富丽堂皇。 
LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
