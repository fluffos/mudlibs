// tuwu.c

#include <ansi.h>

inherit F_SSERVER;
 
void tuwu_end(object me, object target);
int perform(object me, object target)
{
        int skill;
        string msg;
        object weapon, obj;
        int mlvl,tlvl; //等级
        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("金蛇吐雾只能在战斗中使用。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "忙着呢，你放心攻击吧。\n");
        if (!objectp(obj=present("jinshe zhui", me))) 
                return notify_fail("你没有金蛇锥，不能使用绝招！\n");
        if( (int)me->query_skill("jinshe-zhui", 1) < 100 )
                return notify_fail("你的金蛇锥法不够娴熟，不会使用金蛇吐雾。\n");
        if( (int)me->query("neili") < 300 )
                return notify_fail("你内力不够了。\n");

        //计算level
        if (userp(target))    tlvl  = target->query("level");
           else  tlvl  = to_int(pow(target->query("combat_exp")/400, 0.333)-random(5));
        if (userp(me))        mlvl = me->query("level");
           else  mlvl  = to_int(pow(me->query("combat_exp")/400, 0.333)-random(5));
        if (tlvl < 1) tlvl=1;
        if (mlvl < 1) mlvl=1;
        if (wizardp(me))
                tell_object(me,sprintf("mlvl:%d,tlvl:%d,mysword:%d,tdodge:%d\n",mlvl,tlvl,me->query_skill("sword"),target->query_skill("dodge")));

        skill = me->query_skill("jinshe-zhui", 1); 
        me->add("neili", -200);
        F_KUNGFU->hit_wound("qi", (int)skill/ 3, 0, me, target);
        me->start_busy(2+random(2));
//B-        
        if ( F_KUNGFU->hit_rate( me->query_skill("force")*mlvl, target->query_skill("dodge")*tlvl, 6, me, target) ){
                message_combatd(
                  HIY "只听一阵狂风扫叶般的声响中，$N手中的"YEL"金蛇锥"HIY"闪出夺目的光芒，闪耀得
                  $n眼冒金花，“金蛇吐雾”！除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
                COMBAT_D->report_status(target);
                target->set_temp("block_msg/all",1);
                F_KUNGFU->hit_busy( "confuse", (int)skill/40, target );
                call_out("tuwu_end", (int)skill/50, me, target);
        } else {
                me->start_busy(2);
                msg = HIY"$p情急智生，用剑气迫开了$P的雾气。\n"NOR;
                message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
        }
        
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

void tuwu_end(object me, object target)
{
        if(target){        
                target->set_temp("block_msg/all", 0);
                message_vision("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
                tell_object(target, HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
        }
        return;
}

