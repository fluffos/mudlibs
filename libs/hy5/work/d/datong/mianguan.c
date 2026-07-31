// Room: /open/dt/mianguan.c

inherit ROOM;

void create()
{
	set("short", "面馆");
	set("long", @LONG
面馆的老板是一个回回，他在这里开这家面馆已经有二三十
年了，从厨房端出去的每一碗面都是他亲手拉出来的。他卖的大
碗牛肉拉面既筋道又便宜，所以这个面馆虽不像旁边的认一力那
么有名，可每天也招来不少穷乡亲们。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu4",
]));

	setup();
	replace_program(ROOM);
}
