// Rewrote by iszt@pkuxkx, 2007-02-12

#include "lev.h"

void create()
{
	set_name(RED"蜈蚣"NOR, ({"wu gong", "wugong"}));
	set("long", "一只有毒的火红色大蜈蚣。\n");

	set("race", "野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
	set("attitude", "aggressive");
	set("max_qi", 500+random(500));
	set("max_jing", 500+random(500));
	set("max_neili", 500+random(500));
	set("max_jingli", 500+random(500));
    set("qi", 1000);
    set("jing", 1000);
    set("neili", 1000);
    set("jingli", 1000);

	set("dex", 30);
	set("str", 30);

	set("age", 5);

	set("shen_type", -1);

	set("combat_exp", 500000);

	set_temp("apply/attack", 40);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defence",50);

	set("vendetta/authority",1);
	set("death_msg", "$N啪的一声瘫倒在地上死了。\n");

	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("wugong_poison") < 10 )
	{
		F_POISON->poison_attack(me,ob,"wugong_poison", 20);
		tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}