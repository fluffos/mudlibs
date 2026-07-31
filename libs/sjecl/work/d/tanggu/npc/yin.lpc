// yin.c 殷老板
inherit NPC;

inherit F_DEALER;
void create()
{
	set_name("殷老板", ({ "yin laoban", "yin", "laoban" }));
	set("shen_type", 0);
        set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long", "当铺老板正在盯着你看来看去。\n");
	set("no_get_from", 1);
    
	set("no_clean_up", 0);
	set_skill("cuff", 60);
	set_skill("dodge", 60);
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
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}
