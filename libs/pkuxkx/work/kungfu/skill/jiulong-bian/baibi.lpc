//Cracked by Roath
///kungfu/skill/yunlong-bian/riyue.c 日月无光
// sdong 09/98

#include <ansi.h>
#define Menpai "天地会"
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
    int str, dex, skill, power, shen;
	  object weapon;
	  string msg;

    if( !target ) 
    	target = offensive_target(me);
    
    if( !target ||	!target->is_character() ||	!me->is_fighting(target) )
      return notify_fail("白璧三献只能对战斗中的对手使用。\n");

	  if ( !objectp(weapon = me->query_temp("weapon"))
	       || ( string)weapon->query("skill_type") != "whip" )
		  return notify_fail("你必须先找一条鞭子才能施展鞭法绝技。\n");
        
//    if( me->query_skill_mapped("force") != "cangming-gong" )
//      return notify_fail("你所用的并非浩气苍冥功，施展不出白璧三献！\n");
    if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        && me->query_skill_mapped("force") != "cangming-gong" )
            return notify_fail("你所用的并非浩气苍冥功，施展不出白璧三献！\n");        

    if( me->query_skill("cangming-gong", 1) < 120 )
      return notify_fail("你的浩气苍冥功火候未到，无法施展白璧三献！\n");

    if( me->query_skill("jiulong-bian", 1) < 135 )
      return notify_fail("白璧三献需要精湛的九龙鞭方能有效施展！\n");

    if( me->query("shen") < 100000 )
      return notify_fail("你正气不够，即使施展白璧三献也无甚威力！\n");

    // for a 800K player, frce/2 = 150, shen/3K = 300, power = 300
    // for players > 1.2M, power will hit max
    str = me->query_str();
    power = random( me->query("shen") / 50000 ) + me->query_skill("force",1)/2;
    if(power<150)
    	power=150;
    	
    if(power>900)
    	power=900;

    if( me->query("neili") <= 200+power*2 )
        return notify_fail("你的内力不够使用白璧三献！\n");
    
    if( me->query("jingli") <= power/2 )
        return notify_fail("你的精力不够使用白璧三献！\n");

    message_vision(HIW "$N运足内力，猛地一扬"NOR+"$n"+HIW"卷起无边正气遮月掩日，一股"NOR+
                   HIM "罡风"NOR+HIW"随著漫天鞭影扑天盖地的向敌人袭来。\n" NOR, me, me->query_temp("weapon"));

    me->add_temp("apply/attack",power/3);
    me->add_temp("apply/damage",power/3);
    target->add_temp("apply/armor",-power/5);
    target->add_temp("apply/dodge",-power/5);
   //门派大招影响
   
   if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point")&& !me->query_temp("cmg_zq_buff"))
	{
		me->add_temp("apply/attack", power*12);
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-power);
		msg = HIR "$N正气凛然，临战神勇！\n" NOR;
		message_vision(msg,me,target);


	}

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    
    if ( F_KUNGFU->hit_rate( str, target->query("str")-10, 15, me, target) ) 
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    
    if ( F_KUNGFU->hit_rate( str, target->query("str")-5, 16, me, target) ) 
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if (me->query_temp("cmg_zq_buff"))
	{
		me->add_temp("apply/attack", -power*12);
		me->delete_temp("cmg_zq_buff");
	}

    me->add_temp("apply/attack",-power/3);
    me->add_temp("apply/damage",-power/3);
    target->add_temp("apply/armor",power/5);
    target->add_temp("apply/dodge",power/5);

    // modification by chu:
    // The cost was 100 and 50 each, which is too low.  Right now people use
    // riyue to kill opp, perform one after continuously.
    // now the cost will be around 900 neili 400 jingli, which means high
    // hands can only perform 3, 4 times in a fight
    me->add("neili", -power);
    me->add("jing", -power/2);
    me->start_busy( 3+random(2));

    return 1;
}


