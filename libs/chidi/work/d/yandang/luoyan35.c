// Room: /d/yandang/luoyan35.c

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
走进月洞门,就是一个小花园,种满了各种花草,扬,柳,桃,李,不一而
足,有几条鹅卵石铺成的小路在草木中隐现,再向北有一座宽敞的大房子,
就是客人居所.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan34",
  "north" : __DIR__"luoyan36",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
