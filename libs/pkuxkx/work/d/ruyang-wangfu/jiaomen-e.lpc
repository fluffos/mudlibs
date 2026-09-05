//jiaomen-e.c -- 东角门
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"东角门"NOR);
  set("long", @LONG
这里是汝阳王府的东角门，因为王爷的家眷都住在王府的东院，为了
方便家眷出入，这个小门倒是常开着的。
LONG
  );

  set("exits", ([     
      "northwest" : __DIR__"weishiying-e",   
      "north" : __DIR__"dongyuan-menfang", 
      "west" : __DIR__"weiqiang-e",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
