/*  /kungfu/vast/perform_model_critical.c
*
* 自创武功领悟技能模版
* from dugu-jiujian/poqi.c 主要来自独孤九剑 破气
*
* deWolf(vax)@pkuxkx <deWolf_maTri_X@msn.com> 2005.11.09
*/

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
    object weapon;
	object victim_obj;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("威力一击只能对战斗中的对手使用。\n");

	if ("SKILL_BASE_NAME"=="sword" || "SKILL_BASE_NAME"=="blade" 
		|| "SKILL_BASE_NAME"=="whip" || "SKILL_BASE_NAME"=="staff" || "SKILL_BASE_NAME"=="spear")
	{
		if (!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "SKILL_BASE_NAME")
		{
			if (!objectp(weapon = me->query_temp("secondary_weapon"))
				|| (string)weapon->query("skill_type") != "SKILL_BASE_NAME")
			{
				return notify_fail("使用威力一击需要合适的兵器!\n");
			}
		}
	}
	else
	{
		if (objectp(weapon = me->query_temp("weapon")) 
			&& objectp(weapon = me->query_temp("secondary_weapon")))
		{
			return notify_fail("使用威力一击需要空出一只手来!\n");
		}
	}
	
	if( (time() - me->query_temp("critical_end")) < 8 )
		return notify_fail("你刚刚使用过威力一击！\n");
	if( (int)me->query_skill("SKILL_EN_NAME", 1) < PERFORM_NEED_LEVEL )
		return notify_fail("你的功夫不够娴熟，不会使用「PERFORM_CH_NAME」。\n");
	if( me->query("neili") <= 2*PERFORM_NEED_NEILI )
		return notify_fail("你的内力不够使用「PERFORM_CH_NAME」！\n");
	if( me->query("jingli") <= 2*PERFORM_NEED_JINGLI )
		return notify_fail("你的精力不够使用「PERFORM_CH_NAME」！\n");
	
	me->add("neili", -PERFORM_NEED_NEILI);
    me->add("jingli", -PERFORM_NEED_JINGLI);	
	msg = "PERFORM_ACTION！\n";
	
	me->start_busy(1);
	me->set_temp("critical_end",time());
    if( random(me->query_str()+me->query_int())+10 > (target->query_str() + target->query_int()/2)/2 )
	{
		msg += RED "$n突然间感到丹田内一阵刺痛，继而冷热虚闷接踵而至，霎那间内力乱突，聚集胸口之间。\n" +
                "「哇」一声口中血喷三丈，真气狂泻而出！显然是受了极重的内伤！\n" NOR;
		target->receive_damage("qi",PERFORM_AMOUNT );
		target->receive_wound("qi",(PERFORM_AMOUNT + random(PERFORM_AMOUNT))/2 );
		target->receive_damage("jing",PERFORM_AMOUNT/2 );
		target->receive_wound("jing",(PERFORM_AMOUNT + random(PERFORM_AMOUNT))/3 );
		
		if ("SKILL_BASE_NAME"=="staff")
		{
			if (random(100)<15)
			{
				if (victim_obj = target->query_temp("weapon"))
				{
					// 鞭爆中夺取武器
					msg += HIG "$N用回手一勾，发力一扫，$n眼睁睁地看着$w将自己的"
						+victim_obj->query("name")+"夺走震碎!\n" NOR;
					victim_obj->unequip();
					victim_obj->set("name", "断裂的" + victim_obj->query("name"));
					victim_obj->set("value", victim_obj->query("value")/10);
					victim_obj->set("weapon_prop", 0);
					target->reset_action();
				}
			}
		}
    }
	else
	{
		me->start_busy(random( 3 ));
		msg += HIG "\n$n勉强闪避，狼狈地躲开了「PERFORM_CH_NAME」！\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
