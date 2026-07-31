// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "聚朋茶馆");
	set("long", @LONG
几张方桌，几个方凳，茶馆的设施虽然简陋，却是一个大好去处，许多
人在这里谈天说地，你可以在这里打听到许多的奇闻佚事，所以城里城外的
人没事都会来这里座一座，抽上几口水烟，天南地北的聊聊。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"west" : __DIR__"nandajie2",
	]));

	set("objects", ([
		__DIR__"npc/chaxiaoer" : 1,
		__DIR__"npc/obj/yantong":1,
	]));

	setup();
	replace_program(ROOM);
}

