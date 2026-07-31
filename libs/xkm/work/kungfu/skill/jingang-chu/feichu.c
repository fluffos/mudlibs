//feichu.c 金刚降魔杵飞掷金杵之技
//Xuanyuan
/*
    说话之间，台上达尔巴和霍都斗得更加狠了。两人一师所传，互知对方武功家
数，达尔巴胜在力大招沉，霍都长于矫捷轻灵，看看又斗数百招，兀自不分胜败。
突然之间，达尔巴大喝一声，金杵脱手，疾向霍都掷去，这杵重达五十余斤，一掷
之下势道凌厉之极。霍都吃了一惊，他生平从未见师兄使这般招数，心道：“他久
斗不胜，发起蛮来了？”急忙侧身闪避。达尔巴抢上前去，手掌在金杵上一撞，金
杵转过方向，又向霍都追击过去。霍都大骇，才知道十余年中师兄追随师父左右，
师父又传了他深湛武功，这飞掷金杵之技正是从师父五轮飞砸的功夫中变化出来，
眼见金杵撞来的力道太猛，决不能以铁扇招架，只得滑步斜身躲过，金杵从他头顶
横掠而过，相差不逾两寸。

    达尔巴金杵越掷越快，高台四周插着的火把被疾风所激，随着忽明忽暗。霍都
在杵影中跳荡闪避，往往间不容发。台下群雄屏息以观，瞧着这般险恶的情势，无
不骇然。达尔巴掷到第十八下，猛喝一声，双掌推杵，金杵如飞箭般平射而出。霍
都再也无法闪避，砰和一声，金杵正撞胸口。他身子软软垂下。横卧台下，一动也
不动了。
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object weapon);
private int super_attack(object me, object target, object weapon);
private int remove_attack(object me, object weapon);
int perform(object me, object target)
{
	object weapon;
	int skill, damage;
	string *limb, type, result, str;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("飞掷金杵之技只能对战斗中的对手使用。\n");

	if( me->query_temp("fengmo") )
                return notify_fail("你已在使用飞掷金杵之技了！\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("你手中无杵，如何能够施展飞掷金杵之技？\n");

	if( me->query_skill_mapped("force") != "longxiang-banruo" )
                return notify_fail("你所用的并非龙象般若功，无法配合杖法施展飞掷金杵之技！\n");

        if( me->query_skill("force") < 120 )
                return notify_fail("你的龙象般若功火候未到，无法配合杖法施展飞掷金杵之技！\n");

	if( me->query_skill("staff") < 120 )
		return notify_fail("你金刚降魔杵修为不足，还不会使用飞掷金杵之技！\n");

	if( me->query("neili") <= 800 )
		return notify_fail("你的内力不够施展飞掷金杵之技！\n");
	if( me->query("jingli") <= 500 )
		return notify_fail("你的精力不够施展飞掷金杵之技！\n");

 	skill = me->query_skill("staff");

	message_vision(HIR "\n突然之间，$N大喝一声，"+weapon->name()+HIR"脱手，疾向$n掷去，这"+weapon->name()+HIR"本就十分沉重，一掷之下势道凌厉之极！\n\n" NOR, me, target);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3){
		if( random( target->query_skill("dodge") + target->query_skill("parry") ) < random((me->query_skill("staff") + me->query_skill("jingang-chu"))*2/3) ){
			damage = random(((int)me->query_skill("jingang-chu"))+me->query("jiali"))*( 100 + random(me->query("jiajin")) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 1000) damage = 1000;
			me->add("neili", -me->query("jiali"));
			me->add("jingli", -me->query("jiajin"));
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2), me);

                       message_vision( HIR "\n$N无法闪避，砰 的一声，"+weapon->name()+HIR"正撞胸口。他身子软软垂下，萎靡在地。\n\n"NOR,target,me);
			COMBAT_D->report_status(target);
		}else{
			damage = random(((int)me->query_skill("jingang-chu"))+me->query("jiali"))*( 1 + random(me->query("jiajin")) ) ;
			if(damage > 1500) damage = 1500;
			if(damage < 300) damage = 300;
			me->add("neili", -me->query("jiali"));
			me->add("jingli", -me->query("jiajin"));
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);

			limb = target->query("limbs");
			type = "挫伤";
			message_vision(HIR"\n只听$N一声惨叫，"+weapon->name()+HIR"正中$N"+limb[random(sizeof(limb))]+"，结果$P闷哼一声跌了个跟头。\n\n"NOR,target);
			COMBAT_D->report_status(target);
			}
	message_vision(HIY "\n$N纵身上前，接住了飞旋的"+weapon->name()+HIY"。\n\n" NOR, me, weapon);
	me->add("neili", -300);
	me->add("jingli", -100);
	me->start_busy(2+random(3));
		return 1;
	}

	message_vision( HIG"\n$N生平从未见这般招数，心道：“"+me->name()+HIG"久斗不胜，发起蛮来了？”急忙侧身闪避。\n" NOR,  target, me);
	message_vision(HIR "\n$N大呼酣战，双手在"+weapon->name()+HIR"上一推，"+weapon->name()+HIR"仍在空中高低左右回旋！\n\n" NOR, me, target);
	me->set_temp("feichu", 1);
	me->set_temp("location", file_name(environment(me)));
	me->add("neili", -200);
	me->add("jingli", -100);
	weapon->unequip();
   weapon->move("/u/program/workroom");
	weapon->set("no_clean_up", 1);
	me->reset_action();
	call_out("check_fight", 1, me, target, weapon);

	return 1;
}

void check_fight(object me, object target, object weapon)
{
	string *limbs, limb, result, str, type;
	int damage;

	me->reset_action();

	if ( me->is_fighting() && me->query_temp("feichu") >= 6 ) {
	   call_out("super_attack", 1, me, target, weapon);
	}else
	if ( me->query_temp("feichu") >= (int)me->query_skill("jingang-chu", 1)/30 ) {
	   call_out("remove_attack", 1, me, weapon);
	}
	else if ( me->is_fighting() && me->query_temp("feichu") ) {
	limbs = target->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	type = "挫伤";

	   message_vision(HIR "\n突然间"+weapon->name()+HIR"自行向$N的"+limb+"猛然追击过去！\n" NOR, target, weapon);

	   if ( random(me->query("combat_exp")) > target->query("combat_exp")/2 ) {

	   damage = me->query("str")*2 +random(me->query_skill("jingang-chu", 1));
	   target->receive_damage("qi", damage, me);
	   target->receive_wound("qi", random(damage/2), me);
       result = COMBAT_D->damage_msg(damage, type);
	   result = replace_string( result, "$l", limb);
	   str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));

	   message_vision(result, me, target);
	   message_vision("($N"+str+")\n", target);
	   me->add("neili", -30);
	   }
	   else {
		message_vision(HIY "$N看得分明，身形一让，避过了"+weapon->name()+HIR"！\n" NOR, target, weapon);
	   }
	   message_vision(HIR "\n$N抢上前去，手掌在"+weapon->name()+HIR"上一撞，"+weapon->name()+HIR"转过方向，在半空飞旋。\n\n" NOR, me, weapon);


	   me->add_temp("feichu", 1);
	   call_out("check_fight", 1, me, target, weapon);
	}
	else {
	   call_out("remove_attack", 1, me, weapon);
	  
	}
}		
int super_attack(object me, object target, object weapon)
{
	int damage;
	string *limb, type, result, str;

	remove_call_out("check_fight");
	me->delete_temp("feichu");

	message_vision( RED"\n$N掷到第六下，又是暴喝一声，双掌加力猛推"+weapon->name()+RED"，"+weapon->name()+RED"如飞箭般平射而出。\n"NOR,me,target);

	if ( file_name(environment(me)) == me->query_temp("location") && living(me) ) {
		if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3){
		if( ( random( target->query_skill("dodge") ) >  (int)me->query_skill("jingang-chu")*2/3 && random(5) == 1) ){
			message_vision(HIR"\n$N用力过猛，控制不住"+weapon->name()+"走势，“哎哟”一声，"+weapon->name()+"砸在了自己小腿上。\n\n"NOR, me );
			me->receive_damage("qi", 30+random(50),  me);
			me->start_busy(1+random(3));
			str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
			message_vision("($N"+str+")\n", me);
			weapon->move(me->query_temp("location"));
			message("vision", "只听得锵的一声，"+weapon->name()+"力尽由半空跌落。\n", environment(weapon), ({weapon}) );
			me->delete_temp("location");
			return 1;
		}else if( random( target->query_skill("dodge") + target->query_skill("parry") ) < random((me->query_skill("staff") + me->query_skill("jingang-chu"))*2/3) ){
			damage = random(((int)me->query_skill("jingang-chu"))+me->query("jiali"))*( 100 + random(me->query("jiajin")) ) ;
			if(damage > 3000) damage = 3000;
			if(damage < 1000) damage = 1000;
			me->add("neili", -me->query("jiali"));
			me->add("jingli", -me->query("jiajin"));
			me->start_busy(1+random(2));
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2), me);

			message_vision( HIR "\n$N再也无法闪避，砰和一声，"+weapon->name()+HIR"正撞胸口。他身子软软垂下。跌倒在地，一动也不动了。\n\n"NOR,target,me);
			COMBAT_D->report_status(target);
		}
		else
		{
			damage = random(((int)me->query_skill("jingang-chu"))+me->query("jiali"))*( 1 + random(me->query("jiajin")) ) ;
			if(damage > 1500) damage = 1500;
			if(damage < 300) damage = 300;
			me->add("neili", -me->query("jiali"));
			me->add("jingli", -me->query("jiajin"));
			me->start_busy(1+random(2));
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);

			limb = target->query("limbs");
			type = "挫伤";
			message_vision(HIR"\n只听$N一声惨叫，"+weapon->name()+HIR"正中$N"+limb[random(sizeof(limb))]+"，结果$P闷哼一声跌了个跟头。\n\n"NOR,target);
			COMBAT_D->report_status(target);
			}
		weapon->move(me);
		weapon->set("no_clean_up", 0);
		weapon->wield();
		message_vision(HIY "\n$N纵身上前，将飞旋的"+weapon->name()+HIY"收回。\n\n" NOR, me, weapon);
		me->delete_temp("location");
		return 1;
		}
			message_vision( HIG"\n$N眼见"+weapon->name()+HIG"撞来的力道太猛，决不能招架，只得滑步斜身躲过，"+weapon->name()+HIG"从$N头顶横掠而过，相差不逾两寸。\n" NOR,  target);
			weapon->move(me->query_temp("location"));
			message("vision", "只听得锵的一声，"+weapon->name()+"力尽由半空跌落。\n", environment(weapon), ({weapon}) );
			me->start_busy(2+random(3));
		}
	me->delete_temp("location");

	return 1;
}

int remove_attack(object me, object weapon)
{
	remove_call_out("check_fight");
	me->delete_temp("feichu");
	
	if ( file_name(environment(me)) == me->query_temp("location") && living(me) ) {
		weapon->move(me);
		weapon->set("no_clean_up", 0);
		weapon->wield();
		message_vision(HIY "\n$N纵身上前，将飞旋的"+weapon->name()+HIY"收回。\n\n" NOR, me, weapon);
	}
	else {
		weapon->move(me->query_temp("location"));
		message("vision", "只听得锵的一声，"+weapon->name()+"力尽由半空跌落。\n", environment(weapon), ({weapon}) );
	}
	me->delete_temp("location");

	return 1;
}
