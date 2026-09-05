// room: /d/xingxiu/tianroad4.c
// Jay 3/18/96
#include <ansi.h>
inherit ROOM;
#include "/d/xingxiu/flower.h"
void init();
int do_jump(string arg);

void create()
{
        set("short", WHT"山坡"NOR);
        set("long", @LONG
这里是一处山坡，气温极低，覆盖了一层薄薄的初雪。一个采药人正在
采药。东面一条深涧(valley)挡住你的去路，放眼对岸，确实一片黄土地。
相隔不到百丈，深涧分开，却像是两个世界。
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad5"
]));
        set("objects", ([
                __DIR__"npc/caiyaoren"  : 1,
                __DIR__"npc/obj/xuelian" : 1,
                flower:random(2) ,
        ]));

       set("item_desc", ([
        "valley" : "深涧有三丈多宽，不过因为这边地势高，应该不难跳(jump)过去。\n"
        ]) );


        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="valley" ) {
               message("vision", me->name() + 
                          "一提气，双足点地跳过了深涧。\n",
               environment(me), ({me}) );
               me->move("/d/xingxiu/tianroad3");
               message("vision", me->name() + 
                          "从深涧上面跳了下来。\n",
               environment(me), ({me}) );
               return 1;
       }
}
