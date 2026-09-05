// File         : gifttang.c
// Created By   : iszt@pkuxkx, 2006-12-31

inherit ITEM;
#include <ansi.h>
void init();

void create()
{
        set_name(HIM"酸梅汤"NOR,({"suanmei tang", "tang"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一杯热热的酸梅汤，看见就令人流口水～～～\n");
                set("unit", "杯");
                set("value", 140);
                set("remaining", 3);
                set("drink_supply", 30);
        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int recover, jing, e_jing, m_jing;
        string msg;
        int reward;
        object me = this_player();

        recover = 5;

        if( !this_object()->id(arg) )
                return 0;
        if( me->is_busy() )
                  return notify_fail("你上一个动作还没有完成。\n");
        if((int)me->query("water")>= (int)me->max_water_capacity() )
                  return notify_fail("你已经喝太多了，先别这么不要命的猛灌了。\n");
        set("value", 0);
        me->add("water", (int)query("drink_supply"));
        jing = (int)me->query("jing");
        e_jing = (int)me->query("eff_jing");
        m_jing = (int)me->query("max_jing");

        if (jing < e_jing )
                if ( (jing + recover) >= e_jing )
                        me->set("jing", e_jing);
                else
                        me->set("jing", jing+recover);

        if( me->is_fighting() )
                me->start_busy(2);
        add("remaining", -1);

        if ( query("remaining"))
                message_vision("$N端起一杯酸梅汤，有滋有味的品了几口。\n"+
                                        "一股酸甜之味直入心头，$N觉得精神好多了。\n", me);
        else {
                message_vision("$N端起一杯酸梅汤，一饮而尽。\n"+
                                        "一股酸甜之味直入心头，$N觉得精神好多了。\n", me);
                if(me->query("gift/20070101") != 4)
                        me->add("gift/20070101", 1);
                else if(random(4) < 1)
                {
                        msg = WHT"忽然一只"HIW"白鹤"NOR+WHT"飞来，衔着一张"HIR"帖子"NOR+WHT"和一枚"HIY"丹药"NOR+WHT"，放在$N身边就又展翅飞走了。\n";
                        msg += WHT"$N急忙打开帖子，只见上面龙飞凤舞的写着：\n";
                        msg += HIR"        ┎--------------┒\n";
                        msg += HIR"        ┃意  如  事  万┃\n";
                        msg += HIR"        ┖--------------┚\n"NOR;
                        msg += HIG"$N服下丹药，不禁胸怀大畅，似乎文才武艺都提高了一个层次！\n"NOR;
                        message_vision(msg, me);
                        reward = random(me->query("combat_exp") / 41);
                        if(reward > 200000)
                                reward = reward / 2 + 140000;
                        if(reward > 400000)
                                reward = reward / 4 + 300000;
                        me->set_skill("literate", me->query_skill("literate", 1) + 1 + random(4));
                        me->improve_skill("literate", 14);
                        tell_object(me, HIC"你的「读书写字」进步了！\n"NOR);
                        me->add("combat_exp", reward);
                        me->add("exp/20070101", reward);
                        tell_object(me, WHT"你的经验增加了" + chinese_number(reward) + "点！\n"NOR);
                        me->add("gift/20070101", 1);
                }
                destruct(this_object());
        }
        return 1;
}

