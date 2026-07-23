// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob,*inv,target_w;
        string msg, string1;
	int skill, ap, dp, equip;
	int extra;
        int count;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「五轮大法」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("「五轮大法」用的兵器不是这个！\n");
	if((int)me->query_skill("force") < 160 )
		return notify_fail("你的内功等级不够，使不出「五轮大法」绝技。\n");

	if(me->query_skill_mapped("force") != "longxiang")
		return notify_fail("没有龙象般若功作为根基，是无法使出「五轮大法」绝技的！\n"); 
	if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("riyue-lun",1) < 150 )
		return notify_fail("你的日月轮法不够！\n");
	if( !target ) target = offensive_target(me);

	if( !target
	  ||!target->is_character()
	  ||!me->is_fighting(target) 
	  ||!living(target))
		return notify_fail("「五轮大法」只能对战斗中的对手使用。\n");

	extra = me->query_skill("riyue-lun",1) / 6;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIY "$N纵跃退後，立时呜呜、嗡嗡、轰轰之声大作，金光闪闪，银光烁烁，五只轮子从五个不同方位飞袭出来！" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "银轮回转！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIR  "铁轮回转！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "铜轮回转！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  BLU   "锡轮回转！ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
if (me->query_skill("necromancy",1) > 200)
{
	if (target->query_temp("weapon"))
	{
	target_w = target->query_temp("weapon");

		if( target->query("combat_exp")/2 < 
			random(me->query("combat_exp", 1) )
			&& random(2)==0 )
		{
			target_w->unequip();
			target_w->reset_action();
			target_w->move(environment(target));
			target_w->set("name", target_w->query("name") + "的碎片");
			target_w->set("value", 0);
			target_w->set("weapon_prop", 0);
			target_w->set("long", "一堆破碎物事，好象是兵器碎片。\n");
        message_vision(RED"\n$N听到「叮当」，一声兵刃破碎的声音，自己的兵器碎片溅了一地！！\n"NOR,target);

		}
	}
}
if (me->query_skill("xiaowuxiang",1) > 200)
{

		if( target->query("combat_exp")/2 < 
			random(me->query("combat_exp", 1) )
			&& random(2)==0 )
		{
		inv = all_inventory(target);
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
message_vision(RED"\n$N闻到一股焦味，发现身上的"+inv[equip]->query("name")+HIR"已被烧得残破不堪，掉在了地上！\n"NOR,target);
			inv[equip]->unequip();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", inv[equip]->query("name") + "的碎片");
			inv[equip]->set("value", 0);
			inv[equip]->set("armor_prop", 0);
			inv[equip]->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
			}
		}
	}
}
	me->add("neili", -250);
	me->start_busy(3);
	return 1;
}
