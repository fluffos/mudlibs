// gfbing.h
// By River 98/09

#include <ansi.h>
void init()
{
	object name1;
	object ob = this_player();
	object me = this_object();

	name1 = ob->query("id");
	::init();

	if (interactive(ob)
	 && !environment(ob)->query("no_fight")
	 && me->query_temp("guanfu") == name1
	 && ob->query_condition("tz_job")) {
		me->set_temp("apply/attack",  random(30));
		me->set_temp("apply/dodge",  random(50));
		if (!me->query_temp("skillset")) {
			command("say 哈哈，无耻叛贼，居然敢占山为王，拿命来吧！");
			ob->start_busy(3);
			remove_call_out("dest");
			call_out("dest",360);
			me->set_leader(ob);
			remove_call_out("do_clone");
			call_out("do_clone", 0, me, ob);
		}
		else {
			command("say 想跑？既然被我发现踪迹，拿命来吧！");
			ob->start_busy(1);
			me->set_leader(ob);
			remove_call_out("dest");
			call_out("dest",360);
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
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
        me->set_skill("dodge",number);
        me->set_skill("parry",number);
        me->set_skill(t_force,number);
        me->set_skill(t_dodge,number);
        me->set_skill(killerskill1["t_skill"],number);
        me->set_skill(killerskill1["b_skill"],number);

        me->map_skill("force",t_force);
        me->map_skill("dodge",t_dodge);
        me->map_skill("parry",killerskill1["t_skill"]);
        me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
       
        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

        me->set("max_qi",k_qi*2/3);
        me->set("eff_qi",k_qi*2/3);
        me->set("qi",k_qi*2/3);
        me->set("max_jing",k_jing*2/3);
        me->set("eff_jing",k_jing*2/3);
        me->set("eff_jingli", k_neili*2/5);
        me->set("jing",k_jing*2/3);
        me->set("max_neili",k_neili*2/3);
        me->set("neili",k_neili*2/3);
        me->set("combat_exp",ob->query("combat_exp")*2/3);

        me->set_temp("skillset",1);       
        me->set_leader(ob);
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, ob); 
        return 1;
}

void dest()
{
	object me;
	me = this_object();

	write(me->query("name")+"大呼一声：不好，要归队了，下次等着瞧。\n",me);  
	write(me->query("name")+"一个转身，慌乱离去。\n",me);  

	destruct(this_object());
}

void kill_ob(object ob)
{
	if(!ob) return;
        ::kill_ob(ob);
}

void die()
{
	object ob;
	
	ob = query_temp("last_damage_from");
	
	if (ob->query("id") == query_temp("guanfu"))
		ob->set_temp("mark/done", 1); 

	::die();
}
