#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage,damagea,extra,exp;
object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「超生渡化」？\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

                
                if(!me->is_fighting())
                return notify_fail("「超生渡化」只能在战斗中使用！\n");
                if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");
                if((int)me->query("neili") < 400 )
                return notify_fail("你的内力不足！\n");

                if((int)me->query("jing") < 150 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                if((int)me->query_skill("buddhism", 1) < 160)
                return notify_fail("你的大乘佛法不够娴熟，使用这一招会有困难！\n");                
                if((int)me->query_skill("lunhui-zhang", 1) < 160)
                return notify_fail("你的轮回杖法不够熟练，使用这一招会有困难！\n");
              

                me->delete("env/brief_message");
                target->delete("env/brief_message");

        exp = (int)me->query("combat_exp"); 
            extra=(int)me->query_skill("lunhui-zhang");
            damagea=random((int)me->query_skill("lunhui-zhang"));
              message_vision(HIR"\n$N缓缓说道:佛曰：“以暴止暴，以杀止杀!”我今天就大开杀戒，代表佛祖来惩罚你们这些顽恶之徒！\n"NOR,me,target);
if(random((int)target->query("combat_exp"))/2 < (int)me->query("combat_exp"))
{
              target->receive_damage("qi",damagea);
              target->receive_wound("qi",damagea/2);
              target->receive_damage("jing",damagea/3);
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
                me->add_temp("apply/attack", 200); 
                me->add_temp("apply/damage", 1200); 
                me->add("combat_exp", exp);  
                message_vision(HIY"\n天理循环，报应不爽！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n天网恢恢，疏而不漏！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n放下屠刀，立地成佛！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n初转法轮，诸行无常！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n法轮常转，诸法无我！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIG"\n正法永住，涅磐寂静！\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


                me->add_temp("apply/attack", -200); 
                me->add_temp("apply/damage", -1200); 
                me->add("combat_exp", -exp);  
               damage=(int)me->query_skill("staff")+random((int)me->query_skill("buddhism"));
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{
              message_vision(HIC"\n$n在$N的超度之下，好象已经到了极乐世界．．．．\n"NOR,me,target);
              message_vision(HIC"\n$n呆呆的立在那里，不知所措。\n"NOR,me,target);
              target->receive_damage("qi",damage,me);
              target->receive_wound("qi",damage/2,me);
//              target->start_busy(2);
              COMBAT_D->report_status(target);
}
              me->receive_damage("jing", 30);
              me->add("neili", - 300);
              me->start_busy(3);
return 1;
}

