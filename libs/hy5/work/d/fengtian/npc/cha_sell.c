// cha_sell.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("马大嫂", ({ "ma dasao" }) );
	set("title","茶馆老板娘");
        set("gender", "女性" );
        set("age", 35);
        set("long","这是一位满脸笑容的中年妇女。\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

	set("sell_all_day",1);

        setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{	
	object ob;

	::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}