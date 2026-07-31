// Room: /open/dt/youfujie2.c

inherit ROOM;

void create()
{
	set("short", "右府街");
	set("long", @LONG
当初为这条街命名的时候也曾着实费了一番脑筋，后来一位
李将军的南方客人想到了一个主意：既然这条街就座落在将军府
的右面，不如就叫右府街好了。这条街很短，但却位于城市的中
心，是大同城里最繁华的地带。北面是野味轩，南面是是西北一
带有名的如意赌坊。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"youfujie1",
  "east" : __DIR__"youfujie3",
  "south" : __DIR__"ruyidufang",
  "north" : __DIR__"yeweizhai",
]));

	set("outdoors","datong");
	setup();
	replace_program(ROOM);
}
