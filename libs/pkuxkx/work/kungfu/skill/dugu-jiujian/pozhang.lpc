#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg, *skill;
        int damage,i;
        object weapon;
        mapping pmap;
        int howlong=0;
        int npc_chance=0;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「破掌式」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("dugu-jiujian", 1) < 120 )
                return notify_fail("你的独孤九剑不够娴熟，不会使用「破掌式」。\n");

        if( objectp(weapon=target->query_temp("weapon")) )
                return notify_fail("对方不是空手，你怎么破掌？\n");

        if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你必须使剑才能使用「破掌式」！\n");

       if ( (int)target->query_temp("no_perform") )
                return notify_fail("对方已经处于封魔状态了！\n");

       if ( (int)me->query("neili") < 50 )
              return notify_fail("你的内力不够呀!\n");

        me->add("neili",-50);

        msg = HIC "$N" + weapon->name() + HIC + "忽伸忽缩，在$n防御圈子外游转不定。$n被这古怪剑招弄的\n" +
        "胡里糊涂，招数微见滞涩，$N的" + weapon->name() + HIC + "便突然如蛇行虎窜刺将进来，$n刚刚\n" +
        "定下心神，却发现$N的剑尖已经定住了自己的掌心！\n" + NOR;
        message_vision(msg, me, target);
        msg = "";
        me->start_busy(1);
        if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) )
        {
                msg += HIR + "$n大惊之下已经忘了闪躲，$N挺剑直进，$n只觉掌心一凉，一截剑尖\n" +
                "从手背露了出来。$n一双肉掌竟如糖葫芦般穿在了$N的" + weapon->name() + HIR + "上！正是专破\n" +
                "各类空手武功的\n\n" +
                HIW + "『独孤九剑』之  " + HIY + BNK + "破掌式！\n\n" + NOR;
                message_vision(msg, me, target);
                msg = "";

                pmap = target->query_skill_prepare();
                if( !mapp(pmap) || sizeof(pmap)==0 )
                {}
                else{
                        skill = keys(pmap);
                        for (i=0; i<sizeof(skill); i++) {
                                target->prepare_skill(skill[i]);
                        }
                        target->reset_action();
                }

                damage = (int)me->query_skill("dugu-jiujian", 1);

                damage = damage/5;

                F_KUNGFU->hit_wound("qi", damage, 0, me, target);
         //加入no_perform的效果

             if ((!userp(target))) {
             npc_chance=target->query("chat_chance_combat");
             target->set_temp("chat_chance_combat",npc_chance);
             target->set_temp("no_perform",1);
             target->delete("chat_chance_combat");
             howlong = (int)me->query_skill("sword", "dugu-jiujian") + (int)me->query_skill("dugu-jiujian");
             howlong=random(howlong/50)+5;
             if(howlong>20)  howlong=20;
             if(me->query_temp("magic_set")) howlong+=howlong/2;
             call_out("remove_effect_npc",howlong,target,me);
             message_vision(MAG"\n$n不明所以，手掌被剑所伤，顿时无法使用绝技！\n"NOR, me,target);
             }
             if ((userp(target))) {
             howlong = (int)me->query_skill("sword", "dugu-jiujian") + (int)me->query_skill("dugu-jiujian");
             howlong=random(howlong/50)+5;
             if(howlong>20)  howlong=20;
             target->set_temp("no_perform",1);
             call_out("remove_effect_player",howlong,target,me);
             message_vision(MAG"\n$n不明所以，手掌被剑所伤，顿时无法使用绝技！\n"NOR, me, target);
             }
             COMBAT_D->report_status(target);
        }
        else
        	{
                me->start_busy(3);
                if (random(2) == 0)
                        msg += HIG + "$n心知" + weapon->name() + HIG + "抵掌难有幸理，当下深吸一口长气，丹田内力霎时奔腾而出\n" +
                        "直至掌心！$N觉得剑势微微一挫，$n聚掌成球吐气开声，已将长剑荡在一边，\n" +
                        "就此破解了这独一无二的　　" + HIW + "『破掌式』" + HIG + "！！\n" + NOR;
                else    msg += HIG + "$n于千钧一发之际双掌外翻，化掌为刀，胸前门户大开。同时身形疾向后射！\n" +
                                "$N剑势堪堪用老，手腕垂剑，回成独孤九剑起手式。$n远远地站着，心中暗想\n" +
                                "下次这剑再刺过来，我当如何抵挡？\n" + NOR;
                message_vision(msg, me, target);
        }
        return 1;
}

void remove_effect_npc(object target)
{
       if (!target) return;
	target->set("chat_chance_combat",target->query_temp("chat_chance_combat"));
       target->delete_temp("no_perform");
       message_vision(HIG"\n$N手上的伤势好转了一些，又能使用那些绝技了！\n"NOR,target);
}

void remove_effect_player(object target)
{
	if (!target) return;
       target->delete_temp("no_perform");
       message_vision(HIG"\n$N手上的伤势好转了一些，又能使用那些绝技了！\n"NOR,target);
}
