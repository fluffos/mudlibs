
// weaponor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("兵器贩子", ({ "weaponor" }) );
        set("title", "兵器屋");
        set("gender", "男性" );
        set("age", 32);
        set("long", "卖兵器的是个中年人，满脸伤疤。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 60);

        set("inquiry", ([
                "兵器屋" : "本店专卖各种长短兵器", 
        ]) );
//        set("where","north");

        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));
        setup();
        add_money("silver", 50);
        add_money("coin", 300);
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "兵器贩子道：这位"
                                + RANK_D->query_respect(ob)
                                + "，自个儿挑一件称手的兵器吧\n");
                        break;
                case 1:
                        say( "兵器贩子突然间出了神，好象想起了他的往事\n");
                        break;
				case 2:
						say("兵器贩子突然神秘的说，我们这里可是有好武器卖的哟！！\n");
						break;
        }
}
