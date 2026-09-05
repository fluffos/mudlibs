//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", WHT"通济门"NOR);
        set("long", 
"这里是建康府的东南面的通济门，出城不远就是无想山。\n"

        );
        set("exits", ([
                
                "south" : __DIR__"citywall",
                "east" : __DIR__"citywall",
                "west" : __DIR__"huaiqingqiao",
				"southeast" : __DIR__"wuxiangn2",
                
        ]));
        set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
        set("dirty",5+random(5));
		set("inbound","west");
		set("mj_inbound",1);
        set("outdoors", "yingtianfu");
        setup();
   
}

