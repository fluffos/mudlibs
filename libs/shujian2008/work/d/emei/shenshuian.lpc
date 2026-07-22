// Room: /d/emei/shenshuian.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "神水庵" NOR);
	set("long", @LONG
神水庵位于宝掌峰下，庵前有大峨石和玉液泉，泉出石下，清澈无比，终
年不涸。一株大海棠树，已是数百苍龄，抱可数围，高达十余丈。旁边有福寿
庵；由此西上中峰寺，东下纯阳殿。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
	  "south" : __DIR__"fushouan",
	  "eastdown" : __DIR__"chunyangdian",
	  "westup" : __DIR__"zhongfengsi",
]));
set("objects",([
    __DIR__"npc/xiangke" : 2,
]));

	setup();
}
