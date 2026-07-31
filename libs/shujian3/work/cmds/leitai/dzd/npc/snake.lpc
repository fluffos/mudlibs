// /d/dzd/npc/snake.c

inherit __DIR__"animal";

void create()
{
	set_name("毒蛇",({"snake","she","dushe"}));
	set("race","野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs",({"bite"}));
	set("attitude","peaceful");
	set("age",3);
	set("combat_exp",3000000);
	set("long","这是一只含有巨毒的蛇。\n");
	set("max_qi",5000);
	set("max_jing",3500);
	set("max_neili",7000);
	set("neili",7000);
	set("eff_jingli",4000);
	set("jingli",4000);
	set("jiali",200);
	set("str",100);
	set("con",100);
	set("dex",100);
	set("chat_chance", 10);
       set("chat_msg", ({
		(: random_move :),
		"蛇在远处用狰狞的目光盯着你。\n",
		"蛇懒洋洋的把身子盘成一团。\n",
       }));
	set_temp("apply/attack",200);
	set_temp("apply/damage",200);
	set_temp("apply/armor",800);
	setup();
}

int hit_ob(object me, object victim, int damage)
{
 	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 6);
       return 0;
}
	