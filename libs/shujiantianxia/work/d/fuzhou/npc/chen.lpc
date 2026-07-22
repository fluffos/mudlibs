// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("陈阿婆", ({ "chen apo", "chen", "apo" }));
	set("title", "杂货铺老板娘");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "女性");
	set("age", 55);
	set("long",
		"陈阿婆久居福州城，据说她年轻时很有几分风韵，福威镖局\n"
		"当时的少镖头林震南还追求过她。\n");
	set("combat_exp", 280000);
	set("attitude", "friendly");
	set("inquiry", ([
                "林震南" : "阿南生着那俊，那会琢一个河南七子婆，唉。\n",
                "name" : "婆婆我夫家姓陈。陈林半边天嘛。\n",
                "here" : "福州是个港口，会行船的人很多。\n",
	]));

	set("vendor_goods", ({
		(["name": "/d/fuzhou/npc/obj/xiuhua","number":5]),
		(["name": "/d/city/obj/flower_shoe","number":5]),
		(["name": "/d/city/obj/pink_cloth","number":5]),
		(["name":  "/d/city/obj/goldring","number":5]),
		(["name":   "/d/city/obj/necklace","number":5])
	}));

	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
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
		say("陈阿婆笑眯眯地说道：人客来坐。\n");
		break;
	case 1 :
		say("陈阿婆说道：可嘴的，你要买什？\n");
		break;
	}
}
