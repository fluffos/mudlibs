// Room: /d/fengtian/hua.c

inherit ROOM;

void create()
{
	set("short", "花店");
	set("long", @LONG
这间小小的花店为新汇路增加了不少的景致，走进花店就有
一种清新的感觉，除了花香还有花店里青春的气息，别忘了花店
的老板是个很漂亮的小姑娘。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xh3",
]));

	set("objects",([
	__DIR__"npc/flower_sell" : 1,
]));

	setup();
	replace_program(ROOM);
}
