//mizong yin+fen
//liu 2002

#include <ansi.h>
#include <armor.h>
#include <combat.h>

string* place = ({"太阳穴","面门","前胸","左肩","右肩","小腹","天灵盖"});
string* side = ({"左侧","右侧","身后"});

int mizong(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{
        	object armor;
        	int damage, jiali, jiajin, ap, dp, pp, dmg, lvl, my_exp, max_dmg;
        	string *limbs, limb, type, result, str, dodge_skill;

        	my_exp = me->query("combat_exp");
        	type = "内伤";

	        message_vision(HIR "$N长吸一口气，身上衣衫缓缓涨起，两掌变得通红，射出一股灼人热气。$n的身影被笼罩在一团火焰之中。\n\n" NOR, me,target);
        	lvl = (int)(lvl / 5);
	        me->add("neili", -lvl*2); 
        	me->add("jingli", -100);  
	        jiali = me->query("jiali");
        	jiajin = me->query("jiajin");

		if(me->query_skill("huoyan-dao")) {
			me->set_temp("memory",me->query_skill("huoyan-dao",1));
			me->set_skill("huoyan-dao", dk/2+me->query_skill("huoyan-dao",1)/2);
		} else me->set_skill("huoyan-dao", dk);
		me->map_skill("strike", "huoyan-dao");
		me->prepare_skill("strike", "huoyan-dao");

	        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
	        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

		if (wizardp(me)) printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);	// check overflow

	        ap = (ap+random(ap*2))/2;

	        if( ap > dp ) {
			tell_object(target, RED"你只觉一股热浪扑面，霍的胸口一阵剧痛。\n"NOR);
			if( target->query_temp("armor/cloth"))
			{
				armor = target->query_temp("armor/cloth");
				if( armor->query("armor_prop/armor") < 150)
				{
					if( armor->query("id") == "armor") message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块碎片四下飞散！\n"NOR, target, armor);
					else message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块破布掉在地上。\n"NOR, target, armor);
					armor->unequip();
					armor->move(environment(target));
					armor->set("name", "破碎的" + armor->query("name"));
					armor->set("value", 0);
					armor->set("armor_prop/armor", 0);
					target->reset_action();
				}
			}
			dmg = me->query_skill("force")+me->query_skill("strike")+me->query("jiajin");
			dmg = (dmg + random(dmg*2))/2;   
			damage = dmg*(1+random(me->query("jiali")/15)); 
			max_dmg = 2000;
			if (my_exp > 1000000) max_dmg = max_dmg + (int)((my_exp-1000000)/2000);
			if( damage > max_dmg ) damage = max_dmg;
			if( ap < pp ) damage = random(damage);
			//damage = random((int)me->query_skill("strike"))*5;  
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage/2+random(damage/2), me);
			target->start_busy(1+random(2));   // target busy time > own busy time
			me->start_busy(2+random(2));
			if(jiali > me->query("neili")) jiali = me->query("neili");
			if(jiajin > me->query("jingli")) jiajin = me->query("jingli")-1;
            
			me->add("neili", -jiali-lvl);      // cost neili 140
			me->add("jingli", -jiajin-lvl/2);  // cost jingli 120

			limbs = target->query("limbs");

			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);

			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
        
		} else {
			message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
			me->start_busy(1+random(3));
		}

			if(me->query_temp("memory")) me->set_skill("huoyan-dao",me->query_temp("memory",1));
			else me->delete_skill("huoyan-dao");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");
	} else {


		int damage, skill, me_exp, tt_exp;

		if(me->query_skill("dashou-yin")) {
			me->set_temp("memory",me->query_skill("dashou-yin",1));
			me->set_skill("dashou-yin", dk/2+me->query_skill("dashou-yin",1)/2);
		} else me->set_skill("dashou-yin", dk);
		me->map_skill("hand", "dashou-yin");
		me->prepare_skill("hand", "dashou-yin");

		damage = me->query_skill("hand")+me->query_skill("force")+random(me->query("jiajin")+me->query("jiali"))*4;
		skill = me->query_skill("dashou-yin",1);
		me_exp = me->query("combat_exp",1)/1000;
		tt_exp = target->query("combat_exp",1)/1000;

		message_vision(HIM"\n$N双手合十，矮身抢向$n" + side[random(3)] + "，突然两手并起，以手化掌！\n$N巨掌起处劲从臂发，一股劲风猛然扑向$n" + place[random(7)] + "，正是密宗绝学“大手印”！\n"NOR,me,target);

		if( target->query_skill("poison") && tt_exp + target->query_skill("poison",1) > me_exp + skill)
		{
			message_vision(HIR"\n$N力道刚施上，忽然身不由主的跳起，\n犹似捏上一块烧得通红的钢块，手掌只烧得火辣辣地疼痛，放手不迭。\n\n"NOR,me,target);

			me->receive_damage("qi", skill*2, me);
			me->receive_wound("qi", skill, me);
			COMBAT_D->report_status(me);
		}
		else if( target->query_skill("strike"))
		{
			message_vision(HIY"\n$n也是运力于掌，要以数十年修习的内功相抵。\n"NOR,me,target);

			if((me->query("max_neili")+me->query_skill("force"))*2/3 > random(target->query("max_neili")+target->query_skill("force")))
			{
				message_vision(HIB"\n两股劲风刚触到，$n内劲相差太远，一声惨叫，被$N震得筋折骨断，五脏碎裂。\n\n"NOR,me,target);
				damage = damage*3/2;
				target->receive_damage("qi", damage+random(damage), target);
				target->receive_wound("qi", damage/2+random(damage/2), target);
				COMBAT_D->report_status(target);
			}
			else if( me->query("max_neili")+me->query_skill("force") > random(target->query("max_neili")+target->query_skill("force")))
			{
				message_vision(HIB"\n两股劲风刚触到，$n内劲稍有不及，闷哼一声，被$N震得静脉逆转，血气翻涌。\n\n"NOR,me,target);

				target->receive_damage("qi", damage+random(damage), target);
				target->receive_wound("qi", damage/2+random(damage/2), target);
				COMBAT_D->report_status(target);
			}
			else if( me->query_int() >= target->query_int() )
			{
				message_vision(HIM"\n两股劲风刚触到，$N突变内力为外功，右掌斗然探出，力捏$n的手掌，\n"NOR,me,target);

				if( me->query_skill("hand") > random(target->query_skill("dodge") ))
				{
					message_vision(HIB"\n这一下迅捷之至，$n变招不灵，手掌骨骼咯咯作响，险些被$N掐碎。\n\n"NOR,me,target);
					damage = damage*2/3;
					target->receive_damage("qi", damage+random(damage), target);
					target->receive_wound("qi", damage/2+random(damage/2), target);
					COMBAT_D->report_status(target);
				}
				else
				{
					message_vision(HIG"\n这一下迅捷之至，$n变招却也甚是灵动，反手勾腕，强对强，硬碰硬，两人手腕一搭上，立即分开。\n"NOR,me,target);
				}
			}

			else if( (me->query("max_neili") + me->query_skill("force") )*3/2 > random(target->query("max_neili") + target->query_skill("force") ))
			{
				message_vision(HIR"\n两股劲风刚触到，$N内劲稍有不及，闷哼一声，被$n震得静脉逆转，血气翻涌。\n\n"NOR,me,target);
				damage = damage*2/3;
				me->receive_damage("qi", random(damage*2), me);
				me->receive_wound("qi", random(damage), me);
				COMBAT_D->report_status(me);
			}
			else
			{
				message_vision(HIR"\n两股劲风刚触到，$N内劲相差太远，一声惨叫，被$n震得筋折骨断，五脏碎裂。\n\n"NOR,me,target);
				me->receive_damage("qi", random(damage*2), me);
				me->receive_wound("qi", random(damage), me);
				COMBAT_D->report_status(me);
			}
		}
		else if( (me_exp + me->query_skill("hand"))*2/3 > random(tt_exp + target->query_skill("dodge") ))
		{
			message_vision(HIB"\n$n一声惨叫，被$N震得筋折骨断，五脏碎裂。\n\n"NOR,me,target);
			damage = damage*3/2;
			target->receive_damage("qi", damage+random(damage), target);
			target->receive_wound("qi", damage/2+random(damage/2), target);
			COMBAT_D->report_status(target);
		}
		else if( me_exp + me->query_skill("hand") > random(tt_exp + target->query_skill("dodge") ))
		{
			message_vision(HIB"\n$n闷哼一声，被$N震得静脉逆转，血气翻涌。\n\n"NOR,me,target);

			target->receive_damage("qi", damage+random(damage), target);
			target->receive_wound("qi", damage/2+random(damage/2), target);
			COMBAT_D->report_status(target);
		}
		else if( (me_exp + me->query_skill("hand"))*3/2 > random(tt_exp + target->query_skill("dodge") ))
		{
			message_vision(HIB"\n$n轻哼一声，被$N震得连退几步，内息不畅。\n\n"NOR,me,target);
			damage = damage*2/3;
			target->receive_damage("qi", damage+random(damage), target);
			target->receive_wound("qi", damage/2+random(damage/2), target);
			COMBAT_D->report_status(target);
		}
		else
		{
			message_vision(HIG"\n$n冷哼一声，双足一点跳了开去。\n"NOR,me,target);
		}

		if( wizardp(me) ) tell_object(me,"damage "+damage+"\n");

		me->add("neili",-skill);
		me->add("jingli",-skill/2);
		me->start_busy(2+random(2));
		target->start_busy(random(2));

			if(me->query_temp("memory")) me->set_skill("dashou-yin",me->query_temp("memory",1));
			else me->delete_skill("dashou-yin");
			me->delete_temp("memory");
			me->prepare_skill("hand");
			me->map_skill("hand");
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}