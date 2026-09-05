// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南门");
        set("long", @LONG
这里是义兴县的南门，城墙上贴着几张官府告示(gaoshi)。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "southeast" : "/d/suzhou/guandaonb",
                "north" : __DIR__"yx",
]));
     set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
    set("objects", ([
        "/d/city/npc/bing" : 1,
        ]));    
   setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n"+HIW+"义兴县尊手令\n"+NOR;
}