// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("王阿婆", ({ "wang apo", "wang", "apo" }));
	set("title", "杂货铺老板娘");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "女性");
	set("age", 55);
	set("long",
		"王阿婆久居平安城，据说她年轻时很有几分风韵，\n"
		"当时的绝情星星还追求过她。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
                "绝情星星" : "他怎会看上我呢，唉。\n",
                "name" : "婆婆我夫家姓王。所以叫王阿婆。\n",
                "here" : "平安城是个地方,很安全。\n",
	]));
	
	set("vendor_goods", ({
		"/d/pingan/npc/shop/xiuhua",
		"/d/pingan/npc/shop/flower_shoe",
                "/d/pingan/npc/shop/pink_cloth",
                "/d/pingan/npc/shop/goldring",
                "/d/pingan/npc/shop/necklace",
//                "/d/pingan/npc/shop/mianju",
                "/d/pingan/npc/shop/mabudai",
                "/d/pingan/npc/shop/sleepbag",
	}));

	setup();
   carry_object("/d/city/obj/flower_shoe")->wear();
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
		say("王阿婆笑眯眯地说道：人客来坐。\n");
		break;
	case 1 :
		say("王阿婆说道：可嘴的，你要买什？\n");
		break;
	}
}
