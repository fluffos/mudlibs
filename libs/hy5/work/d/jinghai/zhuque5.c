// Room: /d/jinghai/zhuque5.c

inherit ROOM;

void create()
{
	set("short", "岔路口");
	set("long", @LONG
这里是一个三岔路口。迎面吹来一阵咸咸的气味，看来离海
边不远了。东南面是好象隐约可以听到波涛声，往南就是有不小
一座庄院，往北是一条泥泞的小路。
LONG
	);
	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"bank1",
  "southeast" : __DIR__"zhuque2",
  "south" : __DIR__"zhuque1",
  "north" : "/d/zuojiacun/lu19",
]));

	setup();
	replace_program(ROOM);
}
