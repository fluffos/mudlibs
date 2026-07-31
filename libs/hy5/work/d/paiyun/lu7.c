// Room: /d/paiyun/lu7.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条小路弯弯曲曲向山林的深处延伸，路旁是郁郁葱葱树林
，驻足路旁你可以闻到空气里绿色的味道（wen〕。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu5",
  "east" : __DIR__"mingzhai1",
  "north" : __DIR__"lu8",
]));
	set("outdoors", "paiyun");

	set("objects",([
	__DIR__"npc/shanfei" : 2,
	__DIR__"npc/fei_tou" : 1,
]));

	setup();
	replace_program(ROOM);
}
