//castigate重破斩
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
	if((int)me->query("neili")< 1200)
	return notify_fail("你的法力太差了！\n");

        
        msg = BLU"一个巨大的黑色冲击波向$N"BLU"的身上打来，!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对黑暗属性目标无作用
       if ((int)target->query("magicgift")==5)
{
damagic=900+damage*3;
                target->receive_damage("qi", damagic);
damagic=900+damage;
                target->receive_wound("qi", damagic);
}
//对光属性目标强大
else  if ((int)target->query("magicgift")==6)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=900+damage*3;
target->receive_damage("qi", 900+damage*3);
target->receive_wound("qi", 900+damage);
}

        msg += BLU"$n"BLU"的附近消失在了黑色光辉中!!\n"NOR;
                 if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"$n"HIG"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
        }
        msg = HIW"一个巨大的白色冲击波向$N"HIW"的身上打来，!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对黑暗属性目标无作用
       if ((int)target->query("magicgift")==5)
{
damagic=500+damage*3;
                target->receive_damage("qi", damagic);
damagic=500+damage;
                target->receive_wound("qi", damagic);
}
//对光属性目标强大
else  if ((int)target->query("magicgift")==6)
{
damagic=6800+damage*5;
                target->receive_damage("qi", damagic);
damagic=6800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIW"$n"HIW"的附近消失在了白色光辉中!!\n"NOR;
                 if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"$n"HIG"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
        }
        msg = HIY"一个巨大的金色冲击波向$N"HIY"的身上打来，!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//对黑暗属性目标无作用
       if ((int)target->query("magicgift")==5)
{
damagic=800+damage*3;
                target->receive_damage("qi", damagic);
damagic=800+damage;
                target->receive_wound("qi", damagic);
}
//对光属性目标强大
else  if ((int)target->query("magicgift")==6)
{
damagic=6800+damage*5;
                target->receive_damage("qi", damagic);
damagic=6800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIY"$n"HIY"的附近消失在了金色光辉中!!\n"NOR;
                 if (!target->is_busy())
                target->start_busy(1);
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"$n"HIG"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
        }
		COMBAT_D->report_status(target);
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
me->add("neili",-880);
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
                return notify_fail(HIB"「重破斩」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 6000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");
	
	if((int)me->query_skill("magic-dark",1)< 750)
	return notify_fail("你的黑暗魔法太差了！\n");
	msg = HIB "$N"HIB"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;


       msg += HIB"$N"HIB"念到 比黑暗还要漆黑的力量啊，！！\n"NOR;
       msg += HIB"$N"HIB"念到 比夜晚还要深沉的力量啊，！！\n"NOR;
       msg += HIB"$N"HIB"念到 在混沌之海汝之伟大存在啊，，！！\n"NOR;
       msg += HIB"$N"HIB"念到 金色的黑暗之王啊，，！！\n"NOR;
       msg += HIB"$N"HIB"念到 在混沌之海汝之伟大存在啊，，！！\n"NOR;
       msg += HIB"$N"HIB"念到 吾在这里向汝请愿，向汝发誓..\n"NOR;
       msg += HIB"$N"HIB"念到 对于阻挡在吾前面的愚蠢之辈啊，集合汝与吾之力,赐予他们同等的毁灭吧.\n"NOR;
msg += BLK"    ※※※※※※※※※※※※\n"NOR;
msg += BLK"               *\       \n"NOR;
msg += BLK"             /   \\      \n"NOR;
msg += BLK"        * ━/━*━\\━ *  \n"NOR;
msg += BLK"         \ /       \\ /  \n"NOR;
msg += BLK"          *  混 沌  *    \n"NOR; 
msg += BLK"         / \\      / \\   \n"NOR;
msg += BLK"        * ━\\━*━/━ *   \n"NOR;
msg += BLK"             \\  /       \n"NOR;
msg += BLK"               *         \n"NOR;
msg += BLK"            重破斩!!      \n"NOR;
msg += BLK"    ※※※※※※※※※※※※  \n"NOR;

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


