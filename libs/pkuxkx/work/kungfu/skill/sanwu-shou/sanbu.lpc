
// 三无三不手 Zine Oct 28 2010
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int remove_eff(object me)
{
    if (me)
    {
        me->delete_temp("三无三不手");
    }
}

int perform(object me, object target)
{
        object weapon;
        int buff,sanwu,target_parry,my_exp,target_exp,my_qi,busy=0;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("『三无三不手』只能对战斗中的对手使用。\n");
        if (me->query("family/family_name")!="古墓派")
        return notify_fail("『三无三不手』只有古墓弟子可以使用。\n");
        if (target->is_busy())
                return notify_fail("对手正忙着呢，不须使用『三无三不手』。\n");
        if( (int)me->query_skill("sanwu-shou", 1) < 160 )
                return notify_fail("你的三无三不手功力太浅，无法施展『三无三不手』。\n");

        if( (int)me->query_skill("hand", 1) < 100 )
                return notify_fail("你的基本手法功力太浅，无法施展『三无三不手』。\n");
        if( (int)me->query_skill("yunu-xinfa", 1) < 100 )
                return notify_fail("你的内功功力太浅，无法施展『三无三不手』。\n");
                
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力太浅，无法施展『三无三不手』。\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够，无法施展『三无三不手』。\n");
        if (me->query_skill_mapped("force") != "yunu-xinfa")
                return notify_fail("你用什么为内功基础来使『三无三不手』?\n");
        if (objectp(weapon = me->query_temp("weapon")) )
                return notify_fail("空手才能施展『三无三不手』。\n");
        if( me->query_skill_mapped("parry") != "sanwu-shou")
                return notify_fail("你使得了『三无三不手』么?\n");
                 
        if (me->query_temp("三无三不手"))
        {
            return notify_fail("你刚刚使用过『三无三不手』，要休息一会才能再用。\n");
        }
        buff=to_int(sqrt(to_float(me->query("age"))));
        busy=(int)me->query_skill("sanwu-shou",1)/25;
        if (busy>25)
        {
            busy=25;
        }
        sanwu=(int)me->query_skill("sanwu-shou",1);
        target_parry=(int)target->query_skill("parry",1);
        my_exp=(int)me->query("combat_exp");
        target_exp=(int)target->query("combat_exp");
        my_qi=(int)me->query("max_qi")/10+random((int)me->query("eff_qi")/10);
        if (my_qi>3500)
        {
            my_qi=3500;
        }
        message_vision("\n"+CYN+"$N"+CYN+"这一招“无孔不入”，乃是向敌人周身百骸进攻，虽是一招，其实千头万绪，一招之中包含了数十招，竟是同时点$n"+CYN+"全身各处大穴。\n"NOR, me,target);
//C-
        if ( F_KUNGFU->hit_rate( sanwu/2, target_parry/2, 9, me, target) )
        {
            message_vision(WHT"$N惨叫一声，被$n点个正着。\n"NOR,target,me);
            F_KUNGFU->hit_busy( "jiemai", busy, target );
        }
        else
        {
            message_vision(HIG"$N轻巧地躲开了$n第一招。\n"NOR,target,me);
            busy=0;
        }
        message_vision("\n"+CYN"$N"+CYN+"跟着一招“无所不至”。这一招点的$n"+CYN+"周身诸处偏门穴道。\n"NOR, me,target);
//C-
        if (F_KUNGFU->hit_rate( sanwu, target_parry, 9, me, target) )
        {
            message_vision(WHT"$N闷哼一声，被$n点中周身诸穴。\n"NOR,target,me);
            F_KUNGFU->hit_busy( "jiemai", busy*2+random(2), target );
        }
        else
        {
            if (busy=0)
            {
                message_vision(WHT"$N高兴得太早了，躲过了前招，却被$n后招点个正着。\n"NOR,target,me);
                target->add_busy(1+random(3));
            }
            else
            {
                message_vision(HIG"$N险险避开了$n第二招。\n"NOR,target,me);
            }
        }
        message_vision("\n"+CYN"$N"+CYN+"“三无三不手”的第三手“无所不为”立即使出。这一招不再点穴，专打$n"+CYN+"眼睛、咽喉、小腹、下阴等人身诸般柔软之处。\n"NOR, me,target);
//C-
        if ( !F_KUNGFU->hit_rate( target_exp, my_exp, 9, me, target) )
        {
            message_vision(RED"\n$N手上不停，插入$n周身柔软之处。\n"NOR, me,target);
            F_KUNGFU->hit_wound("qi", my_qi, my_qi, me, target);
            COMBAT_D->report_status(target);
        }
        else
        {
            message_vision(HIG"\n$N的招式被$n完全挡开。\n"NOR, me,target);
        }
        me->set_temp("三无三不手",1);
        call_out("remove_eff",buff,me);
        return 1;
}

