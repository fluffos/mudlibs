//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江渡口");
        set("long", @LONG
这里是长江南岸的渡口，南边就是重镇建康府了。
LONG
        );
        set("exits", ([
             "west" : __DIR__"dkn2a",
             "east" : __DIR__"dkn2b",
             "southwest" : "/d/yingtiannorth/tulun3",
        ]));
       

        
        set("free",1);//免费渡口

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan2"); //船
        set("waittime",15); //等船时间
        set("arrivetime",15); //船行时间
        set("passtime",16);//放板时间
        set("destination","/d/changjiangnorth/dkb2"); //目的地
        set("npc_forbidden_dirs",({"southwest"}));
        setup();
}

#include "cj-pass.h"