inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("王老板", ({ "wang" }) );
	set("gender", "男性" );
	set("age", 31);
	set("long",
		"防具店的老板,手底下还可以．\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ({
		"d/city/npc/obj/mabudai",
		"d/city/npc/obj/beixin",
		"d/city/npc/obj/toukui",
		"d/city/npc/obj/cycle",
		"d/city/npc/obj/surcoat",
		"d/city/npc/obj/shield",
		"d/city/npc/obj/huwan",
		"d/city/npc/obj/zhitao",
		"d/city/npc/obj/huyao",
		"d/city/npc/obj/caoxie",
		"d/city/npc/obj/pixue",
		"d/city/npc/obj/shoutao",
		"d/city/npc/obj/tieshou",
		"d/city/npc/obj/jinsijia",
		"/d/xingxiu/obj/fire",
	}));
	set_skill("sword",80);
	set_skill("dodge",50);
	set_skill("parry",50);
	setup();
//	carry_object(__DIR__"/shop/changjian")->wield();
	carry_object(__DIR__"shop/tiejia")->wear();
}
void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

