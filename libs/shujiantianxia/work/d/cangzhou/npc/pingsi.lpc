
inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("平四", ({ "ping si", "ping", "si" }));
	set("gender", "男性");
	set("age", 40);
	set("str", 20);
	set("dex", 20);
	set("long", "这是一位独眼老人，原是沧州客栈的一个烧火的小伙计，\n"+
		"当年苗人风和胡一刀比武后救了胡一刀的幼子胡斐，并抚养成人。\n");
	set("combat_exp", 50000);
	set("shen_type", 1000);
	set("attitude", "peaceful");

	set_skill("cuff", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 10);

	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 20);
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}
