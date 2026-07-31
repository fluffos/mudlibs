// Room: /d/fengtian/chaguan.c

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
和老磨坊一样，这间茶馆也是盛京很著名的一个地方，同样
的百年老店，同样的年青一代的老板，同样的红红火火。这里不
但有上好的长白山参茶，还有不少东北的特色小吃，每天都有三
教九流的人在这里聚会侃天。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xh1",
]));

	set("objects",([
	__DIR__"npc/cha_sell" : 1,
]));

	setup();
	replace_program(ROOM);
}
