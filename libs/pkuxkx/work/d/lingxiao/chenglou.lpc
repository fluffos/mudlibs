// File         : chenglou.c
// Created By   : iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short", HIC"凌霄城楼"NOR);
        set("long", @LONG
凌霄城城楼两层，向外(out)望去，莽莽雪山尽收眼底，令人豪气顿生。平
时弟子进出无须上到二层，所以这里只有几名弟子在巡逻。
LONG);
        
        set("outdoors", "凌霄城");
        set("item_desc", ([
                "out" : "外面是一道深谷，跃(yue)下去恐怕有死无生。\n",
        ]));
        set("exits", ([
                "eastdown" : __DIR__"chengtoue1",
                "westdown" : __DIR__"chengtouw1",
        ]));
        set("objects", ([
                __DIR__"npc/dizixl" : 3,
        ]));

        setup();
}


void init()
{
        add_action("do_yue", "yue");
}

int do_yue(string arg)
{
        object me = this_player();   

        if (arg != "out")
                return notify_fail("你想往哪跳？\n");
        if (me->is_busy())
                return notify_fail("先忙完别的事再说吧。\n");
        if (me->query_skill("dodge",1) < 30) 
                return notify_fail("你轻功太差，甚至无法翻过城墙垛！\n");

        message_vision(HIR"$N心存侥幸，妄图探秘，身行一纵，跃入深谷。\n"NOR, me);
        me->move(__DIR__"xueguan");

        if (random(4)<1)
        {
                message_vision(HIG"$N从上边掉了下来，居然毫发无伤，又站了起来！\n"NOR, me);
                tell_room(environment(me), "你不禁心里嘀咕，" +me->name()+ "是什么神人？\n", me);
                me->improve_skill("dodge", 3000);
        }
        else
        {
                message_vision(HIR"$N从上边掉了下来，狠狠的拍在了地上，手指跳动两下便断了气……\n"NOR, me);
                me->receive_damage("qi", 100, "从凌霄城楼上跳入深谷摔" );  
                me->die();
        }

        return 1;
}
