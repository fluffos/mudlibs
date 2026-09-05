//test
// /task/npc/target.c
//Made by jason@pkuxkx
//2001.1.3
inherit NPC;

int other_qi,other_jing;

int leave();

void create()
{
        set_name("情痴",({"freecv"}));
        set("gender", "男性");
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("max_qi", 8000);
        set("qi", 8000);
	
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
        if (query("task_bekill")==ppl->query("id"))
	{
		object me=this_player();
		object output=this_object();
		object weapon,ar;
		mapping armor;
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
                command("say sorry,没别的理由有人看你不顺托我给您服务!");
                output->kill_ob(me);
                lvl= me->query("str") - me->query("per") - 5;
                output->set("jiali",me->query("max_neili")/15);
                output->set("combat_exp",me->query("combat_exp"));
                output->set("max_neili",me->query("max_neili"));
                output->set("max_qi",8000);
                output->set("max_jing",me->query("max_jing"));
                output->set("jing",me->query("max_jing"));
                output->set("qi",me->query("max_qi"));
                output->set("neili",me->query("max_neili"));
		
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
        if(query("task_bekill")==ppl->query("id"))
	{
                write("有没有风度阿，打个架也这么婆婆妈妈的?\n");
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
                write("不是吧。。。打个架也这么麻烦阿，不要啦。。。\n");
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
        say(" 我faint,你还真猛，打不过你总跑的过你吧？");
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
        command("say 无聊，不陪你玩乐，走人走人！\n");
	destruct(this_object());
	return 1;
}
