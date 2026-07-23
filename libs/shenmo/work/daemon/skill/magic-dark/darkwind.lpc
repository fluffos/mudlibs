//darkwind暗黑龙卷风

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIB"「暗黑龙卷风」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 600)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-dark",1)< 350)
	return notify_fail("你的黑暗魔法太差了！\n");

if (target->is_busy())
return notify_fail("现在正是用攻击敌人的时候啊！\n");
                me->start_busy(1);
        msg = HIC "$N"HIC"口中轻轻吟唱起了咒文..\n"NOR;
        msg += HIC"$N"HIC"念到，念到 激怒神的人们，将承受上天无情的制裁……”，\n"NOR;
        msg += HIC"$N"HIC"念到，以天地诸元为名，召集四方风之精灵，十二界的黑暗之力供我使唤！”，\n"NOR;
        msg += HIC"$N"HIC"大叫一声  暗黑龙卷风!!  ,$n"HIC"的附近突然挂起了黑色的龙卷风.！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对气属性目标无作用
       if ((int)target->query("magicgift")==3)
{
target->start_busy(3);
damagic=damage;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
//对土光属性目标强大
else  if ((int)target->query("magicgift")==4
||(int)target->query("magicgift")==6)
{
target->start_busy(8);
damagic=damage*3;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=damage+300;
target->receive_damage("qi", damage+300);
target->receive_wound("qi", damage+300);
target->start_busy(4);
}

target->apply_condition("ill_dongshang",10);
target->apply_condition("ill_fashao",10);
target->apply_condition("ill_kesou",10);
target->apply_condition("ill_shanghan",10);
target->apply_condition("ill_zhongshu",10);
target->apply_condition("ice_poison",10);
target->apply_condition("xx_poison",10);
target->apply_condition("cold_poison",10);
target->apply_condition("flower_poison",10);
target->apply_condition("rose_poison",10);
target->apply_condition("scorpion_poison",10);
        msg += BLK"$n"BLK"大吃一惊，给黑暗笼置!!\n"NOR;
	msg += BLK"$n"BLK"在黑暗感到全身说不出的难受!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"$n"HIG"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
                me->start_busy(2);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->add("neili", -400);
        return 1;
}
