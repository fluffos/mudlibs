// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "东城门");
        set("long", "这里是曲阜的东门。城墙上贴着告示(gaoshi)。东北通向石门山。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               //"north" : "/d/changjiang/cjn20",
               "west" : __DIR__"southstreet2",
               "northeast" : __DIR__"guandaoe",
               
                
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
