// hou.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("王大米", ({ "wang dami", "dami", "wang" }));
	set("gender", "男性");
	set("nickname", HIC"米行工头"NOR);
	set("age", 40);
	set("str", 20);
	set("dex", 20);
	set("per", 20);
	set("long", "这位就是这家米行的工头，负责指挥工人将货物搬进搬出，\n"+
		"如果你想打工赚些钱，可以跟他谈谈看。\n");
	set("combat_exp", 35000);
	set("shen_type", 0);
	set("attitude", "peaceful");

	set_skill("cuff", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
