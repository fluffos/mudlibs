//书店老板
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("唐老板", ({ "tang laoban", "tang","laoban" }));
        set("long","唐老板本是南方人，不知道怎么跑到洛阳来作水果生意。\n不过她卖的大都是南方的水果。\n");
        set("shen_type", 1);
        set("gender", "女性");
        set("age", 38);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
             __DIR__"obj/apple",
             __DIR__"obj/durian",
             __DIR__"obj/banana",
             __DIR__"obj/pineapple",
             __DIR__"obj/orange",
             __DIR__"obj/watermelon",
             __DIR__"obj/lichee",
        }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
