inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("杨铁匠", ({ "yang tiejiang", "yang" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "杨铁匠是祖传几代的老把式,这家打铁铺也是老字号了。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
               "/d/city/obj/gangdao" ,
               "/d/city/obj/tiejia",
               "/d/xingxiu/npc/obj/tiegun",
               "/d/village/npc/obj/hammer",

           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
