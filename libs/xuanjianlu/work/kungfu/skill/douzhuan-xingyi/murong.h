//murong cs+
//liu 2002

#include <ansi.h>
#include <combat.h>

int murong(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{
		int lvl, str, wx, skill;
		string weapon;

		if(me->query_skill("canhe-zhi")) {
			me->set_temp("memory",me->query_skill("canhe-zhi",1));
			me->set_skill("canhe-zhi", dk/2+me->query_skill("canhe-zhi",1)/2);
		} else me->set_skill("canhe-zhi", dk);
		me->map_skill("finger", "canhe-zhi");
		me->prepare_skill("finger", "canhe-zhi");

		message_vision(HIM "$N口中默念“动静如参商”，心随意转，劲跟力发。只听得内力破空之声呲呲作响！\n"
		+"内力化作一股剑气直奔$n射去！\n" NOR, me, target);

		str = me->query_str();
		wx = me->query_int();

		me->add_temp("apply/strength",str*2);
		me->add_temp("apply/intelligence",wx*2);

		lvl=me->query_skill("finger");
		skill=(me->query_skill("canhe-zhi",1)+me->query_skill("douzhuan-xingyi" ,1)) / 2;

		me->add("neili", -lvl);
		me->add("jingli", -lvl);

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		me->add_temp("apply/strength", -str*2);
		me->add_temp("apply/intelligence", -wx*2);

		tell_object(me, HIY "你缓缓收住身形，轻吁一口气，将内力收回丹田。\n" NOR);

		if(me->query_temp("memory")) {
			me->set_skill("canhe-zhi",me->query_temp("memory",1));
			me->delete_temp("memory");
		} else {
			me->delete_skill("canhe-zhi");
			me->prepare_skill("finger");
			me->map_skill("finger");
		}

		me->start_busy(1+random(1));
	} else {

        	object weapon;
        	string *limb, type, result;
        	int skill,jiajin,max_jiajin,jiali,max_jiali,damage;

		if(me->query_skill("xingyi-zhang")) {
			me->set_temp("memory",me->query_skill("xingyi-zhang",1));
			me->set_skill("xingyi-zhang", dk/2+me->query_skill("xingyi-zhang",1)/2);
		} else me->set_skill("xingyi-zhang", dk);
		me->map_skill("strike", "xingyi-zhang");
		me->prepare_skill("strike", "xingyi-zhang");

        	skill=me->query_skill("douzhuan-xingyi",1);

                message_vision(CYN"\n$N突然怒道：“难道我拿你不下？”说罢呼的一掌，向$n拍了过去！\n"NOR,me,target);

		me->add_temp("apply/attack", skill);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->add_temp("apply/attack", -skill);
		me->add("neili", -skill);
		me->add("jingli", -skill/3);
		me->start_busy(random(2));

		if(me->query_temp("memory")) me->set_skill("xingyi-zhang",me->query_temp("memory",1));
		else me->delete_skill("xingyi-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

                message_vision(HIC"\n一掌拍过，$N左手跟着从右掌掌底穿出，使出一招“石破天惊”的掌力，径自拍向$n！\n"NOR,me,target);

		jiali = me->query("jiali",1);
                jiajin= me->query("jiajin",1);
		damage = me->query_skill("force")*2+random(jiali+jiajin)*3;
		limb = target->query("limbs");
		type="内伤";

		if (me->query("combat_exp",1)/10000 + me->query_dex() + random(me->query_skill("force")) < 
                        target->query("combat_exp",1)/10000 + target->query_dex() + target->query_skill("dodge")/2)
		{
                	message_vision(HIY"\n$n听得$N厚重的掌风在响起，不敢硬接，当即斜退三步，闪了开去。\n\n"NOR,me, target);
                	me->add("neili", -(skill+jiali));
                	me->add("jingli", -(skill+jiajin)/2);
                	me->start_busy(1+random(2));
			me->delete_temp("tong");
                	return 1;
		}

		if (me->query("combat_exp",1)/10000 + me->query_dex() + random(me->query_skill("strike")) < 
                        target->query("combat_exp",1)/10000 + target->query_dex() + target->query_skill("parry")/2)
		{
        		if (target->query_skill("strike") && target->query("race") == "人类")
        		{
                		weapon = target->query_temp("weapon");
                		if(weapon)
                		{
		                        weapon->unequip();
                		        weapon->move(environment(target));
		                        target->reset_action();
                		}
		                message_vision(HIW"\n$n听得$N厚重的掌风在响起，当下吐气开声，“嘿”的一声呼喝，与$N硬对一掌\n"NOR,me,target);

		                if( me->query("max_neili")+me->query_skill("force")+me->query("neili") > target->query("max_neili")+target->query_skill("force")+target->query("neili"))
                		{
                        		message_vision(HIR"\n$n见$N雄浑的掌力，自知多半抵挡不住，不禁失声惊呼，呼声刚起，便硬吃了一掌。\n"NOR,me,target);
	                        	target->receive_wound("qi", damage/2, me);
        	              		target->receive_damage("qi", damage/2+random(damage), me);
	                	        result = COMBAT_D->damage_msg(damage, type);
        	                	result = replace_string( result, "$l", limb[random(sizeof(limb))]);
	        	                result = replace_string( result, "$p", target->name() );
        	        	        message_vision(result, me, target);
                		} else {
                                        target->add("neili", -skill-jiali);
		                        message_vision(HIG"\n只听“轰”的一声，双方掌力激荡，各退三步，各自心中一凛，均觉对方武功着实了得。\n"NOR,me,target);
                		}
        		}
			COMBAT_D->report_status(target);
		        me->add("neili", -(skill+jiali));
		        me->add("jingli", -(skill+jiajin)/2);
		        me->start_busy(1+random(2));
			me->delete_temp("tong");
		        return 1;
		} else {
			message_vision(HIR"\n$N这一掌使足阴柔内劲，波的一声响，$n的"+limb[random(sizeof(limb))]+"上已重重的中了$N一掌。\n"NOR,me, target);

			target->receive_wound("qi", damage, me);
			target->receive_damage("qi", damage+random(damage), me);
			if(!jiali ) type = "瘀伤";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);
		}

		COMBAT_D->report_status(target);
		me->add("neili", -(skill+jiali));
		me->add("jingli", -(skill+jiajin)/2);
		me->start_busy(2+random(2));
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}