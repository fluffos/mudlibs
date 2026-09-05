// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南昌东门");
        set("long", "这里是南昌城的东门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "east" : __DIR__"guandaoe1",
               "west" : __DIR__"eaststreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        set("objects", ([
		"/d/nanchang/npc/wujiang1": 1,
        "/d/nanchang/npc/bing" : 2,
        "/d/nanchang/npc/xiaofan" : 1,
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
	if (dir=="west")
    {
        if (me->query("sinan")=="yes")
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
    if (dir=="east" && present("qing zhuan",me))
    {
        return notify_fail("你要把老白的青砖搬哪去？\n");
    }
	return ::valid_leave(me, dir);
}
