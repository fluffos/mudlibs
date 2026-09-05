//test svn
// /task/npc/target.c
//Made by jason@pkuxkx
//2001.1.3
inherit NPC;

int other_qi,other_jing;

void leave();

void create()
{
	set_name("贼人",({"thief"}));
        set("chat_chance",30);
	set("chat_msg",({
		(: random_move :),
	}));
	setup();
	carry_object("/clone/armor/tiejia")->wear();
	call_out("leaving",1200);
}


void init()
{
	
	add_action("do_clone","hit");
	add_action("do_clone","fight");
	add_action("do_clone","hitall");
	add_action("do_clone","perform");
	add_action("do_clone","yong");
	add_action("do_clone","kill");
	add_action("do_clone","killall");
	add_action("do_clone","exert");
	add_action("do_clone","yun");	
}

int do_clone()
{
	int i;
	string *sname,*pname,*mname,*tmp;
	string *skls = ({
    "force","dodge","strike","unarmed","blade","sword","parry",
	});
	mapping skill_status,prepare_status,map_status,wprepare_status;
	object ppl=this_player();
	if (ppl == this_object()->query("opp"))
		return 0;
	this_object()->set("opp",ppl);
	if (!is_fighting(this_object()))
	{
		object me=this_player();
		object output=this_object();
		object weapon,ar;
		mapping armor;
			
		if (me->query("zyhb"))
			output->set("zyhb",1);
		
		output->set("combat_exp",me->query("combat_exp")*4/5);
		output->set("qi",me->query("qi")/2);
		output->set("max_qi",me->query("max_qi")/2);
		output->set("eff_qi",me->query("eff_qi")/2);
		output->set("jing",me->query("jing")/2);
		output->set("max_jing",me->query("max_jing")/2);
		output->set("eff_jing",me->query("eff_jing")/2);
		output->set("neili",me->query("neili")/2);
		output->set("max_neili",me->query("max_neili")/2);
		output->set("jingli",me->query("jingli")/2);
		output->set("max_jingli",me->query("max_jingli")/2);
		output->set("jiali",me->query("jiali")/2);
		
    	if ( mapp(skill_status = output->query_skills()) ) {
        	skill_status = output->query_skills();
        	sname  = keys(skill_status);
		}
		
		for(i=0; i<sizeof(skill_status); i++) {
            		output->delete_skill(sname[i]);
        	}
        	
	    if ( mapp(prepare_status = me->query_skill_prepare()) ) {
        	pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
            		output->prepare_skill(pname[i]);
        	}
    	}
	    if ( mapp(wprepare_status = me->query_wprepare()) ) {
        	pname  = keys(wprepare_status);

		for(i=0; i<sizeof(wprepare_status); i++) {
            		output->prepare_wskill(pname[i]);
        	}
    	}
    	   	output->delete("weapon");
    	    if ( mapp(skill_status = me->query_skills()) ) {
        	skill_status = me->query_skills();
        	sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
				if (sname[i]!="iron-cloth" && sname[i]!="qiankun-danuoyi")
            		output->copy_skill(sname[i], skill_status[sname[i]]);
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
	    if ( mapp(wprepare_status = me->query_wprepare()) ) {
        	pname  = keys(wprepare_status);

		for(i=0; i<sizeof(wprepare_status); i++) {
            		output->prepare_wskill(pname[i], wprepare_status[pname[i]]);
        	}
    	}
		for (i=0;i<sizeof(skls);i++) {
			if (output->query_skill(skls[i]) < 30)	//task npc 基本功夫最低等级
					output->set_skill(skls[i],30);
		}
		if (output->query("combat_exp") < 3000)
			output->set("combat_exp",3000);
		output->reset_action();
				
    
   }
	return 0;
}
void unconcious()
{
die();
}

void leaving()
{
		message_vision(this_object()->query("name") + "匆匆走开了。\n",this_object());
		call_out("leave",1);
}
void leave()
{
	destruct(this_object());
}