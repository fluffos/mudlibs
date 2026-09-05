//城门
// By Zine 23 Nov 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HBCYN+HIW+"存义街"+NOR);
        set("long", 
"这里是存义街，西面通往中城。一个中年人故作高人状的坐在地上。\n"

        );
        set("exits", ([
                
              
                
                "west" : __DIR__"zhongcheng",
                "east" : __DIR__"lrj",
                "south" : __DIR__"foodshop",
                "north" : __DIR__"zahuopu",
                
        ]));
         set("objects", ([
		__DIR__"npc/noname" : 1,
	    ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

