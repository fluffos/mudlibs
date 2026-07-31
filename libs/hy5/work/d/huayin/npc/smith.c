// smith.c

inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("史老汉", ({ "shi lao han"}) );
        set("gender", "男性" );
        set("age", 58);
	set("str",88);
        set("long", "他就是铜山村的史铁匠。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 10);
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