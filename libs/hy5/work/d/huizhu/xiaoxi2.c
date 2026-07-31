// Room: /d/huizhu/xiaoxi2.c

inherit ROOM;

void create()
{
	set("short", "湖泊");
	set("long", @LONG
转了几个弯，从一排参天青松中穿了出去,眼前一片大湖，湖的南端
又是一条大瀑布,水花四溅,日光映照,现出一条彩虹,湖周花树参差，杂花
红白相间，倒映在碧绿的湖水之中，奇丽莫名。远处是大片青草平原无边
无际,的延伸出去，与天相接，草地上几百只白羊在奔跑吃草
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiangxiang.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaoxi1",
  "north" : __DIR__"byriver",
]));

	setup();
	replace_program(ROOM);
}
