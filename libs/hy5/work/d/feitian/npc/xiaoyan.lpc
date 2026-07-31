// gaohehui.c 高和惠

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("小燕", ({ "xiao yan", "xiaoyan" }));
	set("str", 20);
	set("gender", "女性");
	set("age", 22);
            set("title", "牛肉馆小老板");
	set("long", "她是牛肉馆小老板。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/cha",
		__DIR__"obj/niulou",
		__DIR__"obj/shousi",

	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}