// waiter.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("维吾尔少女", ({ "girl", "shaonv", "shao nv" }) );
	set("gender", "女性" );
	set("age", 19);
	set("long",
		"这位小姑娘一边忙里忙外，还和客人有说有笑。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小姑娘");
	setup();
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
	switch( random(2) ) {
	case 0:
		say( "维吾尔少女笑咪咪地说道：这位" + RANK_D->query_respect(ob)
			+ "，进来喝杯奶茶，歇歇腿吧。\n");
		break;
	case 1:
		say( "维吾尔少女擦擦手，连忙说道：这位" + RANK_D->query_respect(ob)
			+ "，快请进来。\n");
		break;
	}
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "维吾尔少女忙说道：多谢您啦！请上楼歇息吧。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
