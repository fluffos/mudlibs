// huang-son-in-law 桃花岛女婿

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define SONINLAW NPCDATA + "huang-son-in-law"

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

int do_clone(object me, object ob);

string query_save_file()
{
	return SONINLAW;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
		set_name("郭靖", ({ "nvxu" }) );
		set("title", "黄药师之女婿" );
		set("gender", "男性" );
		set("age", 19);
		set("long","他就是黄药师的乘龙快婿，黄蓉的心上人！\n");
		set("attitude", "peaceful");

		set("str", 25);
		set("con", 25);
		set("int", 25);
		set("dex", 25);

		set("max_qi", 500);
		set("eff_qi", 500);
		set("qi", 500);
		set("max_jing", 300);
		set("jing", 300);
		set("neili", 500);
		set("max_neili", 500);
		set("jiali", 40);
		set("shen", 1000000);
		set("shen_type", 1);

		set("no_clean_up",1);
		set("combat_exp", 500000);

		set_skill("force",  100); 
		set_skill("unarmed",100);
		set_skill("sword",  100);
		set_skill("dodge",  100);
		set_skill("parry",  100);

		set("armor", "/clone/misc/cloth");

		setup();

		carry_object("/clone/misc/cloth")->wear();        
	}
	else {
		set("id", "nvxu");
		set_name(query("name"), ({ query("id") }));
		setup();
		if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
		if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();        
	}
}

int do_copy(object me, object ob)
{
	seteuid(getuid());

//	me->add("generation", 1);	

	me->set("name",  ob->query("name") );
	me->set("title", "桃花岛乘龙快婿");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");

	ob->set_temp("apply/short", ({me->query("short")}));
	
	me->set("short", me->query("title") + " " + me->query("name") + "( Taohuadao nvxu)");
	me->delete("title");

	do_clone(me, ob);

	return 1;
}

int do_clone(object me, object ob)
{
	object *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	seteuid( geteuid(me) );
	me->set("winner", ob->query("id"));
	me->set("death_count", ob->query("death_count"));

/* delete and copy skills */

/*	if ( mapp(skill_status = me->query_skills()) ) {
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
*/	
/* delete and copy skill maps */
/*
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
*/	
/* delete and copy skill prepares */
/*
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
*/
/* unwield and remove weapon & armor */
/*
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
	set("weapon", 0);
	set("armor", 0);
*/
/* wield and wear weapon & armor */
/*
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("weapon_prop/damage") > 100 
		||  inv[i]->query("armor_prop/armor") > 100 ) continue;

		if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			me->set("armor", base_name(inv[i]));
		}
	}
*/
/* copy entire dbase values */
/*
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("age", hp_status["age"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);
		me->set("death_count",hp_status["death_count"]);
		me->set("death_times",hp_status["death_times"]);
*/
	save();

//	tell_object(ob, "状态储存完毕。\n");

	return 1;
}
