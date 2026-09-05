//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "ConnCWall.h"
void create()
{
        set("short", "淮清桥");
        set("long", 
"这里是淮清桥，连接着通济门和城内。北面是建康府最高长官的府邸。\n"

        );
        set("exits", ([
                
              
                "west" : __DIR__"shengfu",
                "east" : __DIR__"tongji",
                "south" : __DIR__"citywall",
				"north" : __DIR__"dufu/damen"
                
        ]));
        
        set("outdoors", "yingtianfu");
        setup();
   
}

