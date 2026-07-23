inherit NPC;
inherit F_VENDOR;

string query_save_file() { return DATA_DIR + "npc/陈老板"; }
void create()
{

	set_name("陈老板", ({ "lao ban", "chen", "laoban" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位陈老板正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/jinjiezhi",
		__DIR__"obj/zuanshijiezhi",
		__DIR__"obj/yuzhuo",
		__DIR__"obj/yuzhui",
		__DIR__"obj/xianglian",				
	}));

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

	add_action("do_buy", "buy");
	add_action("do_list", "list");

}
void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			message_vision("陈老板打量了$N一会，笑道：这位"+
			RANK_D->query_respect(ob)+"，您想要点什么？\n",ob);
			break;
		case 1:
			say( "陈老板说道：这位" + RANK_D->query_respect(ob)
				+ "，你也是上雁荡拜师的吧。\n");
			break;
                           }
}



