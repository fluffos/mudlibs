//weiqiang-e.c -- 围墙（东）
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"围墙"NOR);
  set("long", @LONG
这里的围墙十分高大，大红的油漆漆满墙面，金黄色的琉璃瓦覆盖在
围墙顶端。东面有个小门，似乎开着。
LONG
  );

  set("exits", ([     
			"west" : __DIR__"wangfu-fumen",
			"east" : __DIR__"jiaomen-e",

  ]));

	set("outdoors", "luoyang");
	setup();
	replace_program(ROOM);
}
