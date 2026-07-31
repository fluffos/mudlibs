// heijian-jindao 刀剑齐挥
/*
    公孙谷主大喜，当当当，挥剑砍了三刀，左手刀却同时使了“定阳针”、“虚式分
金”、“荆轲刺秦”、“九品莲台”四招。这四手剑招飘逸流转，四剑夹在三刀之中。杨过
尚能勉力抵御，小龙女却意乱心慌，想挥剑去削他刀锋，但金刀势如飞凤，劈削不到。杨过
情知不妙，拚着自身受伤，使一招全真剑法中的“马蹴落花”，平膀出剑，剑锋上指，将对
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void attack_ob(object me, object target,object weapon,object weapon2);
int perform(object me, object target)
{
	int i;
	object *inv;
	object weapon2;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("刀剑齐挥只能对战斗中的对手使用。\n");

        if( me->query_dex() < 40 )
                return notify_fail("你在身法上先天禀赋不足，不能使用刀剑齐挥！\n");
        
        if( me->query_skill("dodge") < 180 )
                return notify_fail("刀剑齐挥需要超绝的轻功配合，方能有效施展！\n");

        if( me->query_skill("sword") < 180 )
                return notify_fail("你剑法未到炉火纯青之境，还不会使用刀剑齐挥！\n");
        if( me->query_skill("blade") < 180 )
                return notify_fail("你刀法未到炉火纯青之境，还不会使用刀剑齐挥！\n");
        if( me->query_skill("heijian-jindao",1) < 180 )
                return notify_fail("你黑剑金刀未到炉火纯青之境！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用刀剑齐挥！\n");

        if( me->query("jing") <= 500 )
                return notify_fail("你的精不够使用刀剑齐挥！\n");

        if (!weapon)
                return notify_fail("你手中无剑怎能使用刀剑齐挥？！\n");
        if (me->query_temp("heijian-jindao/luanren",1))
                return notify_fail("你正在使用阴阳倒乱刃法无法再刀剑齐挥！\n");

        if ( me->query_skill_mapped("sword") != "heijian-jindao"
          || me->query_skill_mapped("parry") != "heijian-jindao"
          || me->query_skill_mapped("blade") != "heijian-jindao"
          && userp(me))
             	return notify_fail("你必须先将黑剑金刀相互配合。\n");
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }
	if (!objectp(weapon2)) return notify_fail("你只有一种兵器就想刀剑齐挥？\n");
        me->add_temp("apply/attack", me->query_skill("heijian-jindao",1)/10);
        message_vision(HIC"$N大喝一声立时武功招势奇幻无方，刀剑招势逆转，挥剑砍了三刀！\n"NOR, me, target);
	if (!me->query_temp("heijian-jindao/nizhuan",1)) {
		me->set_temp("heijian-jindao/nizhuan",1);
		i=4;
	}
	if (weapon->query("skill_type")=="blade") {
		weapon->unequip();
		weapon2->wield();
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		weapon2->unequip();
		weapon->wield();
	} else if (weapon->query("skill_type")=="sword") {
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
	}
	if (i==4) {
		me->delete_temp("heijian-jindao/nizhuan");
	}
        me->add_temp("apply/attack", -me->query_skill("heijian-jindao",1)/10);
        me->add("neili", -500);
        me->add("jing", -100);
me->start_busy(3);
	call_out("attack_ob",1,me,target,weapon,weapon2);
	me->start_perform(4,"刀剑齐挥");

        return 1;
}
void attack_ob(object me, object target,object weapon,object weapon2)
{
	int i;
	if (!me) return ;
	if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
		return ;
	}
	message_vision(HIR"\n紧接着$N毫不停留左手刀同时使了“定阳针”、“虚式分金”、“荆轲刺秦”、“九品莲台”四招。\n"+
"这四手剑招飘逸流转，四剑夹在三刀之中。\n"+"$n勉力抵御，想挥剑去削他刀锋，但"+
weapon->name()+weapon2->name()+HIR"势如飞凤，劈削不到。\n"NOR,me,target);
	if (!me->query_temp("heijian-jindao/nizhuan",1)) {
		me->set_temp("heijian-jindao/nizhuan",1);
		i=4;
	}
        me->add_temp("apply/attack", me->query_skill("heijian-jindao",1)/6);
	if (weapon->query("skill_type")=="blade") {
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
	} else if (weapon->query("skill_type")=="sword") {
		weapon->unequip();
		weapon2->wield();
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		weapon2->unequip();
		weapon->wield();
	}
        me->add_temp("apply/attack", -me->query_skill("heijian-jindao",1)/6);
	if (i==4) {
		me->delete_temp("heijian-jindao/nizhuan");
	}
}

