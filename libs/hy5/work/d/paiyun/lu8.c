// Room: /d/paiyun/lu8.c

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
  "west" : __DIR__"lu9",
  "south" : __DIR__"lu7",
  "east" : __DIR__"mingzhai2",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
