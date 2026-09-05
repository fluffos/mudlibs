//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西津渡口");
        set("long", @LONG
这里是长江南岸的渡口，扼守镇江门户。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjn4",
             "east" : __DIR__"dkn1a",
             "southeast" : "d/zhenjiang/tuluw2",
        ]));
       

        

        set("free",1);//免费渡口

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiang/duchuan1"); //船
        set("waittime",20); //等船时间
        set("arrivetime",12); //船行时间
        set("passtime",20);//放板时间
        set("destination","/d/changjiangnorth/dkb1"); //目的地
        set("npc_forbidden_dirs",({"southeast"}));
        setup();
}

#include "cj-pass.h"
