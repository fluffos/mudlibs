// Room: /d/yanjing/xiangxue.c

inherit ROOM;

void create()
{
	set("short", "香雪厅");
	set("long", @LONG
香雪厅内灯烛辉煌，摆着一桌筵席.大金国六皇子完颜洪烈正陪着
几人饮酒.桌旁放着一张太师椅,垫了一张厚厚的毡毯,上面坐了个和尚
看来脸色不大好,旁边几个青衣小童伺候着.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wangye.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhongyuan",
]));

	setup();
	replace_program(ROOM);
}
