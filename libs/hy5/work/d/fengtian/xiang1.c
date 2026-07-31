// Room: /d/fengtian/xiang1.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wy1",
  "east" : __DIR__"minju",
  "north" : __DIR__"xiang2",
]));

	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
