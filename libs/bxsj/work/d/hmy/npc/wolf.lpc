// wolf.c

inherit NPC;

void create()
{
        set_name("野狼", ({ "ye lang", "lang", "wolf"}) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的野狼。\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 10000);
	set("shen_type", -1);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"野狼大声：喔！喔！喔！喔！喔！喔！\n",
		"野狼突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
        set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
void die()
{
	object ob;
	message_vision("$N惨嚎一声，死了！\n", this_object());
       ob = new(__DIR__"obj/goupi");
 	ob->move(environment(this_object()));
	destruct(this_object());
}
