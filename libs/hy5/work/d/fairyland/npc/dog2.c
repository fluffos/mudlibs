// dog.c

inherit NPC;

void create()
{
	set_name("平寇将军", ({"dog"}));
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的大恶狗。\n");
	set("attitude", "peaceful");
	
	set("str", 36);
	set("cor", 30);
	set("dex", 30);
       set("max_qi", 5500);
	set("max_jing", 5220);
	set("neili", 5000);
	set("max_neili", 5000);
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);
	
	set_temp("apply/attack", 115);
	set_temp("apply/defense", 115);
	set_temp("apply/damage", 516);
	set_temp("apply/armor", 512);

	setup();
}

void init()
{
	object ob;

	::init();
	if (living(this_object()) && interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 24) {
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
