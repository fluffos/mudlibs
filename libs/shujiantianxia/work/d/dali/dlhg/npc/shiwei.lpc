// shiwei.c 带刀侍卫
// Modify by Looklove@SJ fixed bug 2000/9/8

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("皇宫侍卫", ({ "huanggong shiwei", "shiwei", "wei" }));
	set("gender", "男性");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他手握钢刀，目视前方，真是威风凛凛。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("blade", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("eff_jingli", 200);
	set("jingli", 200);
	
	setup();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/armor")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
	ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

void kill_ob(object me)
{
	object ob;
	int i;

	::kill_ob(me);
	if (!is_killing(me->query("id")))
		return;
	for (i = 1; i <= 4; i++)
		if (objectp(ob = present("huanggong shiwei "+i))
		&& !ob->is_killing(me->query("id")))
			ob->kill_ob(me); 
}

int accept_fight(object me)
{
	command("say 竟敢和大理皇宫侍卫过不去，今天算你倒霉。\n");
	if (!is_killing(me->query("id")))
		me->add_condition("killer", 15);
	kill_ob(me);
	return 1;
}
