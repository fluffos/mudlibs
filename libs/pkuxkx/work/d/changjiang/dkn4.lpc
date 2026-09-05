//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江南岸的渡口。南面就是江汉通黔贵的要冲——岳阳。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjn22",
             "east" : __DIR__"dkn4a",
        ]));
       

         set("free",1);//免费渡口

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan4"); //船
        set("waittime",11); //等船时间
        set("arrivetime",12); //船行时间
        set("passtime",11);//放板时间
        set("destination","/d/changjiangnorth/dkb4"); //目的地
        set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"