// yang.c 杨老板 

inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("杂货铺老板", ({ "lao ban", "laoban" }));
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 45);
        set("long",
                "老板是土生土长的扬州人，做了几十年的小买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
		(["name": BOOK_D("quanpu"),"number":15]),
		(["name": MISC_D("mabudai"), "number": 5]),
		(["name": ARMOR_D("beixin"),"number":12])
        }));
        
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",1);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

