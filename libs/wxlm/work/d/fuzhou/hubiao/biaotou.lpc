


inherit "/kungfu/class/generate/chinese";

void create()
{
	mapping name;
	int i;
	string *fams;

	name = NPC_D->get_cn_name();
	set_name("林镖师", name["id"]);
	set("title", HIW"福威镖局镖师"NOR);
	set("gender", (i==0?"女性":"男性"));
	set("age", 35 +random(30));
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("int", 25+random(5));
	set("con", 25+random(5));
	set("dex", 25+random(5));
	set("str", 25+random(5));
	set("per", 25);
	set("biaotou", 1);

	set("chat_chance", 2);
        set("chat_msg",({
		CYN+query("name")+"喝道：“闲杂人等闪开了。”"NOR"\n",
		CYN+query("name")+"喝道：“快走快走，别偷懒！”"NOR"\n",
	}));

	set_skill("literate", query("int") * 10);

	set("location",1);
	setup();
	fams = keys(init_family);
	setup_family(fams[random(sizeof(fams))]);
}

void heart_beat()
{
	object me = this_object();
	object where;

	if ( ! me) return;
	if ( !environment(me)) return;

	if ( me->query_temp("protecting")) {
		where = environment(me->query_temp("protecting"));
		if ( where && environment(me) != where)
			me->move(where);
	}
	::heart_beat();
}
