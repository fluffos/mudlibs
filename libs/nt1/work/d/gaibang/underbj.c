// Room: /d/gaibang/underbj.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "街边狗洞");
	set("long", @LONG
这是北京城一条偏僻街边的狗洞里。四周丢满了各种杂物，还有丐帮
弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。这里居然还摆着几
个油腻腻的木人，不知道是打哪儿偷来的。
LONG );
	set("exits", ([
		"out"   : "/d/beijing/caroad_e1",
		"south" : __DIR__"bjandao2",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 3,
	]));
	setup();
	replace_program(ROOM);
}

