//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河渡口"NOR);
        set("long", @LONG
这里是黄河北岸的渡口，西北通向兰州。
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"hhb18",
             "southwest" : __DIR__"hhb19",
        ]));
       

        set("boatvalue",80);
        set("pin","4");

        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");
       //渡船属性
        set("boat","/d/huanghenorth/duchuan4"); //船
        set("waittime",5); //等船时间
        set("arrivetime",7); //船行时间
        set("destination","/d/huanghe/dkn4"); //目的地
        set("ticket","4"); //船票编号
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "hh-pass.h"