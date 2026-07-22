// laoban.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老板", ({ "lao ban", "ban" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是苏州城里药铺里有名气的老板。\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 200);
	set("max_jing", 300);
	set("shen_type", 1);

	set("combat_exp", 40000);
	set("attitude", "friendly");

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 40);
	set_temp("apply/attack", 7);
	set_temp("apply/defense", 7);
	set_temp("apply/damage", 5);

	set("vendor_goods", ({
	}));

	setup();
	add_money("silver", 10);
}

void init()
{
//add_action("do_buy", "buy");
}
