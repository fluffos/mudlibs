//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "文渊阁");
        set("long", 
"这里是内阁办公的所在，闲杂人等，不得进入。\n"

        );
        set("exits", ([
                
              
                
                "out" : __DIR__"wenhua",
                "west" : __DIR__"wenyuan_w",
                "east" : __DIR__"wenyuan_e",
                
                
                
        ]));
        set("objects", ([
		__DIR__"npc/xueshi4" : 1,
        __DIR__"npc/xueshi3" : 1,
	    ]));  
        setup();
   
}

