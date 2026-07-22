// By River@SJ

inherit NPC;
#include <ansi.h>
#include "npc_skill.h"

int do_kill(object me);

void create()
{
	string weapon;
	mapping name, skills;
	int i, j, p;

	i = random(4);

	name = RNAME_D->get_random_name(i);
	skills = npc_skills[random(sizeof(npc_skills))];
	set_name(name["name"], name["id"] + ({ "zhanglao" }));
	set("title", HIY"日月神教长老"NOR);
	set("gender", (i==0?"女性":"男性"));
	set("age", 30 + random(40));
	set("long", "这是日月神教的长老，看起来武功不错。\n");
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 25);
	set("dex", 30);
	set("int", 25+random(5));
	set("con", 30);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("eff_jingli", 4000);

	set_skill("literate", query("int") * 10);
	p = skills["difficult"];
	set("difficult", p);

	for( j = 0; j < sizeof(keys(skills)); j ++){
		if ( keys(skills)[j] == "family") continue;
		if ( keys(skills)[j] == "difficult") continue;
		set_skill(keys(skills)[j], 500);
		set_skill(values(skills)[j], 500);
		map_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "cuff")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "claw")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "finger")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "strike")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "leg")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "hand")
			prepare_skill(keys(skills)[j], values(skills)[j]);

		switch (keys(skills)[j]) {
			case "family" :	
			case "force":
			case "difficult":
			case "dodge":
			case "parry":
			case "hand":
			case "cuff":
			case "strike":
			case "claw":
			case "leg":
			case "finger":	continue;
			case "sword":	weapon = "sword";	break;
			case "blade":	weapon = "blade";	break;
			case "hook":	weapon = "hook";	break;
			case "dagger":	weapon = "dagger";	break;
			case "whip":	weapon = "whip";	break;
			case "brush":	weapon = "brush";	break;
			case "staff":	weapon = "gangzhang";	break;
			case "club":	weapon = "gun";		break;
			case "axe":	weapon = "axe";		break;
			case "hammer":	weapon = "falun";	break;
			case "stick":	weapon = "zhubang";	break;
			case "throwing":weapon = "shizi";	break;
			default :	weapon = "none";	break;
		}
	}

	if (! random(4)) 
		weapon = "none";

	setup();

	if ( weapon != "none")
		carry_object(BINGQI_D(weapon))->wield();

	carry_object(ARMOR_D("cloth"))->wear();

	add_money("silver", random(50)+ 30);

	if (clonep())
		call_out("dest", 300, this_object());
}

void dest(object ob)
{
	if ( ob ) destruct(ob);
}

void init()
{
	object ob;       

	::init();
	if (interactive(ob = this_player())
	&& query_temp("target") == ob->query("id")
	&& ! query_temp("skill_set")) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void heart_beat()
{
	object env, target , ob = this_object();

	::heart_beat();

	if (! ob || !environment(ob) ) return;

	target = find_player(query_temp("target"));

	if (target && !present(target) && (env = environment(target))
	&& !is_fighting() && !target->is_ghost() && living(this_object())) {
		move(env);
		tell_room(environment(ob), ob->name()+ "迈着大步冲了过来。\n", ({ ob }) );
		if ( !environment(ob)->query("no_fight"))
			::kill_ob(target);
	}

	if ( ob->is_fighting()
	 && query("cure") < 5
	 && query("qi") < query("max_qi")/5*4
	 && query("combat_exp") > 2000000 ){
		receive_curing("qi", query("max_qi")/5);
		add("qi", query("max_qi")/5);
		add("cure", 1);
		if (! ob->is_busy())
			tell_room(environment(ob), ob->name()+"深深的吸了口气，脸色顿时好了许多。\n", ({ ob }) ); 
	}
}

int do_kill(object ob)
{
	mapping skills;
	string *sk;
	object me; 
	int lv,exp,i,b_exp,p;

	me = this_object();
	lv = (int)ob->query("max_pot");
	lv = lv-100;
	exp = ob->query("combat_exp");

	b_exp = 300000;

	p = query("difficult");

	if(!ob) return 0;

	if (exp < 500000){
		set("combat_exp", exp * 4/5);
		lv = lv *(p+6)/10;
	}
	else {
		set("combat_exp",(exp+random( 50000 * (exp/b_exp)*p)));
		lv = lv *(p+9)/10;
	}
	set("max_qi", ob->query("max_qi")*5/4);
	set("qi",  me->query("max_qi"));
	set("eff_qi", me->query("max_qi"));
	set("jing",  ob->query("max_jing"));
	set("max_jing", ob->query("max_jing"));
	set("eff_jing", ob->query("max_jing"));
	set("max_neili", ob->query("max_neili")*5/4);
	set("neili", me->query("max_neili"));
	set("jingli", ob->query("max_jingli"));
	set("eff_jingli", ob->query("max_jingli"));
	set("jiali", lv/(6+random(p)));

	if ( p == 3 && ! random(20) && exp > 1000000)
		set_temp("double_attack", 1);

	if ( exp > 2000000)
		set_temp("apply/armor", 100);

	skills = query_skills();
	if (mapp(skills)){
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if ( sk[i] != "literate")
			skills[sk[i]] = lv;
	}
	set_temp("skill_set", 1);
	message_vision(HIR"\n$n对着$N大喝一声：大胆"+ RANK_D->query_rude(me)+"竟敢来我日月神教捣乱！！\n\n"NOR,ob,me);
	::kill_ob(ob);
}

void greeting(object ob)
{
	if (!ob
	 || !present(ob)
	 || query_temp("target") != ob->query("id"))
		return;

	ob->add_busy(1);
	set_leader(ob);
	add_busy(1);
	remove_call_out("dest");
	call_out("dest", 120, this_object());
	do_kill(ob);
}

void do_lost()
{
	object me;
	me = this_object();
	tell_room(environment(me), "\n"+name()+"大喊一声：老子不奉陪了！转身几个起落就不见了。\n");
	dest(me);
}

void unconcious()
{
	object me;
	me = this_object();

	tell_room(environment(me), "\n"+name()+"大喊一声：不好！！转身几个起落就不见了。\n");
	dest(me);
}
