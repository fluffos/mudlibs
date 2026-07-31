// yang.c 杂货铺伙计 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("助手", ({ "zhushou", "shou" }));
	set("title", "杂货铺伙计");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 29);
	set("long",
		"伙计是土生土长的扬州人，在杂货铺干了好几年了。\n");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 4000);
	set("attitude", "friendly");
	set("vendor_goods", ({
	      __DIR__"obj/pixue",
		__DIR__"obj/shoutao",
		__DIR__"obj/tieshou",
		__DIR__"obj/jinsijia",
		"/d/xingxiu/obj/fire",
	     "/clone/pants/piku",
		"/d/item/obj/chanhs",
		"/d/city/obj/rrose",
		"/d/city/obj/yrose",
		"/clone/misc/wood",
		"/clone/misc/shoeshine",
		"/clone/misc/brush",
	}));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

