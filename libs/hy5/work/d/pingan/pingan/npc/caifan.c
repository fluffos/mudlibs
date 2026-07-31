// xiaoer2.c 面馆小二

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("卖菜的", ({ "caifan" }) );
	set("gender", "男性" );
	set("age", 22);
        set("long",
                "一个为生活而终日奔波的小商人．\n");
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/cai",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


