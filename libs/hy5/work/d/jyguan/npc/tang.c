// tang.c 当铺老板 

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int redeem(string arg);

void create()
{
	set_name("唐某", ({ "tang" }));
	set("title", "当铺老板");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"据说和中土经营当铺生意的唐氏是同宗。\n");
	set("no_get_from", 1);
	set("no_get",1);
	set_skill("unarmed", 80);
	set_skill("dodge", 70);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}

void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
