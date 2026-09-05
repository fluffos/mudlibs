// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南门");
        set("long", "这里是江州的南门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               //"northeast" : __DIR__"xunyanglou",
               "south" : __DIR__"guandaos1",
               "north" : __DIR__"streetd",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "jiangzhou");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n江州知府谕\n";
}

