// xinghe Modify By River@SJ 2001.12.13
inherit F_SSERVER;
#include <ansi.h>
#include <combat.h>

mapping valid_types = 
([
	"finger":	"指法",
	"hand":		"手法",
	"cuff":		"拳法",
	"claw":		"爪法",
	"strike":	"掌法",
	"leg":		"腿法",
]);

int perform(object me, object target)
{
	string *skill, basic1, msg, sk;
	int i;
	mapping smap, pmap;

	if( !target ) target = offensive_target(me);

        if( !objectp(target)
	 ||  !target->is_character()
	 ||  !me->is_fighting(target) )
		return notify_fail("「星河千帆舞」只能对战斗中的对手使用。\n");

	if ( me->query_skill("bihai-chaosheng", 1) < 250 )
		return notify_fail("你的碧海潮生功不够，无法使出星河千帆舞。\n");

	if ( me->query_skill("suibo-zhuliu", 1) < 250 )
		return notify_fail("你的随波逐流修为未到，无法使出星河千帆舞。\n");

	if ( me->query_skill("tanzhi-shentong", 1) < 250 )
		return notify_fail("你的弹指神通修为未到，无法使出星河千帆舞。\n");

	if ( me->query_skill_mapped("parry") != "tanzhi-shentong"
	 || me->query_skill_mapped("finger") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong")
	 	return notify_fail("你现在无法使用星河千帆舞。\n");

	if ( me->query_temp("weapon"))
		return notify_fail("你现在无法使用星河千帆舞。\n");

	if ( me->query_skill("finger",1) < 250 )
		return notify_fail("你的指法修为不足，使不出星河千帆舞。\n");

	if( me->query("max_neili") < 3500 )
		return notify_fail("你内力太弱，不能出星河千帆舞。\n");

	if( me->query("neili") < 1200 )
		return notify_fail("你真气太弱，不能出星河千帆舞。\n");

	if( me->query("jingli") < 1000 )
		return notify_fail("你精力太弱，不能出星河千帆舞。\n");

	if ( me->query_temp("thd/xinghe"))
		return notify_fail("你正在使用星河千帆舞。\n");

	sk = me->query("env/xinghe");

	if (!sk || sk == "tanzhi-shentong") 
		return notify_fail("你必须选择一个技巧来配合！\n");

	if (me->query_skill(sk,1) < 250)
		return notify_fail("你的组合技巧还没纯熟。\n");

	smap = me->query_skill_map();
	pmap = me->query_skill_prepare();

	skill = keys(valid_types);
	for (i=0; i<sizeof(skill); i++) {
		if( smap[skill[i]] == sk ) basic1 = skill[i];
	}
	if ( !basic1 )
		return notify_fail("这种技能尚未激发或目前不能准备。\n");

	skill = keys(pmap);
	for (i=0; i<sizeof(skill); i++) {
		me->prepare_skill(skill[i]);
	}

	me->prepare_skill(basic1, sk);
	me->reset_action();

	me->start_perform(3, "星河千帆舞");
	msg = HIW"\n$N长啸一声，身形加快，施展出桃花绝技“星河千帆舞”，招数一变，不时抽空施展弹指神通！\n"NOR;
	me->add("neili",-400);
	me->add_temp("apply/attack", 50);
	me->add("jingli", - 200);
	me->set_temp("thd/xinghe",1);
	message_vision(msg, me, target);
	call_out("check", 2, me, target, me->query_skill("tanzhi-shentong",1)/15);
	return 1;
}

string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
"涌泉穴","大锥穴","风府穴",
}); 

void check(object me, object target, int count)
{
	int p, lvl, i, x=0;
	int ap, dp;
	string msg, *skill, dodge_skill, name, *limbs;
	mapping pmap;

	if ( !me ) return;

	lvl = me->query_skill("finger") * 3;
	lvl += me->query("jiali");
	pmap = me->query_skill_prepare();

	if (count > 0 && target && me->is_fighting(target)) {

		if (!sizeof(pmap)) msg = "unarmed";
		else msg = keys(pmap)[0];

		ap = COMBAT_D->skill_power(me, msg, SKILL_USAGE_ATTACK);
		dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
		dp -= random(dp/3*2);

		if ( target->is_busy()) dp -= dp/2;

		if ( random(ap + dp) > dp )
			x = 1;

		if ( me->query_temp("xinghe/"+target->query("id")) > 1+random(2)
		 && !userp(target)
		 && ap * 2 > dp )
			x = 1;

		limbs = target->query("limbs");
		name = xue_name[random(sizeof(xue_name))];
		message_vision(HIW"\n$N将弹指神通挟在招数之中，弹出一道指风，直指向$n的「"+name+"」！\n", me, target);
		message_vision(replace_string(SKILL_D("tanzhi-shentong")->query_action(me, 0)["action"],"$l", limbs[random(sizeof(limbs))]) + "！\n"NOR, me, target);

		if (wizardp(me))
			tell_object(me, sprintf("ap: %d, dp: %d，prepare: %s，damage：%d\n", ap, dp, msg, lvl));

		switch (x) {
			case 1:
				target->receive_damage("qi", lvl, me);
				target->receive_wound("qi", random(lvl), me);
				if (!random(5)) target->add_condition("no_force", 3);
				msg = COMBAT_D->damage_msg(lvl, "刺伤");
				if (random(2) && target->query("qi") >=0 || target->query("eff_qi")+target->query_temp("apply/qi") < 0) {
					p = (target->query("eff_qi")+target->query_temp("apply/qi"))*100
						/(target->query("max_qi")+target->query_temp("apply/qi"));
					msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
				}
				else {
					p = target->query("qi")*100/(target->query("max_qi")+target->query_temp("apply/qi"));
					msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
				}
				msg = replace_string( msg, "$w", "弹指剑气");
				msg = replace_string( msg, "$l", name);
				me->delete_temp("xinghe/"+target->query("id"));
				message_vision(msg,me,target);
				break;
			case 0:
				dodge_skill = target->query_skill_mapped("dodge");
				if( !dodge_skill ) dodge_skill = "dodge";
				me->add_temp("xinghe/"+target->query("id"), 1);
				msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
				message_vision(msg, me, target);
				break;
			default: return notify_fail("报告wiz，出错了！！\n");
		}
		call_out("check", 3, me, target, count -3);
	}
	else {
		skill = keys(pmap);
		for (i=0; i<sizeof(skill); i++) {
			me->prepare_skill(skill[i]);
		}
		me->prepare_skill("finger", "tanzhi-shentong");
		me->delete_temp("thd/xinghe");
		me->delete_temp("xinghe");
		me->add_temp("apply/attack", -50);
		me->start_perform(1, "星河千帆舞");
		if (living(me) && ! me->is_ghost())
			message_vision(HIW"\n$N招数一变，又转回了弹指神通。\n"NOR, me);
	}
}

string perform_name(){ return HIW"星河千帆舞"NOR; }

int help(object me)
{
        write(HIW"\n弹指神通之「星河千帆舞」："NOR"\n\n");
        write(@HELP
	要求：	最大内力 3500 以上；
		当前内力 1200 以上；
		当前精力 1000 以上；
		碧海潮生功等级 250 以上；
		随波逐流等级 250 以上；
		弹指神通等级 250 以上；
		基本指法等级 250 以上；
		激发指法为弹指神通；
		激发招架为弹指神通；
		空手且备指法为弹指神通。
	
	使用说明：
		set xinghe <空手特殊武功>
		例：set xinghe luoying-zhang

HELP
        );
        return 1;
}
