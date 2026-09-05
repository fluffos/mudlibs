// xiyi.c  蜥蜴
// Updated by iszt@pkuxkx, 2007-03-11
// hongdou 98.9.20

inherit NPC;

void create()
{
	set_name("大蜥蜴", ({ "xi yi", "xiyi"}) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只头部昂起，吐着信子，拖着长尾巴，正向你挑衅的花斑大蜥蜴。\n");
	set("attitude", "aggressive");
	
	set("str", 35);
	set("cor", 40);

	set("limbs", ({ "头部", "后背", "前腿", "后腿","尾巴" }) );
	set("verbs", ({ "hoof", "bite" }) );

	set("combat_exp", 20000);
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"大蜥蜴向你冲来，看来想吃掉你！\n",
	}) );
		
	set_temp("apply/attack", 43);
	set_temp("apply/damage", 35);
	set_temp("apply/armor", 30);

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
	message_vision("$N翻了个身，八只爪颤抖了几下，僵直不动了！\n", this_object());
	destruct(this_object());
}
