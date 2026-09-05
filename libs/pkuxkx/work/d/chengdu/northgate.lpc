
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "北门");
        set("long", "这里是成都的北门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               
               "south" : __DIR__"northstreet1",
               "north" : __DIR__"guandaon1",
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "chengdu");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n四川总督谕\n";
}

