// Created by iszt@pkuxkx, 2007-02-12

#include <ansi.h>

void init()
{
	add_action((: call_other, __DIR__"liquan", "do_remake" :), "remake");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int jiali;
	jiali=me->query("jiali");