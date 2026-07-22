//edit by feng
//2008.10.20

#include <ansi.h>
inherit NPC;

#define PRODUCT "/clone/shoufei/product"

void create()
{
	set_name("扶桑武士", ({ "wushi"}));
	set("gender", "男性");
	set("age",26);
	set("long", "他是一位扶桑武士，潜心研究中原武术多年。\n");

	setup();
	carry_object("/clone/misc/hic_cloth")->wear();
}

void init()
{
	object ob,me;
	int i,j;
	mapping skill_status,map_status,ob_data,my_data;
	string *sname,*mname;

	ob = this_player();
	me = this_object();
	if(!me->query("skill",1))
	{
	    if ( mapp(skill_status = ob->query_skills()) )
	    {
	        sname  = keys(skill_status);
	        for(i=0; i<sizeof(skill_status); i++)
	        {
	            me->set_skill(sname[i], skill_status[sname[i]]/2);
	        }
	    }
	    if ( mapp(map_status = ob->query_skill_map()) ) {
	        mname  = keys(map_status);
	        for(i=0; i<sizeof(map_status); i++) {
	            me->map_skill(mname[i], map_status[mname[i]]);
	        }
	    }
	    if ( mapp(map_status = ob->query_learned()) ) {
	        mname  = keys(map_status);
	        for(i=0; i<sizeof(map_status); i++) {
	            skill_status=([ mname[i]: map_status[mname[i]] ]);
	        }
	    }
	    
	    ob_data=ob->query_entire_dbase();
	    my_data=me->query_entire_dbase();
	
	    my_data["max_neili"]  = ob_data["max_neili"];
	    my_data["max_jingli"] = ob_data["max_jingli"];
	    my_data["neili"]      = ob_data["neili"];
	    my_data["jingli"]     = ob_data["jingli"];
	    my_data["max_qi"]     = ob_data["max_qi"];
	    my_data["max_jing"]   = ob_data["max_jing"];
	    my_data["eff_qi"]     = ob_data["eff_qi"];
	    my_data["eff_jing"]   = ob_data["eff_jing"];
	    my_data["qi"]         = ob_data["qi"];
	    my_data["jing"]       = ob_data["jing"];
	    my_data["jiali"]      = ob_data["jiali"];
	    my_data["int"]        = ob_data["int"];
	    my_data["con"]        = ob_data["con"];
	    my_data["str"]        = ob_data["str"];
	    my_data["dex"]        = ob_data["dex"];

	    me->set("skill",1);
	}
	call_out("findPlayer",5); //寻敌
}

void die()
{
	object me,ob,memory,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");
	team = me->query_team();
	memory = (object)me->query_temp("mirror/mirror_memory");

//tell_object(find_player("feng"),sprintf("%O %O %O\n",team,memory,me));
	if(!team || !clonep(memory) || !team || !me || !userp(me))
	{
		tell_room(environment(ob),HIM"轰~~~~！\n扶桑武士仓惶之下，扔下烟雾弹，逃跑了。\n"NOR);
		destruct(ob);
		return;
	}
	
	memory->add("make_boss",1);
	tell_room(environment(ob),HIM"轰~~~~！\n扶桑武士仓惶之下，扔下烟雾弹，逃跑了。\n"NOR);

	size = sizeof(team);
	for(i=0;i<size;i++)
	{
		if(!team[i]) continue;
		level = team[i]->query("jh_dj/dj");
		exp = 1000*(1+random(level))/size;

		if(exp)
		{
			pot = exp/2;
			tell_object(team[i],sprintf("你获得了%d点经验，%d点潜能。\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
		}
	}
	//掉宝
	rand = random(100);
//tell_object(find_player("feng"),sprintf("killer: rand = %d",rand));
	if(rand < 10) file = PRODUCT->get_random_level_product(1+random(15),me->query("jh_dj/dj")-5,me->query("jh_dj/dj"));
	else if(rand < 5) file = PRODUCT->get_random_level_product(1+random(15),me->query("jh_dj/dj"),me->query("jh_dj/dj"));

	if(file)
	{
		item = new(file);
		if(item)
		{
			item->move(environment(ob));
		}
	}
	destruct(ob);
}

//函数：寻敌
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;
	
	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);
	
	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
