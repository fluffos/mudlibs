//written by lnwm on 97/07/08
//qingcheng_shan2.c

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
        "east"   	:		__DIR__ "qingcheng_shan1",
		"west"		:		__DIR__ "qingcheng_shan3",
    ]));
    setup();
}


