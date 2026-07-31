inherit NPC;

void create()
{
	set_name("店小二",({"xiao er","xiao","er"}));
	set("gender", "男性" );
	set("age", 20);
	set("long",
		"眉清目秀的小伙计，整天笑嘻嘻的，忙得不亦乐乎。\n");
	set("combat_exp",200);
	set_temp("apply/defense",10);
	set_temp("apply/attack",5);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
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
			message_vision("店小二见你过来,忙迎上来，笑道：这位"+
			RANK_D->query_respect(ob)+"，您往里边请!\n",ob);
}
