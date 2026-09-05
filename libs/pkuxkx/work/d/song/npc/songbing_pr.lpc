// bing.c 官兵

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("捧日卫战士", ({ "pengri zhanshi","zhanshi", "shi" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是一位捧日卫麾下的士兵。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);


    
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	//carry_object("/clone/weapon/fangtianji")->wield();
	carry_object("/d/hangzhou/npc/obj/junfu")->wear();
}

