// Room: /u/xiaozhen/caizhu1.c

inherit ROOM;

void create()
{
	set("short", "洪家大门");
	set("long", @LONG
这里便是天水镇的首富洪百万家的大门了，一对石狮子镇住
大门的两侧，门口灯笼高悬上写着一个“洪”字，朱漆大门足有
两寸厚。两条大狼狗卧于门边。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sroad2",
  "east" : __DIR__"caizhu2",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wolf_dog" : 2,
]));

	setup();
	replace_program(ROOM);
}
