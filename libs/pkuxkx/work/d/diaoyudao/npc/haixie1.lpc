// haixie1.c  海蟹
// hongdou 98.9.20

inherit NPC;

void create()
{
	set_name("海蟹", ({ "hai xie", "xie" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只舞动双鳌，口吐白沫，横行霸道的海螃蟹，在海滩上经常能见到。\n");
    set("attitude", "peaceful");
	
	set("str", 35);
	set("cor", 40);

	set("limbs", ({ "头部", "后背", "前鳌", "后腿" }) );
	set("verbs", ({ "hoof", "qian" }) );

	set("combat_exp", 20000);
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"海蟹舞动起大钳子向你冲来！\n",
	}) );
		
	set_temp("apply/attack", 43);
	set_temp("apply/damage", 35);
	set_temp("apply/armor", 30);

	set("shen_type",-1);
set("score",200);
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
	message_vision("$N翻了个身，八只爪颤抖了几下，僵直不动了！\n", this_object());
	ob = new(__DIR__"obj/xierou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
