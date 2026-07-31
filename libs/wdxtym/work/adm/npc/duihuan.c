// huanong.c

#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("兑换使者", ({ "duihuan shizhe"}));
	set("nickname","无所不在"); 

	set("gender", "男性");
	set("long",
		"一位非常牛逼的兑换使者。\n");
	set("str", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 800000);
	set("attitude", "friendly");

	set("vendor_goods", ([
		"/clone/tingyuge"    : 100000,//3						
	]));

	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
		"排好队，一个一个来”\n",
	}));

	carry_object("/clone/cloth/cloth")->wear();
	set_max_encumbrance(100000000);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
