// yang.c 杨老板 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("杨永贵", ({ "Yang yonggui", "yang" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"杨老板是土生土长的本地人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/xingxiu/obj/fire",
		"/clone/misc/chema",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
