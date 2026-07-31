//Cracked by Roath
//wzfeng@xkx 2002 1

// super-miejue.c 「灭绝神剑-最强之剑」
/*
峨嵋剑法飘香雪！
剑走游龙鬼见愁！
剑气缥缈寒霜月！
龙吟九天剑影光！
御剑如花九天散！
心意潇潇剑飞天！
情已憔憔剑孤行！
峨嵋剑法佛光照！
金顶剑光仙气飘！
灭绝神剑神鬼嚎！
*/
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void checking(object me);

int perform(object me, object target)
{
	int level;
	int dodge, parry, attack, sword;

	object weapon;
    weapon = me->query_temp("weapon");
       if( !weapon || !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何施展「灭绝神剑－最强之剑」？\n");
	   if(me->query("family/family_name")!="峨嵋派")
		   return notify_fail("你非峨嵋弟子，不能将灭剑和绝剑的精华融会贯通。\n");
   	   if(me->query("class")!="bonze")
		   return notify_fail("你非峨嵋出家弟子，六根不静，无法将灭剑和绝剑的精华融会贯通。\n");
    if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「灭绝神剑－最强之剑」只能在战斗中使用。\n");
		if( (int)me->query_temp("miejue") )
                return notify_fail("你已经施展「灭绝神剑」！\n");
              if( (int)me->query_temp("perform/miejian") )
                return notify_fail("你已经施展「灭剑」心法！\n");
        if( me->query("jingli") <=1500  )
                return notify_fail("你的精力不够，无法使出「灭绝神剑－最强之剑」。\n");
        if( me->query("neili") <=2000  )
                return notify_fail("你的内力不够，无法使出「灭绝神剑－最强之剑」。\n");
        if( (level = (int)me->query_skill("emei-jian", 1)) < 400 )
                return notify_fail("你的峨嵋剑法不够娴熟，无法将灭剑和绝剑的精华融会贯通。\n");
		if( me->query_skill("linji-zhuang", 1) < 400 )
                return notify_fail("你的临济十二庄修为火候未到，无法将灭剑和绝剑的精华融会贯通！\n");
                if( time()-(int)me->query_temp("perform/super-miejuetime") <
                (int)me->query_skill("emei-jian", 1)/50)
                return notify_fail("你刚使用无上心法和消耗太多先天真气，暂时无法施展此招！\n");
		if( me->query("married_times") !=0 )
                return notify_fail("你已不是处子之身，难以施展「灭绝神剑－最强之剑」！\n");
                
                  if( me->query("combat_exp") < (target->query("combat_exp")/3) )
                return notify_fail("对方武技之高，功力之奇，让你大为震惊，你无法在这种高手面前聚集先天剑气。\n这「灭绝神剑－最强之剑」自然也无法使出。\n");
		
		if( userp(me) )
        {
                me->add("neili", -2000);
               me->add("jingli", -1500);
        }
         message_vision(HIY "\n只见$N一声清啸，双目闪出奇异光彩，手中"+weapon->name()+"刹然回收，抱立身前......\n" NOR, me, target);
         message_vision(HIY "只觉此时天地色变，无尽的气势和剑意仿佛聚集在$N手中"+weapon->name()+"上！\n" NOR, me, target);

		 message_vision(HIW "\n$n只觉四周都被$N释放出的无尽剑气包围，身心都被这片先天剑气遥遥锁定，想逃走都不可能！\n" NOR, me, target);

        	me->set_temp("perform/super-miejuelvl",level/50);
        	me->set_temp("perform/super-miejuehit",1);
        
		dodge = target->query_skill("dodge")/2;
        	parry = target->query_skill("parry")/2;
        	attack = target->query_temp("apply/attack")/2;
        	
        	target->add_temp("apply/dodge", -dodge);
		target->add_temp("apply/parry", -parry);
		target->add_temp("apply/attack", -attack);
		target->add_temp("apply/speed", -dodge);
		me->add_temp("apply/damage",level/15);

        call_out("remove_effect", level/50*2, me, target, dodge, parry, attack, sword,level);
		me->set_temp("perform/super-miejuetime",time());
		
		//printf("%d\n",time());
		target->start_busy(level/50+1);
		
		
        return 1;
}


void remove_effect(object me, object victim, int dodge, int parry, int attack, int sword,int level)
{
	if( objectp(victim) )
	{
		//victim->add_temp("perform_target/miejian", -1);
		victim->add_temp("apply/dodge", dodge);
		victim->add_temp("apply/parry", parry);
		victim->add_temp("apply/attack", attack);
		victim->add_temp("apply/speed", dodge);
	}


		me->delete_temp("perform/super-miejuetime");
		me->add_temp("apply/damage",-level/15);
			me->start_busy(2);
    tell_object(me,HIC"\n你深深吸了口气，先天真气渐渐转弱，刹那间，无上剑气消失的无影无踪。\n"NOR);

	if( objectp(me) && objectp(victim) && victim->is_fighting(me) )
		message_vision(HIY "\n\n$N领教了最强之剑的神威，想起来不由一阵后怕。。\n" NOR, victim, me);
}


