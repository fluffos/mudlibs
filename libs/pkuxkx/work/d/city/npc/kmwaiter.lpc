

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("伙计", ({ "huoji", "waiter" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 25);
	
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	
	set("vendor_goods", ({
		__DIR__"obj/kmfood1",
		__DIR__"obj/kmfood2",
        __DIR__"obj/kmfood3",
        __DIR__"obj/jiudai",
//                __DIR__"obj/tairu", //不合武侠氛围
	}));

	setup();
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();

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
		say("伙计笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进来坐坐。\n");
		break;
	case 1 :
		say("伙计说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！本店有各种菜式，快来试试。\n");
		break;
	}
}
