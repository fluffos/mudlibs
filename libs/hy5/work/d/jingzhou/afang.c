// afang.c 阿芳
// congw 98/08/29

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("阿芳", ({ "afang", "fang" }));
	set("title", "茶僚老板");
        set("nickname", "荆州老姑娘");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
        set("age", 20);
        set("per", 30);
	set("long",
                "阿庆嫂是荆州城里有名的大美人，因为爷儿们总喜欢往她这儿逛，\n"
                "阿芳也因为不知道的原因，迟迟不嫁，惹得爷儿们心痒痒。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
                "结婚" : "结婚？你有几万两黄金？？筹够了来找我吧。嘻嘻！\n",
		"生意" : "这个么……。还将就。\n",
	]));
	
	set("vendor_goods", ({
		__DIR__"obj/peanut",
		__DIR__"obj/tofu",
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
	add_action("do_sell", "sell");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
                say("阿芳笑着打招呼：这位" + RANK_D->query_respect(ob) +
			"，要点啥吗？\n");
		break;
	case 1 :
                say("阿芳说道：嗨！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！我的卖的吃的都是家传秘方做的哟！\n");
		break;
	}
}
