#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg, *skill;
	object weapon;
	mapping skills;
	int i;


	if( !target ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("「总诀式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if((int)me->query_skill("dugu-jiujian",1) < 350 )
		return notify_fail("你的独孤九剑还不够火候。\n");

	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return notify_fail("你现在无法使用「总诀式」！\n");

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return notify_fail("你现在无法使用「总诀式」！\n");

	if((string)me->query_skill_mapped("dodge") != "dugu-jiujian" && userp(me))
		  return notify_fail("你现在无法使用「总诀式」！\n");

	if(target->query_temp("dgjj/zongjue") )
	       return notify_fail("你现在已经在向对手使用「总诀式」了。\n");

	if((int)me->query("jingli")<2500)
		return notify_fail("你的精力不够！\n"); 
	
	msg = HIW"\n$N剑上完全不出内力，剑随意行，毫无章法！\n"NOR;
	me->start_perform(3,"「总诀式」");
	me->add("jingli", -2000);
	if (random(me->query_int()) > target->query_int()/2){
	msg+= HIG"\n$n只觉得处处受制，武功中厉害之处完全无法发挥出来！\n"NOR;
	skills = target->query_skill_map();
	if (!skills) return notify_fail("他并没有激发特殊技能。\n");
	skill = keys(skills);
	i = sizeof(skill);
	while (i--)
	  target->map_skill(skill[i]);
	target->delete("jiali");

	target->set_temp("no_enable",1);
	target->set_temp("dgjj/zongjue",1);
	me->set("jiali",0);
	call_out("remove_effect",me->query_skill("dugu-jiujian",1)/10,me,target);
	} else
	msg+= HIG"\n$n灵机一动，身随剑走，果然$N再也无法随意出招。\n"NOR;
	message_vision(msg,me,target);
	return 1;
}

void remove_effect(object me, object target)
{
	if (me) me->delete_temp("dgjj/zongjue");
	if (target) target->delete_temp("no_enable");
	if (target) target->delete_temp("dgjj/zongjue");
}
