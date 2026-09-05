// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "胭脂铺");
	set("long", @LONG
这是一家非常小的店铺，里面专门卖各种胭脂水粉和
化妆用的工具。
LONG);

	set("exits", ([
		"west" : __DIR__"westmarket-1",
	]));
	set("objects", ([
		__DIR__"npc/quyan": 1,
	]));

	setup();
  set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
	replace_program(ROOM);
}