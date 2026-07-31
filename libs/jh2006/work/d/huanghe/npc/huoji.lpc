// huoji. 药铺伙计

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("伙计", ({ "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("per", 18);
        set("age", 18);
        set("long", "他是这儿的伙计，正在店里忙里忙外。\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/clone/medicine/zhuye" :6,
                "/clone/medicine/jinchuang" :25,
                "/clone/medicine/huoxiang" :12,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

