// zine aug 26 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"巨蟒"NOR,({"ju mang","mang","jumang","snake","python"}));
	set("race","野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs",({"bite"}));
	set("age",random(500));
	set("combat_exp",10000000);
	set("long","这是一只黑色的巨蟒。\n");
	set("max_qi",50000);
	set("max_jing",50000);
	set("max_neili",50000);
	set("neili",50000);
	set("jiali",400);
	set("eff_jingli",50000);
	set("jingli",50000);
	set("str",80);
	set("con",60);
	set("dex",80);
	set("chat_chance", 10);
    set("chat_msg", ({
		"巨蟒盘起身体，昂着头，对你做出了攻击的姿势。\n",
		"巨蟒吐出了蛇信，愤怒地打量着你。\n",
	}));
	set_temp("apply/attack",200);
	set_temp("apply/damage",200);
	set_temp("apply/armor",800);
	setup();
	carry_object("/biwu/xy/obj/jmd");
}

void init()
{
	object ob = this_player();
	
	if(userp(ob))
		{
			
			remove_call_out("kill_ob");
       		call_out("kill_ob", 1, ob);
       	}
}

