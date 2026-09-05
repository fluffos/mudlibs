inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("扬铁匠", ({ "yang tiejiang", "yang" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "扬铁匠是祖传几代的老把式,这家打铁铺,还有对面张铁匠的买卖,为保卫襄阳出了不少力.\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
              "/d/migong/xiaocun1/obj/yuenu" ,
              "/d/migong/xiaocun1/obj/guitou" , 
              "/d/migong/xiaocun1/obj/lianhuan",
              "/d/migong/xiaocun1/obj/qingtong",           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


