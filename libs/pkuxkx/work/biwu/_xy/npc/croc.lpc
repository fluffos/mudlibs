// zine aug 26 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"鳄鱼"NOR,({"e yu","e","croc"}));
	set("race","野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs",({"bite"}));
	set("age",random(500));
	set("combat_exp",8000000);
	set("long","这是一只土黄色的鳄鱼。\n");
	set("max_qi",40000);
	set("max_jing",40000);
	set("max_neili",40000);
	set("neili",40000);
	set("jiali",300);
	set("eff_jingli",40000);
	set("jingli",40000);
	set("str",80);
	set("con",80);
	set("dex",20);
	set("chat_chance", 10);
    set("chat_msg", ({
		"鳄鱼流下了几滴眼泪。\n",
		"鳄鱼懒洋洋的看着你，就像看着一块晚餐一样。\n",
	}));
	set_temp("apply/attack",200);
	set_temp("apply/damage",200);
	set_temp("apply/armor",800);
	setup();
	carry_object("/biwu/xy/obj/eyp");
}

void init()
{
	object ob = this_player();
	
	if(userp(ob))
		{
			
			remove_call_out("kill_ob");
       		call_out("kill_ob", 3, ob);
       	}
}

