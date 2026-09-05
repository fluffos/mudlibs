// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "西门");
        set("long", "这里是岳阳城的西门，城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "west" : __DIR__"yueyanglou",
               "east" : __DIR__"weststreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "yueyang");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n岳阳知府谕\n";
}

