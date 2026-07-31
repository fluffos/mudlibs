// tangtian.c 唐甜


inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("唐甜", ({ "tang tian", "tang" }));
	set("title", "茶铺小姑娘");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 16);
	set("long",
		"可爱的小姑娘，总是笑得那么甜，但在她的眼神里，\n"
		"隐隐带着一股邪气。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", ([
		"龙都香茗" : "这可是我们蜀中的名茶哟。\n",
		"刚柔并济盟" : "这个么……。\n",
	]));
	
	set("vendor_goods", ({
		"/d/tangmen/obj/zhusun",
		"/d/tangmen/obj/tea",
                "/d/tangmen/obj/jitui",
                "/d/tangmen/obj/jiudai",
	}));

	setup();
	carry_object("/d/tangmen/obj/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("唐甜带着蜜般的笑容说道：这位" + RANK_D->query_respect(ob) +
			"，来喝杯龙都香茗吧。\n");
		break;
	case 1 :
		say("唐甜笑嘻嘻说道：这位" + RANK_D->query_respect(ob) + 
			"您来了啊！我这儿有蜀中特产翡翠竹荪。\n");
		break;
	}
}
