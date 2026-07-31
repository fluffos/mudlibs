// yang.c 杨老板 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("赵老板", ({ "zhao laoban", "zhao", "laoban"}));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"赵老板是土生土长的大理人，做了几十年的小买卖。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
        set("unique", 1);
	set("combat_exp", 40000);
	set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":ARMOR_D("beixin"),"number":15]),
         }));
	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
