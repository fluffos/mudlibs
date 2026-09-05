// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南昌北门");
        set("long", "这里是南昌城的北门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               //"northeast" : __DIR__"xunyanglou",
               "south" : __DIR__"northstreet",
               "north" : "/d/jiangzhou/guandaos4",
               
                
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
	object pl=this_player();
    if (present("qing zhuan",pl))
    {
        if (pl->query("max_neili")<1000)
        {
            return notify_fail("你的体力太弱，青砖压得你寸步难行。\n");
        }
        if (time() - pl->query_temp("ncjob/last_go_time") <= 5)
        {
            return notify_fail("你扛着青砖一步一步地向前挪动。\n");
        }
        else
        {
            pl->set_temp("ncjob/last_go_time",time());
        }
    }
	return ::valid_leave(me, dir);
}