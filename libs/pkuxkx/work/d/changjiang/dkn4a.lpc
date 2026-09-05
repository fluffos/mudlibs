//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "陵矶");
        set("long", @LONG
这里是长江南岸的渡口。南面就是江汉通黔贵的要冲——岳阳。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkn4",
             "east" : __DIR__"cjn21",
        ]));
       

        set("boatvalue",120);
        set("pin","4a");

        set("objects", ([
        "/d/changjiang/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan4a"); //船
        set("waittime",5); //等船时间
        set("arrivetime",8); //船行时间
        set("passtime",5);//放板时间
        set("destination","/d/changjiangnorth/dkb4a"); //目的地
        set("ticket","4a");
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"