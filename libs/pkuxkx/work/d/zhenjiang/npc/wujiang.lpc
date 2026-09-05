// wujiang.c 武将

inherit NPC;
// inherit F_SKILL;

void create()
{
	set_name("武将", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("halberd", 60);
	set_skill("lujia-ji", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	map_skill("halberd", "lujia-ji");
	map_skill("parry", "lujia-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}

void init()
{
	object ob;
	add_action("do_say","say");
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
int do_say(string arg)
{
	object *team,me=this_player();
	if (!me->query_temp("OustBandit/psw"))
	return 0;
	if (!arg||arg!=me->query_temp("OustBandit/psw"))
	return 0;
	if (!team=me->query_temp("OustBandit/team"))
	return 0;
	if (!arrayp(team))
	return 0;
	if (sizeof(team)<3||sizeof(team)>5)
	return 0;
	for (int i=0;i<sizeof(team);i++)
	{
		if (!team[i])
		return 0;
		if (!team[i]->query_temp("OustBandit/psw")||team[i]->query_temp("OustBandit/start")||environment(team[i])!=environment(this_object()))
		return 0;
	}
	message_vision("$N对着$n大声说：“"+arg+"”。\n",me,this_object());
	for (int i=0;i<sizeof(team);i++)
	team[i]->set_temp("OustBandit/start",1);
	command("say 前路难测，"+me->query("name")+"，你们多多保重。\n");
	command("bow");
	return 1;
}
