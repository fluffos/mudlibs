// lifeheal.c

#include <ansi.h>

int exert(object me)
{
int damage;
        if (!wizardp(me) && !me->query("5zhuan") && !me->query("4zhuan") && !me->query("zhuanbest") && !me->query("guard/flag") && !me->query("zhuanshen"))
		return notify_fail("返天归原法，只有转生后才可以使用！\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("你的内功修为还不够。\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 10 )
		return notify_fail("你的真气不够。\n");
if (!me->is_fighting() && me->query_temp("zsgyf",1)>0 ) 
{
me->set_temp("zsgyf",0);
message_vision(HIR "$N经过一阵调理，脸色变的正常了。\n" NOR, me);
}




if ((int)me->query_temp("zsgyf",1) >=6 && !me->query("5zhuan") && !me->query("4zhuan") && !me->query("zhuanbest") && !me->query("guard/flag"))  return notify_fail( me->name() + "气血还在翻腾！看来这次战斗无法再次使用了。\n");
if ((int)me->query_temp("zsgyf",1) >=12 && !me->query("5zhuan") && !me->query("4zhuan")) return notify_fail( me->name() + "气血还在翻腾！看来这次战斗无法再次使用了。\n");
if ((int)me->query_temp("zsgyf",1) >=16 && !me->query("5zhuan")) return notify_fail( me->name() + "气血还在翻腾！看来这次战斗无法再次使用了。\n");
if ((int)me->query_temp("zsgyf",1) >=30) return notify_fail( me->name() + "气血还在翻腾！看来这次战斗无法再次使用了。\n");

if (me->query_condition("guiyuan")) return notify_fail( me->name() + "才用过返天归原法！气血还在翻腾！\n");

	if( (int)me->query("qi") >= (int)me->query("max_qi") 
	&& (int)me->query("jing") >= (int)me->query("max_jing")
	&& (int)me->query("neili") >= (int)me->query("max_neili")
	&& (int)me->query("eff_qi") >= (int)me->query("max_qi") 
	&& (int)me->query("eff_jing") >= (int)me->query("max_jing")	)
		return notify_fail( me->name() + "并未受伤！\n");



message_vision(HIR "$N咬破舌尖 运起返天归原法 吐出一口鲜血 提起全身的精力与潜力。\n" NOR, me);
if (me->is_fighting()) me->add_temp("zsgyf",1);
if (userp(me) && me->query("5zhuan"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")*2) 
me->add("qi",me->query("max_qi"));
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2) 
me->add("eff_qi",me->query("max_qi"));

if( (int)me->query("jing") < (int)me->query("max_jing")*2) 
me->add("jing",me->query("max_jing"));
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2) 
me->add("eff_jing",me->query("max_jing"));
if( (int)me->query("neili") < (int)me->query("max_neili")*2) 
me->add("neili",me->query("max_neili"));
if (me->is_busy()) me->start_busy(1);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",1);
}


else if (userp(me) && me->query("4zhuan"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")) 
me->add("qi",me->query("max_qi")*3/4);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")) 
me->add("eff_qi",me->query("max_qi")*3/4);

if( (int)me->query("jing") < (int)me->query("max_jing")) 
me->add("jing",me->query("max_jing")*3/4);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")) 
me->add("eff_jing",me->query("max_jing")*3/4);
if( (int)me->query("neili") < (int)me->query("max_neili")) 
me->add("neili",me->query("max_neili")*3/4);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",1);
}

else if (userp(me) && me->query("zhuanbest"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")) 
me->add("qi",me->query("max_qi")*3/4);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")) 
me->add("eff_qi",me->query("max_qi")*3/4);

if( (int)me->query("jing") < (int)me->query("max_jing")) 
me->add("jing",me->query("max_jing")*3/4);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")) 
me->add("eff_jing",me->query("max_jing")*3/4);
if( (int)me->query("neili") < (int)me->query("max_neili")) 
me->add("neili",me->query("max_neili")*3/4);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",1);
}


else if (userp(me) && me->query("zhuanshen"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")) 
me->add("qi",me->query("max_qi")*1/2);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")) 
me->add("eff_qi",me->query("max_qi")*1/2);

if( (int)me->query("jing") < (int)me->query("max_jing")) 
me->add("jing",me->query("max_jing")*1/2);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")) 
me->add("eff_jing",me->query("max_jing")*1/2);
if( (int)me->query("neili") < (int)me->query("max_neili")) 
me->add("neili",me->query("max_neili")*1/2);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",2);
}

if (!me->is_fighting() ) me->apply_condition("guiyuan",3);		



	return 1;
}
