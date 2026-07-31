// Room: /d/gaibang/undersl.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "屋角边");
	set("long", @LONG
这是老乔家厨房大木柴堆下面。里面破破烂烂的，丢满了各种杂物，
还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。这里还立
着几个木人，已经颇为陈旧，看样子象是从少林寺里面偷出来的，地上丢
着几个鸡腿和牛皮酒袋，也不知道是谁扔在这里的。
LONG );
	set("exits", ([
		"up"        : "/d/shaolin/chufang2",
		"southwest" : __DIR__"slandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/he-bj" : 1,
		"/clone/npc/mu-ren" : 4,
		"/d/city/obj/jitui" : 3,
		"/d/city/obj/jiudai" : 2,
	]));
	setup();
	replace_program(ROOM);
}

