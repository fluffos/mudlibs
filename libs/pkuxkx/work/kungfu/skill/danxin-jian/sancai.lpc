// xian.c  云龙三现

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	int extra,hit_rate;
	string msg;
	mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "danxin-jian" ]),//高级技能名称
            ]);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("剑出三才只能对战斗中的对手使用。\n");

	if ( (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword"))
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("danxin-jian", 1) < 50 )
		return notify_fail("你的碧血丹心剑不够娴熟，不会使用「剑出三才」。\n");

	if( (int)me->query_skill("cangming-gong", 1) < 50 )
		return notify_fail("你的浩气苍冥功不够高，不能使用「剑出三才」。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「剑出三才」。\n");

	extra = me->query_skill("danxin-jian",1) / 5;
	extra += me->query_skill("cangming-gong",1) /5;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
        //显示perform具体情况
        me->set_temp("combat_env",me->query("env/skip_combat"));
        me->set("env/skip_combat",0);
        target->set_temp("combat_env",target->query("env/skip_combat"));
        target->set("env/skip_combat",0);	
	
   //门派大招影响
   if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point") && !me->query_temp("cmg_zq_buff"))
	{
		hit_rate=2;
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-600);
		msg = HIR "$N大气凛然，临战神勇！\n" NOR;
		message_vision(msg,me,target);
	}
	else
	{
		hit_rate=6;
	}


	      msg = HIC "$N微微一笑，身形回转，长吸一口气,欲使出“天、地、人”三者合一的绝技疾攻$n。"NOR;
		  
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_SPECIAL,msg);
        if ( F_KUNGFU->hit_rate( me->query_skill("dodge"), target->query_skill("dodge"), hit_rate, me, target) )
        {
          msg = HIW "$N一招“苍天曷极”，剑势大气磅礴，剑锋正走沉稳击向$n周身，$n只觉得全身气脉通道阻塞，真气顿被压迫！\n"NOR;
          message_vision(msg, me, target);
          if (!target->is_busy())
          	F_KUNGFU->hit_busy( "jiemai", 4+random(4), target );
        }
        
      	msg = HIR"只见$N手中剑光幻作一条金龙,腾空而起,倏的罩向$n！"NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_SPECIAL,msg);
        if ( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), hit_rate, me, target) )
        {
          msg = HIC "$N又一招“地断肝肠”，剑走奇路，扫中$n的身上,$n只觉得全身一阵急痛！\n"NOR;
          message_vision(msg, me, target);
          F_KUNGFU->hit_wound("qi", extra * (2+random(2)), 0, me, target);
          F_KUNGFU->hit_wound("jing", extra * (2+random(2)), 0, me, target);
          COMBAT_D->report_status(target);
        }
        
        msg = HIG  "蓦地一招“人剑合一”，影若游龙，横空出世，仿佛一条青龙向$n窜去！" NOR;
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_SPECIAL,msg);
        if ( F_KUNGFU->hit_rate( me->query_skill("force"), target->query_skill("force"), hit_rate, me, target) )
        {
          msg = MAG "$N狠狠刺中$n的章门穴，没溅出什么血，$n只觉得全身内力提不起来了！\n"NOR;
          message_vision(msg, me, target);
          F_KUNGFU->hit_wound("qi", extra * (3+random(3)), extra * (3+random(3)), me, target);
          COMBAT_D->report_status(target);
        }

	me->delete_temp("attack_val");
	if (me->query_temp("cmg_zq_buff"))
	{
		me->delete_temp("cmg_zq_buff");
	}
        
        //恢复combat设置    	                                          
        me->set("env/skip_combat",me->query_temp("combat_env"));        
        target->set("env/skip_combat",target->query_temp("combat_env"));        
	me->add("neili",- 300);
	me->add_temp("apply/attack", - extra);
	me->add_temp("apply/damage", - extra);
	me->start_busy(2 + random(4));
	return 1;
}
