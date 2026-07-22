inherit NPC;
inherit F_VENDOR;
//inherit F_DEALER;

void create()
{
        set_name("郏芯", ({ "jia xin", "jia" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 35);
        set("long",
                "郏老板是土生土长的凤凰星人，做了几十年的小买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/u/zhangm/fenghuang/obj/beixin",
                "/u/zhangm/fenghuang/obj/toukui",
                "/u/zhangm/fenghuang/obj/cycle",
                "/u/zhangm/fenghuang/obj/shield",
                "/u/zhangm/fenghuang/obj/pixue",
                "/u/zhangm/fenghuang/obj/huoba",
                        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


