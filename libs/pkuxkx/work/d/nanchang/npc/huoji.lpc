// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("巫医", ({ "wu yi", "wuyi","doctor" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 40+random(18));
	set("long", "他是壮族山寨的神医，远近闻名。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		        
                "/clone/drug/hugu",
                "/clone/drug/jinchuang",
                "/clone/drug/yangjing",
                

	}));

	set("shen_type",1);set("score",200);setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
