// waiter.c

inherit NPC;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 20);
	set("str",50);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
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
	if( !ob || environment(ob) != environment() || ob->query_temp("rent_paid")) return;

	switch( random(2) )
	{
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 200) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
		who->set_temp("rent_paid",1);
		return 1;
	}

	else
	{
		tell_object(who, "小二摇摇头说道：住店一晚二两银子。\n");
			return 0;
	}
}
