// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "北门");
        set("long", @LONG
这里是义兴县的北门，城墙上贴着几张官府告示(gaoshi)。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "south" : __DIR__"yx",
                "north" : __DIR__"shanlu",
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