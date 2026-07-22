// dog.c

inherit NPC;

void create()
{
        set_name("车骑将军", ({"cheqi jiangjun", "dog"}));
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的大恶狗。\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);
	
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;

	::init();
	if (living(this_object()) && interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 20) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
	message_vision("$N惨嚎一声，死了！\n", this_object());
	new("/clone/armor/goupi")->move(environment());
	destruct(this_object());
}
