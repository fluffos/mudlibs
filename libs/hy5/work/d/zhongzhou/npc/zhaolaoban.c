inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("赵德言", ({ "zhao deyan", "zhao", "deyan" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);

        set("gender", "男性");
        set("age", 45);
        set("long", "赵德言是土生土长的中州人，做了几十年的小买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/cuttonp",
                "/d/xingxiu/obj/fire",
                __DIR__"obj/chanhs",
                __DIR__"obj/wood",
                __DIR__"obj/shoeshine",
                __DIR__"obj/brush",
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
