
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("张铁匠", ({ "zhang tiejiang", "zhang" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "张铁匠是祖传几代的老把式,这家打铁铺,还有对面扬铁匠的买卖,为保卫襄阳出了不少力.\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
             __DIR__ "obj/qingtong",
             __DIR__"obj/lianhuan",
                }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
