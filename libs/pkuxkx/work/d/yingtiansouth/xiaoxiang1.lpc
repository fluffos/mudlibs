//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "qingxi.h"
void create()
{
        set("short", HIW"小巷"NOR);
        set("long", 
"这是一条连接建康府太平门到朝阳门的小巷。\n"

        );
        set("exits", ([
                
                //"east" : __DIR__"citywall",
                //"west" : __DIR__"citywall",
                "northwest" : __DIR__"taiping",
				"southeast" : __DIR__"chaoyang",
                
        ]));
        set("dirty",5+random(5));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));
		set("inbound","southeast");*/
        set("outdoors", "yingtianfu");
        setup();
   
}

