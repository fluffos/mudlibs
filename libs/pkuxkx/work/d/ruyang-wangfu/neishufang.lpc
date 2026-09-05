//neishufang.c -- 内书房
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"内书房"NOR);
  set("long", @LONG
王爷平时不太爱看书，书房是很少来的。但最近每到深夜，这里的灯
总是亮着，说不定是郡主偶尔在用功？

LONG
  );

  set("exits", ([     
      "west" : __DIR__"neizhai-houyuan",
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
