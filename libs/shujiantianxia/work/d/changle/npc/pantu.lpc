// By River@SJ
// 2003.2.27 

inherit NPC;
#include <ansi.h>
#include "npc_skill.h"

void create()
{
	object ob;
	mapping name;
	int i = random(4);

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"] + ({ "dizi" }));
	set("gender", (i==0?"女性":"男性"));
	set("age", 30 + random(40));
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 25);
	set("dex", 30);
	set("int", 25+random(5));
	set("con", 30);

	set("no_get", 1);
	set("no_bark", 1);
	set("no_ansuan", 1);
	set("no_quest", 1);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("eff_jingli", 4000);

	set_skill("literate", query("int") * 10);

	setup();

	ob= new(ARMOR_D("cloth"));
	ob->set("name", "粗布衣");
	ob->move(this_object());
	ob->wear();
	add_money("silver", random(50)+ 30);

	if (clonep())
		call_out("dest", 900, this_object());
}

void dest(object ob)
{
	if ( ob ){
		tell_room(environment(ob), "\n"+name()+"大喊一声：不好！！转身几个起落就不见了。\n");
		destruct(ob);
	}
}

void init()
{
	object ob;       

	::init();
	if (interactive(ob = this_player())
	&& query_temp("target_pantu") == getuid(ob)
	&& ob->query_temp("changle/target") == this_object()) {
		if ( !query_temp("meet")) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
		else {
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
		}
	}
}

void heart_beat()
{
	object env, target , ob = this_object();

	::heart_beat();

	if (! ob || !environment(ob) || ! query_temp("meet") ) return;

	target = find_player(query_temp("target_pantu"));

	if ( !target || (target && target->is_ghost())) {
		remove_call_out("dest");
		call_out("dest", 0, ob);
		return;
	}

	if ( target->query_temp("changle/target") != ob) {
		remove_call_out("dest");
		call_out("dest", 0, ob);
		return;
	}

	if (target && !present(target) && (env = environment(target))
	&& !is_fighting() && !target->is_ghost() && living(this_object())) {
		move(env);
		tell_room(environment(ob), ob->name()+ "迈着大步冲了过来。\n", ({ ob }) );
		if ( !environment(ob)->query("no_fight"))
			::kill_ob(target);
	}

	if ( ob->is_fighting()
	 && query("cure") < 4
	 && query("qi") < query("max_qi")/5*4
	 && query("combat_exp") > 2000000 ){
		receive_curing("qi", query("max_qi")/5);
		add("qi", query("max_qi")/5);
		add("cure", 1);
		if (! ob->is_busy())
			tell_room(environment(ob), ob->name()+"深深的吸了口气，脸色顿时好了许多。\n", ({ ob }) ); 
	}
}

int do_copy(object me, int team, int i)
{
	mapping skills;
	string msg, *sk;
	object weapon;
	int j, lvl, exp;

	skills = npc_skills[team];
	for( j = 0; j < sizeof(keys(skills)); j ++){
		if ( keys(skills)[j] == "family") continue;
		if ( keys(skills)[j] == "difficult") continue;
		if ( keys(skills)[j] == "team" ) continue;
		set_skill(keys(skills)[j], 200);
		set_skill(values(skills)[j], 200);
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
			case "team" :
			case "force":
			case "difficult":
			case "dodge":
			case "parry":
			case "hand":
			case "cuff":
			case "strike":
			case "claw":
			case "leg":
			case "finger":		continue;
			case "sword":		msg = "sword";		break;
			case "blade":		msg = "blade";		break;
			case "hook":		msg = "hook";		break;
			case "dagger":		msg = "dagger";		break;
			case "whip":		msg = "whip";		break;
			case "brush":		msg = "brush";		break;
			case "staff":		msg = "gangzhang";	break;
			case "club":		msg = "gun";		break;
			case "axe":		msg = "axe";		break;
			case "hammer":		msg = "falun";		break;
			case "stick":		msg = "zhubang";	break;
			case "throwing":	msg = "shizi";		break;
			default :		i = 0;			break;
		}
	}
	if ( i ) {
		weapon = new(BINGQI_D(msg));
		weapon->move(this_object());
		weapon->wield();
	}
	set("title", skills["family"]+"弟子");

	lvl = me->query("max_pot");
	lvl = lvl - 100;
	exp = me->query("combat_exp");

	if (exp < 500000){
		set("combat_exp", exp * 4/5);
		lvl = lvl * 4/5;
	}
	else {
		set("combat_exp", exp + random(exp/4));
	}

	set("max_qi", me->query("max_qi") + me->query_temp("apply/qi"));
	set("qi",  query("max_qi"));
	set("eff_qi", query("max_qi"));
	set("max_jing",  me->query("max_jing")+ me->query_temp("apply/jing"));
	set("jing", query("max_jing"));
	set("eff_jing", query("max_jing"));
	set("max_neili", me->query("max_neili") * 5/4);
	set("neili", query("max_neili"));
	set("eff_jingli", me->query("max_jingli"));
	set("jingli", query("eff_jingli"));
	set("jiali", lvl / 4);

	if ( ! random(20) && exp > 1000000)
		set_temp("double_attack", 1);

	if ( exp > 2000000)
		set_temp("apply/armor", 80 +random(30));

	skills = query_skills();
	if (mapp(skills)){
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if ( sk[i] != "literate")
			skills[sk[i]] = lvl;
	}
	return 1;
}

void greeting(object ob)
{
	if (!ob || !present(ob) || query_temp("target_pantu") != ob->query("id"))
		return;

	if ( !ob->query_temp("changle")) return;

	ob->add_busy(1);
	set_leader(ob);
	add_busy(1);
	remove_call_out("dest");
	call_out("dest", 300, this_object());
	set_temp("meet", 1);
	message_vision(CYN"\n$n看见$N手中握着的粗布碎片，不由脸色大变，大喝道：既然已被你看破，你也就别活了！\n"NOR, ob, this_object());
	::kill_ob(ob);
}

void die()
{
	object me;
	me = query_temp("last_damage_from");

	if ( objectp(me) && query_temp("target_pantu") == getuid(me) && me->query_temp("changle"))
		me->set_temp("changle/done", 3);

	::die();
}

void kill_ob(object ob)
{
	object me = this_object();
 
	if ( query_temp("target_pantu") != getuid(ob)
	|| ob->query_temp("changle/target") != me) {
		command("!!!");
		me->remove_enemy(ob);
		ob->remove_killer(me);
		return;
	}
	::kill_ob(ob);
}

void accept_fight(object ob)
{
	if ( query_temp("target_pantu") != getuid(ob)
	|| ob->query_temp("changle/target") != this_object()) {
		command("peace "+ ob->query("id"));
		return;
	}
}
