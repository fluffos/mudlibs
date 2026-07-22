// /d/xiangyang/muren.c 木人

inherit NPC;

int do_turn(string arg);
int do_get(string arg);

void create()
{
	set_name("木人", ({ "mu ren", "mu", "ren", "wood man", "wood", "muren" }) );
	set("gender", "男性" );
	set("age", 30);
	set("mute", 1);
	set("long", "一个制作精巧的木人，材料是选用上等红木，\n"
	"关节处以细小的铜钉铆合，显得极为灵活，\n"
	"头部是用整块的圆木雕琢而成，眼神流动，\n"
	"嘴巴也好象能发出声音来。在背部有一个小小的开关(trigger)。\n");
	set("attitude", "friendly");

	set("str", 25);
            set("no_quest", 1);
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

	set_weight(10000);
	set("material", "wood");
	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	
	set("owner", this_object());

	setup();
}

void init()
{
	if (query("destructing")) return;
	add_action("do_get", "get");
	add_action("do_turn", ({"turn", "ban"}));
	if (!objectp(query("owner"))) {
		set("destructing", 1);
		set_ghost(1);
		call_out("destruct_me", 1);
	}
}

void destruct_me()
{
	destruct(this_object());
}

void unconcious()
{
	object me = this_object();

	this_player()->add_temp("muren_num", -1);
	say("木人忽然发出“哗啦”一声巨响，铆在关节处的铜钉都脱落了下来，\n"
	"身体整个散架了，凌乱地落了一地。\n");
	new("/d/xiangyang/obj/mutou")->move(environment(me));
	destruct(me);
}

void die()
{
	unconcious();
}

int accept_fight(object ob)
{
	return notify_fail("看清楚点，那只是个木人而已！\n");
}

int do_get(string arg)
{
	object npc = this_object();
	object me = this_player();

	if (!arg) return notify_fail("你要捡起什么东西？\n");
	if (npc != present(arg, environment())) return 0;
	if (environment() == me) {
		write("你不是已经扛着了吗？\n");
		return 1;
	}
	if (query("owner") != me) {
		write("这个不是你订做的木人！\n");
		return 1;
	}
	if (is_busy() || is_fighting()) {
		write("木人正在作战，你无法拿起它！\n");
		return 1;
	}
	if (npc->move(me)) {
		if (me->is_fighting()) me->start_busy(1);
		message_vision( "$N将$n扛在了背上。\n", me, npc);
		return 1;
	}
	else {
		write("你无法拿起木人！\n");
		return 1;
	}
	return 0;
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
	if (query("owner") != ob) return notify_fail("你发现开关似乎被什么东西卡住了，怎么扳都扳不动。\n");

//	if (ob->is_fighting()) return notify_fail("你正忙着打架呢！\n");
	if (is_fighting()) return notify_fail("木人正在自动作战，你无法碰到开关！\n");

	if (environment() == ob) return notify_fail("先把木人放下来再说吧！\n");
	if (environment(ob) != environment()) return notify_fail("你够不到木人的开关！\n");
	if (environment()->query("no_fight")) return notify_fail("这里不准打架！\n");

	message_vision("$N轻轻地扳动了木人背后的开关。\n", ob);	
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

	message_vision("木人忽然一跃而起，对$N发动了猛烈的进攻！\n", ob);	
	me->fight_ob(ob);
	ob->fight_ob(me);
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	write("看清楚点，那只是个木人而已！\n");
}

int remove_enemy(object ob)
{
	if (query("fight_times") >= 30) {
		unconcious();
		return 1;
	}

	return ::remove_enemy(ob);
}
