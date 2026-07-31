// Room: /lanzhou/xiaochidian.c
// xws 1998/10/14 

inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
	你一走进来，就闻到一股浓浓的小吃香味，人站在门口就有一种想好好吃
一顿的感觉。几张八仙桌一字排开，坐满了客人，或高声谈笑，或交头接耳。你要
想打听江湖掌故和谣言，这里倒是个好所在。小二在桌子之间穿来穿去，忙得根本
就来及招呼你。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"beidajie2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

