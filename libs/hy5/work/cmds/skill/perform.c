// perform.c

//inherit F_CLEAN_UP;
inherit F_SSERVER;
int main(object me, string arg)
{
object target;
	object weapon;
	string martial, skill;
	mapping prepare;
	
	seteuid(getuid());

	if( !target ) target = offensive_target(me);

        if (me->is_fighting())
{
	if( !target)
		return notify_fail("现在不能使用这个绝技。\n");
if (me->is_fighting(target) )
{
	if( environment(target)!=environment(me))
		return notify_fail("你要对谁使用这个绝技？\n");
}

}
	if (userp(me) && me->is_busy())
		return notify_fail("( 你上一个动作还没有完成，不能用功。)\n");
	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");
if (target && me)
{
if(!target->query_condition("killer") && environment(me)->query("no_fight"))
		return notify_fail("这里不允许打斗！\n");
}
	if(userp(me) &&  me->query_temp("combat_yield") )
	return notify_fail("你不是打不还手吗?\n");
if (userp(me) && !me->query_skill_mapped("force"))
return notify_fail("你没有内功，在使用中啊!\n");

	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");
  if (me->is_perform()) return notify_fail("你正在使用"+me->query_perform()+"。\n");

	 if( !arg ) return notify_fail("你要用外功做什么？\n");

        if( me->query_condition("no_perform") )
		return notify_fail("( 你气息不匀，暂时不能施用外功。)\n");

	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
		if( weapon = me->query_temp("weapon") )
			martial = weapon->query("skill_type");
		else {
			prepare = me->query_skill_prepare();
			if (sizeof(prepare)) martial = keys(prepare)[0];
			else
			martial = "unarmed";
		}
	}

	notify_fail("你所使用的外功中没有这种功能。\n");
if( environment(me)->query("magicroom") && martial != "spells"
&& me->is_fighting() && userp(me))
{
if ( me->query("neili") < me->query("max_neili")/3)
me->add("neili",-me->query("neili")/4);
else me->add("neili",-me->query("max_neili")/4);
tell_object(me,"一种神奇的力量限制你想要用的绝学，你用尽全力方才使出想用的绝技。。。\n");
tell_object(me,"看了这个世界，只能使用魔法。。。\n");
}
if (me && target)
{
if( userp(me) && !userp(target) && objectp(target) && me!=target ) 
	target->set_temp("last_damage_from", me);
}
	if( stringp(skill = me->query_skill_mapped(martial))
	&& SKILL_D(skill)->perform_action(me, arg,skill) ) {
		if( random(120) < (int)me->query_skill(skill) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}
	if (sizeof(prepare) > 1) {
		martial = keys(prepare)[1];
		if( stringp(skill = me->query_skill_mapped(martial))
		&& SKILL_D(skill)->perform_action(me, arg,skill) ) {
			if( random(120) < (int)me->query_skill(skill, 1) )
				me->improve_skill(skill, 1, 1);
			return 1;
		}
	}
	if( stringp(skill = me->query_skill_mapped("parry"))
	&& SKILL_D(skill)->perform_action(me, arg,skill) ) {
		if( random(120) < (int)me->query_skill(skill, 1) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}
	if( stringp(skill = me->query_skill_mapped("dodge"))
	&& SKILL_D(skill)->perform_action(me, arg,skill) ) {
		if( random(120) < (int)me->query_skill(skill, 1) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}
	return 0;
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。

若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚跟武器技能
的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，如：

perform parry.yi

or

perform chan

换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}
