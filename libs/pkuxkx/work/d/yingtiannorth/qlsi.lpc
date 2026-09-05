//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", GRN"清凉寺"NOR);
        set("long", 
"这里清凉寺，庙里有个老方丈帮人算命。\n"

        );
        set("exits", ([
                
              
                "out" : __DIR__"qls",
				"north" : __DIR__"qlsi2",
                
        ]));
        
        set("objects", ([
                __DIR__"npc/monk" : 1,
        ]));
        setup();
   
}

int valid_leave(object me,string dir)
{
	if (dir=="north")
	return notify_fail("清凉寺后山，闲人止步。\n");
	return ::valid_leave(me,dir);
}