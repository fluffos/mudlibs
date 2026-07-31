// Room: /d/sandboy/road1.c

inherit ROOM;

void create()
{
	set("short", "田埂");
	set("long", @LONG
田埂两边长满各类绿色的青草,许多还开出了美丽的花朵.一眼望去,眼
前是金灿灿的一片稻田,快到该收割的时候了.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"pond",
  "east" : __DIR__"road2",
  "south" : __DIR__"daotian1",
  "north" : __DIR__"daotian2",
]));

	setup();
	replace_program(ROOM);
}
