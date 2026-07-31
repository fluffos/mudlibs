inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("李老板", ({ "li" }) );
	set("gender", "男性" );
	set("age", 31);
	set("long",
		"武嚣店的老板,手底下还可以．\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ({
		"/d/pingan/npc/shop/changqiang",
//		"/d/pingan/npc/shop/changjian",
//		"/d/pingan/npc/shop/gangjian",
		"/d/pingan/npc/shop/club",
		"/d/pingan/npc/shop/gangdao",
//		"/d/pingan/npc/shop/blade",
		"/d/pingan/npc/shop/throwing",
		"/d/pingan/npc/shop/zhubang",
		"/d/pingan/npc/shop/whip",
	}));
	set_skill("sword",80);
	set_skill("dodge",50);
	set_skill("parry",50);
	setup();
	carry_object(__DIR__"obj/sword")->wield();
	carry_object(__DIR__"shop/tiejia")->wear();
}
void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

