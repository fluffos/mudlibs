//perform of yanxing-dao 
//刀剑合击
//Made By jason@pkuxkx
//2001-5-11
// Modified by iszt@pkuxkx, 2007-04-05

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	int damage, sk_blade, sk_sword, pflv, i, max;
	string msg;
	object weapon, secweapon;
    int dam_jian,dam_dao,dam;
    mapping jian,dao;
    string msg_dao,msg_jian;
    string *limbs,limb;
    mapping attack_val = ([
        "base" : ([ "weapon" : "blade", ]),//基本功夫类型
        "skill" : ([ "weapon" : "yanxing-dao", ]),//高级技能名称
        ]);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「刀剑合击」只能对战斗中的对手使用。\n");

    if(!objectp(weapon=me->query_temp("weapon"))||weapon->query("skill_type")!="blade")
        return notify_fail("右手无刀如何刀剑合击？\n");

    if(!objectp(secweapon=me->query_temp("secondary_weapon"))||secweapon->query("skill_type")!="sword")
        return notify_fail("左手无剑如何刀剑合击？\n");

	sk_blade = (int)me->query_skill("yanxing-dao", 1);
    if( sk_blade < 170 )
		return notify_fail("你的雁行刀法不够娴熟，不会使用「刀剑合击」。\n");

	sk_sword = (int)me->query_skill("fuliu-jian", 1);
	if( sk_sword < 170 )
		return notify_fail("你的回风拂柳剑不够娴熟，不会使用「刀剑合击」。\n");

	if( (int)me->query_skill("linji-zhuang", 1) < 170 )
		return notify_fail("你的临济十二庄不够高，不能用内力使出刀剑合击。\n");

	if( (int)me->query("neili", 1) < 800 )
		return notify_fail("你现在内力太弱，不能使出刀剑合击。\n");

/*	if(me->query_skill_mapped("sword")!="fuliu-jian")
		return notify_fail("你用的不是回风拂柳剑法，无法与雁行刀法配合。\n"); */
    //C		
	me->add("neili",-500);
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;
	
	if( F_KUNGFU->hit_rate(me->query("combat_exp")+100*(sk_blade+sk_sword),  (int)target->query("combat_exp"), 8, me, target) )
	{
		jian="/kungfu/skill/fuliu-jian"->query_action(me,secweapon);
		dao="/kungfu/skill/yanxing-dao"->query_action(me,weapon);
		limbs=target->query("limbs");
		message_vision(MAG"$N身形展动，一手刀，一手剑，刀剑合击，向$n发起了攻击！\n\n"NOR,me,target);
		msg_dao=dao["action"];
		msg_jian=jian["action"];
		limb = limbs[random(sizeof(limbs))];
		msg_dao=replace_string(msg_dao,"$w",weapon->name());
		msg_dao=replace_string(msg_dao,"$v",weapon->name());
		msg_dao=replace_string(msg_dao,"$l",limb);
		limb = limbs[random(sizeof(limbs))];
		msg_jian=replace_string(msg_jian,"$w",secweapon->name());
		msg_jian=replace_string(msg_jian,"$v",secweapon->name());
		msg_jian=replace_string(msg_jian,"$l",limb);
		message_vision(msg_dao+"。\n",me,target);
		message_vision(HIR"刀口准确地斩在$n"HIR"身上，$N"HIR"哼的一声冷笑，左手剑锋紧随着一转……\n"NOR,me,target);
		message_vision(msg_jian+"。\n",me,target);
		message_vision(HIY"嗤的一声，剑锋再度在$n"HIY"身上划过，一横一竖两道伤口深可见骨，血花飞溅！\n"NOR,me,target);
		dam_jian=secweapon->query("weapon_prop/damage")*(100+random(100)+jian["damage"])/100;
		dam_dao=weapon->query("weapon_prop/damage")*(100+random(100)+dao["damage"])/100;
		dam=(dam_jian+dam_dao)*5/2;
		dam+= (dam*pflv)/5;
		max=5000;
		max+=pflv*1000;
		if ( dam>max ) dam=max;
		F_KUNGFU->hit_wound("qi", dam, dam/3, me, target);
        COMBAT_D->report_status(target);
		if (pflv>=3)
		{
			message_vision(MAG"\n$N一招得手，顺势一旋，如同风车一般直罩向了$n！\n"NOR,me,target);
			if (target->query_skill_mapped("parry") == "qiankun-danuoyi")
				max = 1 + (pflv - 2) * (pflv - 2);  // 2/5/10
			else 
				max = (pflv - 2) * 2;	 // 2/4/6
			me->add_temp("apply/attack", (sk_blade+sk_sword)/10);
			me->add_temp("apply/damage", (sk_blade+sk_sword)/20);  		
			me->set_temp("apply/invalid_target_special", 1);
			for (i=0;i<max;i++)
			{
				me->set_temp("attack_val", attack_val);
				COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
			}
			message_vision(MAG"\n$N飞旋而过，长长地吁了一口气！\n\n"NOR,me,target);
			me->delete_temp("apply/invalid_target_special");
			me->add_temp("apply/attack", -(sk_blade+sk_sword)/10);
			me->add_temp("apply/damage", -(sk_blade+sk_sword)/20);  			
		}
		if ( !target->is_busy() )
		  target->start_busy(2);
		me->start_busy(2+random(2));
	}
	else
	{
		message_vision("$N刀剑齐出，试图给予$n致命的一击。但$n滑如游鱼，飞快地闪开了。\n", me,target);
		me->start_busy(2);
	}
	return 1;       
	
}