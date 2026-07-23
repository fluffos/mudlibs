// wh_poison.c

#include <ansi.h>
	
int update_condition(object me, int duration)
{
	int i,j;
	string dutype;
	object * ob,* inv,obj;
	mapping exits;
	string *directions;
	string roomf,dis,oroom;
	string* luanyu=({"...","????"});
	mapping dirs = ([
	"north":		"北面",
	"south":		"南面",
	"east":			"东面",
	"west":			"西面",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上面",
	"down":			"下面",
	"enter":		"里面",
	"out":			"外面"
	]);

	if(!me)
		return 0;
	if(duration<1)
	{
		me->delete("poisontype");
		me->delete_temp("no_fight");
		if(objectp(me->query_temp("huanjue",1)))
		{
			destruct(me->query_temp("huanjue",1));
		}
		me->delete_temp("huanjue");
		me->delete_temp("block_msg/sound");
		me->delete_temp("block_msg/emote");
                return 0;
	}
	if(me->is_ghost())
        {
         	me->delete("poisontype");
		me->delete_temp("no_fight");
		if(objectp(me->query_temp("huanjue",1)))
		{
			destruct(me->query_temp("huanjue",1));
		}
		me->delete_temp("huanjue");
		me->delete_temp("block_msg/sound");
		me->delete_temp("block_msg/emote");
                return 0;
        }
	dutype=me->query("poisontype");
	if(dutype!="水")
	{
		if(objectp(me->query_temp("huanjue",1)))
		{
			destruct(me->query_temp("huanjue",1));
		}
		me->delete_temp("huanjue");
		me->delete_temp("block_msg/sound");
		me->delete_temp("block_msg/emote");
	}
	switch(dutype)
	{
		case "金"://杀气
			tell_object(me,HIR"你感到突然有一股杀气从心头冒出！\n"NOR);
			ob = all_inventory(environment(me));
           		for(i=0; i<sizeof(ob); i++) 
			{
				if(!living(ob[i])) 
					continue;
				if(ob[i]->is_fighting(me))
					continue;
				if(me->query("combat_exp")>ob[i]->query("combat_exp"))
					continue;
				me->kill_ob(ob[i]);
				ob[i]->kill_ob(me);
			}
			if(!me->is_fighting())
			{
				if(me->query("neili")>=100)
				{
					tell_object(me,"你忙运内力压制心中的杀气。\n");
					me->add("neili",-100);
				}
				else if(me->query("qi")>me->query("max_qi")/20)
				{
					tell_object(me,"却无处可以发泄，只得重重地捶了自己的胸膛一拳，吐了一口鲜血出来！\n");
					me->add("qi",-me->query("max_qi")/50);
				}
				else
					tell_object(me,"但你现在气血不足，还是老实点吧。\n");	
			}
			break;
		case "木"://畏惧
			tell_object(me,HIR"你突然感到万分恐惧，只想找个地方躲起来！\n"NOR);
			if(me->query("shen")>0)
			{
				me->add("shen",-(1000+random(501)));
				if(me->query("shen")<0)
					me->set("shen",0);
			}
			else if(me->query("shen")<0)
			{
				me->add("shen",1000+random(501));
				if(me->query("shen")>0)
					me->set("shen",0);
			}
			me->set_temp("no_fight",1);
			break;
		case "水"://幻觉
			if(!me->query_temp("huanjue",1))
			{
				obj=new("/d/sld/npc/obj/huanjue");
				if(!obj)
					break;
				if(obj->move(me))
					me->set_temp("huanjue",obj);
				else
				{
					me->set("poisontype","木");
					destruct(obj);
					break;
				}
			}
			else
			{
				obj=me->query_temp("huanjue",1);
				if(!objectp(obj) || (me!=environment(obj)))
				{
					if(objectp(obj))
						destruct(obj);
					me->delete_temp("huanjue");
					obj=new("/d/sld/npc/obj/huanjue");
					if(!obj)
						break;
					if(obj->move(me))
						me->set_temp("huanjue",obj);
					else
					{
						me->set("poisontype","木");
						destruct(obj);
						break;
					}
				}
			}
			me->set_temp("block_msg/sound",1);
			me->set_temp("block_msg/emote",1);
			tell_object(me,HIR"你陷入了迷幻之中！\n"NOR);
			break;
		case "火"://热
			tell_object(me,HIR"你突然感到全身燥热无比！\n"NOR);
			ob = all_inventory(me);
			for(i=0;i<sizeof(ob);i++)
			{
				if(ob[i]->query("no_drop"))
					continue;
				inv = all_inventory(environment(me));  
        			if(sizeof(inv)>49)
				{
					if(!ob[i]->is_character())
            					destruct(ob[i]);
				}
				else if(ob[i]->move(environment(me)))
				{
            				if(ob[i]->is_character() )
                				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, ob[i]);
            				else 
					{
                				message_vision(sprintf("$N丢下一%s$n。\n",ob[i]->query("unit")),me,ob[i]);
                                        }
            			}
        		}
			if(me->query("jingli")>100)
				me->add("jingli",-100);
			else
				me->set("jingli",1);
			break;
		case "土"://错乱
			tell_object(me,HIR"你突然感到头脑一片混乱，神智不清！\n"NOR);
			switch(random(3))
			{
				case 0: //random move
					if( environment(me) && living(me))
					{
						exits = environment(me)->query("exits");
						if( mapp(exits) && sizeof(exits))
						{
							directions = keys(exits);
							dis=directions[random(sizeof(directions))];
							roomf=exits[dis];
							if(objectp(find_object(roomf)) || objectp(load_object(roomf)))
							{
								oroom=environment(me)->name(1);
								message_vision(sprintf("$N往%s离开了。\n",dirs[dis]),me);
								me->move(roomf);
								message_vision(sprintf("$N从%s走过来。\n",oroom),me);
								break;
							}
						}
					}
				case 1: //give 
					ob = all_inventory(environment(me));
					inv = all_inventory(me);
					if(sizeof(ob)>1 && sizeof(inv)>0)
					{
						i=random(sizeof(inv));
						j=i;
						while(inv[i]->query("no_drop") || inv[i]->query("no_give"))
						{
							i=i+1;
							if(i==sizeof(inv))
								i=0;
							if(i==j)
								break;
						}
						if(!inv[i]->query("no_drop") && !inv[i]->query("no_give"))
						{
							for(j=0;j<sizeof(ob);j++)
							{
								if(me==ob[j])
									continue;
								if(living(ob[j]) && inv[i]->move(ob[j]))
								{
									message_vision(sprintf("$N把%s塞给$n。\n",inv[i]->name(1)),me,ob[j]);
									break;
								}
							}
							if(j<sizeof(ob))
								break;
						}
					}
				default://random say
					message_vision(luanyu[random(sizeof(luanyu))],me);
					break;
			}	
			break;
		default:
			break;
	}
	me->set_temp("last_damage_from", "神龙五行"+dutype+"毒发作");
	message_vision(BLU "$N身中的神龙五行"+dutype+"毒发作了！\n" NOR, me);
	me->apply_condition("wh_poison", duration-1);
	
	return 1;
}

string query_type(object me)
{
        return "poison";
}