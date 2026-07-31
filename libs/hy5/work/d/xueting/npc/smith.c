// smith.c
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("张铁匠", ({ "smith zhang","zhang","smith" }) );
        set("gender", "男性" );
        set("age", 38);
	set("str",88);
        set("long", "他就是雪亭镇铁器作坊老板张铁匠。\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));

        setup();

	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
