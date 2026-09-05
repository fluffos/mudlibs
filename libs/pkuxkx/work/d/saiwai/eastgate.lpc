//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "东门");
        set("long", 
"这里是张家口的东门，几个士兵正在盘查过往的百姓。\n"

        );
        
        set("exits", ([
                //"west" : __DIR__"eastavenue1",
                "west" : __DIR__"eaststreet",
                //"southwest" : __DIR__"citywall2",
                "east" : __DIR__"guandaoe1",
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "saiwai");
        setup();
   
}


