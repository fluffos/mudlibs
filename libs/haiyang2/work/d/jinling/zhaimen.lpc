#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","双霄寨门");
  set("long",@LONG
这里是紫金山上绿林人物聚居的地方。巨木搭成的山寨门立在一个狭窄的山
口处，两边皆是山石，寨门口一面大旗上绣着日月交辉的图案，迎风飘扬。由东
面一路下山就是金陵城。北面入了山寨，可就......
LONG);
  set("exits",([
    "westdown"   : __DIR__"zijinshan2",
    "eastdown"  : __DIR__"zijinshan",
//    "north"  : __DIR__"juyiting",
  ]));
   set("objects",([
              "/d/hainan/npc/man4" : 1,
   ]));
  setup();
        replace_program(ROOM);
}
