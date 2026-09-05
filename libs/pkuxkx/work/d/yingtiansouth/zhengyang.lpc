//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIR"正阳门"NOR);
        set("long", 
"这里是建康府的东南面的正阳门。\n"

        );
        set("exits", ([
                
                "west" : __DIR__"citywall",
                "east" : __DIR__"citywall",
                "south" : __DIR__"guandaosa",
                "north" : __DIR__"junying",
                
        ]));
        set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
        set("dirty",5+random(5));
		set("inbound","north");
		set("mj_inbound",1);
		set("mingtask_inbound",1);
        set("outdoors", "yingtianfu");
        setup();
   
}
string GiveMyArea()
{
	return "建康府南城";
}
