inherit NPC;

void create()
{
	set_name("官差", ({ "guan chai", "chai" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "他是临安府街头的官差，负责治安。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 30);
	set("dex", 30);
	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("blade", 80);
	set_skill("force", 150);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 40);
	setup();
	carry_object(__DIR__"obj/chaifu")->wear();
}

void init()
{
	object *all=all_inventory(environment(this_object()));
	for (int i=0;i<sizeof(all);i++)
	{
		if (all[i]->is_fighting()&&all[i]!=this_object())
		{
			if (userp(all[i]))
			command("tell "+all[i]->query("id")+" 不许当街打架！");
			all[i]->remove_all_killer();
		}
	}
}