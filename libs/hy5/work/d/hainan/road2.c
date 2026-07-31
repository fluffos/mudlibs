// Room: /d/hainan/road2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
鹅卵石铺成的一条小径,两边的花草都整理得十分别致.远处山川历
历在目,风中隐隐传来隆窿的水声.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road1",
  "northwest" : __DIR__"road3",
  "eastup" : __DIR__"road4",
]));

	setup();
	replace_program(ROOM);
}
