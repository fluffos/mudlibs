// Room: /d/linzhi/lin03.c

inherit ROOM;

void create()
{
	set("short", "高原大路坡道");
	set("long", @LONG
你走到一条高原坡道上，蓝蓝的天空上飘着朵朵白云，你感
到心灵被静化了。你向四周看去，只见天地相接处白峰起伏，那
一定是高山积雪了。前面是一道山涧，不时传来流水的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin02",
  "northdown" : __DIR__"lin04",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2800);
	setup();
	replace_program(ROOM);
}
