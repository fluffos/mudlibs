inherit NPC;
#include <ansi.h>

void create()
{
	set_name("水无几", ({ "shui wuji", "wuji", "shui" }));
	set("gender", "男性");
	set("title",HIR+"将军府 "+HIW+"司直");
	set("age", 52);
	set("str", 45);
	set("dex", 46);
	set("long", "他是将军府里文官的首席————水无几。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 160);
	set_skill("force", 160);
	set_skill("halberd", 160);
	set_skill("lujia-ji", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);

	map_skill("halberd", "lujia-ji");
	map_skill("parry", "lujia-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	set("max_jingli",400);
	set("jingli",400);
	set("max_qi",40000);
	set("eff_qi",40000);
	set("qi",40000);
	setup();
	carry_object("/clone/armor/pifeng")->wear();
}
void die()
{
	message_vision("$N取出一颗丹药服下后，全身伤势竟彻底恢复了。\n",this_object());
	fullme();
	return;
}
