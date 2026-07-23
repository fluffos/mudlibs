//gaibang lt+3h+xl,3h app 1
//liu 2002

#include <ansi.h>
#include <armor.h>
#include <combat.h>

int sanhui(object me, object target);

void remove_effect(object me);
void remove_effect2(object me, object target, int lvl);
void msg_display(object me, object target, int lvl);

int gaibang(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 0 )
	{
		string weapon;
		int skill, enfor, amount;
		enfor = me->query("jiali");
		skill = me->query_skill("force");
		amount = skill/3;
		message_vision(HIR "\n$N仰天大喝，双手立刃雷霆般地对着$n劈出，掌风卷动无数飞砂走石，天地为之变色！\n" NOR, me, target);

		me->add_temp("apply/attack", amount);
		me->add_temp("apply/strike", amount/3);
		me->add_temp("apply/damage", amount);

		if(me->query_skill("xianglong-zhang")) {
			me->set_temp("memory",me->query_skill("xianglong-zhang",1));
			me->set_skill("xianglong-zhang", dk/2+me->query_skill("xianglong-zhang",1)/2);
		} else me->set_skill("xianglong-zhang", dk);
		me->map_skill("strike", "xianglong-zhang");
		me->prepare_skill("strike", "xianglong-zhang");

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		me->add("neili", -amount*3);
		me->add("jingli", -amount);

		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/strike", -amount/3);

		if(me->query_temp("memory")) me->set_skill("xianglong-zhang",me->query_temp("memory",1));
		else me->delete_skill("xianglong-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		me->start_busy(1+random(2));

	} else if( random(2)==1) {

        	message_vision( HIR"\n$N深吸一口气，挫步沉肩，看来要出猛招了！\n"NOR, me);

        	me->add("neili", -100);
        	me->add("jingli", -100);
        	me->set_temp("sanhui", 1);

		me->apply_condition("tong",1);

        	me->start_busy(1);
        	call_out("sanhui", 1, me, target);
		return 1;

	} else {

		object armor;
		int jiali, jiajin, lvl, my_exp;
	
		my_exp = me->query("combat_exp");

		me->set_temp("xianglong",1);
		message_vision(HIR "$N气聚丹田，双掌自外向里转了个圆圈，缓缓的凝聚全身功力。\n\n" NOR, me,target);
		lvl = (int)(lvl / 5);
		me->add("neili", -lvl*2); 
		me->add("jingli", -100);  
		jiali = me->query("jiali");
		jiajin = me->query("jiajin");
		me->add_temp("apply/parry", lvl );
		me->start_busy(2+random(2));

		//call_out("msg_display",1+(int)((me->query_skill("strike")-300)/50),me,target,lvl);
  		call_out("msg_display",1+random(1),me,target,lvl);
		return 1;
	}

	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}

int sanhui(object me, object target)
{
        int enfor, skill, amount;
	int dk = me->query_skill("douzhuan-xingyi",1);

        if ( !living(me) || me->is_ghost() || environment(me) != environment(target) )
        {
                remove_effect(me);
                return 1;
        }
        else if ( !living(target) || !me->is_fighting(target) )
        {
                message_vision(CYN"\n$N当即收回右掌，左掌在身前画了个圆圈。\n"NOR,me);
                remove_effect(me);
                return 1;
        }
        else if ( (int)me->query("neili", 1) < 500 )
        {
                tell_object(me, HIR"你待要再发一掌，却发现自己的内力不够了！\n"NOR);     
                remove_effect(me);
                return 1;
        }
        else
        {
                skill = me->query_skill("force");
                enfor = me->query("jiali");

                me->set_temp("sanhui_busy", (int)me->query_temp("sanhui"));

                switch ( me->query_temp("sanhui") )
                {
                        case 1:
                                amount = skill/2;
                                me->set("jiali", (int)(enfor+enfor/3));
                                break;
                        case 2:
                                amount = skill/3;
                                me->set("jiali", (int)(enfor+enfor/2));
                                break;
                        case 3:
                                amount = skill/4;
                                me->set("jiali", enfor*2);
                                break;
                }

		if(me->query_skill("xianglong-zhang")) {
			me->set_temp("memory",me->query_skill("xianglong-zhang",1));
			me->set_skill("xianglong-zhang", dk/2+me->query_skill("xianglong-zhang",1)/2);
		} else me->set_skill("xianglong-zhang", dk);
		me->map_skill("strike", "xianglong-zhang");
		me->prepare_skill("strike", "xianglong-zhang");

                me->add_temp("apply/attack", amount);
                me->add_temp("apply/damage", amount);
                me->add_temp("apply/strike", amount/3);

                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));

                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/damage", -amount);
                me->add_temp("apply/strike", -amount/3);
                me->set("jiali", enfor);

		if(me->query_temp("memory")) me->set_skill("xianglong-zhang",me->query_temp("memory",1));
		else me->delete_skill("xianglong-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

                if ( !me->query_temp("sanhui") || me->query_temp("sanhui") == 3 )
                        remove_effect(me);
                else
                {
                        me->add_temp("sanhui", 1);
                        sanhui(me, target);
                }
        }

        return 1;
}

void remove_effect(object me)
{
        int sanhui_busy = me->query_temp("sanhui_busy");

        int amount = (int)(450 - me->query_skill("force")) / 2;
        if ( amount < 6 ) amount = 6;

        if ( sanhui_busy == 3 )
                message_vision(RED"\n$N三掌击出，大耗真气，不得不转攻为守，稍事调息。\n"NOR,me);

        if ( me->query_temp("sanhui") )
                me->delete_temp("sanhui");

        me->add("neili", -100 * sanhui_busy);

        me->start_busy(sanhui_busy + random(2));
	me->delete_temp("tong");
	me->delete_temp("sanhui_busy");
}

void msg_display(object me, object target, int lvl)
{
	string *circle, msg;

	if( !target || !me->is_fighting(target)
	|| !living(me) || me->is_ghost() 
	|| environment(me) != environment(target) || !me->is_fighting() )
	{
		me->delete_temp("xianglong");
		me->delete_temp("tong");
		tell_object(me,"不待发招对手已经无法战斗，你只好收回内劲。\n");
		return;
	}

        circle = ({
                "$N突然大喝一声，双掌齐出，向$p当胸猛击过去。\n",
                "$N大步迈出，左手一划，右手呼的一掌，猛向$p击去。\n"
        });

        msg = HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        circle = ({
                "掌力未到，$p已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至。",
                "只一瞬之间，$p便觉气息窒滞，$N掌力竟如怒潮狂涌，势不可当，又如是一堵无形的高墙，向$p身前疾冲。"
        });

        msg = msg + HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        if( target &&  target->is_character() && me->is_fighting(target) )
	{
        	message_vision(msg, me, target);
        	call_out("remove_effect2",1,me,target,lvl);
        } else {
		me->delete_temp("xianglong");
		me->delete_temp("tong");
		me->add_temp("apply/parry",-lvl);
	}
        return 0;
}

void remove_effect2(object me, object target, int lvl)
{
	int jiali, jiajin, ap, dp, pp,dmg,damage;
	object weapon;
	string *limbs, limb, result, str, type;

	int dk = me->query_skill("douzhuan-xingyi",1);

		if(me->query_skill("xianglong-zhang")) {
			me->set_temp("memory",me->query_skill("xianglong-zhang",1));
			me->set_skill("xianglong-zhang", dk/2+me->query_skill("xianglong-zhang",1)/2);
		} else me->set_skill("xianglong-zhang", dk);
		me->map_skill("strike", "xianglong-zhang");
		me->prepare_skill("strike", "xianglong-zhang");

	weapon=target->query_temp("weapon");
        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        type = "内伤";

        if (wizardp(me)) printf("ap = %d , pp = %d , dp = %d , me->query_temp(apply/parry) = %d , lvl = %d .\n",ap*2,pp,dp,me->query_temp("apply/parry"),lvl);

        if( target && target->is_character() && me->is_fighting(target) )
	{
        	if( ap > random((dp+pp)*(1-(me->query_skill("strike")/1000))/2) ) {
            		message_vision(HIM"$N的双掌已跟着击到，砰的一声呼，重重打中$p胸口，跟着喀喇喇几声，肋骨断了几根。\n"NOR, me, target);
            		dmg = (int)(((me->query_skill("strike")-300)/50)+1) * 1000 + me->query("jiali")*2 + me->query("jiajin")*2;

            		target->receive_damage("qi", dmg,  me);
            		target->receive_wound("qi", dmg/2+random(dmg/2), me);
            		target->start_busy(1+random(2));
	
            		if(jiali > me->query("neili")) jiali = me->query("neili");
			if(jiajin > me->query("jingli")) jiajin = me->query("jingli")-1;
            
			me->add("neili", -jiali-lvl);
			me->add("jingli", -jiajin-lvl/2);

			limbs = target->query("limbs");

			result = COMBAT_D->damage_msg(dmg, type);
			result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
			result = replace_string( result, "$p", target->name() );
			message_vision(result, me, target);

			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
		} else {
			if ( objectp(weapon) )
			{
				message_vision(HIC "$n大惊之下，$p连划三个半圆护住身前，同时足尖着力，飘身后退，避开了$N的一掌。\n" NOR, me, target, weapon);
			} else {
				message_vision(HIC "$n大惊之下，双掌连划三个半圆护住身前，同时足尖着力，飘身后退，避开了$N的一掌。\n" NOR, me, target);
			}
        	}
        }
        me->delete_temp("xianglong");
	me->delete_temp("tong");
	me->add_temp("apply/parry",-lvl);


		if(me->query_temp("memory")) me->set_skill("xianglong-zhang",me->query_temp("memory",1));
		else me->delete_skill("xianglong-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

        return 0;
}
