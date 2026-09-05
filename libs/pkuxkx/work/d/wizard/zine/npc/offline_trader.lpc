inherit NPC;

void create()
{
	set_name("榷场管事", ({ "quechang guanshi", "guanshi","shi" }));
	set("age", 52);
	set("gender", "男性");
	set("long", "这是一位榷场的管事，常年在此，油水十分充足。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 25000);
        set("shen_type",1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object me,object item)
{
	if (this_object()->is_busy())
		return notify_fail("没看我正忙着吗？");
	if (!item->is_gems())
		return notify_fail("我只负责调换错误的随机装备。\n");
	if (item->is_gem())
		return notify_fail("我只负责调换错误的随机装备。\n");
	if (arrayp(item->query("id"))||item->query("id")==item->query("skill_type")||item->query("id")==item->query("armor_type"))
		return notify_fail("这件装备不符合调换规则。\n");
	if (item->query("gem_ob_autoloaded"))
		return notify_fail("随机装备脱下来再弄。\n");
	if(item->query("skill_type"))
		item->set("skill_type",item->query("id"));
	if(item->query("armor_type"))
		item->set("armor_type",item->query("id"));
	item->save();
	item->move(me);
	command("say 你原来的东西找好了，给你吧。");
	this_object()->start_busy(1);
	return 1;
}
