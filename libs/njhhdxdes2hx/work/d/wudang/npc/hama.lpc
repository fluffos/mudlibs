// hama.c 蛤蟆
inherit NPC;

void create()
{
	set_name("蛤蟆", ({ "ha ma", "ha", "ma" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只难看的蛤蟆。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
	ob = new(__DIR__"hamarou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
