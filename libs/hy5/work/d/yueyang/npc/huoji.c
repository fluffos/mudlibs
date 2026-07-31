// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "这是一个不太老实的伙计。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"jinchuang",
		__DIR__"yangjing",
		__DIR__"dust",
		__DIR__"xionghuang",
	}));

	setup();
	carry_object("/clone/cloth/male1-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
