#include <ansi.h>

inherit ITEM;

int do_zh(string arg);
int do_yes(string arg);
int do_no(string arg);

object obj;

void create()
{
	set_name(YEL "神龙招魂牌" NOR, ({"zhaohunpai" ,"pai" }));
	set_weight(20);
        
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块神龙教的招魂牌，是神龙弟子用来(zhaohun)，诱迫他人归顺的，\n");
		set("no_sell",1);
		set("no_get",1);
		set("no_steal",1);
		set("no_give",1);
		set("no_drop",1);
	}
	setup();
}

void init()
{
	add_action("do_zh","zhaohun");
	add_action("do_yes","yes");
	add_action("do_no","no");
	obj=this_player();
}

int do_zh(string arg)
{
	object me=this_player();
	string tid,tname;
	int i,j,k,texp,myexp,adds,kar,times,qnadd,bz,temp,zhcs,qi;
	string * skill=({"poison","shenlong-yaoli","force","dulong-dafa"});

	if((uptime()-query("zhaotime"))<2)
		return notify_fail("不用如此卖力，休息一下再招吧。");
	else
		set("zhaotime",uptime());
	if(!arg || arg==" " || arg==" ") return 0;

	if((obj = present(arg, environment(me))) && (obj->is_character())) {
		if(obj->is_corpse())
			return notify_fail("人都死了，你还招什么招？! \n");
		tname=obj->name();
		tid=obj->query("id");
		texp=obj->query("combat_exp"); 
		myexp=me->query("combat_exp");
                bz=1;
		if(!living(obj))
		{
			if((texp<=myexp) || random(3)==0)
				return notify_fail("这个人现在处于昏迷中，听不到你说的话! \n");
			bz=random(2)+2;
		}
		if((tname!=me->query("quest_kill/name")) || (tid!=me->query("quest_kill/id")))
			return notify_fail("没有让你诱迫这个人归顺呀! \n");

		message_vision("$N拿出招魂牌对着"+tname+"一晃，然后口念咒语。\n",me);
		
		me->receive_damage("jingli",50);

		if(myexp<=0) myexp=1;
		if(texp<=0) texp=1;

		i = texp;
                zhcs=me->query_temp("zhaohun/times",1);
                qi=obj->query("qi");
                if(qi<=0) qi=1;
		if(myexp<texp)
			bz= bz*(random(1200) + obj->query("max_qi")*200/qi)*myexp;
		else {
			bz= (random(500) + obj->query("max_qi")*100/qi)*myexp;
			temp=myexp;
			myexp=texp;
			texp=temp;
		}
                bz=bz*((zhcs/10)+1);    
		if ( (bz < (i*(random(500)+500))) || random(2)) {
			me->start_busy(random(3)+1);
			if(random(3)==0)  {
				message_vision(tname+"狠狠地瞪了$N一眼。\n",me);
				
				return 1;
			}
			else  {
				message_vision(tname+"对$N怒喝道：看来非教训你一下不可！\n",me);
				
				obj->kill_ob(me);
				me->fight_ob(obj);
                                obj->set_leader(me);
                                tell_object(me, tname+"决定跟随你一起行动！\n");
				zhcs++;
                		me->set_temp("zhaohun/times",zhcs);
                                remove_call_out("nofollow");
                                call_out("nofollow", random(30)+30, obj); 
				return 1;
			}
		}

		me->remove_enemy(obj);
		obj->remove_killer(me);
		if(obj->query_leader())
		{
			remove_call_out("nofollow");
			obj->set_leader(0);
		}
		tell_room(environment(obj),tname+"突然入魔似地不由自主地全身发抖，随之瘫倒在地。\n");
		if(random(10)>7)    {
			tell_object(me, tname+"对你哀求道：这儿是点小意思，您就大人大量放过我吧！(yes/no)\n");
			me->set_temp("quest/huilu",1);
			return 1;
		}

		tell_room(environment(obj), tname+"跪倒在地，高呼道：洪教主神通广大，战无不胜！\n" );

		me->set("quest_kill/questing",0);

		kar=random(me->query_kar());
		if(kar>30) kar=30;
		times= 4+ random(5);
		
		i = texp*1000/(myexp+1)+(kar*50/times);
		if(i>=2000)
		{
			j=random(sizeof(skill));
			k=0;
			while(1)
			{
				if(j==0)
				{
					if(me->query_skill("poison",1)>=150)
					{
			   			break;
					}
					j++;
				}
				if(j==1)
				{
					if(me->query_skill("shenlong-yaoli",1)>=200)
			   		{
			   			break;
					}
					j++;
				}
				if(j==2)
				{
					if(me->query_skill("force",1)>=200 && 
					   me->query_skill("force",1)<
					   (me->query_skill("shenlong-yaoli",1)+100))
					{
						break;
					}
					j++;
				}
				if(j==3)
				{
					if(me->query_skill("dulong-dafa",1)>=200 && 
					   me->query_skill("dulong-dafa",1)<
					   me->query_skill("force",1))
					{
						break;
					}
					if(k==0)
					{
						j=0;
						k=1;
					}
					else
					{
						j=-1;
						break;
					}
				}
			}
			if(j!=-1)
				me->improve_skill(skill[j],i*2,1);
		}
		if ((i>2500) || (i<0)) i=2500;
		qnadd = 10 + (i/2+random(i/2))/16;
		if (qnadd>me->query("max_pot") ) qnadd = me->query("max_pot");
		adds = qnadd+ random(qnadd*2);
		adds=adds*2;
		qnadd=qnadd*2;

		i =10+i/4*3/16;
		if(wizardp(me)) tell_object(me,"get pot: "+i+"\n" );

         	i = me->query("max_pot")-me->query("potential");
		if ( i< qnadd ) qnadd = i;
                if (adds > 300) adds = 280+random(40);
                if (adds <30) adds = 30;
                
                //me->add("combat_exp",adds);
                adds = me->add_exp_combat(adds,tname,"神龙招魂");
                
		qnadd = adds/5 + random(adds/10);
		me->add("potential",qnadd);

		if( me->query("potential") > me->query("max_pot"))
			me->set("potential", me->query("max_pot"));

		me->add("shen",-adds*2);

		tell_object(me,"你被奖励了"+chinese_number(adds)+"点经验，"
			+chinese_number(qnadd)+"点潜能，"+chinese_number(adds*2)+"点负神！\n");

// add 招魂 Log By River
	        log_file("job/shenlong",sprintf("%8s%-10s招魂任务(0)奖励经验%3d，潜能%2d，目前经验：%d。\n",
			me->name(1),"("+me->query("id")+")", adds ,qnadd, me->query("combat_exp")));

		if(me->query_temp("quest_kill/failin5",1)!=0)
			me->delete_temp("quest_kill/failin5");

		if(!me->query("quest_kill/quests"))
			me->set("quest_kill/quests",1);
		else
			me->add("quest_kill/quests",1);
		destruct(this_object());
		return 1;
	}
	return 0;    
}

void nofollow(object ob)
{
	if(objectp(ob)) {
		if(living(ob) && ob->query_leader())
			ob->set_leader(0);
		else if(!living(ob) && !ob->is_corpse())
			call_out("nofollow",5,ob);
	} 
}

int do_yes(string arg)
{
	object me=this_player();
	string tid,tname;
	int golds,adds,times,kar,myexp,texp,temp;
	object gold;

	if(me->query_temp("quest/huilu",1)==0)
		return 0;
	if(!objectp(obj))
	{
		destruct(this_object());
		return 1;
	}
	tname=obj->name();
	tid=obj->query("id");
	texp=obj->query("combat_exp");
	myexp=me->query("combat_exp");
	kar=me->query_kar();

	if((tname!=me->query("quest_kill/name")) || (tid!=me->query("quest_kill/id")))  return 0;

	tell_object(me,"你对"+tname+"嘿嘿一笑，道：也罢，这次就放你一马！钱呢？\n");
	tell_object(me,tname+"赶忙从怀里掏出几块银子，悄悄地塞给你。\n");

	golds=random(texp/1000)*kar/20;
	if(golds<10) golds=10;
		else if(golds>200) golds=200;

	gold=new("/clone/money/silver");
	gold->set_amount(golds);
	if(!(gold->move(me)))
		gold->move(environment(me));
	
	times=15+random(16);
	if(myexp<=0)  myexp=1;
	if(texp<=0)   texp=1;
	if(myexp>texp)   {
		temp=myexp;
		myexp=texp;
		texp=temp;
	}

	adds=100+random(120*texp*kar/(times*myexp));
	me->add("shen",-adds);
	tell_object(me,"你被奖励了"+chinese_number(adds)+"点负神！\n");
	me->delete_temp("quest/huilu");
	destruct(this_object());

	return 1;
}

int do_no(string arg)
{
	object me=this_player();
	string tid,tname;
	int i,j,k,adds,times,kar,qnadd,myexp,texp;
   	string * skill=({"poison","shenlong-yaoli","force","dulong-dafa"});

	if(me->query_temp("quest/huilu",1)==0)
		return 0;
	if(!objectp(obj))
	{
		destruct(this_object());
		return 1;
	}
	tname=obj->name();
	tid=obj->query("id");
	texp=obj->query("combat_exp");
	myexp=me->query("combat_exp");
	kar=me->query_kar();

	if((tname!=me->query("quest_kill/name")) || (tid!=me->query("quest_kill/id")))    return 0;

	tell_object(me,"你对"+tname+"冷笑一声，道：就这么点钱，打发叫化子啊？！随即又向"+tname+"口念咒语。\n");
	tell_room(environment(obj), tname+"跪倒在地，高呼道：洪教主神通广大，战无不胜！\n" );

	me->set("quest_kill/questing",0);

	kar=random(me->query_kar());
	if(kar>30) kar=30;
	times= 4+ random(5);
		
	i = texp*1000/(myexp+1)+(kar*50/times);
	if(i>=2000)
	{
		j=random(sizeof(skill));
		k=0;
		while(1)
		{
			if(j==0)
			{
				if(me->query_skill("poison",1)>=150)
				{
		   			break;
				}
				j++;
			}
			if(j==1)
			{
				if(me->query_skill("shenlong-yaoli",1)>=200)
		   		{
		   			break;
				}
				j++;
			}
			if(j==2)
			{
				if(me->query_skill("force",1)>=200 && 
				   me->query_skill("force",1)<
				   (me->query_skill("shenlong-yaoli",1)+100))
				{
					break;
				}
				j++;
			}
			if(j==3)
			{
				if(me->query_skill("dulong-dafa",1)>=200 && 
				   me->query_skill("dulong-dafa",1)<
				   me->query_skill("force",1))
				{
					break;
				}
				if(k==0)
				{
					j=0;
					k=1;
				}
				else
				{
					j=-1;
					break;
				}
			}
		}
		if(j!=-1)
			me->improve_skill(skill[j],i*2,1);
	}
	if ((i>2500) || (i<0)) i=2500;
	qnadd = 10 + (i/2+random(i/2))/16;
	if (qnadd>me->query("max_pot") ) qnadd = me->query("max_pot");
	adds = qnadd+ random(qnadd*2);
	adds=adds*2;
	qnadd=qnadd*2;

	i =10+i/4*3/16;
	if(wizardp(me)) tell_object(me,"get pot: "+i+"\n" );

      	i = me->query("max_pot") - me->query("potential");
	if ( i< qnadd ) qnadd = i;
	if (adds <30) adds = 30;
        if (adds >300) adds = 280+random(40);
        
        adds = me->add_exp_combat(adds,tname,"神龙招魂");
        //me->add("combat_exp",adds);
        //me->add("job_time/神龙招魂",1);
	qnadd = adds/5 + random(adds/10);
	
	me->add("potential",qnadd);
	if( me->query("potential") > me->query("max_pot"))
		me->set("potential", me->query("max_pot"));
	me->add("shen",-adds*2);
	tell_object(me,"你被奖励了"+chinese_number(adds)+"点经验，"
			+chinese_number(qnadd)+"点潜能，"+chinese_number(adds*2)+"点负神！\n");	

        log_file("job/shenlong",sprintf("%8s%-10s招魂任务(1)奖励经验%3d，潜能%2d，目前经验：%d。\n",
		me->name(1),"("+me->query("id")+")", adds ,qnadd, me->query("combat_exp")));

	if(me->query_temp("quest_kill/failin5",1)!=0)
		me->delete_temp("quest_kill/failin5");

	if(!me->query("quest_kill/quests"))
		me->set("quest_kill/quests",1);
	else
		me->add("quest_kill/quests",1);
	me->delete_temp("quest/huilu");
	destruct(this_object());
	return 1;
}
   
