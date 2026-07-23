// daxiao.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/jing"))
		return notify_fail("你已经在运大小庄了！\n");


	if( me->is_fighting() )
		return notify_fail("战斗中无法运大小庄！\n");

	if( (int)me->query("neili") < 500)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("jing") < skill + 100)
		return notify_fail("你的精不够运大小庄。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 150)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
"$N坐了下来运起大小庄，呼吸吐纳，真气直透九重。脸上神色一会变"HIR"红"NOR"，\n"
"一会变"HIC"青"NOR"，一会又变成"HIY"黄"NOR"色，最后终于回复原来的脸色。\n" NOR, me );
	me->add("neili",  -500);
	me->add("eff_jing", 0 - skill);
	me->add("jing", 0 - skill);
	me->add("eff_qi", 2 * skill);
	me->add("qi", 2 * skill);
	me->set_temp("linji/jing", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "忽然你全身感到一阵乏力，一肚皮不自在，原来你的大小庄收功了！\n" NOR );
		me->add("eff_jing", me->query_temp("linji/jing"));
		me->add("jing", me->query_temp("linji/jing"));
		if (me->query("eff_qi") > me->query_temp("max_qi"))
			me->set("eff_qi", me->query("max_qi"));
		if (me->query("qi") > me->query("eff_qi"))
			me->set("qi", me->query("eff_qi"));
		if (me->query("eff_jing") > me->query("max_jing"))
			me->set("eff_jing", me->query("max_jing"));
		if (me->query("jing") > me->query("eff_jing"))
			me->set("jing", me->query("eff_jing"));
		me->delete_temp("linji/jing");
}