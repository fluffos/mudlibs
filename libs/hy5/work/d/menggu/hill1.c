// Room: /d/menggu/hill1.c

inherit ROOM;

void create()
{
	set("short", "荒山上");
	set("long", @LONG
稀疏的灌木,草丛.坡顶比较平缓,西北风一阵紧,一阵缓,北面的一片乌
云缓缓移动过来,昏黄的月光下几点磷火漂移不定.东面的草丛中似乎有些
东西在闪着白光.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kezhene.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"caocong",
  "northwest" : __DIR__"caocong1",
  "westdown" : __DIR__"shulin",
]));

	setup();
	replace_program(ROOM);
}
