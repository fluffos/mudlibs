//Yanqi 08/11/2k

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"

int do_clone(object me, object ob);

void create()
{
	set_name("抢匪", ({ "qiang fei", "fei" }) );
	set("gender", "男性");
	set("long", "这是一个抢匪，专门抢劫私盐。\n");
	set("shen", -15000);
	set("attitude", "killer");
	set("age", random(20)+25);

	set("str", 20);
	set("int",20);  
	set("con",20);     
	set("dex",20);
	set("combat_exp", 9999999);

	set("shen_type", -1);
	set("max_qi",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("max_jing",9999);
	set("eff_jing",9999);
	set("jing",9999);
	set("max_jingli",9999);
	set("eff_jingli",9999);
	set("jingli",9999);
	set("neili",9999);
	set("jiali", 99);
	set("max_neili",9999);
	set("score", 1000);
        
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	if (random(10) < 3)
		add_money("silver", random(30));

	carry_object(ARMOR_D("armor/cloth"))->wear();
	call_out("dest", 200, this_object());
	setup();
}

void init()
{
	object yan,name1;
	object ob = this_player();
	object me = this_object();

	yan = present("yan ba", me);
	name1 = ob->query("id");
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& yan
	&& me->query_temp("name1")==name1
	&& ob->query_temp("newbiejob2/start")
	&& ob->query_temp("newbiejob2/middle")) {
		command("say 想拿你的盐，先纳命来吧！！！");
		me->set_leader(ob);
		if (!me->query_temp("skillset")) do_clone(me, ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}       

int do_clone(object me, object ob)
{
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing,k_jingli;
	string t_force,t_dodge;

	number = (int)ob->query("max_pot");
	number = number - 110 - random(15);
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_jingli = (int)ob->query("eff_jingli");
	k_neili = (int)ob->query("max_neili");

	killerskill1 = skill2[random(sizeof(skill2))];

/*set killer's skill*/

	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];       

	me->set_skill("force",number);
	me->set_skill("dodge",number);
	me->set_skill("parry",number);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number);
	me->set_skill(killerskill1["t_skill"],number);
	me->set_skill(killerskill1["b_skill"],number);

/* set killer's  skill maps */

	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

/* set killer's skill prepares */

	me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

/* copy entire dbase values */

	me->set("max_qi",k_qi-100);
	me->set("eff_qi",k_qi-100);
	me->set("qi",k_qi-100);
	me->set("max_jing",k_jing-100);
	me->set("eff_jing",k_jing-100);
	me->set("eff_jingli",k_jingli-100);
	me->set("max_jingli",k_jingli-100);
	me->set("jingli",k_jingli-100);
	me->set("jing",k_jing-100);
	me->set("max_neili",k_neili-100);
	me->set("neili",k_neili-100);
	me->set("jiali", k_neili / 60);
	me->set("combat_exp",ob->query("combat_exp")*2/3);

	me->add_temp("apply/attack",  30);
	me->set_temp("apply/dodge", 50);

	me->set_temp("skillset",1);
	remove_call_out("dest");
	call_out("dest", 200, this_object());
	return 1;
}

void dest(object ob)
{
	if( !ob) return;
	if (!living(this_object())) {
		call_out("dest", 10, ob);
		return;
	}
	say(name()+"道：不跟你在这挠痒痒了，老子得回去领赏去了。\n");
	say(name()+"匆匆离开。\n");  
	destruct(this_object());
}

void unconcious()
{
	object me, ob;
	me = this_object();
	ob = me->query_temp("last_damage_from");
	if(ob 
	&& objectp(ob)
	&& ob->query_temp("newbiejob2/start") 
	&& ob->query_temp("newbiejob2/middle"))
		ob->set_temp("newbiejob2/over",1);
	::unconcious();
}

void die()
{
	object me, ob;
	me = this_object();
	ob = me->query_temp("last_damage_from");
	if(ob 
	&& objectp(ob) 
	&& ob->query_temp("newbiejob2/start") 
	&& ob->query_temp("newbiejob2/middle"))
		ob->set_temp("newbiejob2/over",1);
	::die();
}
