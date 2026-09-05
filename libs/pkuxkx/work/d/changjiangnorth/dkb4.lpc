//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江北岸的渡口。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjb22",
             "east" : __DIR__"dkb4a",
        ]));
       
         set("free",1);//免费渡口

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiangnorth/duchuan4"); //船
        set("waittime",11); //等船时间
        set("arrivetime",12); //船行时间
        set("passtime",11);//放板时间
        set("destination","/d/changjiang/dkn4"); //目的地
        set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"