//test
// /task/npc/target.c
//Made by jason@pkuxkx
//2001.1.3
inherit NPC;

int other_qi,other_jing;

int leave();

void create()
{
	set_name("贼人",({"thief"}));
        set("chat_chance",10);
	set("chat_msg",({
		(: random_move :),
	}));
	
	setup();
}

void init()
{
	
	int lvl,i;
	string *sname,*pname,*mname,*tmp;
	string *skls = ({
    "force","dodge","strike","unarmed","blade","sword","parry",
	});
	mapping skill_status,prepare_status,map_status;
	object ppl=this_player();
	if(ppl->query_temp("task_target")==query("id")
	&&query("task_bekill")==ppl->query("id"))
	{
		object me=this_player();
		object output=this_object();
		object weapon,ar;
		mapping armor;
                if (output->query_temp("met_time") == 1)
                        return;
                if (output->query_temp("met_time")==0)
                {
                        output->set_temp("met_time",1);
                         for (i=0;i<5;i++)
                                random_move();
                }
                if (output->query_temp("met_time") == 1)
                {
                        output->set_temp("met_time",2);
                        output->random_move();
                }
                output->set_temp("met_time",2);
			
		if(query_temp("weapon")) 
		{
			destruct(output->query_temp("weapon"));
			delete_temp("weapon");
		}
		if(query_temp("secondary_weapon"))
		{
			destruct(output->query_temp("secondary_weapon"));
			delete_temp("secondary_weapon");
		}
		if(armor=output->query_temp("armor"))
		{
			tmp=keys(armor);
			for(i=sizeof(armor)-1;i>=0;i--)
			{
				destruct(armor[tmp[i]]);
			}
			delete_temp("armor");
		}
		if(me->query_temp("weapon"))
		{
			
			weapon=new(base_name(me->query_temp("weapon")));
			weapon->set("weapon_prop/damage",
			weapon->query("weapon_prop/damage")/2);
			weapon->set("owner",query("id"));
			weapon->set("value",0);
			weapon->set("no_get",1);
			weapon->set("no_give",1);
			weapon->set("no_drop",1);
			weapon->set("no_store",1);
			weapon->move(output);
			
			command("wield all");
		}
		if(me->query_temp("secondary_weapon"))
		{
			
			weapon=new(base_name(me->query_temp("secondary_weapon")));
			weapon->set("weapon_prop/damage",
			weapon->query("weapon_prop/damage")/2);
			weapon->set("owner",query("id"));
			weapon->set("value",0);
			weapon->set("no_get",1);
			weapon->set("no_give",1);
			weapon->set("no_drop",1);
			weapon->set("no_store",1);
			weapon->move(output);
			
			command("wield all");
		}
		if(armor=me->query_temp("armor") )
		{
			tmp=keys(armor);
			for(i=0;i<sizeof(armor);i++)
			{
				ar=new(base_name(armor[tmp[i]]));
				ar->set("value",0);
				ar->set("no_get",1);
				ar->set("no_drop",1);
				ar->set("no_give",1);
				ar->set("no_store",1);
				ar->set("owner",query("id"));
				ar->move(output);
				
			}
			command("wear all");
		}
		command("say 不是冤家不聚头，纳命来吧！！");
		if(random(3)>1) output->kill_ob(me);
		lvl=me->query_temp("task_level");
		
	    if (mapp(skill_status=me->query("weapon")))
            	output->set("weapon",skill_status);
    	    else    
    	    	output->delete("weapon");
    	    if ( mapp(skill_status = me->query_skills()) ) {
        	skill_status = me->query_skills();
        	sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
            		output->set_skill(sname[i], skill_status[sname[i]]+(lvl-4));
        	}
    	}
    
    	    if ( mapp(map_status = me->query_skill_map()) ) {
            	mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
            		output->map_skill(mname[i], map_status[mname[i]]);
        	}
    	}
    
	    if ( mapp(prepare_status = me->query_skill_prepare()) ) {
        	pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
            		output->prepare_skill(pname[i], prepare_status[pname[i]]);
        	}
    	}
		for (i=0;i<sizeof(skls);i++) {
			if (output->query_skill(skls[i]) < 30)	//task npc 基本功夫最低等级
					output->set_skill(skls[i],30);
		}
		if (output->query("combat_exp") < 3000)
			output->set("combat_exp",3000);
				
    
	add_action("do_change","wield");
	add_action("do_change","wear");
	add_action("do_change","unwield");
	add_action("do_change","remove");
	add_action("do_change","drop");
	add_action("do_enable","enable");
        add_action("do_enable","jifa");
        add_action("do_enable","bei");
        add_action("do_enable","wbei");
        add_action("do_enable","prepare");
   }

}

int do_change(string arg)
{
	object ppl=this_player();
	if(ppl->query_temp("task_target")==query("id")
	&&query("task_bekill")==ppl->query("id"))
	{
		write("临阵换装，来不及了吧？\n");
		return 1;
	}
	return 0;
}

int do_enable(string arg)
{
	object ppl=this_player();
	if(ppl->query_temp("task_target")==query("id")
	&&query("task_bekill")==ppl->query("id"))
	{
		write("临阵换招，来不及了吧？\n");
		return 1;
	}
	return 0;
}

varargs int receive_wound(string type, int damage, object who)
{
    string owner=query("task_bekill");
    if (objectp(who))
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "qi": other_qi+=damage; break;
		case "jing": other_jing+=damage; break;
	    }
	}
    }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
    string owner=query("task_bekill");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "qi": other_qi+=damage; break;
		case "jing": other_jing+=damage; break;
	    }
	}
    }
    return ::receive_damage(type, damage, who);
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
	        string owner=query("task_bekill");
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

void unconcious()
{
die();
}


void die()
{
	string owner;
    	string skill;
        object owner_ob;
	object me=this_object();
	string str,msg;
	int max_qi, max_jing, ratio, exp_r, pot_r;
	max_qi=query("max_qi");
	max_jing=query("max_jing");
	
        owner = query("task_bekill");
	if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
		if( owner_ob->query_temp("task_target")!=query("id") 
			|| query_temp("last_damage_from") != owner_ob )
			//modified by icer 
			//别人杀的不算
		{
			//log_file("task","leave fuc \n");
			leave();
		
			return;
		}
        	
	    if(environment(owner_ob)==environment() && living(owner_ob) ) {
   		message("vision",me->name()+"叹了口气，我认栽。\n",environment());
	    } else {
		message_vision("$N死了。\n",this_object());
	    }
	    	    
		    ratio=100*(max_qi-other_qi)/max_qi;
		    if(ratio<0) ratio=0;
		    ratio=ratio*(max_jing-other_jing)/max_jing;
		    
		    if(ratio<0) ratio=0;
		     
		    exp_r=query("kill_reward/exp")*ratio*2/150;
		    pot_r=query("kill_reward/pot")*ratio*2/200;
		    owner_ob->add("combat_exp",exp_r);
		    owner_ob->add("potential",pot_r);
		    
		    if (owner_ob->query_temp("task_level")==9)
          		owner_ob->set_temp("task_level",5);
        	   else 
        	   	owner_ob->add_temp("task_level",1);
     
        	   message("vision","你被奖励了"+chinese_number(exp_r)+"点经验和"+
        	   chinese_number(pot_r)+"点潜能!\n",owner_ob);
         	
   		    owner_ob->delete("task_target");
     }
     
	destruct(this_object());
	return;
}

int goto_leave()
{
	remove_call_out("leave");
	call_out("leave",query("wait_time"));
	return 1;
}

int leave()
{
	command("haha");
	command("say 东西是我拿的，人也是我杀的，谁能把我怎么样？哈哈哈……\n");
	destruct(this_object());
	return 1;
}
