// bear.c

inherit NPC;

void create()
{
	set_name("黑熊", ({ "bear", "xiong" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只面目凶恶，体型硕大的黑熊\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 6000);
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"大黑熊大声吼叫起来：瓯!\n",
		
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	set("shen_type",-1);
set("score",1000);
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
        object ob, corpse;
	message_vision("$N惨嚎一声，死了！\n", this_object());
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), this_player())) )
                corpse->move(environment());
        destruct(this_object());
}
