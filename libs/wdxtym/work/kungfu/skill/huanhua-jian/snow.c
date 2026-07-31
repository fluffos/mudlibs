// tie@fengyun
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "天下"ZJBR"有雪"; }
int perform(object me, object target)
{
	string msg;
	int i, lmt, damage ;
	int ap,dp;	object weapon;
	weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIW "「天下有雪」只能对战斗中的对手使用。\n"NOR);	
	if( (int)me->query_skill("huanhua-jian",1) < 600)
		return notify_fail(HIW "你的「浣花剑法」还不到家，无法使用「天下有雪」！\n"NOR);
	if( (int)me->query_skill("feihua-wuping",1) < 600)
		return notify_fail(HIW "你的「飞花无凭」还不到家，无法使用「天下有雪」！\n"NOR);
	if ((int)me->query("neili") < 1000)
		return notify_fail("你的内力不够，无法使用「天下有雪」！\n");	
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力修为不够，无法使用「天下有雪」！\n");	
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if ((int)me->query_skill("guiyuan-dafa", 1) <600)
		return notify_fail("你的归元大法火侯太浅，无法使用「天下有雪」！\n");
	if (me->query_skill_mapped("force")!="guiyuan-dafa")
		return notify_fail("你的未使用归元大法，无法使用「天下有雪」！\n");	
	if (me->query_skill_mapped("sword") != "huanhua-jian")
		return notify_fail("你没正确激发该技能 。\n");	
	if (! objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你起码也得拿把剑吧!");
	if (!(int)me->query("breakup"))
        return notify_fail("你任督二脉未通,无法使用「天下有雪」！\n"NOR); 
	if (weapon->query("weapon_prop/damage") < 10)
		return notify_fail("你使用的武器太渣渣了！\n");	
	
	 message_vision(HBWHT "$N贯通浣花派武学，使出了浣花派的绝学之精髓！\n" NOR, me, target);
	
	msg = HIY  "$N长啸一声，剑招顿挟风云之式，剑气猛的暴涨三尺，手中的\n"+ weapon->name()+  "如狂风暴雨般地向$n卷来！\n\n" NOR;
	message_vision(msg,me,target);
	ap = me->query("xyzx_sys/level") + me->query_skill("huanhua-jian", 1) + me->query_skill("feihua-wuping",1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
        
		damage = me->query_skill("huanhua-jian",1) + me->queryry_skill("sword",1) + me->query_skill("guiyuan-dafa",1) + weapon->query("weapon_prop/damage");
		damage = damage + random(damage);
	if(damage < 10 ) damage = 10; //2015.4 加入解决伤害为0
	if(me->query_skill("huanhua-jian",1) < 2000)  lmt=4+random(4);	
	if(me->query_skill("huanhua-jian",1) >= 2000)  lmt=7+random(7);
	for(i=1;i<=lmt;i++)
	{
	msg =  HIW "$N大喝一声：接第"+chinese_number(i)+"剑！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	target->receive_damage("qi", damage,me);
	target->receive_wound("qi", damage,me);
    me->add("neili", -100*lmt);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage +"。\n" NOR);
	
	if ( me->query_skill("huanhua-jian",1) > 3000)
	{
		message_vision(HIY"一轮剑雨之后，$N手中长剑又出现新的变化，若无情又有情，手中的"+ weapon->name()+  "仿佛有了生命般，$N大喝一声：「天下有雪」！\n"NOR,me,target);
		damage = me->query_skill("huanhua-jian",1)*me->query("dex",1)+me->query_skill("feihua-wuping",1)*me->query("dex",1)+me->query_skill("guiyuan-dafa",1)*me->query("dex",1)+ me->query_skill("sword",1) + weapon->query("weapon_prop/damage")*(2+random(me->query("dex",1)))/2;
		damage = damage + random(damage);
		if(damage < 10 ) damage = 10; //2015.4 加入解决伤害为0
	if (random(ap) > dp/3 )	
	{
		message_vision(HIC"$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐渐逼近$n\n"NOR,me,target);
		message_vision(HIB"$n看到漫天剑光，抽身后跃，只这一刹，\n"NOR,me,target);
		message_vision(HIY"漫天剑影化为一剑直刺$n前胸，快捷无伦，只有一剑！\n"NOR,me,target);
		target->receive_wound("jing", damage/2,me);
		target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/3,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/3 +"，精神的内伤为"+ damage/2 +"。\n" NOR);
	//	if (!target->is_busy()) target->start_busy(random(3));
		me->add("neili", -(me->query("jiali")+100));
		target->add("neili", -(me->query("jiali")+1000));
	}
	else
    {

        message_vision(HIC"可是$n轻轻一笑，侧身右转，伸出两指，正弹在$P的剑上，\n"NOR,me,target);
        message_vision(HIY"长剑在$n身侧划过，$n以为毫发无伤。然而$n一低头，"+ weapon->name()+ "自胸口拔出！\n"NOR,me,target);
        me->add("neili", -(me->query("jiali")+100));
		target->receive_damage("qi", damage/5,me);
        target->receive_wound("qi", damage/5,me);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/5 +"，内伤为"+ damage/5 +"。\n" NOR);
    }
	}
	me->start_busy(5);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
