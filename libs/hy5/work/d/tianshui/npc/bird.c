// bird.c
inherit NPC;

void create()
{
	set_name("小鸟", ({ "bird" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
        set("long", "一只可爱的小鸟。\n");

	set("str", 10);
	set("combat_exp", 500);
        set("attitude","peaceful");

        set("limbs", ({ "头部", "身体","翅膀" }) );
	set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 100);

        setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("$N叽叽的叫着!\n",this_object());
}