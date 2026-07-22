// Room: /d/feitian/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这儿是梅庄的厨房。除了为四位庄主准备饭菜之外，当然大部分时间
都是忙着为本庄弟子准备伙食。虽然梅庄规定了开饭时间，但不少弟子还
是趁着厨师们闲聊之机，偷偷找些东西以备断粮之豫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
          "northwest" : __DIR__"xiangfang",
          "northeast" : __DIR__"huayuan",
]));
	set("objects",([
	__DIR__"obj/shousi":2,
	__DIR__"obj/cha":3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
