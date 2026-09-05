//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河渡口"NOR);
        set("long", @LONG
这里是黄河南岸的渡口，往南通向曲阜。渡过黄河向北就是北京。
LONG
        );
        set("exits", ([
             "east" : __DIR__"hhn2",
             "west" : __DIR__"hhn3",
             "southeast" : "/d/qufu/guandaonw2",
        ]));
       

        
        set("boatvalue",120);
        set("pin","1");
        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");
        //渡船属性
        set("boat","/d/huanghe/duchuan1"); //船
        set("waittime",5); //等船时间
        set("arrivetime",4); //船行时间
        set("destination","/d/huanghenorth/dkb1"); //目的地
        set("ticket","1"); //船票编号
		set("npc_forbidden_dirs",({"southeast"}));
        setup();
}

#include "hh-pass.h"