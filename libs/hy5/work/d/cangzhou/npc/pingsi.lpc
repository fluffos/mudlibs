
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
	set("combat_exp", 150000);
	set("shen_type", 1000);
	set("attitude", "peaceful");

	set_skill("cuff", 160);
	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/armor", 130);
	set_temp("apply/damage", 110);

	set("neili", 1900);
	set("max_neili", 1900);
	set("jiali", 20);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
