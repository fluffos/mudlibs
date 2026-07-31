// tie@fengyun
string query_name() { return "[冰魔法]"ZJBR"寒冰流矢"; }
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
        int damage,damagic;

	if( !target ) target = offensive_target(me);

	        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIW"「冰魔法·寒冰流矢」只能对战斗中的对手使用。\n"NOR);

	if((int)me->query("neili")< 1000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1))
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

	if((int)me->query_skill("bingzhi-shengdian",1)< 250)
	return notify_fail("你的冰之圣典太差了！\n");


	extra = me->query_skill("spells",1) / 40;
	extra += me->query_skill("bingzhi-shengdian",1) /40;
 	if (extra> 33) extra = 33;
        i = extra/4;
        msg = HIW "$N"HIW"口中高吟了一段了咒文.$N"HIW"的上空形成了"+chinese_number(i)+"道冰魔法·寒冰流矢.\n"NOR;
        msg += HIW"$N"HIW"念到 冥王啊，令所有至高无上的力量集于我身! 冰河啊，狂奔吧!!!\n"NOR;
        msg += HIW"$N"HIW"扬起了手,所有的"HIW"冰魔法·寒冰流矢"NOR","HIW"全部对准了$n"HIW"发射而去!\n"NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = WHT"    第"+chinese_number(i+1)+"道"HIW"冰魔法·寒冰流矢!\n"NOR;
        msg += HIW"     →* "NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("bingzhi-shengdian", 1);
//对水属性目标无作用
       if ((int)target->query("bingzhi-shengdian")==2)
{
damagic=5000+damage*45;
                target->receive_damage("qi", damagic);
damagic=5000+damage*45;
                target->receive_wound("qi", damagic);
}

else  if ((int)target->query("bingzhi-shengdian")==1)
{
damagic=10000+damage*75;
                target->receive_damage("qi", damagic);
damagic=10000+damage*75;
                target->receive_wound("qi", damagic);
}
else
{
damagic=7500+damage*65;
target->receive_damage("qi", 7500+damage*65);
target->receive_wound("qi", 7500+damage*65);
}

        msg += HIW"\n  $n"HIW"没法躲避，被冰魔法·寒冰流矢炸得飞了起来！\n"NOR;
		message_combatd(msg, me, target);
        } else
        {
        msg += HIW"\n  $p"HIW"飞身跃起，结果冰魔法·寒冰流矢在$p"HIW"身下爆炸。\n"NOR;
		message_combatd(msg, me, target);
        }

	}
	i = extra/4;
		COMBAT_D->report_status(target);
if (wizardp(me))
tell_object(me, "基本杀伤为"+damagic+"点。\n" NOR);
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
	me->add("neili", - 120 * i);
	me->start_busy(3);
	return 1;
}

