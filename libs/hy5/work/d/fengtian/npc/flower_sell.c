// flower_sell.c


inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("卖花女", ({ "flower seller" }) );
	set("gender", "女性" );
	set("age", 15);
	set("long","这是一位清秀的小女孩。\n");
	set("combat_exp", 50);

	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/rose",
		__DIR__"obj/y_rose",
		__DIR__"obj/w_rose",
		__DIR__"obj/baihe",
		__DIR__"obj/ju",
	}));


	set("sell_all_day",1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}