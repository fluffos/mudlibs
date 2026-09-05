//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河古渡"NOR);
        set("long", @LONG
这里是黄河北岸的渡口，渡过河去通向灵州。
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"hhb16",
             "southwest" : __DIR__"hhb17",
             "northwest" : "/d/mingjiao/shamobian",
        ]));
       

        set("boatvalue",90);
        set("pin","3");

        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");
       //渡船属性
        set("boat","/d/huanghenorth/duchuan3"); //船
        set("waittime",5); //等船时间
        set("arrivetime",7); //船行时间
        set("destination","/d/huanghe/dkn3"); //目的地
        set("ticket","3"); //船票编号
		set("npc_forbidden_dirs",({"northwest"}));
        setup();
}

#include "hh-pass.h"