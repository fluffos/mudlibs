//by sdong 07/98

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int skill, skill1, skill2;
        string msg;
        object victim,ob;
        object weapon,weapon2;
    object *inv;
    int i, count;
     int damage,jiali,jiajin;
     string bei_skill;
	jiali = (int)me->query("jiali");
	jiajin= (int)me->query("jiali");

        if( !victim ) victim = offensive_target(me);

       if( !target ) target = offensive_target(me);
        if( !victim || !victim->is_character() || !me->is_fighting(victim) )
                return notify_fail("只能对战斗中的对手使用。\n");


        if(     me->query_skill("yunv-jian",1) < 1 ||
                me->query_skill("quanzhen-jian",1) < 1 
                )
                return notify_fail("必须通晓并备有玉女剑法与全真剑法！\n");

        if(me->query_skill("quanzhen-jian",1) <120)
                return notify_fail("你的全真剑法不够熟练，不能双剑和璧左右互搏！\n");

        if(me->query_skill("yunv-jian",1) <180)
                return notify_fail("你的玉女剑法不够熟练，不能双剑和璧左右互搏！\n");

        if( !objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("必须持有剑！\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("meinv-quan", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("yunv-jian", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("yunv-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yunv-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通古墓派武学，使出了古墓派的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);

        skill =  ( me->query_skill("yunv-jian",1) + me->query_skill("yunv-jian",1)
                + me->query_skill("meinv-quan",1) +me->query_skill("yunv-xinfa",1) 
                + me->query_skill("yunv-xinfa")) / 10; 
        message_vision(
        HIR "$N突然间左手抽出另一把剑，双手使出截然不同的剑法，正是左右互搏绝技。\n"+HIC"只见$N双剑一交，左右手玉女剑法与全真剑法配合得天衣无缝，攻守之势猛然大增！\n\n" NOR, me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/damage", skill/2);
        me->add_temp("apply/dodge",  skill/2);
        me->add_temp("apply/parry",  skill/2);

        bei_skill = me->query_skill_mapped("sword");
    me->map_skill("sword", "yunv-jian");
        message_vision(HIG"浪迹天涯！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"花前月下！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"抚琴按萧！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");

        message_vision(
        HIR "$N剑招愈来愈怪,可是互相呼应，厉害杀招却是层出不穷\n" NOR, me);

        me->setup();
        message_vision(HIY"小园艺菊！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "yunv-jian");
        me->setup();
        message_vision(HIG"西窗夜话！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIY"松下对弈！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->map_skill("sword", "quanzhen-jian");
        me->setup();
        message_vision(HIG"清饮小酎！\n" NOR,me,target);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));

    me->map_skill("sword", bei_skill);
        me->setup();

        me->start_busy(3);

	msg = HIB "\n\n$N真气催动，带得拳意纵横无情！\n"NOR;
        msg += HIY "\n$N右手支颐，左袖轻轻挥出，长叹一声，脸现寂寥之意，无奈中使出杀招。\n\n"NOR;
  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/3 ) || !living(target) )
  {
			damage = random(  me->query_skill("meinv-quan",1) + me->query_skill("yunv-xinfa",1) + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
			if(damage > 6000) damage = 6000;
			if(damage < 600) damage = 600;

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage, me);
			target->start_busy(0);

		if ( damage < 1000) {
			msg += HIR"只听砰的一声，$n被一拳击中小腹，内血翻涌喷口而出。\n"NOR;
		}else if ( damage < 2000) {
			msg += HIR"只听砰、砰两声，$n左眼发青、右眼发紫，鲜血直流。\n"NOR;
		}else if ( damage < 3000) {
			msg += HIR"只听砰、砰、砰三声响，$n身上被了几个窟窿，鲜血狂喷。\n"NOR;
		}else {
			msg += HIR"只听砰、砰、砰、砰几声巨响，$n被打得骨骼碎裂飞了出去。\n"NOR;
		}
		msg += NOR;
  }
  else {
	 msg += HIG"$n灵光一现，纵身跃起，本能的反应帮$n逃过此劫。\n\n"NOR;
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);

	msg = HIB "\n$N悄退数步似要坐倒，右手支颐，左袖轻轻向$n挥出，长叹一声，脸现寂寥之意。\n\n"NOR;

	msg += HIY"这是“美女拳法”最后一招的收式，叫作“古墓幽居”，却是杨过所自创，林朝英固然\n";
	msg += HIY"不知，即便是小龙女也是不会。当年杨过掌年学全了美女拳法之后，心想祖师婆婆姿容\n";
	msg += HIY"德行不输于古代美女，武功之高更不必说，这路拳法中若无祖师婆婆在，算不得有美皆\n";
	msg += HIY"备，于是自行拟了这一招，虽说为抒写林朝英而作，举止神态却是模拟了师父小龙女。\n\n";

  if( random( me->query("combat_exp") ) > random( target->query("combat_exp")/3 ) || !living(target) )
  {
	damage = random(  me->query_skill("force",1) + me->query_skill("cuff",1) + me->query("jiali") )*( 1 + random(me->query("jiali")/5) ) ;
	if(damage > 5000) damage = 5000;
	if(damage < 800) damage = 800;

	target->receive_damage("qi", damage,  me);
	target->receive_wound("qi", damage, me);
	target->start_busy(0);

	if ( damage < 800) {
		msg += HIR"只听噗的一声，$n被一拳击中小腹，内血翻涌喷口而出。\n"NOR;
	}else if ( damage < 1400) {
		msg += HIR"只听砰、砰两声，$n左眼发青、右眼发紫，狼狈不堪。\n"NOR;
	}else if ( damage < 2000) {
		msg += HIR"结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
	}else {
		msg += RED"只听砰、砰、砰、砰几声巨响，$n被打得骨骼碎裂飞了出去。\n"NOR;
	}
	msg += NOR;
	}
	else {
	msg += HIG"$n灵光一现，纵身跃起，本能的反应辟开了$N的衣袖。\n\n"NOR;
	message_vision(msg+"\n", me, target);
	return 1;
  }

	message_vision(msg+"\n", me, target);
	COMBAT_D->report_status(target);

        return 1;
}

