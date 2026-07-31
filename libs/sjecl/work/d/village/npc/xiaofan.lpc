// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小贩", ({ "xiao fan" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long",
                "这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
        	 (["name": __DIR__"obj/stick" ,"number":25]),
        	 (["name": __DIR__"obj/shoes" ,"number":15]),
        	 (["name": __DIR__"obj/bottle" ,"number":15]),
        	 (["name": __DIR__"obj/egg" ,"number":20]),
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 100);
}

void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
