// smith.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("ÖÜÌú½³", ({ "smith zhou","zhou","smith" }) );
        set("gender", "ÄÐÐÔ" );
        set("age", 38);
	set("str",88);
        set("long", "Ìú½³ÆÌÀÏ°åÕÅÌú½³¡£\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
	set("attitude", "friendly");
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
