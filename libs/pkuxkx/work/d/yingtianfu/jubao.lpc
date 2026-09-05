//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", "聚宝门");
        set("long", 
"这里是应天府的正南面的聚宝门。\n"

        );
        set("exits", ([
                
                "west" : __DIR__"citywall27",
                "east" : __DIR__"citywall28",
                "south" : __DIR__"guandaos1",
                "north" : __DIR__"neicheng/zhenhuaiqiao",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","north");
        set("outdoors", "yingtianfu");
        setup();
   
}

