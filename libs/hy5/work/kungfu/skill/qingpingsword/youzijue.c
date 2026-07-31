//fatangel@fengyun
//trap attack
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int extra,ddg,damage;
    string msg;

            if(!target) target=offensive_target(me);
            if((string) me->query_skill_mapped("dodge")!="chaos-steps")
	     return notify_fail("清平剑法必须与倒乱七星步法配合使用！\n");
	     weapon=me->query_temp("weapon");
	     extra=me->query_skill("qingpingsword",1);
            if(extra<50) return notify_fail("你的［清平剑法］还不够精熟！\n");
            if(!target
       	||!target->is_character()
	       ||!me->is_fighting(target) )
            return notify_fail("［诱字决］只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);

            if(target->is_busy()||target->query_temp("is_unconcious"))
            return notify_fail("你的对手已经手忙脚乱了，放胆进攻吧！\n");                    

            msg=HIW"\n$n平平一剑削了出去，攻势不猛守势不严，下半身更是空门大露！\n\n"NOR;

            if(random(me->query("combat_exp"))<target->query("combat_exp")/4
             &&random(target->query("combat_exp"))<me->query("combat_exp")/2)
            {
            msg+=HIC"$N看出有诈，并未乘隙还击，反而倒退一步。\n"NOR;
            message_vision(msg,target,me);
            me->start_busy(2);
            return 1;
            }

            if(me->query("combat_exp")<random(target->query("combat_exp")/4))
            {
            msg+=HIW"$N看出有诈，却成竹在胸，将计就计地向$n攻去！\n"NOR;
            damage=COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_REGULAR,msg);
            }
            else
            {
            msg+=HIW"$N看见机不可失，马上向$n攻去！"NOR;
            ddg=me->query_skill("chaos-steps",1)/10;
            me->add_temp("apply/dodge",ddg);
            damage=COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_REGULAR,msg);
            me->add_temp("apply/dodge",-ddg);
            }
                 if(damage>1)
                 {
                 msg=HIR"\n不想$N弄巧反拙，被$n攻入空隙，顿时手忙脚乱！\n"NOR;
                 message_vision(msg, me, target);
                 me->start_busy(2);
                 return 1;
                 }

            msg=HIY"\n$N身形急转，早已闪到$n身后，在$n还没反应过来时已发起了一连串的攻击！\n"NOR;
            message_vision(msg, me, target);
            target->start_busy(2);
            me->add_temp("apply/damage",300+extra);
            msg=HIY"第一招！"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            msg=HIY"第二招！"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            msg=HIY"第三招！"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            msg=HIY"最后一招！"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            me->add_temp("apply/damage",-(300+extra));
            me->start_busy(2);
            return 1;
}

