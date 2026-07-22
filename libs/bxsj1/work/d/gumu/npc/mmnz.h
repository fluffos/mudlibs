// mmnz.h
// By River 98/09

#include <ansi.h>

int do_clone(object me,object ob);
int kill_ob(object ob);

void init()
{
	object name1;
	object ob = this_player();
	object me = this_object();

	name1 = ob->query("id");        
	::init();
	if (interactive(ob) 
	 && !environment(ob)->query("no_fight")
	 && !(me->query_temp("mmnz") != name1 )
	 && ob->query_temp("gm/job") 
	 && ob->query_condition("gm_job")){
		me->set_temp("apply/attack",  random(30));
		me->set_temp("apply/dodge",  random(50)); 
		if (!me->query_temp("skillset")) {
			command("say 既然被你发现小女子的踪迹，拿命来吧！");        
			ob->add_busy(2);
			remove_call_out("dest");
			call_out("dest",360);
			me->set_leader(ob);
			do_clone(me, ob);
		}
		else {
			command("say 想跑？既然被你发现小女子的踪迹，拿命来吧！");  
			ob->add_busy(1);
			me->set_leader(ob);
			remove_call_out("dest");
			call_out("dest",360);
			kill_ob(ob);
		}
	} 
}       

int do_clone(object me, object ob)
{
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;

	number = (int)ob->query("max_pot");
	number = number-115;
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

	killerskill1 = skill1[random(sizeof(skill1))];
	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];       

	me->set_skill("force",number);
	me->set_skill("dodge",number/2);
	me->set_skill("parry",number/2);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number/2);
	me->set_skill(killerskill1["t_skill"],number);
	me->set_skill(killerskill1["b_skill"],number);

	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
       
	me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

	me->set("max_qi",k_qi/3);
	me->set("eff_qi",k_qi/3);
	me->set("qi",k_qi/3);
	me->set("max_jing",k_jing*2/3);
	me->set("eff_jing",k_jing*2/3);
	me->set("jing",k_jing*2/3);
	me->set("max_neili",k_neili*2/3);
	me->set("neili",k_neili*2/3);
	me->set("combat_exp",ob->query("combat_exp")*2/3);
	me->set("long", me->query("long")+"好象就是刚才被"+ob->query("name")+"("+capitalize(ob->query("id"))+")发现的古墓叛逆。\n");
	me->set_name("蒙面女子", ({ob->query("id")+"'s nuzi", "mengmian nuzi", "mengmian"}));

	me->set_temp("skillset",1);       
	me->set_leader(ob);
	kill_ob(ob); 
	return 1;
}

void dest()
{
	object me,ob;
	ob = this_player();
	me = this_object();

	write(me->query("name")+"柳眉一蹙道：下次不要再让我遇见你。\n",me);  
	write(me->query("name")+"一个转身，飘身离去。\n",me);  

	destruct(this_object());
}

void kill_ob(object ob)
{
	object me = this_object();

	if( !ob) return;
	if( me->query_temp("mmnz") != ob->query("id")) {
		me->remove_enemy(ob);
		ob->remove_killer(me);
		return;
	}
	::kill_ob(ob);
}
