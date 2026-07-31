#include <ansi.h>
inherit NPC;

//int skillk = 100 + random(200);

void create()
{
        set_name("雪山丧尸", ({ "zombie" }));
        set("vendetta_mark","zombie");
        set("long", "这是一个腐烂的丧尸。\n");
        set("title", HIB "(鬼气)" NOR);

        set("str", 500);
        set("con", 1200);
        set("dex", 220);
        set("int", 500);
		set("huishi", 2000);
        set("max_qi", random(250000));
        set("max_jing", 500000);
        set("max_neili", 5000000);
        set("max_jingli", 5000000);
		set("fali", 500000);
        set("combat_exp", 100000000);
        set("bellicosity", 5 );
        set("death_msg", RED"\n$N化作了一滩血水。\n\n"NOR);


        set_temp("apply/attack", 500);
        set_temp("apply/parry", 500);
        set_temp("apply/unarmed_damage", 1000);
        set_temp("apply/reduce_damage", 60);

        setup();
}
void init()
{
	object me,ob;
	::init();
	if (interactive(me = this_player()))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, me);
	}
}

void die()
{
	object me,ob,jmem,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");
	//team = me->query_team();
	/*jmem = (object)me->query_temp("jfb/jfb_jmem");

//tell_object(find_player("jerry"),sprintf("%O %O %O\n",team,jmem,me));
	if(!team || !clonep(jmem) || !team || !me || !userp(me))
	{
		tell_room(environment(ob),HIM"亡灵逃跑了。\n"NOR);
		destruct(ob);
		return;
	}

	jmem->add("make_jboss",1);
	tell_room(environment(ob),HIM"轰~~~~！\n亡灵消失了。\n"NOR);

	size = sizeof(team);
	for(i=0;i<size;i++)
	{
		if(!team[i]) continue;
		level = team[i]->query("jym_level/level");
		exp = 500*(1+random(level))/size;

		if(exp)
		{
			pot = exp/3;
			tell_object(team[i],sprintf("你获得了%d点修为，%d点潜能。\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
		}
	}*/
	//掉宝
        rand = random(1000);
//tell_object(find_player("jerry"),sprintf("killer: rand = %d",rand));


	if(file)
	{
		item = new(file);
		if(item)
		{
			ob = this_object();  //NPC
			me = ob->query_temp("last_damage_form"); //玩家
			"/adm/item/equip"->init_equip_prop_1(item);  //变更装备品质
			item->move(environment(ob));
		}
	}
       
	/*		if (me->query_temp("xinyun") < 1)
		{
				item = new("/d/sangshidong/npc/fuyuanguai");
			message_vision(HIR "\n幸运额外加成。\n" NOR,me);
			if(item)
		{
			item->set_amount(2);
			item->move(environment(ob));
		}
			
		
		}*/
	if(rand > 900)
	{
		item = new("/d/sangshidong/npc/jsboss");
		if(item)
		{
			item->set_amount(2);
			item->move(environment(ob));
		}
	}
		   
  else if(rand >= 1)
	{
		item = new("/d/sangshidong/npc/sangshi1");
		if(item)
		{
			item->move(environment(ob));
		}
         }
	destruct(ob);
}

//函数：寻敌
/*void findPlayer()
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
*/