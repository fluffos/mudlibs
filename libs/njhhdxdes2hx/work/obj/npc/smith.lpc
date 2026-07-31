// smith.c 铁匠 

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("李铁匠", ({ "tiejiang li", "li" }));
        set("title", "铁匠铺老板");
        set("shen_type", 0);

        set("gender", "男性");
        set("age", 60);
        set("long",
                "李铁匠以打铁为生，他打造的兵器远进闻名。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 55);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ([
               "/obj/weapon/duanjian":5,
               "/obj/weapon/changjian":4,
               "/obj/weapon/gangjian":3,
               "/obj/weapon/gangdao":5,
               "/obj/weapon/tiegun":6,
               "/obj/weapon/bian":2,
               "/obj/weapon/hammer":3
        ]));

        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
        add_action("do_buy", "buy");
}

