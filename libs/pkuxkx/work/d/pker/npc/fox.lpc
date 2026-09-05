// bear.c

inherit NPC;

void create()
{
	set_name("狐狸", ({ "huli", "fox" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只小小的狐狸，样子蛮可爱的\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 6000);
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		
		
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

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
	
}
