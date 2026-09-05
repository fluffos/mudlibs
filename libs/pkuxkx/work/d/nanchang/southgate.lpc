// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南昌南门");
        set("long", "这里是南昌城的南门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               //"northeast" : __DIR__"xunyanglou",
               "north" : __DIR__"southstreet",
               "south" : __DIR__"guandaos1",
               
                
        ]));
        set("objects", ([
		"/d/nanchang/npc/wujiang1" : 1,
        "/d/nanchang/npc/bing" : 2,
        ]));
        set("outdoors", "nanchang");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n南昌知府谕\n";
}

int valid_leave(object me,string dir)
{  
	if (dir=="south" && present("qing zhuan",me))
    {
        return notify_fail("你要把老白的青砖搬哪去？\n");
    }
	return ::valid_leave(me, dir);
}
