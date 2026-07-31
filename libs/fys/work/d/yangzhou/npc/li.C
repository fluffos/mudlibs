// yangzhou 蓝老板 

inherit NPC;
//inherit F_VENDOR;
//inherit F_DEALER;

void create()
{
	set_name("李德昌", ({ "li dechang", "li","deng chang","boss" }));
	set("title", "米店老板");
	set("mingwang", 10);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"李老板是土生土长的扬州人，做了几十年的米店生意。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
//	set("vendor_goods", ({
//		__DIR__"obj/mabudai",
//		__DIR__"obj/changjian",
//	}));
	
	setup();
}

//void init()
//{
        //add_action("do_list", "list");
        //add_action("do_buy", "buy");
//}
