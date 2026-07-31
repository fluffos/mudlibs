//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "青龙殿");
set("long", @LONG
青龙殿 长梁雕龙，飞檐画凤。里面殿阁高大
雄伟，层层叠叠，琉璃瓦白玉掾富丽堂皇。 
LONG );


set("magicroom",1);set("exits", ([
  "west"   : __DIR__"xuanyuantang",
  "east"   : __DIR__"xinyuegong",
]));


set("objects", ([
]));



setup();
}
