// Room: /d/feitian/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这儿是神古活心流的厨房。虽然神古活心流规定了开饭时间，但不少弟子还
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
