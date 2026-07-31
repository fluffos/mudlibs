// sanjie tianyilu5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天一路");
  set ("long", @LONG
	
路旁长满仙花神草，异香扑鼻，令人心旷神矣，与上山之路
乃天渊之别。而且祥云缭绕，一派安详景况似乎能洗脱人间
烦恼，导人顿悟。
LONG);

  set("exits", ([ 
  "northup" : __DIR__"tianyilu6",
  "southdown" : __DIR__"tianyilu4",
]));
  set("outdoors", 1);

  setup();
}
