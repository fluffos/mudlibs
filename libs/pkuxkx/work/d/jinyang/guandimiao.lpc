//关帝庙 /d/jinyang/guandimiao
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"庙前广场"NOR);
        set("long", 
"里面就是供奉着武圣关公的庙宇，平时香火很旺。\n"

        );
        set("exits", ([
                "north" : __DIR__"eastavenue1",
                "south" : __DIR__"guangchang",
                "enter" : __DIR__"wumiao",
                
        ]));
        
        set("objects", ([
		__DIR__"npc/miaozhu" : 2+random(3),
		__DIR__"npc/xunbu" : 1,
	    ]));
        setup();
   
}


