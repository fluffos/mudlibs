//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河古渡"NOR);
        set("long", @LONG
这里是黄河南岸的渡口，东南面通向灵州。
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"hhn16",
             "southwest" : __DIR__"hhn17",
             "southeast" : "/d/lingzhou/tulusw",
        ]));
       

        
        set("boatvalue",90);
        set("pin","3");
        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");
//渡船属性
        set("boat","/d/huanghe/duchuan3"); //船
        set("waittime",5); //等船时间
        set("arrivetime",7); //船行时间
        set("destination","/d/huanghenorth/dkb3"); //目的地
        set("ticket","3"); //船票编号
		set("npc_forbidden_dirs",({"southeast"}));
        setup();
}

#include "hh-pass.h"