// machine-bonze.c 机械和尚

inherit NPC;

void create()
{
	set_name("机械和尚", ({ "jixie heshang", "jixie", "heshang", "machine bonze", "machine", "bonze" }) );
	set("gender", "男性" );
	set("age", 30);
	set("mute", 1);
	set("long", "一个练功用的机械和尚，是用一些木板和铁皮钉起来的，制作者也许是讨厌和尚，专门用一块猪皮包住了头，在上面写着“臭和尚”三个字。在机械和尚的背部有一个小小的开关(trigger)。\n");
	set("attitude", "friendly");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
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

void init()
{
	add_action("do_turn", "turn");
	add_action("do_turn", "ban");
}

void unconcious()
{
	say("机械和尚忽然发出“哗啦”一声巨响，就此躺倒不动了。\n");
	set("damaged", 1);
	remove_all_enemy();
	reincarnate();
	set("disable_type", " <已损坏>");
	set("qi", 0);
	set("jing", 0);
	set("jingli", 0);
}

void die()
{
	unconcious();
}

int accept_fight(object ob)
{
	return notify_fail("看清楚点，那只是个机械和尚而已！\n");
}

int do_turn(string arg)
{
	object me = this_object();
	object ob = this_player();
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	if (ob->is_busy()) return notify_fail("你正忙着呢！\n");
	if (arg != "trigger" && arg != "kaiguan") return notify_fail("你要扳动什么？\n");

//	if (ob->is_fighting()) return notify_fail("你正忙着打架呢！\n");
	if (is_fighting()) return notify_fail("机械和尚正在自动作战，你无法碰到开关！\n");

	if (random(query("fight_times")) >= 8) {
		set("damaged", 1);
		me->disable_player(" <已损坏>");
	}

	message_vision("$N轻轻地扳动了机械和尚背后的开关。\n", ob);	
	if (query("damaged")) return notify_fail("但是这个机械和尚已经被打坏了，需要找人修理。\n");

	add("fight_times", 1);

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

	set("str", hp_status["str"]);
	set("int", hp_status["int"]);
	set("con", hp_status["con"]);
	set("dex", hp_status["dex"]);

	set("max_qi",    hp_status["max_qi"]);
	set("eff_qi",    hp_status["eff_qi"]);
	set("qi",        hp_status["qi"]);
	set("max_jing",  hp_status["max_jing"]);
	set("eff_jing",  hp_status["eff_jing"]);
	set("jing",      hp_status["jing"]);
	set("max_neili", hp_status["max_neili"]);
	set("neili",     hp_status["neili"]);
	set("jiali",     hp_status["jiali"]);
	set("combat_exp",hp_status["combat_exp"]);

	message_vision("机械和尚忽然一跃而起，对$N发动了猛烈的进攻！\n", ob);	
	me->fight_ob(ob);
	ob->fight_ob(me);
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	write("看清楚点，那只是个机械和尚而已！\n");
}
