// fanren.c
#include <ansi.h>

inherit NPC;

#include <random_name.h>

void create()
{
	string name;
	
        name = get_rndname();
	
	set_name(name, ({ "fanren" }) );
        set("nickname","犯人" );
       set("no_get",1);


	set("gender", "男性" );
	set("age", 30);
	set("long",
"一个日月神教的犯人,他们都是到日月神教卧底的\n各大门派弟子事泄被捕的");
	set("attitude", "heroism");
	create_family("丐帮", 19, "弟子");
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_kee", 300);
	set("eff_qi", 300);
	set("kee", 300);
	set("max_gin", 100);
	set("gin", 100);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);


	setup();
        
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

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


	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_force", hp_status["max_neili"]);
		me->set("force",     hp_status["neili"]);
		me->set("force_factor",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void init()
 {
	add_action("do_kill", "kill");

 }

int do_kill(string arg)
 {
        if(arg=="fanren")
         {
          write(HIR "不准杀犯人!!!\n" NOR);
          return 1;
         }
        return 0;
 }
