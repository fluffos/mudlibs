//书店老板
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("茶馆伙计", ({ "chaguan huoji", "huoji" }));
        set("long","一个在茶馆里跑堂的伙计。\n");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 18);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
             "/d/city/obj/xhlj",
             "/d/city/obj/hsmj",
             "/d/city/obj/tgy",
             "/d/city/obj/jhch",
             "/d/city/obj/erlxzh",
             "/d/city/obj/wlch",
           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

