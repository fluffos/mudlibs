//kaiyuanmen /d/jinyang/kaiyuanmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "开远门");
        set("long", 
"这里是晋阳的南门，开远门。城墙上贴着告示(gaoshi)。\n"

        );
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	    ]));
        set("exits", ([
                "north" : __DIR__"southstreet1",
                "east" : __DIR__"citywall10",
                "west" : __DIR__"citywall12"
                //"north" :
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "jinyang");
        setup();
   
}


string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n晋阳知府谕\n";
}
int valid_leave(object me,string dir)
{  
    if (dir=="north" && me->query_condition("killer"))
    {
        return notify_fail("你已被全城通缉，快去避避风头！\n");
    }
	return ::valid_leave(me, dir);
}