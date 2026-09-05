//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIW"太平门"NOR);
        set("long", 
"这里是建康府的北面的太平门。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"citywall",
                "west" : __DIR__"citywall",
                "southwest" : "/d/yingtiannorth/zongxingqiao",
				"southeast" : __DIR__"xiaoxiang1",
                
        ]));
        set("dirty",5+random(5));
        set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","southeast");
        set("outdoors", "yingtianfu");
        setup();
   
}

