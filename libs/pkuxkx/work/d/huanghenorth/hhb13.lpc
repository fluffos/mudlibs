//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/menggu/entry_migong.h",


void create()
{
        set("short", YEL"黄河北岸"NOR);
        set("long", @LONG
这里是黄河北岸，滚滚黄河一刻不停地奔腾东去。
LONG
        );
        set("exits", ([
             "southeast" : __DIR__"hhb12",
             "west" : __DIR__"hhb14",
             "northwest" : __DIR__"hhb",
        ]));
       

        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );
        set("entry_direction","northwest");
        set("migong","/d/menggu/shamo1");
        set("look_refuse_msg","沙漠里起了沙尘暴，你什么都看不清了。\n");
        set("enter_refuse_msg","沙漠里此时正刮起了沙尘暴，这会儿进去太危险了。\n");
        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}




