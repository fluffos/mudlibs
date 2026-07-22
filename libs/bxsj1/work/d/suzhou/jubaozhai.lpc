#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"聚宝斋"NOR);
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它
发行的银票信誉非常好，通行全国。这里是苏州分店。
LONG
	);

	set("exits", ([
		"east" : __DIR__"nandajie1",
	]));

	set("objects", ([
		__DIR__"npc/laoban2" : 1,
	]));

	set("coor/x",100);
  set("coor/y",240);
   set("coor/z",0);
   set("incity",1);
	setup();
}

