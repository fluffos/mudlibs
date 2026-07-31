// Room: /open/dt/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家专卖一些零碎用品的小店铺，因为对面就是悦来客
栈，所以这里的毛巾、梳子、针线之类的日常用品非常好卖，但
这里也卖金创药、蛇药一类的江湖人常用的物品，所以这店铺虽
小，但生意却着实红火。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"hongchanglu3",
]));

	set("objects",([
	__DIR__"npc/zahuoboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
