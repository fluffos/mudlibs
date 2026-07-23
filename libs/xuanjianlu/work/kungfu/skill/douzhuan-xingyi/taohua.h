//xueshan
//liu 2002

#include <ansi.h>
#include <armor.h>
#include <combat.h>

string* place = ({"太阳穴","面门","前胸","左肩","右肩","小腹","天灵盖"});
string* side = ({"左侧","右侧","身后"});

int taohua(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(4) == 1 )
	{

		int strike, extra, kick, power;
		string weapon;

		if(me->query_skill("luoying-shenjian")) {
			me->set_temp("memory",me->query_skill("luoying-shenjian",1));
			me->set_skill("luoying-shenjian", dk/2+me->query_skill("luoying-shenjian",1)/2);
		} else me->set_skill("luoying-shenjian", dk);
		me->map_skill("strike", "luoying-shenjian");
		me->prepare_skill("strike", "luoying-shenjian");

		if(me->query_skill("xuanfeng-saoye")) {
			me->set_temp("memory2",me->query_skill("xuanfeng-saoye",1));
			me->set_skill("xuanfeng-saoye", dk/2+me->query_skill("xuanfeng-saoye",1)/2);
		} else me->set_skill("xuanfeng-saoye", dk);
		me->map_skill("kick", "xuanfeng-saoye");
		me->prepare_skill("kick", "xuanfeng-saoye");

		message_vision(HIG "$N一声长啸，脸上青气大盛，欺近$n身去，三招落英神剑掌后紧接着三招旋风扫叶腿！\n出手快捷无伦，如同天风海雨般向$n袭来，正是桃花岛的狂风绝技。" NOR, me, target);

		strike = me->query_skill("strike")/6;
		kick = me->query_skill("kick")/6;
		power = strike + kick;
		extra = (power*3/2 + random(power*2))/2;

		if(extra > 300 ) extra =300;

		me->add_temp("apply/attack", extra);
		me->add_temp("apply/speed", extra);
		me->add_temp("apply/damage", extra);

		me->prepare_skill("kick");

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		me->prepare_skill("strike");

		me->prepare_skill("kick" , "xuanfeng-saoye");

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		me->add("neili", -100-random(power*3));
		me->add("jingli", -50-random(power*3));

		me->prepare_skill("strike", "luoying-shenjian");

		me->start_busy(1 + random(2));


		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/speed", -extra);
		me->add_temp("apply/damage", -extra);

		if(me->query_temp("memory")) me->set_skill("luoying-shenjian",me->query_temp("memory",1));
		else me->delete_skill("luoying-shenjian");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		if(me->query_temp("memory2")) me->set_skill("xuanfeng-saoye",me->query_temp("memory2",1));
		else me->delete_skill("xuanfeng-saoye");
		me->delete_temp("memory2");
		me->prepare_skill("kick");
		me->map_skill("kick");

	} else if (random(4)==2){

		string *limb, type, result;
		int skill,jiajin,jiali,damage;

		skill=me->query_skill("douzhuan-xingyi",1);

		jiali = me->query("jiali",1);
		jiajin= me->query("jiajin",1);
		damage = me->query_skill("force")*2+random(jiali+jiajin)*5;
		type="瘀伤";
		limb = target->query("limbs");

		message_vision(HIR "\n$N计由心生一个踉跄，向后倒退，静待$n乘势进逼，斗然间飞起左腿，足心朝天，踢向$n心口。\n\n" NOR, me, target);
		message_vision(HIM "此招正是桃花绝技“怀心腿”，出腿如电，极为刚猛。\n\n" NOR, me, target);

		if ( me->query("combat_exp",1)/1000 + me->query_skill("force") + me->query_int() > target->query("combat_exp",1)/1000 + target->query_skill("dodge") + target->query_skill("parry") + target->query_int())
		{
			message_vision(HIB"$n想不到$N落败之余，尚能出此绝招，待得伸手去格，胸口已被踢中。\n\n"NOR,me,target);

			target->receive_wound("qi", damage, me);
			target->receive_damage("qi", damage+random(damage), me);
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);
			COMBAT_D->report_status(target);
		}
		else if (target->query_temp("taohua_huaixin"))
		{
			message_vision(HIG"$n刚见$N用过此招，当然早有防备，冷哼一声，侧身躲开。\n\n"NOR,me,target);
		}
		else
		{
			message_vision(HIB"$n想不到$N落败之余，尚能出此绝招，待得伸手去格，胸口已被踢中。\n\n"NOR,me,target);

			target->receive_wound("qi", damage, me);
			target->receive_damage("qi", damage+random(damage), me);
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);
			COMBAT_D->report_status(target);
		}
		if( wizardp(me) ) tell_object(me,"damage "+damage+"\n");
		target->set_temp("taohua_huaixin",1);
		me->add("neili", -(skill*2+jiali));
		me->add("jingli", -(skill+jiajin));
		me->start_busy(1+random(2));


	} else if (me->query("gender")=="女性" && random(4) == 3) {

		object weapon;
		int speed, damage, hand;

		weapon = me->query_temp("weapon");

		if(me->query_skill("luoying-shenjian")) {
			me->set_temp("memory",me->query_skill("luoying-shenjian",1));
			me->set_skill("luoying-shenjian", dk/2+me->query_skill("luoying-shenjian",1)/2);
		} else me->set_skill("luoying-shenjian", dk);
		me->map_skill("strike", "luoying-shenjian");
		me->prepare_skill("strike", "luoying-shenjian");

		if(me->query_skill("lanhua-fuxue")) {
			me->set_temp("memory2",me->query_skill("lanhua-fuxue",1));
			me->set_skill("lanhua-fuxue", dk/2+me->query_skill("lanhua-fuxue",1)/2);
		} else me->set_skill("lanhua-fuxue", dk);
		me->map_skill("hand", "lanhua-fuxue");
		me->prepare_skill("hand", "lanhua-fuxue");

		damage = (me->query_skill("lanhua-fuxue",1) + me->query_skill("luoying-shenjian",1))/6;
		hand = (me->query_skill("hand",1)+me->query_skill("strike",1) )/6;
		speed = (me->query_skill("hand",1)+me->query_skill("strike",1) )/200;
		me->add("neili", -80);
		me->add("jingli", -80);

	
		//命中率增加
		me->add_temp("apply/speed", speed);
		me->add_temp("apply/attack", damage);
		me->add_temp("apply/damage", damage/2);

		message_vision(HIY"\n$N突然变招，使出「落英神剑掌」来，掌影飘忽於四方八面，或五虚一实，或八虚一实，真如桃林中狂风忽起、万花齐落一般，妙在姿态飘逸，宛若翩翩起舞。\n"NOR, me,target);

		if(me->is_fighting(target) ) {
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}

		message_vision(HIC"\n但见$N指化为掌，掌化为指，「落英神剑掌」与「兰花拂穴手」交互为用，当真是掌来时如落英缤纷，指拂处若春兰葳蕤，不但招招凌厉，而且丰姿端丽。\n"NOR, me,target);

		if(me->is_fighting(target) ) {
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}
		me->add_temp("apply/speed", -speed);
		me->add_temp("apply/attack", -damage);
		me->add_temp("apply/damage", -damage/2);
		me->start_busy(1+random(1));

		if(me->query_temp("memory")) me->set_skill("luoying-shenjian",me->query_temp("memory",1));
		else me->delete_skill("luoying-shenjian");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		if(me->query_temp("memory2")) me->set_skill("lanhua-fuxue",me->query_temp("memory2",1));
		else me->delete_skill("lanhua-fuxue");
		me->delete_temp("memory2");
		me->prepare_skill("hand");
		me->map_skill("hand");

	} else {

		object weapon;
		string *limb, type, result;
		int skill,max_skill,jiajin,max_jiajin,jiali,max_jiali,damage,exp1,exp2;

		if(me->query_skill("luoying-shenjian")) {
			me->set_temp("memory",me->query_skill("luoying-shenjian",1));
			me->set_skill("luoying-shenjian", dk/2+me->query_skill("luoying-shenjian",1)/2);
		} else me->set_skill("luoying-shenjian", dk);
		me->map_skill("strike", "luoying-shenjian");
		me->prepare_skill("strike", "luoying-shenjian");

		skill=me->query_skill("luoying-shenjian",1);

		jiali = me->query("jiali",1);
		jiajin= me->query("jiajin",1);
		damage = me->query_skill("force")+me->query_skill("strike")+random(jiali+jiajin)*3;
		max_skill=pow(me->query("combat_exp")*10,0.33333)+1;
		max_jiali=me->query_skill("force")/2;
		max_jiajin = me->query("max_jingli")/20;
		type="内伤";
		limb = target->query("limbs");
		exp1=me->query("combat_exp",1)/1000;
		exp2=target->query("combat_exp",1)/1000;

		if (skill<max_skill*2/3)
		{
			message_vision(HIB"\n斗然间$N刷刷两掌，掌势如波，正是“碧波掌”中起手的两招，只不过掌法笨拙，殊无半分此招中必不可缺的灵动之致！\n"NOR,me,target);

			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		} else if (!jiali || !jiajin || jiali<max_jiali/2 || jiajin<max_jiajin/2 ) {
			message_vision(HIY"\n斗然间$N刷刷两掌，掌势如波，正是“碧波掌”中起手的两招，只不过内劲不足，虽不乏此招灵动之致，却不济骇人声势！\n"NOR,me,target);

			me->add_temp("apply/speed", skill);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->add_temp("apply/speed", -skill);
		} else {
			message_vision(HIG"\n斗然间$N刷刷两掌，掌势如波，正是“碧波掌”中起手的两招，掌法、内劲具精，已然将此招中灵动之意发挥得淋漓尽致，声势骇人！\n"NOR,me,target);

			me->add_temp("apply/attack", skill);
			me->add_temp("apply/speed", skill);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->add_temp("apply/attack", -skill);
			me->add_temp("apply/speed", -skill);
		}

		if (skill<max_skill*2/3)
		{
			message_vision(HIY"\n突然间$N手臂疾缩，反手便是一掌，掌势如波，正是桃花岛绝学“碧波掌”，$N所学虽然不精，这掌法却甚奥妙。\n\n"NOR,me, target);
		} else if (!jiali || !jiajin || jiali<max_jiali/2 || jiajin<max_jiajin/2 ) {
			message_vision(HIG"\n突然间$N手臂疾缩，反手便是一掌，掌势如波，正是桃花岛绝学“碧波掌”，$N所学虽然精劲，不过出手稍显绵延之意。\n\n"NOR,me, target);
		} else {
			message_vision(HIM"\n突然间$N手臂疾缩，反手便是一掌，掌势如波，正是桃花岛绝学“碧波掌”，$N所学精劲，出手却也毫不留情。\n\n"NOR,me, target);
		}

		if (exp1+me->query_int()+me->query_skill("strike")>exp2+target->query_int()+(target->query_skill("dodge")+target->query_skill("parry"))/2)
		{
			message_vision(HIW"$n没半点防备，拍的一声，结结实实的打在$n"+limb[random(sizeof(limb))]+"之上，落手着实不轻。\n\n"NOR,me, target);

			target->receive_wound("qi", damage, me);
			target->receive_damage("qi", damage+random(damage), me);
			if(!jiali ) type = "瘀伤";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);
		}

		else if (target->query_skill("strike") && target->query("race") == "人类")
		{
			weapon = target->query_temp("weapon");
			if(weapon)
			{
				weapon->unequip();
				weapon->move(environment(target));
				target->reset_action();
			}
			message_vision(HIW"$n也是运力于掌，要以数十年修习的内功相抵，这一下是以硬接硬，刹那之间，已是高手比拼真力。\n"NOR,me,target);

			if( me->query("max_neili")+me->query_skill("force")+me->query("neili") > target->query("max_neili")+target->query_skill("force")+target->query("neili"))
			{
				message_vision(HIB"\n两股劲风刚触到，$n内劲稍有不及，闷哼一声，被$N震得静脉逆转，血气翻涌。\n\n"NOR,me,target);
				target->receive_wound("qi", damage, me);
				target->receive_damage("qi", damage+random(damage), me);
				result = COMBAT_D->damage_msg(damage, type);
				result = replace_string( result, "$l", limb[random(sizeof(limb))]);
				result = replace_string( result, "$p", target->name() );
				message_vision(result, me, target);
			} else {
				message_vision(HIG"\n$n内劲刚猛，$N自知难敌，大喝一声，运足真气，将$n震开。\n\n"NOR,me,target);
			}
		} else if (exp1+me->query_int()+me->query_skill("strike")*4/3>exp2+target->query_int()+(target->query_skill("dodge")+target->query_skill("parry"))/2)
		{
			message_vision(WHT"$n虽有防备，但身法不灵，拍的一声，结结实实的打在$n"+limb[random(sizeof(limb))]+"之上。\n\n"NOR,me, target);

			damage = damage-random(damage/2);
			target->receive_wound("qi", damage, me);
			target->receive_damage("qi", damage+random(damage), me);
			if(!jiali ) type = "瘀伤";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);
		} else {
			message_vision(CYN"$n早有防备，连忙闪身，虽已然躲过，却也吓的冷汗直流。\n\n"NOR,me, target);
			me->add("neili", -(skill+jiali));
			me->add("jingli", -(skill/2+jiajin));
			me->start_busy(1+random(2));

			if(me->query_temp("memory")) me->set_skill("luoying-shenjian",me->query_temp("memory",1));
			else me->delete_skill("luoying-shenjian");
			me->delete_temp("memory");
			me->prepare_skill("strike");
			me->map_skill("strike");

			if(me->query("neili",1)<0) me->set("neili",0);
			me->delete_temp("tong");
			return 1;
		}

		if( wizardp(me) ) tell_object(me,"damage "+damage+"\n");

		COMBAT_D->report_status(target);
		me->add("neili", -(skill+jiali));
		me->add("jingli", -(skill/2+jiajin));
		me->start_busy(2+random(2));

		if(me->query_temp("memory")) me->set_skill("luoying-shenjian",me->query_temp("memory",1));
		else me->delete_skill("luoying-shenjian");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}