// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "北门");
        set("long", "这里是岳阳城的北门，城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               "north" : "/d/changjiang/cjn20",
               "south" : __DIR__"northstreet",
               //"north" : "/d/jiangzhou/guandaos4",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "yueyang");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n岳阳知府谕\n";
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}