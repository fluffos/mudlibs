//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南市");
        set("long", 
"这里是张家口的南市，东西两面都是一家客栈的产业，北面是一座小广场。\n"

        );
        
        set("exits", ([
                "west" : __DIR__"kedian_w",
                "north" : __DIR__"guangchang",
                "east" : __DIR__"kedian_e",
                "south" : __DIR__"southgate",
                
        ]));
        /*set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));*/
        set("outdoors", "saiwai");
        setup();
   
}


