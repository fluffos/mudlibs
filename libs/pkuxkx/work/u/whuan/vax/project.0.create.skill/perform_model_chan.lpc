/*  /kungfu/vast/perform_model_chan.c
*
* 自创武功领悟技能模版
* from taiji-jian/chan.c  来自太极剑法「缠」字诀
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
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	if ("SKILL_BASE_NAME"=="sword" || "SKILL_BASE_NAME"=="blade" 
		|| "SKILL_BASE_NAME"=="whip" || "SKILL_BASE_NAME"=="staff" || "SKILL_BASE_NAME"=="spear")
	{
		if (!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "SKILL_BASE_NAME")
		{
			if (!objectp(weapon = me->query_temp("secondary_weapon"))
				|| (string)weapon->query("skill_type") != "SKILL_BASE_NAME")
			{
				return notify_fail("使用牵制攻击需要合适的兵器!\n");
			}
		}
	}
	else
	{
		if (objectp(weapon = me->query_temp("weapon")) 
			&& objectp(weapon = me->query_temp("secondary_weapon")))
		{
			return notify_fail("使用牵制攻击需要空出一只手来!\n");
		}
	}
	
	if( (time() - me->query_temp("chan_end")) < 20 )
		return notify_fail("你刚刚使用过牵制攻击！\n");
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
	me->set_temp("chan_end",time());
    if( random(me->query_con()+me->query_int())+10 > (target->query_con() + target->query_int()/2)/2 )
	{
		msg += RED "$n眼看攻势越来越近却是毫无办法，但见自己的缺点无处不在暴露在$N的凌厉攻势之下，不仅手忙脚乱无法出招!\n" NOR;
		target->start_busy( PERFORM_AMOUNT );
		if ("SKILL_BASE_NAME"=="spear")
		{
			if (random(100)<15)
			{
				if (victim_obj = target->query_temp("armor/cloth"))
				{
					// 枪缠中撕烂衣服
					msg += HIG "$N虚晃一招，朝$n的空档直刺下去，$n眼看看无法躲闪，被$w带着一股气道「刺啦」一声卷碎了身上的"
						+victim_obj->query("name")+"!\n" NOR;
					victim_obj->unequip();
					victim_obj->set("name", "撕破的" + victim_obj->query("name"));
					victim_obj->set("value", victim_obj->query("value")/10);
					victim_obj->set("armor_prop", 0);
					target->reset_action();
				}
			}
		}
		if ("SKILL_BASE_NAME"=="whip")
		{
			if (random(100)<15)
			{
				if (victim_obj = target->query_temp("weapon"))
				{
					// 鞭缠中夺取武器
					msg += HIG "$N用$w在$n周围细密的织成了一片鞭网，只听$N突喊一声「走」，$n的虎口顿时一麻，手中的"
						+victim_obj->query("name")+"不翼而飞，断为几截!\n" NOR;
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
		me->start_busy(random( PERFORM_AMOUNT - 1 ));
		msg += HIG "\n$n身形连闪，好不容易将此招「PERFORM_CH_NAME」避过，已吓得冷汗直溜！\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
