// miejue.h
// 灭绝

void attempt_apprentice(object ob)
{
	string *prename =
	 ({ "静", "灵" });
	string name, new_name;
	if( (string)ob->query("gender") != "女性" )
	{
		command ("say 阿弥陀佛！施主呀，贫尼可不敢开这等玩笑啊。");
	return;
	}
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫尼不收『俗家弟子』。");
	return;
	}
	if( (int)ob->query_skill("linji-zhuang", 1) < 120 )
	{
		command("say 老尼我不收练功不勤之人，你还是多练练你的临济十二庄吧。");
	return;
	}
	if( (int)ob->query_skill("force", 1) < 100 )
	{
		command("say 老尼我不收练功不勤之人，你还是多练练你的基本内功吧。");
	return;
	}
	if( (int)ob->query("shen") < - 50000 ) 
	{
		command("say 老尼我最不喜欢的就是凶恶之徒。");
	return;
	}

	name = ob->query("name");
 new_name = prename[random(sizeof(prename))] + name[2..3];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("say 阿弥陀佛，善哉！善哉！");
	command("smile");
	command("recruit " + ob->query("id"));
	ob->set("name", new_name);
	ob->set("title", "峨嵋派第四代弟子");
}

void kill_ob(object me)
{	
	command("chat* sneer " + me->query("id"));
	::kill_ob(me);
}

void unconcious()
{
	command("chat* 哀叹道：可惜我们峨嵋掌门尚未选出，谁要是能找到..环交给.风..就能当掌..");
	::unconcious();
}

int ask_sword()
{
	object me = this_player();
	object ob = this_object();
	
	if(me->query_temp("marks/pass_yitian")) {
	command("say 不是说了么？把掌门的铁指环找来，倚天剑就可给与你用。");
	return 1;
	}

	if (ob->is_busy()) {
	command("nonsense miejue shitai");
	command("nonsense");
	return 1;

	}
	if( ob->is_fighting() ) {
	command("nonsense miejue shitai");
	command("nonsense");
	return 1;
	}

	if( me->query("age") < 20 || (int)me->query("combat_exp", 1) < 300000 ) {
	command("say 无名鼠辈也想打倚天剑的注意？");
	this_object()->kill_ob(this_player());
	this_player()->kill_ob(this_object());
	return 1;
	}
	if( present("yitian jian", me)) {
	command("say 你身上不是有倚天剑了么？怎么还问我？");
	command("sneer " + me->query("id"));
	command("consider " + me->query("id"));
	return 1;
	}
    command("say 屠龙宝刀，号令天下，倚天不出，谁与争锋，哈哈哈哈！");
	set("combat_exp", 2000000);
	set("max_qi", 2000);
	set("eff_jingli", 2000);
	set("eff_jing", 2000);
	set("qi", 2000);
	set("max_neili", 2000);
	set("neili", 2000);
	set("jingli", 2000);
	set("jing", 2000);
	set("jingli", 100);
	
	if(!present("yitian jian", ob)) {
    object tmp = carry_object("/clone/weapon/yitian-jian");
    if (objectp(tmp)) {
	if(present("changjian", ob)) {
	command("unwield changjian");
	destruct(present("changjian", ob));
    command("wield yitian jian");
    }
	}
	}
	prepare_skill("strike");
	prepare_skill("sword");
	ob->reset_action();
	prepare_skill("strike", "sixiang-zhang");
	
	command("say 好吧，既然想得到倚天剑，那么就接老尼几招。\n");
	command("grin " + me->name());
	
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 100);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 50);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 30);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 30);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 30);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 30);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon"), 1);
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	command("sneer");
	command("say 如此不济，也想打倚天剑的主意？！");
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 30);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1;
	}
	if( me->query("family/family_name") == "峨嵋派") {
	command("say 好吧，你把掌门指环找来，倚天剑就可给与你用。\n");	
	tell_room(environment(me), "灭绝师太对" + me->name() + "说道：好吧，你把掌门的铁指环找来，倚天剑就可给与你用。\n", ({me}));
	me->set_temp("marks/pass_yitian", 1);
	ob->set("max_qi", 2000);
	ob->set("max_jing", 2000);
	ob->set("neili", 2000);
	ob->set("max_neili", 2000);
	ob->set("jiali", 30);
	ob->set("combat_exp", 1200000);
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1; 
	}
	else {
	command("say 就算你抗住了我十招也不行，拿命来吧。");	
	if (!present("yitian jian",ob))
	carry_object("/clone/weapon/yitian-jian")->wield();
	else command("wield yitian jian");
	prepare_skill("strike");
	prepare_skill("sword");
	ob->reset_action();
	ob->set("combat_exp", 2200000);
	ob->set("jiali", 100);
	this_object()->kill_ob(this_player());
	this_player()->kill_ob(this_object());
	if (!present(me,environment(ob)) || me->query("qi") <= 0 || me->query("jing") <= 0 || me->query("jingli") <= 0)  {
	if (present("yitian jian",ob))
	destruct(present("yitian jian", ob));
	carry_object("/d/emei/obj/changjian")->wield();
	return 1; } return 1; }
}

int accept_object(object me, object ob)
{
	if( me->query("family/family_name") == "峨嵋派"  && ob->query("id") == "zhi huan" && me->query_temp("marks/pass_yitian")) {
	if(!(me->query_temp("marks/get_ring"))) {
	command("say 这枚指环是从何而来？哼，想骗老尼，没那么容易！");
	command("consider " + me->query("id"));
	command("say 拿命来吧！");
	this_object()->kill_ob(this_player());
	this_player()->kill_ob(this_object());
	return 1;
	}
	command("say 好吧，既然把掌门指环交给了我，那我就把倚天剑给你，记住拿着倚天剑一定要惩罚恶人，不然老尼我可对你不客气。");
	tell_room(environment(me), "灭绝师太给" + me->name() + "一柄倚天剑。\n");
	ob=new("/clone/weapon/yitian-jian")->move(me);
	me->delete_temp("marks/pass_yitian");
	me->delete_temp("marks/get_ring");
	return 1;
	}
	else {
	command("say 哪里来的人胆敢欺骗峨嵋派掌门？");
	command("smash " + me->query("id"));
	this_object()->kill_ob(this_player());
	this_player()->kill_ob(this_object());
	me->delete_temp("pass_yitian");
	return 1;
	}
}
