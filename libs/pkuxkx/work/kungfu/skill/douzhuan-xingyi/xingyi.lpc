// xingyi.c 斗转星移perform星移斗转

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string* valid_weapon() 
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="self" ;
}

void extra_effect(object me, int pflv)
{
	int time, eff;
	if (me->query_temp("apply/invalid_target_special")
		|| (int)me->query_temp("xingyi_extra_effect_cd")>time()) return;
	if (pflv==4 && random(2) || pflv>=5)
	{
		message_vision(HIR"\n$N"HIW"灵台清幽"HIR"、"HIG"神怡气静"HIR"，双目似乎失去了焦距，浑然进入了"HIM"虚空甯宓"HIR"的玄妙境界。\n\n"NOR, me);
		eff = me->query_skill("douzhuan-xingyi", 1) / 10;
		me->set_temp("apply/invalid_target_special", 1); 
		me->set_temp("xingyi_extra_effect", 1); 
		time = 5+random(4);
		if (me->query("safari_skill/mr_douzhuan"))
		{
			time += 5;
			eff += eff/2;
		}
		me->add("apply/damage", eff);
		me->set_temp("active_buffer/family","姑苏慕容");
		me->set_temp("active_buffer/douzhuan-xingyi.xingyi/name", "玄妙星移");                      //buff名称
		me->set_temp("active_buffer/douzhuan-xingyi.xingyi/last_time", time() + time );          //持续时间
		me->set_temp("active_buffer/douzhuan-xingyi.xingyi/effect1", "伤害+"+eff+"点");     	 //效果描述1
		me->set_temp("active_buffer/douzhuan-xingyi.xingyi/effect2", "物理攻击无视对手的额外招架");     //效果描述2
		call_out("remove_extra_effect", time, me, eff);
	}
}

void remove_extra_effect(object me, int eff)
{
	if (objectp(me) && me->query_temp("xingyi_extra_effect"))
	{
		message_vision(HIY"\n$N吐出一口浊气，双目也恢复了灵动。\n\n"NOR, me);
		me->delete_temp("apply/invalid_target_special");
		me->delete_temp("xingyi_extra_effect");
		me->add_temp("apply/damage", -eff);
		me->set_temp("xingyi_extra_effect_cd", time()+30);
		me->delete_temp("active_buffer/douzhuan-xingyi.xingyi");
	}
}

int perform(object me, object target)
{
    int damage, p, pflv;
    string msg;
    object weapon;

    if( !target ) target = offensive_target(me);
    if( !target ||      !target->is_character() ||      !me->is_fighting(target) )
        return notify_fail("星移斗转只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("douzhuan-xingyi", 1) < 120 )
        return notify_fail("你的星移斗转还未练成，不能使用！\n");
    if( (int)me->query_skill("shenyuan-gong",1) < 80 )
        return notify_fail("你的神元功修为不够，使不出斗转星移!\n");

    if( (int)me->query("max_neili") < 1200 )
        return notify_fail("你现在内力修为不够，不能使用星移斗转！\n");
    if( (int)me->query("neili") < 600 )
        return notify_fail("你现在真气不足，不能使用星移斗转！\n");
    if( (int)me->query_skill("parry", 1) < 120 )
        return notify_fail("你的基本招架之法不够娴熟，不能使用星移斗转。\n");

//    if (me->query_skill_mapped("parry") != "douzhuan-xingyi")
//        return notify_fail("你现在无法使用星移斗转。\n");
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "姑苏慕容") 
		pflv=0;
	if (pflv>5) pflv=5;

	msg = HIY "\n忽然天昏地暗，$N使出$n的绝招，袍袖中两股内家真气向$n扑去！\n"NOR;
	
    if( F_KUNGFU->hit_rate( target->query("neili"), me->query("neili"), 17, me, target) ) {
        me->start_busy(3);
        if (!target->is_busy())
          target->start_busy(3);
        me->add("neili", -200);
        me->add("jing", -20);
        target->add("jingli", -50);
        target->add("neili", -200);
        msg += HIY"结果$p和$P两人内力一拼，双方都没占到丝毫好处！\n"NOR;
        message_vision(msg, me, target);
        return 1;
    }
    if( weapon = target->query_temp("weapon") ){
        if( F_KUNGFU->hit_rate( me->query_str(), target->query_str(), 9, me, target) ) {
            me->start_busy(1);
            me->add("neili", -150);
            me->add("jing", -20);
            damage = (int)me->query_skill("shenyuan-gong", 1);
            damage = random(damage)+100;
            F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);

            msg += HIR"\n$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，手中"
                + weapon->query("name")+HIR"脱手飞出。\n"NOR;
            message_vision(msg, me, target);
            COMBAT_D->report_status(target);
            weapon->move(environment(target));
			extra_effect(me, pflv);
        }
        else {
            me->start_busy(2);
            me->add("jing", -25);
            me->add("neili", -60);
            msg += "$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n";
            message_vision(msg, me, target);
        }
    }
    else
    {
        if ( F_KUNGFU->hit_rate( me->query_skill("parry"), target->query_skill("parry"), 6, me, target) )
        {
            me->start_busy(2);
            if (!target->is_busy())
              target->start_busy(random(3));

            me->add("jing", -50);
            damage = (int)me->query_skill("shenyuan-gong", 1);
            damage = (int)me->query_skill("douzhuan-xingyi", 1) +damage;
            damage = damage + random(damage);
            F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
            me->add("neili", -(damage/3));
            msg += damage_msg(damage, "内伤");
			message_vision(msg, me, target);
			COMBAT_D->report_status(target);
			extra_effect(me, pflv);
        } else
        {
            me->start_busy(2);
            me->add("jing", -25);
            me->add("neili", -180);
            msg += CYN"\n$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n" NOR;
			message_vision(msg, me, target);
        }
    }
    return 1;
}
