//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "北市");
        set("long", 
"这里是张家口的北市，北面是长城上著名的关隘大境门，西面是一家食肆，\n东面的空巷确是一片狼藉。\n"

        );
        
        set("exits", ([
                "west" : __DIR__"jiujia",
                "north" : __DIR__"dajingmen",
                "east" : __DIR__"houxiang",
                "south" : __DIR__"guangchang",
                
        ]));
        /*set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));*/
        set("outdoors", "saiwai");
        setup();
   
}


