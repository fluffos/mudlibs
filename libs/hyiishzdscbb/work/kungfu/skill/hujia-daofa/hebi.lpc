#include <ansi.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
	object weapon, weapon1, target;
	int skill, skill1;
	string msg;

	if (!arg) return notify_fail("你想和谁一起双刀合璧？\n");
	if (!objectp(target = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if (target==me) return notify_fail("和自己合璧？\n"); 
	if ( !me->is_fighting() )
		return notify_fail("双刀合璧只能在战斗中使用。\n");
	if ( !target->is_fighting() )
		return notify_fail("双刀合璧只能与战斗中的伙伴一起使用。\n");
	if (me->is_fighting(target))
		return notify_fail("你正在和"+target->name()+"打架呢。\n");

	weapon = me->query_temp("weapon");  
	weapon1 = target->query_temp("weapon");  

	if(!weapon || weapon->query("skill_type") != "blade"
		|| me->query_skill_mapped("blade") != "hujia-daofa"
		|| me->query_skill_mapped("parry") != "hujia-daofa")
		return notify_fail("你现在无法使用「双刀合璧」。\n");

	if(!weapon1 || weapon1->query("skill_type") != "blade"
		|| target->query_skill_mapped("blade") != "hujia-daofa"
		|| target->query_skill_mapped("parry") != "hujia-daofa")
		return notify_fail(target->name()+"现在无法使用「双刀合璧」。\n");

	skill = me->query_skill("hujia-daofa", 1);
	skill1 = target->query_skill("hujia-daofa", 1);

	if(skill < 100 )
        return notify_fail("你的胡家刀法等级不够，不能使用「双刀合璧」。\n");
    
//    if (me->query_skill_mapped("force") != "hujia-daofa")
//		return notify_fail("你所使用的内功不对。\n");
	if(me->query("neili") < 500 )
		return notify_fail("你现在真气太弱，不能使用「双刀合璧」。\n");
	if(target->query("neili") < 500 )
		return notify_fail("对方现在真气太弱，不能使用「双刀合璧」。\n");
    if(me->query("neili") < 1000 )
		return notify_fail("你的内力修为太弱，不能使用「双刀合璧」。\n");
    if(target->query("neili") < 1000 )
		return notify_fail("对方的内力修为太弱，不能使用「双刀合璧」。\n");

	if(me->query_temp("shuangdao_hebi")) 
		return notify_fail("你已经在使用「双刀合璧」了。\n");

	if(me->query_temp("幻影")) 
		return notify_fail("你正在使用无形幻影，不能再使用「双刀合璧」。\n");

	if (me->query_temp("hebi_target")){
		if (me->query_temp("hebi_target")==target)
			return notify_fail("你已经做好和"+target->name()+"双刀合璧的准备了。\n");
		else
			tell_object(me->query_temp("hebi_target"), YEL+me->name()+"决定不和你进行双刀合璧了。\n"NOR); 
	}
	if (target->query_temp("hebi_target") ==me){
		message_vision(MAG"\n$N将手中"+weapon->name()+MAG+"一摆，架在$n的"+weapon1->name()+MAG+"上，双刀相加，顿时光芒四射，声震天地！\n"NOR, me, target);
		me->set_temp("hebi_target", target);
		me->set_temp("shuangdao_hebi", 1); 
		target->set_temp("shuangdao_hebi", 1); 
		me->add("neili", -300);
		target->add("neili", -300);
		me->add("jing", -50);
		target->add("jing", -50);
		me->add_temp("apply/attack", skill);
		me->add_temp("apply/dodge", skill);
		target->add_temp("apply/attack", skill1);
		target->add_temp("apply/dodge", skill1);
		call_out("check_fight", 1, me, skill, (skill+skill1)/20);
		call_out("check_fight", 1, target, skill1, (skill+skill1)/20);
		return 1;
	}
	message_vision(HIC"\n$N将手中"+weapon->name()+HIC"一横，暗示$n和$P一起运用双刀合璧。\n"NOR, me, target);
	tell_object(target, YEL"你如果愿意和"+me->name()+"进行双刀和壁，请也对"+me->name()+"下一次 perform hebi <playername> 的命令。\n"NOR);
	me->set_temp("hebi_target", target);
	return 1;
}

void remove_effect(object me, int skill)
{
	if(me->query_temp("shuangdao_hebi")){
		me->add_temp("apply/attack", -skill);
		me->add_temp("apply/dodge", -skill);
		me->delete_temp("shuangdao_hebi");
		me->delete_temp("hebi_target");
		message_vision(HIR"$N双刀合璧完结，攻守也恢复正常了。\n"NOR, me);
	}
}

void check_fight(object me, int skill, int count)
{
	object weapon;
	object target;

	if (!me) return;
	if (count < 1 || !me->is_fighting()) {
		remove_effect(me, skill);
		return;
	}
	target = me->query_temp("hebi_target");
	if (!target || !target->is_fighting()) {
		remove_effect(me, skill);
		return;
	}
	if (target->query_temp("hebi_target") != me) {
		remove_effect(me, skill);
		return;
	}
	weapon = me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type") != "blade") {
		remove_effect(me, skill);
		return;
	}
	if (me->query_skill_mapped("blade") != "hujia-daofa"
		|| me->query_skill_mapped("parry") != "hujia-daofa") {
		remove_effect(me, skill);
		return;
	}
	if(environment(me) != environment(target)) {
		remove_effect(me, skill);
		return;
	}
    call_out("check_fight", 1, me, skill, count-1);
}
