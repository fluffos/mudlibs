//huashan ld + wj
//liu 2002

#include <ansi.h>

int huashan(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{
		int str, dex;
		string weapon;

		message_vision(MAG "\n只听得$N一声大喝，拳风突然变得猛劲之极，身法却更加飘忽难测！\n\n" NOR, me, target);

		str = me->query_str();
		dex = me->query_dex();
		me->add_temp("apply/strength", str*2);
		me->add_temp("apply/dexerity", dex*2);

		if(me->query_skill("pishi-poyu")) {
			me->set_temp("memory",me->query_skill("pishi-poyu",1));
			me->set_skill("pishi-poyu", dk/2+me->query_skill("pishi-poyu",1)/2);
		} else me->set_skill("pishi-poyu", dk);

		me->map_skill("cuff", "pishi-poyu");
		me->prepare_skill("cuff", "pishi-poyu");

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		me->add("neili", -dk);
		me->add("jingli", -dk);

		me->add_temp("apply/strength", -str*2);
		me->add_temp("apply/dexerity", -dex*2);

		tell_object(me, "\n你缓缓吸了一口气，将内劲收回丹田。\n");

			if(me->query_temp("memory")) me->set_skill("pishi-poyu",me->query_temp("memory",1));
			else me->delete_skill("pishi-poyu");
			me->delete_temp("memory");
			me->prepare_skill("cuff");
			me->map_skill("cuff");

		me->start_busy(1+random(1));
	} else {

		string weapon;
		int time,level,old_time;

		level = me->query_skill("douzhuan-xingyi", 1);
        	old_time = target->query_condition("hyz_damage");
		time = level/20 + old_time;

		message_vision(MAG "\n$N运起紫霞功，全身泛起丝丝紫气，紧接着翻掌劈出一股气劲，无声无息地涌向$n！\n\n" NOR, me, target);

		if(me->query_skill("hunyuan-zhang")) {
			me->set_temp("memory",me->query_skill("hunyuan-zhang",1));
			me->set_skill("hunyuan-zhang", dk/2+me->query_skill("hunyuan-zhang",1)/2);
		} else me->set_skill("hunyuan-zhang", dk);
		me->map_skill("strike", "hunyuan-zhang");
		me->prepare_skill("strike", "hunyuan-zhang");

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        	target->apply_condition("hyz_damage", time);
		tell_object(target,HIR"你只觉得一股火热的内力袭入你的内腑，混身燥热无比！\n"NOR);

		me->add("neili", -150);
		me->add("jingli", -100);

		if(me->query_temp("memory")) me->set_skill("hunyuan-zhang",me->query_temp("memory",1));
		else me->delete_skill("hunyuan-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}