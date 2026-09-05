//书店老板
inherit NPC;
inherit F_DEALER;
void create()
{
    int i=random(100);
        set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
        set("long","一个在药铺里跑堂的伙计。\n");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 18);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
       if (i>30)
    {
        set("vendor_goods", ({
		"/d/city/obj/jinchuang",
                "/d/city/obj/yangjing",
          //      __DIR__"obj/renshen2",
          //      __DIR__"obj/lingzhi",
        }));
    }
	else
    {
        set("vendor_goods", ({
		"/d/city/obj/jinchuang",
                "/d/city/obj/yangjing",
            //    __DIR__"obj/renshen2",
            //    __DIR__"obj/lingzhi",
            "/d/taishan/obj/shechuangzi",
    }));
    
   }
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

