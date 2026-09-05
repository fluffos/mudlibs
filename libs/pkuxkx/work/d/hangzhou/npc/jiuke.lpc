// jiuke.c
// by hubo 208/4/19

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("酒客", ({ "jiu ke","ke" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这是位外地客人，特意来临安府酒家吃饭。\n");
	set("combat_exp", 20000);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	set("shen_type",1);set("score",200);setup();

        carry_object("/clone/misc/cloth")->wear();       
	add_money("silver", 10);
}
