//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "值房");
        set("long", 
"这里内廷各监司的值房，也各监司主官和次官办公之处。\n"

        );
        set("exits", ([
                
              
                
                
                  "out" : __DIR__"zhifang",
            //    "east" : __DIR__"yudao3",
            //    "west" : __DIR__"baihu2",
                
                
                
        ]));
        set("real_dark",1);
        set("sleep_room", "1");
	    set("no_fight", "1");
        setup();
   
}

void init()
{
    add_action("do_look",({ "look","l" }));
}

int do_look()
{
    object ob=this_object();
    object me=this_player();
    if (!me->query("ming/tj/office"))
    {
        tell_object(me,"你不是各监司的主官和次官，快出去！\n");
        me->move(__DIR__"zhifang");
        return 1;
    }
    else
    {
        ob->set("short",me->query("ming/tj/office"));
        ob->set("long","这里是"+me->query("ming/tj/office")+"，你也可以在这里小憩一会。\n");
        tell_object(me,ob->query("short")+" -\n");
        tell_object(me,"    "+ob->query("long"));
        tell_object(me,"    这里唯一的出口是  out。\n");
        return 1;
    }
}