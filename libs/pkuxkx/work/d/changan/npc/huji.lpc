// yang.c 杨老板 
#include <command.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("胡姬", ({ "hu ji", "hu" }));
	set("shen_type", 1);
  set("start_room","/d/changan/jiusi");

	set("gender", "女性");
	set("age", 35);
	set("long",
		"来自波斯的胡姬，跳着异国风情的舞蹈，在酒桌之间跳动。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
    "/d/changan/obj/hubing",
    "/d/changan/obj/botuo",
    "/d/changan/obj/biluo",
    "/d/changan/obj/kaoe",
    "/d/changan/obj/putaojiu",
    "/d/changan/obj/sanlejiang",
	}));
	setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}	