// Room: /d/japan/liushengfu.c

inherit ROOM;

void create()
{
	set("short", "柳生府");
	set("long", @LONG
这里是武士柳生英雄的家,柳生的刀法是家传,据说已经到了惊天地
而泣鬼神的地步.上门拜师的人更是整天络绎不绝.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xuanguan",
  "north" : __DIR__"jiedaoe3",
]));

	setup();
	replace_program(ROOM);
}
