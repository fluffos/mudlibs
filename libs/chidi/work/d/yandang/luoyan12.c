// Room: /d/yandang/luoyan12.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
从客厅出来,就是后园,一般人是不会被邀请到这的,园中的花木扶
疏,鸟语声声,在中心处有一座假山,完全仿照雁荡山而建,一景一物,无
不具体而微,正是令人叹为观止.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan38",
  "south" : __DIR__"luoyan8",
]));

	setup();
	replace_program(ROOM);
}
