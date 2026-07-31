// Room: /d/dali/duan1.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时28分57秒。

inherit ROOM;

void create()
{
	set("short", "大理街道");
	set("long", @LONG
眼前是一条笔直的大街，街上青石平铺，极为宽敞。前面是一座
大府第，府门前两面大旗，旗上分别绣的是「镇南」、「保国」两字，
府额上写的是「镇南王府」。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xbdajie1",
  "east" : __DIR__"duan2",
]));

	setup();
}

