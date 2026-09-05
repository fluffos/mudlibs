//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "都察院");
        set("long", 
"这里大明都察院的衙门，里面是左、右都御使坐堂的地方。\n"

        );
        set("exits", ([
                
                "west" : __DIR__"datong1",
                "enter" : __DIR__"ducha2",
             
                
                
        ]));
        
        set("objects", ([
		__DIR__"npc/zuofu" : 1,
        __DIR__"npc/youfu" : 1,
        __DIR__"npc/daming_npcg" : 1,
	    ]));
        setup();
   
}

