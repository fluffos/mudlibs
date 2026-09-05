// Room: /city/datiepu.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "茶庄");
	set("long", @LONG
这是一家经营茶叶的店铺，淡淡的茶香充溢着整个屋子，茶庄的老板是一位
漂亮的姑娘，这使的扬州城的年青小伙有事没事就来这里转转。这的茶叶种类齐
全，就是价钱贵了点。
LONG);
	set("exits", ([
		"north" : __DIR__"ytjie3",
	]));
	set("objects", ([
		__DIR__"npc/zhongm": 1,
	]));
	setup();
	replace_program(ROOM);
}