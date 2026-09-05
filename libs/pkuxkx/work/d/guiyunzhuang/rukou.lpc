#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIC"迷魂阵入口"NOR);
	set("long","这里是迷魂阵的入口,一位神灵在此看守.\n");
	set("exits",(["west":__DIR__"bridge1",]));
	set("objects",([__DIR__"npc/shenling":1,]));
	setup();
	replace_program(ROOM);
}
