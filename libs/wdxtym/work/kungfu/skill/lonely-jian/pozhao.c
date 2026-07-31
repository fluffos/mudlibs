// tuwu.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	int damage;
	string msg;
	object weapon;
        object weapon2;
        int ap, dp, wound;
         int i, lvl;
	 if( !target ) target = offensive_target(me);

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("独孤九剑必须配合紫霞神功。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("以招破招只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("lonely-jian", 1) < 200 )
		return notify_fail("你的独孤九剑不够娴熟，不会使用以招破招。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你内力不够了。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	skill = me->query_skill("lonely-jian", 1);

	me->add("neili", -100);
	target->receive_damage("qi", (int)skill/ 3,me);
	message_combatd(HIC "$N随手几招向$n刺来,一看只下尽全是刺向$n武功的弱点
$n心中一慌.....不由的发出的怪叫声。\n"NOR,me,target);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
	message_combatd(
        HIR "$N手中的剑发出无数道的剑气,一道一道的剑气向$n刺去！\n" NOR, me, target);
	target->start_busy(1);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
	target->set_temp("block_msg/all",1);
	message_combatd(
        HIR "$n两眼一黑，$n啥也看不见了！\n" NOR, me, target);
    }
	damage = (int)me->query_skill("lonely-jian", 1);
	damage = 500+damage + random(damage);
	target->receive_damage("qi", damage/2,me);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(7);
        me->start_busy(1);
        //	return 1;
    } else
    {
	message_combatd(
        HIR "$N手中的剑发出无数道的剑气,一道一道的剑气向$n刺去！\n" NOR, me, target);
        me->start_busy(2);
        msg = HIY"$p情急智生，向后一跳...逃出了剑气的范围。\n"NOR;
        message_combatd(msg, me, target);
    }

if (skill>=200)
{
	
	msg = HIC "$N" HIC "大喝一声，手中的" + weapon->name() +
              HIC "犹如狂风疾电一般劈刺向$n" HIC "！\n"
              HIR "霎时间只见剑气层层叠叠如波浪般汹涌而起，$n"
              HIR "只觉得呼吸登时不畅。\n" NOR;
	message_combatd(msg, me, target);
lvl = me->query_skill("lonely-jian", 1) / 80;
                if (lvl>9) lvl=9;
                me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1200);
        for (i = 0; i < lvl; i++)
        {
msg=HIM"$N剑气纵横! 第"+chinese_number(i+1)+"道剑气划过了$n的$l。结果鲜血狂奔!\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1200);
}

if (skill>=300)
{
  msg = HIC "$N心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n掷了出去，\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0)
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = target->query("qi")/5;
if (damage >=25000) damage=25000;
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);        
msg += HIC"$n疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃拦腰而过，鲜血飞溅，皮肉卷起！\n"NOR;
    } else
    {
        me->start_busy(2);

msg += HIY"可是$n轻轻一笑，侧身伸指，正弹在$N的剑脊上，剑斜飞落地。\n"NOR;
    }
    message_combatd(msg, me, target);	
	
}	

//if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
void tuwu_end(object me, object target)
{
if (target)
{
	target->enable_player();
	message_combatd("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
	target->set_temp("block_msg/all", 0);
}
	//write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
	return;
}
