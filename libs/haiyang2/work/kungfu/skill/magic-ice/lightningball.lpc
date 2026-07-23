
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIC"「召雷术」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-ice",1)< 150)
	return notify_fail("你的气系魔法太差了！\n");

        msg = HIC "$N"HIC"口中轻轻吟唱起了咒文.\n"NOR;
        msg += HIC"$N"HIC"念到 眩目的霹雳，击碎一切愚蠢的阻挡……$n"HIC"，$n"HIC"听到一声巨响!抽身后跃，\n"NOR;
        msg += HIC"$N"HIC"大叫一声  雷击!!  ,天上掉下一道闪电向$n"HIC"打去，快捷无伦.！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-ice", 1);
//对气属性目标无作用
       if ((int)target->query("magicgift")==3)
{
damagic=200+damage;
                target->receive_damage("qi", damagic);
damagic=150+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
//对土属性目标强大
else  if ((int)target->query("magicgift")==4)
{
damagic=1800+damage*4;
                target->receive_damage("qi", damagic);
damagic=1800+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
else 
{
damagic=350+damage;
target->receive_damage("qi", 350+damage*2);
target->receive_wound("qi", 350+damage);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}

        msg += HIR"$n"HIR"根本没法躲避，一道闪电,端端正\n"NOR;
        msg += HIR"正打在$n"HIR"的身上！!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"可是$p"HIG"轻轻一笑，侧身右转.\n"NOR;
        msg += HIG"闪电在$p"HIG"身侧划过，毫发无伤。\n"NOR;
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
                me->add("neili", -250);
        return 1;
}
