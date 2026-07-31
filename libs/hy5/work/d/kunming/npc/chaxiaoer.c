// chaxiaoer


inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("茶小二", ({ "xiao er", "xiao" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这个茶小二正忙着给客人送茶，递烟。");
	set("combat_exp", 500);
	set("attitude", "friendly");
		
	set("vendor_goods", ({
		__DIR__"obj/yan",
		__DIR__"obj/wan",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
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
		say("茶小二热情的说到：这位" + RANK_D->query_respect(ob) +
			"，马上给你上茶。\n");
		break;
	case 1 :
		say("茶小二说道：这位" + RANK_D->query_respect(ob) + 
			"要不要来两口水烟提提神。\n");
		break;
	}
}
