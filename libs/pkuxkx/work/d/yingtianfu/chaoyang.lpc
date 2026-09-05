//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", YEL"朝阳门"NOR);
        set("long", 
"这里是应天府的正东面的朝阳门。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"citywall7",
                "south" : __DIR__"citywall6",
                "east" : __DIR__"tulue1",
                "west" : __DIR__"neicheng/donganmen",
                
        ]));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
        set("dirty",5+random(5));
		set("inbound","west");
        set("outdoors", "yingtianfu");
        setup();
   
}
