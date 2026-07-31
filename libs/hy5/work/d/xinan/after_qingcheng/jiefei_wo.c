//written by lnwm on 97/07/08
//jiefei_wo.c

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short","劫匪窝");
    set("long",@LONG
这里是青城山劫匪的老窝。
LONG);
    set("exits",([
//      "east"   	:		__DIR__ "shan1",
//		"west"		:		__DIR__ "shan2",
    ]));
    setup();
}

