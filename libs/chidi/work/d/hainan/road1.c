// Room: /d/hainan/road1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
鹅卵石铺成的一条小径,两边是各种花草,有许多你都没见过.彩蝶在
花中飞舞.空气十分的清新!
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi",
  "north" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
