// Room: /d/paiyun/lu9.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条小路弯弯曲曲向山林的深处延伸，路旁是郁郁葱葱树林
，驻足路旁你可以闻到空气里绿色的味道（wen〕。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"lu10",
  "east" : __DIR__"lu8",
  "north" : __DIR__"lin4",
]));

set("objects", ([
	"/d/heifeng/npc/wolfdog":3,
       ]) );

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
