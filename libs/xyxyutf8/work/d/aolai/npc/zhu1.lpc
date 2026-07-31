inherit F_VENDOR_SALE;

void create()
{
       set_name("竹老大", ({"bamboo man", "man"}));
       set("long", "竹老大从小编竹，靠竹器谋生。
附近的人都叫他竹老大，把他的真名倒忘了。\n");
       set("gender", "男性");
        set_level(4);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed",40);
	set_skill("dodge",35);
        set("vendor_goods", ([
                "kuang": "/d/obj/misc/kuang",
        ]) );
        setup();
       	add_money("silver", 1);
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
}

