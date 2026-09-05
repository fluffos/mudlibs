// tongshou.c 太极剑法天地同寿
// fixed desribe bug by jpei 05182008
// 没有一招晕也不是100%命中掉1/3气血了

#include <ansi.h>
inherit F_SSERVER;
inherit YIZHAOYUN;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon;
        int WeaponType,exp_db;

        if( !me->query("tongshou",1) ) return notify_fail("你的外功中没有这种功能。\n");

        if( !target ) target = offensive_target(me);

        if (!objectp(weapon = me->query_temp("weapon"))) WeaponType=0;
        else if((string)weapon->query("skill_type") == "sword") WeaponType=1;

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        {
                msg= HIW "$N独自一人练习天地同寿这一绝招，";
                if(WeaponType==1)
                        msg+="倒转手中"+weapon->query("name")+HIW;
                else if(WeaponType==0)
                        msg+="只见$N骈指如剑";
                else
                        msg+="只见$N化"+weapon->query("name")+HIW+"为剑";
                msg+="回手向自己小腹刺去。\n不料一个收势不及，将小腹刺了个对穿。";
                msg+="$N痛的晕了过去。\n" NOR;
                message_vision(msg, me);
                me->set("eff_qi",me->query("eff_qi")/2);
                me->set("qi",me->query("eff_qi")/2);
                if (!wizardp(me)) me->unconcious();
                return 1;
        }

        msg= HIR "$N眼见不敌$n，登时面如死灰，手中招式慢了下来。\n";
        msg+="$n大喜，愈战愈勇，施展轻功滴溜溜转到$N身后，伸手便来拿$N。\n";
		exp_db=(int)(target->query("combat_exp")/me->query("combat_exp"));
        if( random((int)me->query("tongshou",1))>=2)
        {
            if(WeaponType==1)
                    msg+="$N顺着这一拉之势，回剑便往自己小腹刺去。\n" NOR;
            else if(WeaponType==0)
                    msg+="$N顺着这一拉之势，骈指如剑，回手便往自己小腹刺去。\n";
            else
                    msg+="$N顺着这一拉之势，化"+weapon->query("name")+HIR+"为剑，回手便往自己小腹刺去。\n";
            message_vision(msg,me,target);
            if( !target->is_killing(me->query("id"))) target->kill_ob(me);
//命中率A-
            if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 3, me, target) && exp_db < 101 )
            {
                if(WeaponType==1)
                {
                    msg=HIR"$n一惊之下，"+weapon->query("name")+HIR+"已经透体而过。\n"NOR;
                    message_vision(msg,target);
                    target->receive_damage("qi", 0, me);
                    target->die();
                }
                else if(WeaponType==0)
                {
                    msg=HIY"$n一惊之下，$N的手指已没入$n的小腹。\n"NOR;
                    message_vision(msg,me,target);
                    // target->unconcious();
                    yizhaoyun(target, me);
                }
                else
                {
                    msg=HIY"$n一惊之下，"+weapon->query("name")+HIY+"已没入$n的小腹。\n"NOR;
                    message_vision(msg, me, target);
                    // target->unconcious();
                    yizhaoyun(target, me);
                }
            }
            else
            {
            if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 3, me, target) && exp_db < 101 )
				{
                msg=HIW"$n大惊之下，"+weapon->query("name")+HIW+"已没入$n的小腹深达寸余。\n"NOR;
                message_vision(msg, target, me);
                F_KUNGFU->hit_wound("qi", target->query("eff_qi",1)/3, target->query("eff_qi",1)/10, me, target);
                target->start_busy(5+random(5));
                COMBAT_D->report_status(target);
				}
			else
				{
                msg=HIW"$N大惊之下，惶惶然吸气收腹，将将躲过这一剑。\n"NOR;
                message_vision(msg, target, me);
				}
			
            }
            me->receive_damage("qi", 0, target);
            if (!wizardp(me)) me->die();
        }
        else
        {
            msg=HIW"$N情急之下，照葫芦画瓢的使了招“天地同寿”，不料剑未透体便已气绝身亡。\n"NOR;
            message_vision(msg,me);
            me->receive_damage("qi", 0, target);
            if (!wizardp(me)) me->die();
        }
        return 1;
}


