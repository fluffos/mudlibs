//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", WHT"通济门"NOR);
        set("long", 
"这里是应天府的东南面的通济门。\n"

        );
        set("exits", ([
                
                "south" : __DIR__"citywall30",
                "east" : __DIR__"citywall1",
                "west" : __DIR__"neicheng/huaiqingqiao",
                
        ]));
        set("objects", ([
		__DIR__"neicheng/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
        set("dirty",5+random(5));
		set("inbound","west");
		set("mj_inbound",1);
        set("outdoors", "yingtianfu");
        setup();
   
}

