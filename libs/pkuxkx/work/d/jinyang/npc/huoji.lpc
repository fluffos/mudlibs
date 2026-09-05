// huoji. 药铺伙计

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是一个忙碌的小伙计。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/obj/jinchuang",
                "/d/city/obj/yangjing",
                "/d/city/npc/obj/renshen2",
                "/d/city/npc/obj/lingzhi",
                "/d/taishan/obj/danggui",
	}));

	set("shen_type",1);set("score",200);setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
#include "die.h"