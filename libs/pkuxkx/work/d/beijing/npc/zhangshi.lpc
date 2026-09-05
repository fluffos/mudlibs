//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void set_vendor_status(int);

void create()
{
        set_name("张氏", ({ "zhang shi","zhang" }) );
        set("gender", "女性" );
        set("age", 32);
        set("long",
                "她就是京城绸缎庄的老板娘，长的还有几分姿色。\n");
        set("vendor_goods", ({
             "/d/xiangyang/npc/obj/buliao1",
             "/d/xiangyang/npc/obj/buliao2",
             "/d/xiangyang/npc/obj/buliao3",
             "/d/xiangyang/npc/obj/buliao4",
        }) );
        set("shen_type",1);set("score",200);setup();
	set_vendor_status(30);
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 60);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

#include "/d/beijing/killme.h"
