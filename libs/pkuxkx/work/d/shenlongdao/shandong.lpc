
#include <room.h>
inherit ROOM;

void create()
{
        set("short","山洞");
        set("long",@LONG 
洞外是那一片春光明媚的山谷，而洞内却黑乎乎的，似乎还很潮湿，有
一种奇怪的气味传过来，借着从洞口传来的微弱的光芒，你似乎看到这个洞
还没有走到尽头。
LONG
        );

        set("exits", ([
                "out" : __DIR__"shengu",
                "enter" : __DIR__"shandong2",                     
        ]));
		set("no_newbie_task",1);
        setup();

}

