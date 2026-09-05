// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "西门");
        set("long", "这里是江州的西门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "northeast" : __DIR__"street4",
               // "northeast" : __DIR__"citywall1",
               "west" : __DIR__"guandaow1",
               
                
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

