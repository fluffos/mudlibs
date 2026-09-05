inherit NPC;
#include <ansi.h>

void create()
{
	set_name("守城士兵", ({ "shi bing", "bing", }));
	set("str", 20);
	set("gender", "男性");
	set("age", 20+random(10));
	set("long", "他是一名西夏的守城士兵，负责城门的治安。\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
    set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 80);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	set("XIXIA_GATE_BING",1);
	set("shen_type",-1);set("score",200);setup();
	carry_object("/clone/armor/tiejia")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("xixia_killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 袭击西夏军士者死！\n");
	me->apply_condition("xixia_killer", 100);
	kill_ob(me);
	return 1;
}