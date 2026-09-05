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
             "west" : __DIR__"dkb2a",
             "east" : __DIR__"dkb2b",
             
        ]));
       
        set("free",1);//免费渡口

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiangnorth/duchuan2"); //船
        set("waittime",15); //等船时间
        set("arrivetime",15); //船行时间
        set("passtime",16);//放板时间
        set("destination","/d/changjiang/dkn2"); //目的地
        set("npc_forbidden_dirs",({}));
        setup();
}

#include "cj-pass.h"

