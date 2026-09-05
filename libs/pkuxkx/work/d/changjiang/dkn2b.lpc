//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "燕子矶");
        set("long", @LONG
这里是长江南岸的渡口，南边就是重镇建康府了。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkn2",
             "east" : __DIR__"cjn7",
        ]));
       

        set("boatvalue",80);
        set("pin","2b");

       set("objects", ([
        "/d/changjiang/npc/shaogong" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan2b"); //船
        set("waittime",5); //等船时间
        set("arrivetime",10); //船行时间
        set("passtime",5);//放板时间
        set("destination","/d/changjiangnorth/dkb2b"); //目的地
        set("ticket","2b");
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"