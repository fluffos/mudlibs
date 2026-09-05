//wofang-e.c -- 东卧房
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"东卧房"NOR);
  set("long", @LONG
这里是东卧房，四面墙上挂着毡毯，地上也铺着大红的地毯。走进这
里，你甚至疑心自己到了一个蒙古包，房内的所有物件、摆设都是按照蒙
古人的习俗放置的。汝阳王的原配妻子，老王妃就住在这里。

LONG
  );

  set("exits", ([     
      "west" : __DIR__"neizhai-zhengting",
  ]));

	set("objects", ([
		__DIR__"npc/laowangfei" : 1,
	]));

  setup();
  replace_program(ROOM);
}
//NPC:老王妃1名
