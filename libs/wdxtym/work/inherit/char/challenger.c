// challenge.c

#include <ansi.h>
#include <command.h>

inherit NPC;

object with_ob = 0;

void set_lvl(int lvl)
{
	object me = this_object();
	mapping smap = me->query_skills();
	int i;
	string *skills;
        
        lvl=220;

	skills = keys(smap);
	for(i=0;i<sizeof(skills);i++)
	{
		me->set_skill(skills[i],lvl);
	}
	me->set("combat_exp",lvl*lvl*lvl/10+1000000);
	me->set("jiali",lvl);
	me->set("qi",lvl*2000);
	me->set("eff_qi",lvl*2000);
	me->set("max_qi",lvl*2000);
	/*
	me->set("jing",lvl*1000);
	me->set("eff_jing",lvl*1000);
	me->set("max_jing",lvl*1000);
	*/
	me->set("jing",999999999);
	me->set("eff_jing",999999999);
	me->set("max_jing",999999999);
	
	me->set("neili",lvl*100);
	me->set("max_neili",lvl*200);
}

varargs int receive_damage(string type, int damage, mixed who)
{
	object me = this_object();

	if(objectp(who))
	{
		me->add("boss/"+who->query("id"),damage);
		me->add("all_recive_damage",damage);
	}

	return ::receive_damage(type,damage,who);
}

void die()
{
	object ob;
	object story;
	object env;

	string msg;
	int expi, poti, weiwangi, scorei;
	int i;
	string *items,*killer;
	object obj;
	mapping boss,give;

	if (! objectp(ob = query_last_damage_from()))
		return;

	if (! objectp(story = "/adm/daemons/bossd"->query_running_story()))
		return;

	story->stop_story();
	msg = query("chat_lost");
	if (! msg) msg = "岂有此理！怎么... 怎么可能会这样？";
	command("chat " + msg);
	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name() + "打败了" + name() + "，捍卫了中原武林的尊严。");

//最后一击
	expi = random(query("combat_exp") / 100) + 10;
	poti = random(200) + 50;
	weiwangi = random(query("combat_exp") / 1000) + 10;
	scorei = random(query("combat_exp") / 1000) + 10;
      if (ob->query("combat_exp")>10000000) expi /= 2;
	ob->add("combat_exp", expi);
	ob->add("potential", poti);
	ob->add("weiwang", weiwangi);
	ob->add("score", scorei);

	tell_object(ob, sprintf(HIG "你获得了%s点修为、%s点潜能，并增加了%s点威望、%s点江湖阅历。"NOR"\n",
			chinese_number(expi),chinese_number(poti),
			chinese_number(weiwangi),chinese_number(scorei)));
	set("finished", 1);

//伤害统计
	killer = keys(boss=query("boss"));
        env = environment(this_object());

	if(give = query("die_give2"))
	{
		items = keys(give);
	}
	for(i=0;i<sizeof(killer);i++)
	{
		if(objectp(ob=find_player(killer[i])))
		{
			message_vision("$N累计对boss造成"+ boss[killer[i]] +"点伤害。\n", ob);
			  log_file("boss_give", sprintf("%s：对boss造成 %d      点伤害，ID="+ob->query("id")+"。\n",ctime(time()),boss[killer[i]]));
			ob->add("weiwang",boss[killer[i]]/100);

                  if (ob->query("combat_exp")<10000000) 
                      ob->add("combat_exp",boss[killer[i]]/10);
                  else ob->add("combat_exp",boss[killer[i]]/20);

			if(give&&present(ob,environment(this_object())))
			{
				int j;
				for(j=0;j<sizeof(items);j++)
				{
//					if(random(give[items[j]])==0&&random(query("all_recive_damage"))<boss[killer[i]]
					if(random(query("all_recive_damage"))<boss[killer[i]]
						&&random(query("all_recive_damage"))<boss[killer[i]])
					{
						obj = new(items[j]);
						obj->move(ob);
        obj = new("/clone/0/jiangli");
						obj->move(env);
						tell_object(ob,HIM"你获得了"+obj->query("name")+"。"NOR"\n");
						CHANNEL_D->do_channel( this_object(), "ic",ob->query("name")+"抢走了我的"+obj->query("name")+"。");
						log_file("boss_give", sprintf("%s："+ob->query("id")+"得到了%s/%d。\n",ctime(time()),obj->query("name"),query("all_recive_damage")));
					}
				}
			}
            if (ob->query("combat_exp")<10000000)
			   tell_object(ob,HIM"你获得了"+boss[killer[i]]/10+"点修为和"+boss[killer[i]]/100+"点威望。"NOR"\n");
            else tell_object(ob,HIM"你获得了"+boss[killer[i]]/20+"点修为和"+boss[killer[i]]/100+"点威望。"NOR"\n");
		}
	}
//掉落物品
	if(give = query("die_give"))
	{
		items = keys(give);
		for(i=0;i<sizeof(items);i++)
		{
			if(random(give[items[i]])==0)
			{
				obj = new(items[i]);
				obj->move(environment(this_object()));
			}
		}
	}

	call_out("destruct", 0, this_object());
}

void win()
{
	object ob;
	object story;
	string msg;

	if (sizeof(query_enemy()))
		return;

	if (! objectp(story = "/adm/daemons/bossd"->query_running_story()))
		return;

	story->stop_story();
	command("chat* haha");
	msg = query("chat_win");
	if (! msg) msg = "中原武林，不堪一击！";
	command("chat " + msg);
	set("finished", 1);
	call_out("destruct", 0, this_object());
	::win();
}
