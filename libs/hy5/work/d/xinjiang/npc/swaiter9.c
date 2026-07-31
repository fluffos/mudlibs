 // copyright apstone, inc 1998
inherit NPC;

inherit F_DEALER;
void create()
{
        set_name("卖馕的", ({ "nang seller" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                "一个普普通通的本地人，没有一点起眼的地方。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/nang",
        }));
        setup();
        carry_object(__DIR__"obj/kacloth")->wear();
} 
void init()
{
        object ob; 
        ::init();

        add_action("do_buy", "buy");add_action("do_list", "list");
} 
