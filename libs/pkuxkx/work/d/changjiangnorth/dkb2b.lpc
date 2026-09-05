//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江北岸的渡口，扼守建康府的门户。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkb2",
             "east" : __DIR__"cjb7",
        ]));
       

        set("boatvalue",80);
        set("pin","2b");

        set("objects", ([
        "/d/changjiang/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiangnorth/duchuan2b"); //船
        set("waittime",5); //等船时间
        set("arrivetime",10); //船行时间
        set("passtime",5);//放板时间
        set("destination","/d/changjiang/dkn2b"); //目的地
        set("ticket","2b");
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"