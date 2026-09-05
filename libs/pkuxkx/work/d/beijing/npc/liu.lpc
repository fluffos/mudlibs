//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("刘富贵", ({ "liu fugui", "liu" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是杂货铺的老板，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/obj/recipe/material/flour",
                "/obj/recipe/material/rice",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 60);
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
       if( !this_object()->visible(ob)) return;
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("刘富贵笑眯眯地说道：您请坐。\n");
		break;
	case 1 :
		say("刘富贵说道：客官好，您要买点儿什么？\n");
		break;
	}
}
