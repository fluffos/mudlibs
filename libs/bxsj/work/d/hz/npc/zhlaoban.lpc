// yang.c 李老板 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("李老板", ({ "li laoban", "li" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long", "李老板是土生土长的杭州人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		(["name": BINGQI_D("changjian"), "number":10]),
		(["name": BINGQI_D("gangdao") , "number":15]),
		(["name": MISC_D("mabudai"), "number":15]),
		(["name": ARMOR_D("beixin"), "number":20]),
		(["name": MISC_D("fire"), "number":15]),
		(["name": BINGQI_D("zhubang"), "number":25])
        }));
        setup();
        carry_object(ARMOR_D("jinduan"))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
