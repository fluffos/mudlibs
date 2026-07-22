// /d/miaojaing/npc/xuezhu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(WHT"雪蛛"NOR, ({ "xue zhu", "zhu" }) );
        set("race", "野兽");
        set("age", 15);
        set("long", WHT"一只通体雪白的小蜘蛛，样子甚为奇特。\n"NOR);
        set("attitude", "peaceful");
        set("str", 10);
        set("cor", 30);
        set("limbs", ({ "头部", "身体","尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 50000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);
        setup();
   	if (clonep()) call_out("destroying2", 30, this_object());
}

void destroying2(object me)
{
	if(!me) return;
	if((!living(me)))
	{
		call_out("destroying2", 30, this_object());
		return;
	}
	message_vision("$N突然蹿到地上不见了。\n", me);
	destruct(me);
	return;
}

void destroying(object me)
{
	if(!living(me) && environment(me)->query("name") != "竹筒"){
		message_vision("$N突然蹿到地上不见了。\n", me);
		destruct(me);
		return;
	}
	call_out("destroying", 3, this_object());
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 50);
	return 0;
}
