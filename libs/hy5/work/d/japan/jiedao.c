// Room: /d/japan/jiedao.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是用黄泥夯出的一条街道,十分的宽敞.虽然是泥作的,不过由于当
初建的时候很是用心,所有你要是不小心摔倒了,保你跌断些什么.街道的东
面有一家旅店.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yijiguan",
  "south" : __DIR__"nanmen",
  "north" : __DIR__"jiedaos",
  "east" : __DIR__"lvdian",
]));

	setup();
	replace_program(ROOM);
}
