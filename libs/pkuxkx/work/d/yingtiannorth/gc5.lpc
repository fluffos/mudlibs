//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"中央广场"NOR);
        set("long", 
"这里是建康府的中央广场，人来人往，热闹非常。\n"

        );
        set("exits", ([
                
                "west" : __DIR__"gc4",
                "east" : __DIR__"gc6",
                "south" : __DIR__"gc8",
                "north" : __DIR__"gc2",
                
                
        ]));
        set("objects", ([
                __DIR__"npc/xiaofan" : 1,
				__DIR__"npc/kid" : 1,
				__DIR__"npc/tourist" : 2,
        ]));
        set("no_reset",1);
        set("no_clean_up",1);
        
        set("outdoors", "yingtianfu");
        setup();
   
}

