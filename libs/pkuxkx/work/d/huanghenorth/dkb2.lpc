//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"风陵渡"NOR);
        set("long", @LONG
这里是黄河北岸的渡口，东北通向晋阳。渡过黄河就是洛阳了。
LONG
        );
        set("exits", ([
             "south" : __DIR__"hhb5",
             "northwest" : __DIR__"hhb6",
             "north" : "/d/jinyang/guandaow3",
        ]));
       

        set("boatvalue",150);
        set("pin","2");

        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

       //渡船属性
        set("boat","/d/huanghenorth/duchuan2"); //船
        set("waittime",5); //等船时间
        set("arrivetime",6); //船行时间
        set("destination","/d/huanghe/dkn2"); //目的地
        set("ticket","2"); //船票编号
		set("npc_forbidden_dirs",({"north"}));
        setup();
}

#include "hh-pass.h"