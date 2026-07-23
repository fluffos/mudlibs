//dali qk + wl
//liu 2002

#include <ansi.h>

string* xuedao1 = ({"百会穴","后顶穴","强间穴","脑户穴","风府穴"});
string* xuedao2 = ({"大锥穴","陶道穴","身柱穴","神道穴","灵台穴","足三里"});
string* xuedao3 = ({"中府穴","尺泽穴","孔最穴","列缺穴","太渊穴","少商穴"});
string* xuedao4 = ({"商阳穴","合谷穴","手三里","曲池穴","迎香穴"});
string* xuedao5 = ({"百会穴","灵台穴","太阳穴","膻中穴","命门穴","鸠尾穴","气海穴"});

void back(object target);
int perform2(object me, object target);
int perform3(object me, object target);
int dali(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{
		int sp, dp, time;

		if(me->query_skill("yiyang-zhi")) {
			me->set_temp("memory",me->query_skill("yiyang-zhi",1));
			me->set_skill("yiyang-zhi", dk/2+me->query_skill("yiyang-zhi",1)/2);
		} else me->set_skill("yiyang-zhi", dk);
		me->map_skill("finger", "yiyang-zhi");
		me->prepare_skill("finger", "yiyang-zhi");

		sp = (me->query_skill("finger")*2 + me->query("int")*40 + me->query("combat_exp")/3000);

		dp = (target->query_skill("dodge")+ target->query_skill("parry") + me->query("int")*30 + target->query("combat_exp")/3000);

		if (target->query("family/family_name")=="白驼山" && target->query_skill_mapped("force")=="hamagong")
		dp = dp-dp/3;

		time = me->query_skill("yiyang-zhi",1)/30+random(3);
		
		if (random(sp) > dp/2 ) {
		
			if( me->query_skill("finger") >=  80 && me->query_skill("finger") < 120)
				message_vision(HIR "\n$N向前疾跨一步，左手需晃一招，右手双指直戳，点中了$n的" + xuedao1[random(5)] + "！\n\n" NOR, me, target);

			if( me->query_skill("finger") >= 120 && me->query_skill("finger") < 180)
				message_vision(HIR "\n$N龙行虎步，隐有君王之色，信手点去，一指戳在了$n的" + xuedao2[random(6)] + "！\n\n" NOR, me, target);

			if( me->query_skill("finger") >= 180) 
				message_vision(HIR "\n$N面色凝重，气贯丹田，单指缓缓戳出，一股内力破空而出，正中$n的" + xuedao4[random(5)] + "！\n\n" NOR, me, target);

			me->add("neili",-150);
			me->add("jingli",-30);
			target->start_busy(time);
			target->add("neili",- time*30);
			target->apply_condition("yyz_damage", me->query_skill("yiyang-zhi", 1)+random(me->query_skill("yiyang-zhi", 1)) + target->query_condition("yyz_damage"));
			target->set_temp("yyzenemy", me->query("id"));
        	} else {	
			if (random(sp)>dp/3 && me->query_skill("yiyang-zhi",1)>180)
			{
				message_vision(HIW "\n$N凌空出指，一股内力击中$n的" + xuedao2[random(6)] + "，$n急忙运气与$N的内劲对抗，虽然大耗内力，但是终于没有被点中穴道。\n" NOR, me, target);
				me->add("neili",-150);
				me->add("jingli",-30);
				if (target->query("neili")>time*200) target->add("neili", - time*200);
				else target->set("neili",10);
				me->start_busy(1+random(2));
				target->start_busy(1+random(2));
				target->set_temp("yyzenemy", me->query("id"));
			} else {
				message_vision(HIW "\n$N一指戳去企图点$n的穴道，不料$n眼疾身快，身形一飘，躲开了$N的攻击。$N顿时空门大露 ... \n" NOR, me, target);
				me->start_busy(1+random(1));
			}
		}

			if(me->query_temp("memory")) me->set_skill("yiyang-zhi",me->query_temp("memory",1));
			else me->delete_skill("yiyang-zhi");
			me->delete_temp("memory");
			me->prepare_skill("finger");
			me->map_skill("finger");

	} else {

	object weapon;
	int skill, i ,level;

		if(me->query_skill("qingyan-zhang")) {
			me->set_temp("memory",me->query_skill("qingyan-zhang",1));
			me->set_skill("qingyan-zhang", dk/2+me->query_skill("qingyan-zhang",1)/2);
		} else me->set_skill("qingyan-zhang", dk);
		me->map_skill("strike", "qingyan-zhang");
		me->prepare_skill("strike", "qingyan-zhang");

	skill = me->query_skill("qingyan-zhang",1);
	level = me->query_skill("strike") / 60;
	if (level >5 ) level = 5;
	if ( skill < 60 ) skill = 60;
	if ( skill > 200 ) skill = 200;
	message_vision(WHT"\n$N忽地左掌斜劈，飕的一声轻响，一股劲风向$n呼去，跟着右掌斜劈，又是一股劲风，如此连出"+ chinese_number(level) +"掌，如行云流水，潇洒之极。\n"NOR,me,target);

	me->add_temp("apply/speed", skill);
	me->add_temp("apply/damage", skill/2);
	me->add_temp("apply/attack", skill);

	for( i=0; i < level; i++ )
	{
		COMBAT_D->do_attack(me, target, weapon);
		me->add("neili",-skill/3);
		me->add("jingli",-skill/6);
	}

	me->add_temp("apply/speed", -skill);
	me->add_temp("apply/damage", -skill/2);
	me->add_temp("apply/attack", -skill);
	me->start_busy(1+random(2));

			if(me->query_temp("memory")) me->set_skill("qingyan-zhang",me->query_temp("memory",1));
			else me->delete_skill("qingyan-zhang");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");

	}

	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}
