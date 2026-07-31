//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
地道里一片漆黑，呼呼的风声从四面八方传来。你什么也看不见，只
能在地道里瞎摸乱撞。北面似乎隐隐约约有人说话，但只一会儿又没声了
。你使劲地摇了摇头，很怀疑这到底是不是幻觉。好象你已经迷路了。
LONG
);
	set("exits", ([
		"north" : __DIR__"andao10",
		"south" : __DIR__"andao8",
		"east" : __DIR__"andao10",
		"west" : __DIR__"andao10",
	]));

	setup();
	replace_program(ROOM);
}

