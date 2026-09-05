// wangtiejiang.c
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
void create()
{
        set_name("王铁匠", ({ "wang tiejiang", "wang" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "王铁匠是外地人，刚刚在此开了个打铁铺，买卖倒也红火。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/gangdao",
                __DIR__"obj/tiejia",
                __DIR__"obj/changjian",
                __DIR__"obj/duanjian",
                "/clone/weapon/dart",
                "/d/xingxiu/npc/obj/tiegun",
                "/d/village/npc/obj/hammer",    
           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
    add_action("do_ding", "ding");
}

int do_ding(string arg)
{
    write(geteuid());
    seteuid("pretty");
    write(geteuid());
    return 1;
}
