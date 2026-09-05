// File         : yixiansuo.c
// Created By   : iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short", HIR"一线索"NOR);
        set("long", @LONG
走上一线索，只觉得脚下摇晃的紧，所幸今日天气还算不错，若是赶上风，
只怕还不及现在。不知有多少人向下(down)看而摔死，又有多少人于此自寻短见？
你忽然冒出这样一个奇怪的念头。
LONG);

        set("outdoors", "凌霄城");
        set("no_fight", 1);
//        set("no_get_from", 1);
        set("no_sleep_room", 1);
        set("item_desc", ([
                "down" : WHT"下面云雾缭绕，什么也看不清。可不要跳(tiao)啊！\n"NOR,
        ]));
        set("exits", ([
                "west" : __DIR__"bridgew",
                "east" : __DIR__"bridgee",
        ]));

        setup();
}

void init()
{
        object me = this_player();
        object* ob = deep_inventory(me);
        int i;

        add_action("do_tiao", "tiao");
        add_action("do_tiao", "jump");
        if(!wizardp(me) 
        && me->query_encumbrance() * 100 / me->query_max_encumbrance() > 70+random(31)
        && random(me->query_skill("dodge"))<200)
        {
                message_vision(HIR"$N摇摇晃晃走上铁索，脚下一个不稳，竟头朝下栽了下去！\n"NOR, me);
                me->move(__DIR__"xueguan", 1);
                for(i=0; i<sizeof(ob); i++)
                        if(ob[i]->is_character())
                        {
                                ob[i]->receive_damage("qi", 0, me);
                                message_vision(HIR"$N被$n背着，一同落在了地上！\n", ob[i], me);
                                ob[i]->die();
                        }
                message_vision(HIR"$N从上边掉了下来，狠狠的拍在了地上，手指跳动两下便断了气……\n"NOR, me);
                me->receive_damage("qi", 100, "不慎从凌霄城一线索上跌入深谷摔" );
                me->die();
//                CHANNEL_D->do_channel(this_object(), "rumor",
//                                        me->name() + "不慎从凌霄城一线索上跌入深谷摔死了。");
        }
        return;
}

int do_tiao(string arg)
{
        int i;
        object me = this_player();   
        object* ob = deep_inventory(me);

        if (arg != "down")
                return notify_fail("你想往哪跳？\n");
        if (me->is_busy())
                return notify_fail("先忙完别的事再说吧。\n");
        if (me->query("combat_exp") < 80000)  
                return notify_fail("你想跳下去，可是又没那个胆量！\n");

        message_vision(HIR"$N一时想不开，叹了口气，纵身跳入深谷。\n"NOR, me);
        me->move(__DIR__"xueguan");

        if (random(4)<1)
        {
                message_vision(HIG"$N从上边掉了下来，居然毫发无伤，又站了起来！\n"NOR, me);
                tell_room(environment(me), "你不禁心里嘀咕，" +me->name()+ "是什么神人？\n", me);
                me->improve_skill("dodge", 2000);
        }
        else
        {
                for(i=0; i<sizeof(ob); i++)
                        if(ob[i]->is_character())
                        {
                                ob[i]->receive_damage("qi", 0, me);
                                message_vision(HIR"$N被$n背着，一同落在了地上！\n", ob[i], me);
                                ob[i]->die();
                        }
                message_vision(HIR"$N从上边掉了下来，狠狠的拍在了地上，手指跳动两下便断了气……\n"NOR, me);
                me->receive_damage("qi", 100, "从凌霄城一线索上跳入深谷摔" );                
                me->die();
//                CHANNEL_D->do_channel(this_object(), "rumor",
//                                        me->name() + "从凌霄城一线索上跳入深谷摔死了。");
        }

        return 1;
}
