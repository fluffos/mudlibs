// Room: /d/fengtian/xiang2.c

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
一条居民小巷，这里住着盛京城郊的一些居民和猎户，小巷
很干净清洁，小巷深处是这里最有名的吴猎户家，听说他曾经孤
身闯入过俄罗斯匪帮的驻地。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wujia",
  "south" : __DIR__"xiang1",
]));

	set("objects",([
	"/clone/npc/man" : 3,
]));

	set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
