// Room: /open/dt/shizilukou.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
洪昌路和晋阳街在这里交汇在一起，因此，这里的人流量特
别大，路口四周是几幢造型各异的楼房，更为这里增添了几分繁
华气象。街边不时有关外的牧民向来往的人们兜售牛皮、牛角之
类的商品。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu3",
  "east" : __DIR__"hongchanglu4",
  "south" : __DIR__"jinyangjie3",
  "north" : __DIR__"jinyangjie2",
]));

	set("outdoors","datong");

	set("objects",([
	"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}
