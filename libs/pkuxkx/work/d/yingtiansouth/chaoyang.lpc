//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", YEL"朝阳门"NOR);
        set("long", 
"这里是建康府的正东面的朝阳门。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"citywall",
                "south" : __DIR__"citywall",
                "east" : __DIR__"tulue1",
                "west" : __DIR__"dufu/dongmen",
				"northwest" : __DIR__"xiaoxiang1",
                
        ]));
        set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
        set("dirty",5+random(5));
		set("inbound","west");
        set("outdoors", "yingtianfu");
        setup();
   
}
