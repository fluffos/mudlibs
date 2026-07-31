
// Room: /d/snow/droad1.c

inherit ROOM;

void create()
{
        set("coor",({-20,5000,13}));
	set("short", "山路");
	set("long",
"这是一条久已无人走过的山路，路边的杂草已将小路掩盖。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown": __DIR__"droad0",
  "northup": __DIR__"droad2",
]));
	set("outdoors", "ny");
	setup();
	replace_program(ROOM);
}
