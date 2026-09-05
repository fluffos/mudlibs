// yang.c 杨老板 
#include <command.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("曲妍", ({ "qu yan", "qu" }));
	set("title", "胭脂铺老板");
	set("shen_type", 1);
  set("start_room","/d/changan/yanzhipu");

	set("gender", "女性");
	set("age", 35);
	set("long",
		"胭脂铺曲老板经营的胭脂水粉深受长安城内名门仕女，普通百姓的喜欢。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
    "/d/city/obj/silk_mask",
    "/d/city/obj/xyj_mask",
    "/d/city/obj/antidis_book",
    "/d/city/obj/easy_ftools",
    "/d/city/obj/normal_ftools"
	}));
	setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}	