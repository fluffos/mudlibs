
inherit NPC;
void create()
{
    set_name("大灰狼", ({ "huilang", "lang" }) );
	set("race", "野兽");
	set("age", 10);
    set("long", "一头高大的恶狼, 来势如电, 露出白森森的獠牙。\n");
    set("attitude", "aggressive");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
     set("no_die",1);
	set("combat_exp", 2000);
//	set("shen_type", 0);
//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 4);
	setup();
}
void die()
{
	object ob;
    message_vision("$N凄惨的嚎了几声, 在地上打了几个滚，仰天死了。\n", this_object());
	ob = new(__DIR__"obj/langpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
