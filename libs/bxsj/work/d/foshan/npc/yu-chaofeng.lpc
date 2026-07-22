// yu.c 俞朝奉 

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("俞朝奉", ({ "yu chaofeng", "yu", "chaofeng" }));
	set("long",
		"一双贼眼骨碌骨碌地转着，看起来一副尖酸刻薄的样子。\n");
	set("shen_type", 0);
        set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"当铺老板正在盯着你看来看去。\n");
	set("no_get_from", 1);

        set("no_clean_up", 0);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
        carry_object("/clone/misc/jinduan")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
}

void unconcious()
{
	say( "俞朝奉从怀中取出一瓶药来，喝了两口，神色大为好转。\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}
