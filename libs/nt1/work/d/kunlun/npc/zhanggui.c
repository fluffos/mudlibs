inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("张掌柜", ({ "zhang zhanggui", "zhang" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "别看张掌柜整天懒洋洋的，他心里可盘算得精着呢。\n"+
                "在这边陲之地，再怎么也得有几分本事。\n");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_temp("apply/damage", 25);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city2/obj/diaopi",
                "/d/city/npc/obj/sleepbag",
                "/d/city/obj/beixin",
                "/d/city/obj/pink_cloth",
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
