//大境门 /d/jinyang/dajingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "西门");
        set("long", 
"这里张家口的西门，西南面是一座雄关。\n"

        );
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
                //"west" : __DIR__"eastavenue1",
                "east" : __DIR__"weststreet",
                //"southwest" : __DIR__"citywall2",
                "west" : __DIR__"guandaow1",
                
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

