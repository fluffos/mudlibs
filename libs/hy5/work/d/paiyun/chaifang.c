// Room: /d/paiyun/chaifang.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
一间小小的柴房堆满了干的柴火，柴火码放的很整齐，不过
从安全角度看这里还是很危险的，如果有人在这里放一把火（fanghuo)
嘿嘿那可难说会有什么结果。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu2",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
