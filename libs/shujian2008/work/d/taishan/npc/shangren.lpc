// yang.c 杨老板 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("商人", ({ "shang ren", "ren" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "他穿的很朴素，在这附近做了几年的生意，也没赚到多少钱。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
		(["name": MEDICINE_D("yangjing"),"number": 10]),
		(["name": MISC_D("fire"),"number": 5]),
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
