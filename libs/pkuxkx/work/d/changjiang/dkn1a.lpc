//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江南岸的渡口，扼守镇江门户。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkn1",
             "east" : __DIR__"cjn3",
        ]));
       
        set("boatvalue",180);
        set("pin","1a");
        

        set("objects", ([
        "/d/changjiang/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan1a"); //船
        set("waittime",5); //等船时间
        set("arrivetime",10); //船行时间
        set("passtime",6);//放板时间
        set("destination","/d/changjiangnorth/dkb1a"); //目的地
        set("ticket","1a");
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"