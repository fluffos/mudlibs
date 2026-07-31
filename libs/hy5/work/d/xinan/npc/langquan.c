// dog.c

inherit NPC;



void create()
{
	set_name("大狼犬", ({ "lang quan","dog","quan" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只凶恶的大狼犬，它喉咙里不时发出可怕的低吼声。\n");
	
	set("str", 100);
	set("cor", 100);
	set("max_qi",1400);
	set("qi",1400);
	set("max_jing",1300);
	set("jing",1300);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set("combat_exp", 100000);

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
