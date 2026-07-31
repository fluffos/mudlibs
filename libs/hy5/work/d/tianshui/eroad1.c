// Room: /d/tianshui/eroad1.c

inherit ROOM;

void create()
{
	set("short", "小镇东街");
	set("long", @LONG
这条街道熙熙攘攘，操着南腔北调的行人来来往往，很多人
向西边的广场走去。北面是一家客栈，经常有人进进出出，看样
子生意很好。南面是一家钱庄。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kezhan",
  "west" : __DIR__"cross",
  "south" : __DIR__"yinhao",
  "east" : __DIR__"eroad2",
]));
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
