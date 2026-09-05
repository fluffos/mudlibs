// wujiang.c 武将

inherit NPC;


void create()
{
	set_name("士兵", ({ "shi bing", "bing" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他是一名京营士兵，正在这里巡逻，守卫六部衙门。\n");
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("spear", 100);
	set_skill("yangjia-qiang", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/changqiang")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
#include "die.h"