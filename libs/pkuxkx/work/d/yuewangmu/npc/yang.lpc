//杨铁心
//

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_MASTER;



void create()
{
        set_name("杨老板", ({ "yang tiejiang", "yang" }));
        set("title", "枪铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "杨老板是一个精明的生意人,靠卖仿制的夺魄枪赚了不少钱。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/yuewangmu/obj/falsedpqiang",
                "/d/yuewangmu/obj/dmqiang",
                "/d/yuewangmu/obj/gangqiang",
                "/d/yuewangmu/obj/changqiang",
                "/d/yuewangmu/obj/hyqiang",
           }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

