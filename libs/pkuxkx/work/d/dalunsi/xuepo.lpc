// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "雪坡");
        set("long", @LONG
这里是一片雪地，厚厚的积雪足以没膝，可见山上终年如此。
旁边似乎有一个洞(dong)，经常有人走来走去的样子。
LONG 
        );

        set("exits", ([

                "southwest" : __DIR__"houzidong",


        ]));
        set("objects", ([

        ]));
        set("outdoors", "dalunsi");
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
        me = this_player();

        if( !arg || arg=="" ) return notify_fail("你要钻什么？\n");

        if(me->is_busy() || me->is_fighting())
                return notify_fail("你先忙完了再钻洞吧。");

        if( arg=="dong" )
        {
                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("/d/gaibang/underxs");
                message("vision",
                        me->name() + "从洞外走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}
