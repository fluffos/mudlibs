// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "北城门");
        set("long", "这里是曲阜的北门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "north" : __DIR__"guandaon",
               "south" : __DIR__"northstreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "qufu");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n曲阜知县谕\n";
}

