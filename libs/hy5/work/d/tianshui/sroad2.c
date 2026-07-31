// Room: /d/tianshui/sroad2.c

inherit ROOM;

void create()
{
	set("short", "小镇南街");
	set("long", @LONG
这里是南街，北面便是小镇的中央广场。每逢赶集的日子，
这里就热闹非凡。东面是这一带的首富洪百万的家。门口立着两
个石狮子，一付衙门气派。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sroad1",
  "east" : __DIR__"caizhu1",
  "south" : __DIR__"skou",
  "west" : __DIR__"business",
]));

	set("outdoors","tianshui");

	set("objects",([
"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
