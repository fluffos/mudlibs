//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "扬子津");
        set("long", @LONG
这里是长江北岸的渡口，长江又称扬子江。这里因而得名扬子津。北面不远
就是扬州了。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjb4",
             "east" : __DIR__"dkb1a",
             "northdown" : "/d/city/guandaos2",
             "up" : __DIR__"tingzi",
        ]));
       
        set("free",1);//免费渡口

        set("no_clean_up", 0);
        set("outdoors", "changjiang");
//渡船属性
        set("boat","/d/changjiangnorth/duchuan1"); //船
        set("waittime",20); //等船时间
        set("arrivetime",12); //船行时间
        set("passtime",20);//放板时间
        set("destination","/d/changjiang/dkn1"); //目的地
        set("npc_forbidden_dirs",({"northdown"}));
        setup();
}

#include "cj-pass.h"