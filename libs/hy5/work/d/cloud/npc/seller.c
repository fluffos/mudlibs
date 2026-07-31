
// seller.c

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("杂货贩", ({ "seller" }) );
        set("title", "杂货铺");
        set("gender", "男性" );
        set("age", 32);
        set("long", "卖杂货的是个年轻汉子，面带微笑。\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);
        set_skill("throwing", 30);

        set("inquiry", ([
                "杂货铺" : "这是祖上传下来的产业，小的在勉力维持。", 
        ]) );

//        set("where","north");
	set("vendor_goods", ({
		"/d/city/npc/obj/mabudai",
		"/d/city/npc/obj/beixin",
		"/d/city/npc/obj/toukui",
		"/d/city/npc/obj/cycle",
		"/d/city/npc/obj/surcoat",
		"/d/city/npc/obj/shield",
		"/d/city/npc/obj/huwan",
		"/d/city/npc/obj/zhitao",
		"/d/city/npc/obj/huyao",
		"/d/city/npc/obj/caoxie",
		"/d/city/npc/obj/pixue",
		"/d/city/npc/obj/shoutao",
		"/d/city/npc/obj/tieshou",
		"/d/city/npc/obj/jinsijia",
		"/d/xingxiu/obj/fire",
		"/clone/misc/chema",
	}));

        setup();
        add_money("silver", 5);
        add_money("coin", 300);
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "丐帮" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
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

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}