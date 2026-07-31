// Room: /d/chengdu/npc/xiaofan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小贩", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
	set("shen_type", 1);
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/village/npc/obj/stick",
		"/d/village/npc/obj/shoes",
		"/d/village/npc/obj/bottle",
		__DIR__"obj/food/jitui",
		__DIR__"obj/food/jiudai",
	}) );
	setup();
	carry_object(__DIR__"obj/cloth/male-cloth")->wear();
	carry_object(__DIR__"obj/cloth/male-shoe")->wear();
	add_money("coin", 100);
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

