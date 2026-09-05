// Created by iszt@pkuxkx, 2007-02-12

#include <ansi.h>

inherit F_UNIQUE;

void init()
{
	add_action((: call_other, __DIR__"liquan", "do_remake" :), "remake");
        set("unique",1);
         set("preorder",0);
         set("robinterval",7200);  
	::init();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int jiali;
	jiali=me->query("jiali");
	jiali=random(10+jiali/2);
	if(random(14)>10)
	{
		me->add_temp("apply/attack",jiali);
		me->add_temp("apply/dodge", jiali*3);
		call_out("minus_apply", 2, me, jiali);
		return HIG "$N感受到冥冥中的神力，便如与手中的"+this_object()->name()+HIG"合为一体！\n" NOR;
	}
	return;
}

void minus_apply(object me,int jiali)
{
	if(!me)
		return;
	me->add_temp("apply/attack", -jiali);
	me->add_temp("apply/dodge", -jiali*3);
	return;
}
