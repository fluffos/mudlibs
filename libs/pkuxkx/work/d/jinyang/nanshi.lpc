//南市 /d/jinyang/nanshi
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "南市");
        set("long", 
"这里是南市，整个晋阳城最繁华的所在。\n"

        );
        set("exits", ([
                //"west" : __DIR__"weststreet",
                //"east" : __DIR__"eaststreet1",
                "south" : __DIR__"mishi",
                "northeast" : __DIR__"yangshi",
                
        ]));
       
         set("objects", ([
		__DIR__"npc/liumang" : 1+random(2),
		"/d/city/npc/bookseller":1,
	    ]));
        set("outdoors", "jinyang");
        setup();
   
}


