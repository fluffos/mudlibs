inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("杂货铺老板", ({ "lao ban", "laoban" }));
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 45);
        set("long",
                "老板是土生土长的中原人，做了几十年的小买卖，因为逃避官兵追杀，跑到南疆来了。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
            (["name": FOOD_D("bottle"),"number" : 20]),
            (["name": BINGQI_D("zhujian"),"number" : 15]),
            (["name": MISC_D("fire"),"number" : 5]),
            (["name": BINGQI_D("zhubang"),"number" : 10]),
            (["name": ARMOR_D("beixin"),"number" : 10]),
        }));
        
        setup();
        add_money("silver",1);
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
