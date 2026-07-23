//missile 魔法弹
// tie@fengyun

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
                return notify_fail(YEL"「魔法弹」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 1000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-earth",1)< 250)
	return notify_fail("你的土系魔法太差了！\n");


	extra = me->query_skill("spells",1) / 40;
	extra += me->query_skill("magic-earth",1) /40;
 	if (extra> 33) extra = 33;
        i = extra/4;
        msg = YEL "$N"YEL"口中高吟了一段了咒文.$N"YEL"的脚下形成了"+chinese_number(i)+"道地炎!\n"NOR;
        msg += YEL"$N"YEL"念到 撒撒特．撒撒特．史克罗洛．罗洛斯古！在漆黑深渊燃烧的地狱烈火啊!!\n"NOR;
        msg += YEL"$N"YEL"念到 变成我的剑把敌人消灭扬 !!,所有的"YEL"地炎"NOR","YEL"全部对准了$n"YEL"发射而去!\n"NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = YEL"    第"+chinese_number(i+1)+"道"YEL"地炎!\n"NOR;
        msg += YEL"     ☆☆★∑"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("magic-earth", 1);
//对土属性目标无作用
       if ((int)target->query("magicgift")==4)
{
damagic=90+damage;
                target->receive_damage("qi", damagic);
damagic=95+damage;
                target->receive_wound("qi", damagic);
}

else  if ((int)target->query("magicgift")==3)
{
damagic=950+damage*3;
                target->receive_damage("qi", damagic);
damagic=950+damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=200+damage;
target->receive_damage("qi", 200+damage);
target->receive_wound("qi", 200+damage/2);
}

        msg += HIR"\n  $n"HIR"没法躲避，被地炎炸得飞了起来！\n"NOR;
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"\n  $p"HIG"飞身跃起，结果地炎在$p"YEL"身下爆炸。\n"NOR;
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

