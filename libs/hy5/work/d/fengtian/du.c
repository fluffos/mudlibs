// Room: /d/fengtian/du.c

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
塞北有名的银钩睹坊，当然这里当家的和龙门客栈的老板交
情很深，想来赌的话这里是个好去处，你看门口的人进进出出，
屋里的人更是昏天黑地，好赌的人来到这里就一定有温暖的感觉。

LONG
);



	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ll1",
]));

	set("objects",([
	__DIR__"npc/judge" : 1,
]));

	setup();
}
