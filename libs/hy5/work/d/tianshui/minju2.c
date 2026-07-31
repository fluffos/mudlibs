// Room: /d/china/junying/xiaozhen/minju2.c

inherit ROOM;

void create()
{
	set("short", "屋子");
	set("long", @LONG
屋子里布置得很简陋，墙上挂着几张兽皮，一杆长矛，一把
弓箭，看样子主人是以打猎为生的。一个人躺在地上已经奄奄一
息了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"minju",
]));
	set("no_clean_up", 0);
	set("objects",([
  __DIR__"npc/liehu" : 1,
]));
	setup();
	replace_program(ROOM);
}
