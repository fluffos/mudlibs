// sixiao.c 虎王四啸

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,ob;
	int i,j,skill,level,damage,dmg;
string msg,dodge_skill,*limbs;
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「虎王四啸指」？\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("请使用无争心法!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

    if( objectp(me->query_temp("weapon")) )
      return notify_fail("你必须空手才能使用「震」字诀！\n");
      
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("xuantian-zhi", 1) < 100)
                return notify_fail("你的玄天无情指级别还不够，使用这一招会有困难！\n");



        weapon=me->query_temp("weapon");

	if( me->query("env/brief_message") ){
		i=1;
	} else {
		i=0;
	}
	if( target->query("env/brief_message") ){
		j=1;
	} else {
		j=0;
	}	

	me->delete("env/brief_message");
	target->delete("env/brief_message");

                skill = me->query_skill("xuantian-zhi");
if (skill > 500) skill=500;
    me->add_temp("apply/damage",  3000);
    me->add_temp("apply/attack",  skill/2);

	message_vision(RED"\n$N张口就是一声虎啸，震天动地，左右开弓 使出一招「虎王四啸指」。\n"NOR, me);
  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
  COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
if (random(3)==0 && !target->is_busy()) target->start_busy(3);

	message_vision(RED"\n虎王四啸第一指——一啸红尘惊！"NOR, me);
	me->set("SaneJie", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	message_vision(RED"\n虎王四啸第二指——再啸湖海翻！"NOR, me);
	me->set("SaneJie", 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

	message_vision(RED"\n虎王四啸第三指——三啸鬼神辟！"NOR, me);
	me->set("SaneJie", 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	message_vision(RED"\n虎王四啸第四指——绝啸穹苍灭！"NOR, me);
	me->set("SaneJie", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    me->add_temp("apply/damage",  -3000);
    me->add_temp("apply/attack",  -skill/2);

	me->delete("SaneJie");

        limbs = target->query("limbs");
        level = me->query_skill("xuantian-zhi", 1);
        
         target->start_busy(2);
         msg = HIR"$N面对$n的攻势。突然连点出几道气劲  !!\n"NOR;
         msg += HIR"「玄天无情指!!」。$n两眼被点中大穴 吐出一口鲜血!!。\n"NOR;
             target->add("qi",-(level+100));
             target->add("eff_qi",-(level+100));
        if (userp(target) && target->query("qi") > 50
        && target->query("eff_qi") > 50)
{
	dmg=target->query("qi")/10;
	if (dmg>100000) dmg=100000;
if (target->query("qi")/12 > 20)
             target->add("qi",-dmg);
if (target->query("eff_qi")/12 > 20)
             target->add("eff_qi",-dmg);
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, target);

	if( i ) me->set("env/brief_message", 1);
	if( j ) target->set("env/brief_message", 1);



	me->receive_damage("qi", 100);
	me->add("neili", -100);



	me->start_busy(2);
	return 1;
}
