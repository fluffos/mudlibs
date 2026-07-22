inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include "skill.h";


string *k_weapon = ({"sword","blade","staff","whip","gun",});

void create()
{
	string weapon;
	weapon = k_weapon[random(sizeof(k_weapon))];

	set_name("中军侍卫", ({ "zhongjun shiwei", "shiwei" }));
	set("gender", "男性");
	set("long", "这是负责保护蒙古大汉的中军侍卫，双目有神，满脸胡须。\n");
	set("age", random(20)+25);
	set("str", 20+random(5));
	set("int",20+random(5));
	set("con",20+random(5));
	set("dex",20+random(5));
	set("combat_exp", 20000000);
	set("shen_type", -1);
	set("shen",0);
	set("no_quest",1);
	set("attitude", "friendly");
	set("max_qi",12000);
	set("eff_jingli", 2000);
	set("max_jing",12000);
	set("neili",10000);
	set("max_neili",10000);
	set("score", 100);
	set_skill("force", 1000);
	set_skill("dodge", 1000);
	set_skill("parry", 1000);

	setup();
	carry_object("/clone/armor/armor")->wear();
}

void init()
{
	object me=this_object(), ob=this_player();
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;
	number = (int)ob->query("max_pot");
	number = number-100;

	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

	::init();

	if(!userp(ob))
		return;

	if(!ob->query_temp("gb_job3")
    	 && (file_name(environment(ob)))[0..13]=="/d/gb/zhongjun"
    	 && userp(ob) && !wizardp(ob)){
	    	command("say 什么人竟然擅闯中军！来人，放箭！\n");
    		message_vision("一阵乱箭射来，$N倒在血泊之中。\n",ob);
		ob->set_temp("last_damage_from","被乱箭射");
    		ob->die();
    		return;
	}

   	command("say 大胆！！！\n");

	killerskill1 = skill2[random(sizeof(skill2))];
	number = number - 15 + random(20);

 	/*set killer's skill*/
	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];

	me->set_skill("force",number);
	me->set_skill("dodge",number);
	me->set_skill("parry",number);
	me->set_skill("literate", 150);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number);
	me->set_skill(killerskill1["t_skill"],number);
	me->set_skill(killerskill1["b_skill"],number);
	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
	/* set killer's skill prepares */
	me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
	/* copy entire dbase values */
	me->set("max_qi",k_qi*12/10);
	me->set("eff_qi",k_qi*12/10);
	me->set("qi",k_qi*12/10);
	me->set("max_jing",k_jing);
	me->set("eff_jing",k_jing);
	me->set("jing",k_jing);
	me->set("max_neili",k_neili);
	me->set("neili",k_neili*12/10);
	me->set("jiali", random(20) + 50);
	me->set("combat_exp", ob->query("combat_exp")/5*6);
	me->set_temp("skill_set",1);
	me->kill_ob(ob);
	return;
}

void die()
{
	object me= query_temp("last_damage_from");

	if (objectp(me)) {
		me->add_temp("kill_zhongjun", 1);
	}
	::die();
}
