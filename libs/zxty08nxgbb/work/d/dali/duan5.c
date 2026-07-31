// Room: /d/dali/duan5.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分9秒。

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条弯弯曲曲的长廊通向王府的后院，白玉栏杆上是巧匠雕琢
的茶花图案，形态各异，几欲乱真。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"duan4",
  "southeast" : __DIR__"duan6",
]));

	setup();
}

