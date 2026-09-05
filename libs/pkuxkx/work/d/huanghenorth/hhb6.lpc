//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河北岸"NOR);
        set("long", @LONG
这里是黄河北岸，滚滚黄河一刻不停地奔腾东去。
LONG
        );
        set("exits", ([
             "southeast" : __DIR__"dkb2",
             "northwest" : __DIR__"hhb7",
        ]));
       

        set("couldfish",1);

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}




