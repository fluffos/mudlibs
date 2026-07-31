// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("李老伯", ({ "lilaotou", "li", "laotou" }));
	set("title", "尚武书店老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long",
		"李老伯久居平安城，据说他年轻时是个武林高手，\n");
	set("combat_exp", 38000);
	set("attitude", "friendly");
	
//	set("vendor_goods", ({
//		"/d/pingan/npc/shop/book1",
//		"/d/pingan/npc/shop/book2",
//               "/d/pingan/npc/shop/book3",
//               "/d/pingan/npc/shop/book4",
	//}));

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
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("李老板笑眯眯地说道：人客来坐。\n");
		break;
	case 1 :
		say("李老板说道：这位兄弟，你要买什么？\n");
		break;
	}
}
