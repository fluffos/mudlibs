// huoji. 药铺伙计

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
        set("str", 20);
        set("gender", "男性");
        set("age", 18);
        set("long", "他是一位从乡下来帮忙的伙计。\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
           (["name":__DIR__"obj/lianzi-wan","number":10]),
           (["name":__DIR__"obj/zhengqi-dan","number":10])

          }));

        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

