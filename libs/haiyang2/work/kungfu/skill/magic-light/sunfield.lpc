//sunfield圣光壁

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"「圣光壁」只能在战斗中使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-light",1)< 250)
	return notify_fail("你的光明魔法太差了！\n");

	if((int)me->query("magicgift")==6)
	return notify_fail("你已经使用圣光壁了！\n");

        msg = HIY "$N"HIY"口中轻轻吟唱起了咒文.$N"HIY"的身上布满一层萤光.\n"NOR;
        msg += HIY"$N"HIY"念到 艾烈艾烈．拿姆米利乌圣灵啊，变成我的盾吧！\n"NOR;
        msg += HIY"$N"HIY"大叫一声  圣光壁!!  \n"NOR;
        msg += HIY"$N"HIY"的附近形成了光之盾牌!!  \n"NOR;
        msg += HIY"$N"HIY"身前的圣光壁中向$n射去一道圣光!  \n"NOR;
        me->set("magicgift",6);
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-light", 1);
//对光属性目标无作用
       if ((int)target->query("magicgift")==6 )
{
damagic=600+damage;
                target->receive_damage("qi", damagic);
damagic=350+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
//对黑暗属性目标强大
else  if ((int)target->query("magicgift")==5)
{
damagic=2680+damage*4;
                target->receive_damage("qi", damagic);
damagic=2680+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
else 
{
damagic=900+damage;
target->receive_damage("qi", 900+damage*2);
target->receive_wound("qi", 900+damage);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}

        msg += HIY"$n"HIY"根本没法躲避，$n被光球包围了!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += YEL"可是$p"YEL"轻轻一笑，用魔力造了一个防护屏.\n"NOR;
        msg += YEL"光球打偏了 $p"YEL"毫发无伤。\n"NOR;
		message_combatd(msg, me, target);
        }


if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->start_busy(2);
                me->add("neili", -300);
        return 1;
}