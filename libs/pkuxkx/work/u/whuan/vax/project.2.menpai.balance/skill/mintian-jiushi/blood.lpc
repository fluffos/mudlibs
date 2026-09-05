/*
dewolf : 天似血，招式 来自《枭中雄》, 代码主要来自 英雄剑法

“熟铜人”挟着阵阵劲风，挥映得影幻重重，在卓飞扭曲歪扯的狞狞面孔中呼轰压头，
燕铁衣反手将石念慈按倒地下，身形飞起，“太阿剑”猝然扩展成一片晶幕，晶幕甫现，又
突而散碎，幻成了一天的光矢芒雨射落，在这极目所见的灿亮电耀中，“照日短剑”闪出千
百怪蛇也似的流虹，往上暴卷，于是，卓飞顿时淹没于这一片旋纵横的光芒中，血肉横溅，
惨号宛似在绞人的肝肠！
    “天似血”、“冥天九式”中的第四式。

*/
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天似血只能对战斗中的对手使用。\n");
		
	 // dewolf 大弟子判定
    if( me->query("family/family_name")!="星宿派" || !me->query("family/topone") )
        return notify_fail("只有本派大弟子才有权使用天似血对敌！\n");
    
    if( (int)me->query_skill("mintian-jiushi", 1) < 150 )
        return notify_fail("你的冥天九式还不够熟练，不能使用天似血对敌！\n");
		
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"装备剑才能使用「天似血」!\n"NOR);

    if (me->query("neili") < 200)
		return notify_fail("你的内力不够！\n");
		
	weapon = me->query_temp("weapon");
	extra = me->query_skill("mintian-jiushi",1) / 5+ me->query_skill("sword",1) / 10;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	me->add_temp("apply/damage", extra);
	msg = HIR "$N身形飞起，"+weapon->name()+"猝然扩展成一片晶幕，晶幕甫现，又突而散碎，幻成了一天的光矢芒雨射落，\n在这极目所见的灿亮电耀中，"
		+weapon->name()+"闪出千百怪蛇也似的流虹，往上暴卷！\n    「天似血」、「冥天九式」中的第四式！" NOR;
	message_vision(msg, me, target);
	me->start_call_out(__FILE__, "remove_effect", skill/2, me, extra);
	me->add("neili",-200);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->start_busy(random(3) + 1);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("powerup") ) 
	{
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/damage", -amount);
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("powerup");
        tell_object(me, "你的冥天九式绝技运行完毕，将内力收回丹田。\n");
	}
}