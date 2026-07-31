//bahuang.c   
//by Xuanyuan

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	int skill, dur, drop, age;
	int bili, wuxing, gengu;
	int sum, num1, num2, num3, num4;
	string arg;

	skill = (int)me->query_skill("bahuang-gong", 1);
	dur = (int)me->query("neili");
	age = me->query("age") - 30;
	if (age < 0)
	age = 0;

//	if (! wizardp(me)) 
//		return notify_fail("目前这功能还不开放！\n");

	if( target != me ) 
		return notify_fail("你只能用八荒六合唯我独尊功增强自己功力。\n");

	if( skill < 150 )
		return notify_fail("你的八荒六合唯我独尊功功力不够！n");

	if( (int)me->query_skill("force") < 150 )
		return notify_fail("你的基本内功修为火候未足，无法使用八荒六合唯我独尊功！\n");

	if( me->query("max_neili") <= 2000 )
		return notify_fail("你的内力不够浑厚，无法使用八荒六合唯我独尊功！\n");

	if ( me->query("gender") == "无性" )
		return notify_fail("你无根无性，阴阳不调，难以运用八荒六合唯我独尊功。\n");

	if ( me->query("bahuang_age") > age )
		return notify_fail("八荒六合唯我独尊功只能每三十年用一次。\n");

	if( (int)me->query("neili") < me->query("max_neili")*2 - 100  ) 
		return notify_fail("八荒六合唯我独尊功要在内力充塞全身的时候放可使用，你的内力不够。\n");

	if( (int)me->query_temp("bahuang") ) 
		return notify_fail("你已经在运功中了。\n");

	if (dur < 1)
		return notify_fail("你的内力不够运用八荒六合唯我独尊功。\n");

	message_vision(HIR "$N盘膝坐下，右手食指指天，左手食指指地，口中嘿的一声，鼻孔中喷出了两条淡淡白气。\n" NOR, me);

	me->set("bahuang/temp_age", me->query("age"));
	if(me->query("bahuang_age")){
	me->set("age", me->query("bahuang_age"));
	}
	me->set("bahuang/temp_exp",me->query("combat_exp"));
	if(me->query("bahuang_exp")){
	me->set("combat_exp", me->query("bahuang_exp"));
	}

	me->apply_condition("bahuang", dur);
	me->set_temp("bahuang", 1);
	me->start_busy(10+random(30));
	call_out("checking", 1, me, target,skill);
	return 1;
}
int checking(object me)
{
	if( me->query_temp("bahuang") && me->query_skill_mapped("force") != "bahuang-gong")
	{
		tell_object(me,HIR"你的八荒六合唯我独尊功内力突然间失却控制，便如洪水泛滥，立时要溃堤而出！\n"NOR);
		message_vision(HIR"突然只见$N全身颤抖，手指力抓自己面颊，登时血痕斑斑。\n\n"NOR,me);
		tell_object(me,"因为你在运功时更换内功，导致功力大损！\n");

		me->clear_condition("bahuang");
		me->delete_temp("bahuang");

		me->set("age",me->query("bahuang/temp_age"));
		me->delete("bahuang/temp_age");
			if(!me->query("bahuang_age")){
				me->set("bahuang_age", me->query("age"));
			}
		me->set("combat_exp",me->query("bahuang/temp_exp"));
		me->delete("bahuang/temp_exp");
			if(!me->query("bahuang_exp")){
				me->set("bahuang_exp", me->query("combat_exp"));
			}
		me->add("combat_exp", -(int)me->query("combat_exp",1)/10);
		me->add("max_neili", -200);
		me->add("max_jingli", -150);
		me->add("eff_jingli", -150);

		return 1;
	}
	if(!me->query_temp("bahuang") && me->query("bahuang_age") == me->query("age") )
	{
		tell_object(me, HIR"你的八荒六合唯我独尊功运行完毕。\n"NOR);
		return 1;
	}
	else call_out("checking", 1, me);
	return 1;
}
