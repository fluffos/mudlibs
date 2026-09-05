#include <ansi.h>
inherit NPC;

void create()
{
	set_name("卫士", ({"wei shi","shi","guard"}));
	set("long", 
            HIG"他是和林的金帐卫士的一员。\n"NOR);
	set("gender", "男性");
    set("random_npc",1);
	set("age", 20+random(10));
    set("combat_exp", 400000);
    set_skill("blade", 150);
    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("parry", 150);
    set("d_menggu_shi",1);
    set_temp("apply/attack", 10);
    set_temp("apply/defense", 10);
	set_temp("shediaoquest/jdfm/kouling","finish");
	set("shen_type", -1);
	setup();
    carry_object(__DIR__"items/dao")->wield();
    carry_object(__DIR__"items/cloth5")->wear();
}

void unconcious()
{
	die();
}