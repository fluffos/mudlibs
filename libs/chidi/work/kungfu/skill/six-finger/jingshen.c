// jingshen.c 六脉惊神
// looo/2001/6/28
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

#define PFMNAME "「" HIG "六脉惊神" NOR "」"

mapping *action = ({
        ([ "name":   "少商剑",
           "action": HIW"$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“"HIR"少商剑"HIW"”
有如石破天惊、风雨大至之势，分指$n膻中和$l"NOR,
           "force":  350,
           "dodge":  50,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "商阳剑",
           "action": HIW"$N食指连动，手腕园转，“"HIM"商阳剑"HIW"”一剑又一剑的刺出，轻灵
迅速，奇巧活泼，剑气纵横，$n根本无法看清来路"NOR,
           "force":  400,
           "dodge":  100,
           "damage": 400,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "中冲剑",
           "action": HIW"$N右手中指一竖，“"HIY"中冲剑"HIW"”向前刺出。真气鼓荡，嗤然声响，
无形剑气直指$n的$l"NOR,
           "force":  350,
           "dodge":  40,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "关冲剑",
           "action": HIW"$N右手无名指伸出，“"HIG"关冲剑"HIW"”剑路拙滞古朴，一股雄浑的内
力鼓荡而出，如排山倒海般向$n涌去"NOR,
           "force":  350,
           "dodge":  60,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "少泽剑",
           "action": HIW"$N左手小指一伸，一条气流从少冲穴中激射而出，“"HIW"少泽剑"HIW"”
出手入风，指向$n的$l"NOR,
           "force":  350,
           "dodge":  50,                            
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "少冲剑",
           "action": HIW"$N右手反指，小指伸出，真气自少冲穴激荡而出，“"HIC"少冲剑"HIW"”
横生奇变，从$n意想不到的方向刺向$n的$l"NOR,
           "force":  350,
           "dodge":  40,
           "damage": 500,
           "damage_type":  "刺伤"
        ]),
});

int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int skill, skilldodge;
    int i,flag;

	if (! target) target = offensive_target(me);

	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) )
		return notify_fail(PFMNAME"只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("kuihua-xinfa", 1) > 100)
		return notify_fail(HIY "你感觉气息不顺，使不出"PFMNAME"！\n" NOR);

	if ( (string)me->query_skill_mapped("force") != "kumu-shengong" ||
		(int)me->query_skill("kumu-shengong", 1) < 500 ||
		me->query("family/family_name") != "大理段家" )
		return notify_fail("你的枯木神功修为不够，无法使用"+PFMNAME+"。\n");

	if (me->query_skill_prepared("finger") != "six-finger" && me->query_skill_prepared("unarmed") != "six-finger")
		return notify_fail("你没有准备使用六脉神剑，无法施展" PFMNAME "。\n");

	skill = me->query_skill("six-finger", 1);

    if (skill < 2000)
            return notify_fail("你的六脉神剑修为有限，无法使用" PFMNAME "！\n");

    if (me->query_skill("force") < 10000)
            return notify_fail("你的内功火候不够，难以施展" PFMNAME "！\n");

    if (me->query("max_neili") < 10000)
            return notify_fail("你的内力修为不够,无法施展" PFMNAME "！\n");

    if (me->query("neili") < 3000)
            return notify_fail("你的真气不够，现在无法施展" PFMNAME "！\n");

    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("你必须是空手才能施展" PFMNAME "！\n");

    if (! living(target))
            return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    msg = HIY "$N" HIY "十指连动，忽伸忽缩，或点或按，空中气流激荡，剑气自"
            HIY "$N" HIY "指中汹涌而出，惊震四方！！\n"
            HIR "六剑连出，剑气回荡，直割得$n眉毛削落，脸面生痛，狼狈万分！\n" NOR;

	message_vision(msg, me,target);

	i  = skill / 20;
	me->add_temp("apply/attack", i/2);
	me->add_temp("apply/damage", i/10);

	skilldodge = me->query_skill("duanshi-shenfa", 1);
	flag = 0;
	if((string)me->query_skill_mapped("dodge") == "duanshi-shenfa")
	{
		flag = 1;
                me->add_temp("fight/dodge",skilldodge/2);
	}

	if(target->query_skill("kuihua-xinfa", 1) > 100 || target->query_skill("pixie-jian", 1) > 100)
	{
                flag = 2;
                me->add_temp("fight/dodge",skilldodge/2);
	}

    {
		msg =  HIC "-------------------------少冲剑 \n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,action[5]["action"]);


		msg =  HIW "-------------------------少泽剑 \n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,action[4]["action"]);


		msg =  HIY "------------------------ 中冲剑 \n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,action[2]["action"]);


		msg =  HIG "-------------------------关冲剑 \n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,action[3]["action"]);


		msg =  HIM "-------------------------商阳剑 \n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,action[1]["action"]);


		msg =  HIR "-------------------------少商剑 \n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,action[0]["action"]);
    }

	me->add_temp("apply/attack", -i/2);
	me->add_temp("apply/damage", -i/10);
	if(flag > 0)
	{
                me->add_temp("fight/dodge",-(skilldodge/2)*flag);
	}

	me->add("neili",-3000);
	me->start_busy(4);

	return 1;
}
