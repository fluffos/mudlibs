//nuclea暗黑核融术

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(BLK"「暗黑核融术」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-dark",1)< 150)
	return notify_fail("你的黑暗魔法太差了！\n");

        msg = HIR "$N"HIR"口中轻轻吟唱起了咒文.天空尽然被$N"HIR"用大量的魔力制造出小型的黑洞.\n"NOR;
        msg += HIR"$N"HIR"扬起了手,不知不觉中已对准了$n"HIR"，$n"HIR"看到黑洞中心开始核融合，抽身后跃，\n"NOR;
        msg += HIR"$N"HIR"念到 从负界的混沌唤醒的禁断的黑炎啊，把阻挡在我面前的敌人都化为灰尽吧！！\n"NOR;
        msg += HIR"$N"HIR"大叫一声  暗黑核融术!!  ,$n"HIR"附近发生了核爆！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对火属性目标无作用
       if ((int)target->query("magicgift")==1 )
{
damagic=600+damage;
                target->receive_damage("qi", damagic);
damagic=650+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
//对水光属性目标强大
else  if ((int)target->query("magicgift")==2
||(int)target->query("magicgift")==6)
{
damagic=2800+damage*4;
                target->receive_damage("qi", damagic);
damagic=2800+damage*2;
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

        msg += BLK"$n"BLK"根本没法躲避，$n成了黑暗的核地狱!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += YEL"可是$p"YEL"轻轻一笑，用魔力造了一个防护屏.\n"NOR;
        msg += YEL"核爆过后 $p"YEL"毫发无伤。\n"NOR;
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
