//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江南岸的渡口。
LONG
        );
        set("exits", ([
             "southeast" : __DIR__"cjn13",
             "northwest" : __DIR__"cjn14",
        ]));
       

        set("boatvalue",140);
        set("pin","3");

        set("objects", ([
        "/d/changjiang/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan3"); //船
        set("waittime",5); //等船时间
        set("arrivetime",8); //船行时间
        set("passtime",5);//放板时间
        set("destination","/d/changjiangnorth/dkb3"); //目的地
        set("ticket","3");
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"