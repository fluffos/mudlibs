// gujia.c


inherit NPC;
inherit F_CLEAN_UP;

void create()
{
	set_name("白骨架", ({ "gu jia", "gu", "baigu jia", "jia" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long", "一个练功用的骨架，白骨轮廓鲜明，让人看了不禁寒心。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("con", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 500);
	set("eff_qi", 300);
	set("qi", 500);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
        
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status;
	string *sname, *mname;
	int i;

	me = this_object();

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("这个骨架已经被打散了！\n");	

	if (random(me->query("fight_times")) >= 10) {
		me->set("damaged", 1);
		return notify_fail("这个骨架已经被打散了！\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("你刚跟这个骨架练过功！\n");		

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 300 + random(300), me);	

	me->delete_skill("unarmed");
	me->map_skill("unarmed");
	me->map_skill("dodge");
	me->map_skill("parry");

	if ( !(skill_status = ob->query_skills()) ) return 1;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]);
	}
	
	if ( !(map_status = ob->query_skill_map()) ) return 1;
	mname  = keys(map_status);

	for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
