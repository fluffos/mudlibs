// Rewrote by iszt@pkuxkx, 2007-02-12

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("王明", ({ "wang ming", "wang", "ming" }));
	set("nickname", HIG"乐善好施"NOR);
	set("gender", "男性");
	set("age", 51);
	set("long", "他长得白白胖胖的，一团和气。最喜当人面前逞能卖好，博取善名。\n");
	
	set("combat_exp", 1000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}