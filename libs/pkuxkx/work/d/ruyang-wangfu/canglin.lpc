//canglin.c -- 仓廪
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"仓廪"NOR);
  set("long", @LONG
这里是王府的仓廪，存放了不少粮食，看起来足够王府上上下下吃一
年的了。

LONG
  );

  set("exits", ([     
      "east" : __DIR__"neizhai-qianyuan",
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
