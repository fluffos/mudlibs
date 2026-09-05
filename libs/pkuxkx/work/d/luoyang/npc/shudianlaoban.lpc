//书店老板
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("小厮", ({ "xiao si",}));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 65);
        set("long",
                "一个让孩子们一见就觉得可亲的老翁，他曾经在这里经营一家书店。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/unarmed_book",
                __DIR__"obj/finger_book",
                __DIR__"obj/cuff_book",
                __DIR__"obj/hand_book",
                __DIR__"obj/strike_book",
                __DIR__"obj/claw_book",
           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

