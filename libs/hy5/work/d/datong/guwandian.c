// Room: /open/dt/guwandian.c

inherit ROOM;

void create()
{
	set("short", "古玩店");
	set("long", @LONG
你走进门来，店老板正拿着一只商周时期的小铜鼎仔细拂试，
见你进来，阴阳怪气地瞟了你一眼就又把注意力放到小鼎上去了。
你游目四顾，这里的木架上摆放着各种各样的小玩意，有铜马、
玉佩、金龙等等，除此之外，竟然还有一尊木头雕刻的小佛像。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tanhuanglu3",
]));

	setup();
	replace_program(ROOM);
}
