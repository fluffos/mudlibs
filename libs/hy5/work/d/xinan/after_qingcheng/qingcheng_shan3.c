//written by lnwm on 97/07/08
//qingcheng_shan3.c

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short","青城山侧麓");
    set("long",@LONG
你行走在青城山的侧麓，这里山高林密，树木参天，往东你就能回到富饶的
四川盆地，而向西北则是重重迭迭的山峦和繁密的树林。这些山峦将一直向西延
伸至青藏高原。
LONG);
    set("exits",([
        "east"   	:		__DIR__ "qingcheng_shan2",
		"west"		:		__DIR__ "shan1",
    ]));
    set("objects",([
         __DIR__"npc/caiyao" : 1
    ]));
	setup();
}

int welcome_visitor( object ob )
{
		tell_object(ob,HIM"\n采药人看了你一眼，指着前面说：\n"NOR);
	tell_object(ob,HIM"前面有强人出没，客官听我一句话，赶紧回头别往前走了！\n\n"NOR);
	return 1;
}

