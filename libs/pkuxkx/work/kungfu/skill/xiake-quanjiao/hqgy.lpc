//侠客拳脚之豪气干云
//by guilin/male
// Modified by iszt@pkuxkx, 2007-04-02

#include <ansi.h>

inherit F_SSERVER;
inherit YIZHAOYUN;
int perform(object me,object target)
{
        string msg;
        int busytime;
        int targetshen;
        int damage;
        int coefficient;
        int mlvl,tlvl; //等级
        if( !target ) target = offensive_target(me);
        if(me->query("shen")<0)
                return notify_fail("豪气干云只有正人君子方能使用！");
        if(me->query("shen")<50000)
                return notify_fail("你豪气不够！");
        if(me->query("age")<31)
                return notify_fail("你江湖阅历太浅，哪来的豪情？");
        if( target == me )
                return notify_fail("你一身豪气，不禁自顾吟起李白的侠客行来……\n");
        if( !target || !target->is_character() )
                return notify_fail("你心潮一涌，不禁吟起李白的侠客行来……\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，你豪气预备做给谁看？\n");
        if((int)me->query_skill("xiake-quanjiao",1)<100)
                return notify_fail("你侠客拳脚等级不够，无法让自己豪气逼人！");
        if((int)me->query("neili")<500)
                return notify_fail("你内力不够，无法使用「豪气干云」！");
        targetshen = target->query("shen");
        if(targetshen<0)
                targetshen=0-targetshen;
        if(me->query("gender")=="男性") 
                coefficient=1;
        else if (me->query("gender")=="女性")
                coefficient=2;
        else
                coefficient=4;
        msg=HIW"$N已闯荡江湖多年，往事种种突然浮现于胸，顿觉胸中豪情万丈，不由得开怀大笑起来。\n";

        //计算level
        if (userp(target)) tlvl = target->query("level");
           else  tlvl = to_int(pow(target->query("combat_exp")/400, 0.333)-random(5));
        if (userp(me)) mlvl = me->query("level");
           else  mlvl = to_int(pow(me->query("combat_exp")/400, 0.333)-random(5));
        if (tlvl < 1) tlvl=1;
        if (mlvl < 1) mlvl=1;
        if (wizardp(me))
                tell_object(me,sprintf("mlvl:%d,tlvl:%d,mysword:%d,tdodge:%d\n",mlvl,tlvl,me->query_skill("sword"),target->query_skill("dodge")));

        me->start_busy(2 + random(2));
//C+&A-趋近于C+        
        if( F_KUNGFU->hit_rate( me->query("combat_exp")/100*mlvl, (int)target->query("combat_exp")/100*tlvl, 7, me, target)
          && F_KUNGFU->hit_rate( me->query("shen"), targetshen, 3, me, target) )
        {
                if((int)target->query("shen")<0)
                {
                        busytime=(me->query("shen")-targetshen/20)/500000;
                }
                else
                {
                        busytime=(me->query("shen")-target->query("shen")/4)/500000;
                }
                if(busytime>30) busytime=30;
                if(busytime<4) busytime=4;
                F_KUNGFU->hit_busy( "confuse", busytime/coefficient, target );
                if(target->query("shen")>-10000000)
                        target->add("shen",-1000);
                if(target->query("shen")>0)
                        msg+=HIY"结果$n被$N的万丈豪气震住，一时间不知所措！\n"NOR;
                else
                {
                        msg+=HIR"面对$N的万丈豪气，$n心中不平，邪念顿生，但却一时也为$N正气所牵制。\n" NOR;
                        target->kill_ob(me);
                }
                message_vision(msg, me, target);
                if((int)me->query("shen")<10000000)
                        me->add("shen",100);
                if(random(6)>4)
                {
                        damage=me->query("age")/30;
                        if(damage>4) damage=4;
                        if(damage<1) damage=1;
                        damage=damage*(int)me->query_skill("xiake-quanjiao",1);
                        damage=damage/coefficient;
                        if(damage>target->query("qi")*9/10)
                        {
                                msg=HIW"$n突然间觉得在$N面前无地自容，心血一涌，竟然晕了过去！\n"NOR;
                                // target->set_temp("last_damage_from", me);
                                // target->unconcious();
                                message_vision(msg, me, target);
                                yizhaoyun(target, me, 1);
                        }
                        else
                        {
                                msg=HIW"$n觉得与$N比较起来自惭形秽，一副垂头丧气的样子。\n"NOR;
                                F_KUNGFU->hit_wound("qi", damage, 0, me, target);
                                message_vision(msg, me, target);
                                COMBAT_D->report_status(target);
                        }
                }
        }
        else
        {
                if(target->query("shen")>0)
                        msg+=HIR"面对$N的万丈豪气，$n淡淡一笑轻轻的摇了摇头。\n" NOR;
                else
                {
                        msg+=HIR"面对$N的万丈豪气，$n看到后很是不爽，不退反进，邪恶之气更甚，反以邪气逼人！\n"
                                HIB"$N反受其害！\n" NOR;
                        me->add("shen",-1000);
                        me->receive_wound("jing", 20, "被自己的豪气干云害");
                        me->receive_wound("qi", 20, "被自己的豪气干云害");
                        me->receive_damage("jing", 20, "被自己的豪气干云害");
                        me->receive_damage("qi", 20, "被自己的豪气干云害");
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(me);
                        target->add("shen",-1000);
                        target->kill_ob(me);
                }
        }
        me->add("neili",-100);
        
        return 1;
}

