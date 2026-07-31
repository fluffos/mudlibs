
// zhixin.c

#include <ansi.h>

int exert(object me)
{
	int skill;
        skill = (int)me->query_skill("emeiforce",1);

	if (me->query_condition("linji_zhixin"))
                return notify_fail("你已经在运之心二术了！\n");


	if( me->is_fighting() )
                return notify_fail("战斗中无法运之心二术！\n");

        if( (int)me->query("force") < 200)
		return notify_fail("你的真气不够。\n");

        if( (int)me->query_skill("emeiforce",1) < 60)
                return notify_fail("你的峨嵋心法级别不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail( "你已经受伤过重，无法运功！\n");

	message_vision(
HIY "$N坐了下来运起之心庄，将手掌在脑门上磕了两下，顿觉灵台清明，....\n"
"站了起来，发现脑袋瓜灵光了不少。\n" NOR, me );
	me->apply_condition("linji_zhixin", (int)skill/20);
        me->add("force", -200);
        me->add("eff_sen", -10);
        me->add("sen", -20);
	me->add("int", (int)skill/30);
	me->set("linji/int", (int)skill/30);
	return 1;
}

