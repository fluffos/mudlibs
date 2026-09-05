//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"孟津渡"NOR);
        set("long", @LONG
这里是黄河南岸的渡口，南面通向洛阳。渡过河就进入晋阳了。
LONG
        );
        set("exits", ([
             "east" : __DIR__"hhn4",
             "west" : __DIR__"hhn5",
             "southdown" : "/d/luoyang/luoshui",
        ]));
       

        set("boatvalue",150);
        set("pin","2");

        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");
        //渡船属性
        set("boat","/d/huanghe/duchuan2"); //船
        set("waittime",5); //等船时间
        set("arrivetime",6); //船行时间
        set("destination","/d/huanghenorth/dkb2"); //目的地
        set("ticket","2"); //船票编号
		set("npc_forbidden_dirs",({"southdown"}));
        setup();
}

#include "hh-pass.h"