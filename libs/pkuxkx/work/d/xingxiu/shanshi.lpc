// Room: /d/xingxiu/shanshi.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山石");
        set("long", @LONG
这里是星宿海海边一处山石。东面是方圆几百里都是一望无际的
湖泊和沼泽。因为阴冷潮湿，此处毒虫繁殖甚富。星宿派弟子常来此
捕捉毒虫，以备练毒之用。南边有个黑黢黢的山洞(cave)。
LONG
        );
        set("objects", ([
                __DIR__"npc/haoshou"  : 1,
        ]) );

        set("exits", ([
             "westdown" : __DIR__"xxh3",
        ]));

        set("item_desc", ([
              "cave" : "山洞里飘出一股股腥臭味，你还是快点离开吧。\n"
        ]) );

        set("outdoors", "xingxiuhai");
        setup();
}

void init()
{
    add_action("do_enter", "enter");
    add_action("do_enter", "zuan");   
}

int do_enter(string arg)
{
     object me;
     mapping myfam;
     me = this_player();
     myfam = (mapping)me->query("family");

        if( !arg || arg=="" ) return 0;

        if (arg == "cave" ){   
               if (!myfam || myfam["family_name"] != "星宿派")
                      return notify_fail("洞内一声低喝：不是星宿门人想进去挨揍？\n");
               if (me->query("combat_exp") < 1000000)
                      return notify_fail("你经验不够，进去找死啊！\n");
               message_vision("$N小心翼翼地往山洞里探了探。\n", me); 
               message("vision",me->name() + "一弯腰往山洞里钻了进去。\n", environment(me), ({me}) );
               me->move(__DIR__"cave1");
               message("vision",me->name() + "从外面钻了进来。\n", environment(me), ({me}) );
               return 1;
        }     
}

int valid_leave(object me, string dir)
{   
        return ::valid_leave(me, dir);
}

