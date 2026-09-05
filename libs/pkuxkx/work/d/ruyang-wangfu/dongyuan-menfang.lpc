//dongyuan-menfang.c -- 东院门房
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"东院门房"NOR);
  set("long", @LONG
汝阳王府的东院住着王爷的家眷，这里是个门房，遇有王爷的亲戚、
家人到访，或是内宅吩咐什么事情，这里的仆人都要小心伺候。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"jiaomen-e",   
      "north" : __DIR__"dongyuan-keting", 
      "west" : __DIR__"zoulang-e1",
  ]));

	set("objects", ([
		__DIR__"npc/puren" : 2,
	]));

  setup();
  replace_program(ROOM);
}
//NPC:王府仆人2名
