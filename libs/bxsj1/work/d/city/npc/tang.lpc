// tang.c 唐老板 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("当铺老板", ({ "lao ban", "laoban" }));
	set("shen_type", 0);
        set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"当铺老板正在盯着你看来看去。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}
