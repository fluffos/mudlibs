// zhang.c 张老板

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("张老板", ({ "lao ban", "laoban", "zhang" }));
	set("shen_type", 0);
        set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 46);
	set("long",
		"这个当铺老板正眯缝着眼睛在盯着你看来看去。\n");
	set("no_get_from", 1);

	set("no_clean_up", 0);
	set_skill("unarmed", 600);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

