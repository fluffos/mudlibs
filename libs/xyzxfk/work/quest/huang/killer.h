int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        mapping skill_all;
		string *skill;
		ob = this_object();
        i=maxpot;
		if( i < 100) i = 100;
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        skill_all=ob->query_skills();
		skill = keys(skill_all);
		j = sizeof(skill_all);
        	for(i=0; i<j; i++) 
			{ ob->set_skill(skill[i],maxpot);
			}
        ob->set("max_qi",     me->query("max_qi")*2/3); 
        ob->set("eff_jing", me->query("eff_jing")*2/3); 
        ob->set("max_neili",  me->query("max_neili")); 
        ob->reincarnate(); 
        ob->set("eff_qi",ob->query("max_qi"));
		ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
		call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
  destruct(me); 
  return 1;
}
void die()
{
	object corpse;
	mixed killer;
	if( !living(this_object()) ) revive(1);
	else delete_temp("faint_by");
	COMBAT_D->announce(this_object(), "dead");
	if( !(killer = query_temp("last_damage_from")) )
	killer = "莫名其妙地";
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());
	set_temp("last_damage_from", "莫名其妙地");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}


void init()
{   object ob,player;
    ::init();
    ob=this_object();
	player=this_player();
	if(userp(player)&&player->query("id")==ob->query_temp("must_killby")
		&&!ob->query_temp("already_ini"))
	{   ob->set_temp("already_ini",1);
		call_out("begin_kill",2,ob,player);
	}
	return;
}

void begin_kill(object ob,object player)
{message_vision(HIY"\n$N恶狠狠的对$n喝道：臭贼，大爷我最恨多管闲事的人，今天算你倒霉了！！\n"NOR ,ob,player);
 ob->kill_ob(player);
}
