// waiter.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老渠", ({ "lao qu", "qu",}) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"老渠正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "渠老哥");
	set("vendor_goods", ({
		"/d/murong/obj/yuer",
		"/d/murong/obj/yugou",
		"/d/murong/obj/liejian",
		"/d/murong/obj/liegong",
	}));
	set("shen_type",1);set("score",500);setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list","list");
	add_action("do_buy","buy");

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "老渠笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "老渠用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

