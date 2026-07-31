// Room: /d/xingxiu/silk3c.c
// Jay 3.17/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", WHT"月牙泉"NOR);
        set("long", @LONG
出乎你的意料之外，在沙漠中竟然有一汪月牙形的泉水，涟漪萦回，水草
丛生，清澈见底。这里出产铁背鱼、七星草，但不常见。此泉虽在流沙山群中，
风起沙飞，均绕泉而过，从不落入泉内。北面是一片峭壁(cliff) ，东边传来嗡
嗡的声响。
LONG
        );
        set("resource/water", 1);
       set("outdoors","yili");

        set("exits", ([
//                "west" : __DIR__"silk7a",
                "southeast" : __DIR__"silk3b",
        ]));

        set("item_desc", ([
                "cliff" : "峭壁上似乎有一个洞(hole)。\n"
        ]) );

        setup();
//        replace_program(ROOM);
}


void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
        object me;
        me = this_player();

        if(!arg || arg=="" ) return 0;
        if(arg=="hole"){
            if(me->query_temp("ride_horse"))
                        return notify_fail("骑着马你能进去吗？\n");

                        if(me->query_encumbrance() * 100 / me->query_max_encumbrance() < 20){
               message("vision",me->name()+"一纵身跃进了洞里。\n",environment(me), ({me}));
               me->move(__DIR__"mogaoku");
               message("vision",me->name()+"从洞外跳了进来。\n",environment(me), ({me}));
               return 1;
               }
            else{
               write("你身上背的东西太重，洞口又太高，你够不着。\n");
               return 1;
               }
        }
}

