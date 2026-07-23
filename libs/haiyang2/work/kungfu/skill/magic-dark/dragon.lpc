// dragon 龙破斩

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 1100)
	return notify_fail("你的法力太差了！\n");

        msg = BLK"   轰●○〓※★  \n"NOR;
        msg += BLK"\n一个巨大的黑色冲击波向$N"BLK"的身上打来，!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对黑暗属性目标无作用
       if ((int)target->query("magicgift")==5)
{
damagic=1200+damage;
                target->receive_damage("qi", damagic);
damagic=1200+damage;
                target->receive_wound("qi", damagic);
}
//对光属性目标强大
else  if ((int)target->query("magicgift")==6)
{
damagic=3600+damage*5;
                target->receive_damage("qi", damagic);
damagic=3600+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIR"$n"HIR"的附近成为了一片火海!!\n"NOR;
                if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIB"$n"HIB"飞身跃起，逃过了一难。\n"NOR;
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
me->add("neili",-450);
if (wizardp(me))
tell_object(me, "基本杀伤为"+damagic+"点。\n" NOR);

	return 1;
	
}
int perform(object me, object target)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIB"「龙破斩」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-dark",1)< 550)
	return notify_fail("你的黑暗魔法太差了！\n");


	msg = BLK "$N"BLK"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += BLK"$N"BLK"念到 比黄昏还要昏喑的东西,比血液还要鲜红的东西...\n"NOR;
       msg += BLK"$N"BLK"念到 出现在时间之流  把挡在我面前一切愚不可及的事物摧毁...\n"NOR;
       msg += BLK"$N"BLK"大叫一声  龙破斩!!  巨大的的冲击波直向四周飞去，能量大的可怕！！\n"NOR;
       msg += HIB"  「龙破斩」 \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
	return 1;
}


