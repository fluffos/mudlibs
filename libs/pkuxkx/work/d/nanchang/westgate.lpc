// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南昌西门");
        set("long", "这里是南昌城的西门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "west" : __DIR__"guandaow1",
               "east" : __DIR__"weststreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
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
	if (dir=="west" && userp(me))
    {
        tell_object(me,HIR+"西面通向苗岭，林中瘴气漫溢，如果没有准备，当心送命！\n"+NOR+"南昌知府谕\n");   
    }
    if (dir=="west" && present("qing zhuan",me))
    {
        return notify_fail("你要把老白的青砖搬哪去？\n");
    }

	return ::valid_leave(me, dir);
}

