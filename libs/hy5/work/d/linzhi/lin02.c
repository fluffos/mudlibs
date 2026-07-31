// Room: /d/linzhi/lin02.c

inherit ROOM;

void create()
{
	set("short", "高原大路");
	set("long", @LONG
你走到一条高原大路上，蓝蓝的天空上飘着朵朵白云，你感
到心灵被静化了。你向四周看去，只见天地相接处白峰起伏，那
一定是高山积雪了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin01",
  "westdown" : __DIR__"lin03",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3000);
	setup();
	replace_program(ROOM);
}
