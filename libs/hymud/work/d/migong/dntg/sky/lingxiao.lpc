//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "灵霄宝殿");
set("long", @LONG
灵霄宝殿 长梁雕龙，飞檐画凤。里面殿阁高大
雄伟，层层叠叠，琉璃瓦白玉掾富丽堂皇。玉皇大帝
正坐在中央。
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"qianyuangong",
  "north"   : __DIR__"hougong",
//  "west"   : __DIR__"hougong",
//  "east"   : __DIR__"hougong",
]));


set("objects", ([
  __DIR__"npc/yuhuang"   : 1,
//"/d/qujing/wuzhuang/npc/laojun"   : 1,
  __DIR__"npc/wuquxingjun"   : 1,
]));



setup();
}
