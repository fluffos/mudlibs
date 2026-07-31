// yiren.c

inherit NPC;

void create()
{
	set_name("卖艺人", ({ "yiren" }) );
	set("gender", "男性" );
	set("age", 12);
	set("long", "他五短身材，一身短打扮，浑身上下透着精神。\n");
	set("per", 35);
	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed", 60);
	set_skill("parry", 100);
	set_skill("dodge",100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "卖艺人说道：这位" + RANK_D->query_respect(ob)	+ "不来玩两手？\n",ob);
}