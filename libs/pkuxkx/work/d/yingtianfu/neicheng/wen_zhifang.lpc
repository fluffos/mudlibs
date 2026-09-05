//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "值房");
        set("long", 
"这里大明低级文官的值房，很多人共用一间，可以午睡(sleep)。\n"

        );
        set("exits", ([
                
              
                
                
                  "west" : __DIR__"hongwumen",
          
                
                
        ]));
        set("no_yizhang",1);
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
    if (!me->query("mingpin"))
    {
        tell_object(me,"你不是大明的官员，快出去！\n");
        me->move(__DIR__"hongwumen");
        return 1;
    }
    
    if (!me->query("ming/title"))
    {
        tell_object(me,"这里竟没有你的位置，你去找找吏部侍郎问问吧！\n");
        me->move(__DIR__"hongwumen");
        return 1;
    }
    else
    {
        if (me->query("ming/pro")=="文")
        {
            ob->set("short",me->query("ming/title")+"值房");
            ob->set("long","这里是"+me->query("ming/title")+"的值房，你也可以在这里小憩一会。\n");
            tell_object(me,ob->query("short")+" -\n");
            tell_object(me,"    "+ob->query("long"));
            tell_object(me,"    这里唯一的出口是  west。\n");
            return 1;
        }
        
    }
}