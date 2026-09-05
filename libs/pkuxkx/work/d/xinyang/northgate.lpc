// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "北门");
        set("long", "这里是信阳城的北门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               //"west" : __DIR__"yueyanglou",
               "south" : __DIR__"northstreet",
               "north" : __DIR__"guandaon1",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 1,
        ]));
        set("outdoors", "xiangyangnan");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n信阳总兵令\n";
}

