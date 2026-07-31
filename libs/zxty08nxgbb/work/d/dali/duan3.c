// Room: /d/dali/duan3.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分2秒。

inherit ROOM;

void create()
{
	set("short", "镇南王府大厅");
	set("long", @LONG
走过长长的白玉阶，来到王府大厅。只见正中一块牌匾，写着
「邦国柱石」四个大字，下首署着「丁卯御笔」四个小字。楹柱中
堂挂满了字画，一时也看不了许多。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"duan4",
  "westdown" : __DIR__"duan2",
]));

        set("objects", ([
        __DIR__"npc/yahuan" : 1,
        __DIR__"npc/jiading" : 1,
]));

	setup();
}

