
// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("火头军", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "火头军正忙着招呼军人, 一手提着茶壶, 一手拿着抹布\n");
	set("combat_exp", 5000);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
//        set("where","north");
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        object ob;

        ::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

