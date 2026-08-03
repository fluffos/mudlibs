// mmr1.h

#include <ansi.h>
void init()
{
	object ling, name1;
	object ob = this_player();
	object me = this_object();
	name1 = ob->query("id");
	ling = present("ling pai", ob);

	::init();

	if (interactive(ob) 
        && !environment(ob)->query("no_fight")
	&& ling
	&& !(ling->query_temp("mmr") != name1)
	&& !(ling->query_temp("hsjob") != name1)
	&& !(me->query_temp("mmr") != name1 )
	&& ob->query_temp("hs/jobji")
	&& ob->query_temp("hs/have") )
        {
	        me->set_temp("apply/attack",  random(30));
        	me->set_temp("apply/dodge",  100+random(50));

	        if (!me->query_temp("skillset"))	
		{
		command("say " +"想跑？大爷今天就超渡你！！！\n");	
		ob->start_busy(4);
	        remove_call_out("dest");
	        call_out("dest",240);
		me->set_leader(ob);
	        remove_call_out("do_clone");
	        call_out("do_clone", 0, me, ob);
		}
	        else 
		{
	        command("say 想跑，大爷今天就超渡你！！！\n");	
		ob->start_busy(4);
	        me->set_leader(ob);
	        remove_call_out("dest");
	        call_out("dest",240);
	        remove_call_out("kill_ob");
	        call_out("kill_ob", 0, ob); 
        	}
	}
}	

int do_clone(object me, object ob)
{
	object weapon;
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing,i;
	string t_force,t_dodge;
	number = (int)ob->query("max_pot");
	number = number-100;
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

/*set killer's level*/

        if (ob->query("combat_exp")>800000)
        {
    	    killerskill1 = skill2[random(sizeof(skill2))];
            number = (int)(number*(7+random(3))/10);
    	} 
	if (ob->query("combat_exp")<800000&&ob->query("combat_exp") > 600000)
    	{
    	    killerskill1 = skill2[random(sizeof(skill2))];
	    number = (int)(number*(7+random(2))/10) ;
	}
	if (ob->query("combat_exp")<600000&&ob->query("combat_exp") > 400000)
    	{
	    killerskill1 = skill2[random(sizeof(skill2))];
            number = (int)(number*(6+random(2))/10) ;
	}
	if (ob->query("combat_exp")<400000&&ob->query("combat_exp") > 200000)
    	{
       	    killerskill1 = skill1[random(sizeof(skill1))];
            number = (int)(number*(5+random(3))/10) ;
        }
    	if (ob->query("combat_exp")<200000)
        {
    	    killerskill1 = skill1[random(sizeof(skill1))];
            number = (int)(number*(5+random(2))/10) ;
        }
    	if (number>200) number = 200;
     
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

me->set("max_qi",k_qi*3/4);
me->set("eff_qi",k_qi*3/4);
me->set("qi",k_qi*3/4);
	me->set("max_jing",k_jing);
	me->set("eff_jing",k_jing);
	me->set("jing",k_jing);
	me->set("max_neili",k_neili);
	me->set("neili",k_neili);
me->set("combat_exp",ob->query("combat_exp")*14/10);

	me->set_temp("skillset",1);
	ob->delete_temp("hs/have");
	me->set_leader(ob);
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, ob); 
	return 1;
}

void dest()
{
       object me,ob;
       ob = this_player();
       me = this_object();

       write(me->query("name")+"道：他奶奶的，这次算你命大，下回看老子还饶的了你！\n",me);  
       write(me->query("name")+"匆匆离开。\n",me);  

       destruct(this_object());
}

void unconcious()
{
       object me, ob,name1, ling;
       me = this_object();
       ob = this_player();
       name1 = ob->query("id");
       ling = present("ling pai", ob);
       if ( ling
	&&  !(ling->query_temp("mmr") != name1 )
	&&  !(me->query_temp("mmr") != name1 ) ) {
	if (! (ling->query_temp("killed") )) {
       ling->set_temp("killed", 1);
       ob = new("/clone/money/gold");
       ob->move(me);
       }
	else {
	ling->add_temp("killed", 1);
	}
}
       ::unconcious();
}
