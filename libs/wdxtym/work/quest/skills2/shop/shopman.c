// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("欧野子", ({ "ouoyezi", }));
	set("title", "圣兵器铺老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 55);
	set("long",
		"欧野子久居平安城。他的店里专门专卖一些高档兵器的仿制品\n");
	set("combat_exp", 40000000);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		__DIR__"shops/ban",
		__DIR__"shops/bian",
		__DIR__"shops/club",
		__DIR__"shops/dao",
		__DIR__"shops/hammer",
		__DIR__"shops/qiang",
		__DIR__"shops/sword",
		__DIR__"shops/zhang",
		__DIR__"shops/axe",
		__DIR__"shops/banzi",
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
		say("欧野子笑眯眯地说道：我这里东西多多。\n");
		break;
	case 1 :
		say("欧野子说道：我这里应有尽有？\n");
		break;
	}
}
