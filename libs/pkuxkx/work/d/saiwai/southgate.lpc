//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南门");
        set("long", 
"这里张家口的南门，通向中原的必经之路。\n"

        );
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
                //"west" : __DIR__"eastavenue1",
                "north" : __DIR__"southstreet",
                //"southwest" : __DIR__"citywall2",
                "south" : __DIR__"guandaos1",
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "saiwai");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n宣大总督谕\n";
}

