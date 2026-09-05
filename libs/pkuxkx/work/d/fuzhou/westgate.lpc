
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "西门");
        set("long", "这里是福州的西门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "west" : __DIR__"xiaolu1",
               // "northeast" : __DIR__"citywall1",
               // "southwest" : __DIR__"citywall2",
                "east" : __DIR__"weststreet",
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "fuzhou");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n福州知府谕\n";
}

