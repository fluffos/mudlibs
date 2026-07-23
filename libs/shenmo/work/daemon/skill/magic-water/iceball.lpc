//iceball 寒冰弹

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(WHT"「寒冰弹」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-water",1)< 150)
	return notify_fail("你的水系魔法太差了！\n");

        msg = WHT "$N"WHT"口中轻轻吟唱起了咒文.手中渐渐聚起了一团冰球.冰球渐大.\n"NOR;
        msg += WHT"$N"WHT"扬起了手,不知不觉中已对准了$n"WHT"，$n"WHT"看到漫天寒气，抽身后跃，\n"NOR;
        msg +=WHT "$N"WHT"吟到.冰雪的精灵啊，化为撕裂者，消灭我的敌人吧！！！！\n"NOR;
        msg += WHT"$N"WHT"大叫一声  寒冰弹!!  ,手中的寒冰弹直向$n"WHT"飞去，快捷无伦.！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-water", 1);
//对水属性目标无作用
       if ((int)target->query("magicgift")==2)
{
damagic=100+damage;
                target->receive_damage("qi", damagic);
damagic=50+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
//对火属性目标强大
else  if ((int)target->query("magicgift")==1)
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
damagic=550+damage;
target->receive_damage("qi", 550+damage*2);
target->receive_wound("qi", 550+damage);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}

        msg += WHT"$n"WHT"根本没法躲避，一个巨大寒冰弹,端端正\n"NOR;
        msg += WHT"正打在$n"WHT"的身上！$n"WHT"全身都冻住了!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"可是$p"HIY"轻轻一笑，侧身右转.\n"NOR;
        msg += HIY"寒冰弹在$p"HIY"身侧划过，毫发无伤。\n"NOR;
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
