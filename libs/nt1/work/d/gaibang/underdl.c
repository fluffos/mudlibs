// Room: /d/gaibang/underdl.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大和街边");
	set("long", @LONG
这是大理城中大和街边上的大树洞。里面破破烂烂的，丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。令人
惊讶的是这里居然摆了几个木人，不过上面到处是油腻腻的手印，地上还
零零碎碎的扔着一些鸡腿骨头。
LONG );
	set("exits", ([
		"out"       : "/d/dali/dahejieeast",
		"northeast" : __DIR__"dlandao2",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 4,
		"/d/city/obj/bone"  : 2,
	]));
	setup();
	replace_program(ROOM);
}

