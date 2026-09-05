// haixie2.c  巨海蟹
// hongdou 98.9.20

inherit NPC;

void create()
{
	set_name("巨海蟹", ({ "juhai xie", "xie" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只罕见的巨大的海蟹，它挥舞着双鳌，威风不可一世。\n");
	set("attitude", "aggressive");
	
	set("str", 40);
	set("cor", 45);

	set("limbs", ({ "眼部", "后背", "前鳌", "后腿" }) );
	set("verbs", ({ "hoof", "qian" }) );
	set("combat_exp", 80000);
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"巨海蟹舞动起大钳子向你冲来！\n",
		}));
	set_temp("apply/attack", 60);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 50);

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
