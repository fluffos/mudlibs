// book_boss.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("书店老板", ({ "book seller" }) );

        set("gender", "男性" );
        set("age", 45);
	set("long","他就是盛京书店的老板。\n");
        set("combat_exp", 50);

	set("sell_all_day",1);

        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/npc/obj/lbook1",
                "/d/city/npc/obj/lbook2",
                "/d/city/npc/obj/lbook3"
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        add_action("do_list","list");
        add_action("do_buy", "buy");
 


}