// mu-ren.c 木人
#include <ansi.h>
inherit NPC;
//inherit F_CLEAN_UP;

void create()
{
	set_name(HIY"代理教头"NOR, ({ "jiaolian" }) );
   set("no_get",1);
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个门派教头。\n");
	set("attitude", "heroism");

	set_temp("no_kill", 1);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);

	set("no_get", "1");
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

	set_skill("force", 130); 
	set_skill("unarmed", 130);
	set_skill("dodge", 130);
	set_skill("parry", 130);
	set_skill("sword", 130); 
	set_skill("blade", 130);
	set_skill("staff", 130);
	set_skill("strike", 130);


	setup();
        
}

void init()
{
	object me = this_object();

	add_action("do_recover", "recover");

}

int do_recover()
{
	object me,ob;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();
	ob = this_player();


	if ( wizardp(ob)) 
		return notify_fail("你是WIZ,没有这个资格！\n");;

	if ( ob->query("combat_exp") < 3000000 ) 
		return notify_fail("你的经验不够,没有这个资格！\n");;

	if ( ob->query("score") < 5000 ) 
		return notify_fail("你的江胡阅历不够,没有这个资格！\n");;
	
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
	write("状态复元完毕。\n");
	return 1;
}

int is_apprentice_of() {return 1;}
int recognize_apprentice()
{
return 1;
}