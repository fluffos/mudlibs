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
                return notify_fail(HIB"「暗黑流星爆」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 1000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-dark",1)< 250)
	return notify_fail("你的黑暗魔法太差了！\n");


	extra = me->query_skill("spells",1) / 40;
	extra += me->query_skill("magic-dark",1) /40;
 	if (extra> 37) extra = 37;
        i = extra/4;
        msg = YEL "$N"YEL"口中高吟了一段了咒文.$N"YEL"的上空出现了"+chinese_number(i)+"个黑暗流星.\n"NOR;
        msg += YEL"$N"YEL"念到 大地的黑暗面 对我忠实就回答我的命令，来吧，用邪恶的力量毁灭一切！！！！！\n"NOR;
        msg += YEL"$N"YEL"扬起了手,所有的"HIM"黑暗流星"NOR","YEL"全部对准了$n"YEL"发射而去!\n"NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = YEL"    第"+chinese_number(i+1)+"个"BLK"火黑暗流星!\n"NOR;
        msg += BLK"   ===@ "NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对土属性目标无作用
       if ((int)target->query("magicgift")==4)
{
damagic=300+damage;
                target->receive_damage("qi", damagic);
damagic=350+damage;
                target->receive_wound("qi", damagic);
}

else  if ((int)target->query("magicgift")==2
||(int)target->query("magicgift")==6)
{
damagic=1900+damage*3;
                target->receive_damage("qi", damagic);
damagic=1900+damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=600+damage;
target->receive_damage("qi", 600+damage);
target->receive_wound("qi", 600+damage/2);
}

        msg += HIR"\n  $n"HIR"没法躲避，被流星炸得体无完肤！\n"NOR;
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"\n  $p"HIB"飞身跃起，结果黑暗流星在$p"HIB"身下爆炸。\n"NOR;
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
	me->add("neili", - 150 * i);
	me->start_busy(3);
	return 1;
}

