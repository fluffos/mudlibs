// zuixiange_boss.c

inherit NPC;

void create()
{
	set_name("刘福", ({ "liu fu","boss" }) );
	set("title","醉仙阁掌柜");
	set("gender", "男性" );
	set("age", 45);
	set("long",
		"他就是醉仙阁的老板，由于人勤快，人缘又好，
祖传的小店到他手里越做越大。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");

	setup();
	add_money("silver",10);
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
	if( !ob || environment(ob) != environment() || ob->query_temp("rent_paid")) return;
	switch( random(2) ) {
		case 0:
			say( "掌柜的笑咪咪地说道：您老用饭吧？快里面请。\n");
			break;
		case 1:
			say( "掌柜的笑咪咪地说道：请进请进，在这用饭保您满意。\n");
			break;
	}
}