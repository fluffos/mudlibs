

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("茶博士", ({ "cha boshi", "boshi" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	
	set("vendor_goods", ({
		"/d/city/npc/obj/peanut",
		"/d/city/npc/obj/tofu",
        "/clone/misc/guider",
	}));

	setup();
    carry_object("/clone/cloth/cloth")->wear();

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
       // add_action("do_sell","sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
        if( !this_object()->visible(ob)) return;
	switch(random(2)) {
	case 0 :
		say("茶博士笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来喝杯热茶。\n");
		break;
	case 1 :
		say("茶博士说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！本店有刚炸好的五香花生出售。\n");
		break;
	}
}
