//delete 属性探测

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"「属性探测」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-light",1)< 150)
	return notify_fail("你的光明魔法太差了！\n");

        msg = HIY "$N"HIY"口中轻轻吟唱起了咒文.$N"HIY"的身上布满一层萤光.\n"NOR;
        msg += HIY"$N"HIY"念到 光之神啊，给我力量，照亮我的灵魂吧！！\n"NOR;
        msg += HIY"$N"HIY"扬起了手,不知不觉中已对准了$n"HIY"，$n"HIY"看到一道白光打来，马上抽身后跃，\n"NOR;
        msg += HIY"$N"HIY"大叫一声  探测光波动!!  ,$n"HIY"被光球打中了！\n"NOR;
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
damagic=1000+damage*4;
                target->receive_damage("qi", damagic);
damagic=1000+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
else 
{
damagic=600+damage;
target->receive_damage("qi", 600+damage*2);
target->receive_wound("qi", 600+damage);
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
if ((int)target->query("magicgift")==1)
tell_object(me, HIR"\n敌人的能量属性是火。\n" NOR);
if ((int)target->query("magicgift")==2)
tell_object(me, HIW"\n敌人的能量属性是水。\n" NOR);
if ((int)target->query("magicgift")==3)
tell_object(me, HIC"\n敌人的能量属性是气。\n" NOR);
if ((int)target->query("magicgift")==4)
tell_object(me, YEL"\n敌人的能量属性是土。\n" NOR);
if ((int)target->query("magicgift")==5)
tell_object(me, BLK"\n敌人的能量属性是暗。\n" NOR);
if ((int)target->query("magicgift")==6)
tell_object(me, HIY"\n敌人的能量属性是光。\n" NOR);
if (!target->query("magicgift"))
tell_object(me, HIG"\n敌人没有能量属性。\n" NOR);


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
