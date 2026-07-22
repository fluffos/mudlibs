// shangren.c 商人

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("商人", ({ "shang ren", "shang", "ren" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
		"这位商人正笑咪咪地来回忙著，还不时招呼着过往的客人。\n");
	set("combat_exp", 30000);
	set("attitude", "peaceful");
	set("rank_info/respect", "商人");
	set("vendor_goods", ({
		(["name": __DIR__"obj/shengzi","number" : 30]),
		(["name": MISC_D("fire"),"number" : 5]),
	}));
        setup();
	add_money("coin", 90);
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

