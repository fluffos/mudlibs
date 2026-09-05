//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河渡口"NOR);
        set("long", @LONG
这里是黄河北岸的渡口，往北通向北京。渡过河去就是山东地界了。
LONG
        );
        set("exits", ([
             "east" : __DIR__"hhb2",
             "west" : __DIR__"hhb3",
        ]));
       

        set("boatvalue",120);
        set("pin","1");

        set("objects", ([
                "/d/huanghe/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");
        //渡船属性
        set("boat","/d/huanghenorth/duchuan1"); //船
        set("waittime",5); //等船时间
        set("arrivetime",4); //船行时间
        set("destination","/d/huanghe/dkn1"); //目的地
        set("ticket","1"); //船票编号
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "hh-pass.h"