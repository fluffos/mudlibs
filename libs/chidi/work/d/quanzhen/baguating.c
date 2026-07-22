// baguating.c 八卦亭

#include <room.h>

inherit ROOM;
void close_mark();

void create()
{
        set("short", "八卦亭");
        set("long", @LONG
这里是八卦亭，亭基四方形，亭身呈圆形，象征天圆地方。亭为双亭
重檐翘角，亭顶盖有黄色琉璃瓦，亭身由八根镌刻条龙的石柱支撑。其中
一根柱上的一条龙有拳印(mark)般的缺陷。
LONG
        );
       
        set("exits", ([
                "southeast" : __DIR__"yunjiyuan",
        ]));

        set("item_desc", ([
                "mark" :"你似乎可以将内力从掌印输入（ｔｏｕｃｈ）。\n" ,
        ]));

        setup();
}

void init()
{
         add_action("do_touch", "touch");
}


void close_mark()
{
        object room;

        if(!( room = find_object(__DIR__"zhujianshi")) )
                room = load_object(__DIR__"zhujianshi");
        if(objectp(room))
        {
                delete("exits/down");
                message("vision","只听-咕-噜-咕-噜-地几声，入口已经消失，一切都恢复了原样。\n",this_object());
                message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,
                         this_object());
                
        }
}

int do_touch(string arg)
{       
        object me = this_player();
        object room;
//        object ob;

        if (query("exits/down"))
                return notify_fail("暗道已经是开着了。\n");
        if (!arg || arg != "mark" )
                return notify_fail("你要开什么？\n");
        if ((int)me->query("neili") < 500 ) 
              return notify_fail("你的内力不够？\n");
        if(!( room = find_object(__DIR__"zhujianshi")) )
                room = load_object(__DIR__"zhujianshi");
        if (objectp(room))
        {

                set("exits/down", __DIR__"zhujianshi");
                message_vision("只听到--咕--噜--咕噜--地几声，整座亭子慢慢的向右\n"+
                        "移动，在你的眼前露出了一条暗道。\n", this_player());
                remove_call_out("close_mark");
                call_out("close_mark", 10);
        }

        return 1;
}


