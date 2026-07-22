#include <ansi.h>

inherit ITEM;

int do_sm(string arg);

void create()
{
	set_name(YEL "神龙索命牌" NOR, ({"suomingpai" ,"pai" }));
	set_weight(20);
        
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块神龙教的索命牌，是神龙弟子用来(suoming)的，\n");
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
	add_action("do_sm","suoming");
}

int do_sm(string arg)
{
	object obj,killer;
 	object me=this_player();
	string tid,tname,cond;
	int i,j,k,texp,myexp,adds,kar,times,qnadd;
	string * skill=({"poison","shenlong-yaoli","force","dulong-dafa"});

	if(!arg || arg==" " || arg==" ") return 0;

	if((obj = present(arg, environment(me))) && (obj->is_character()))  {
		if(!obj->is_corpse()) return notify_fail("这个人还没死呢! \n");
		if(!objectp(killer=obj->query("kill_by")))  {
			cond=obj->query("kill_by");
			if(cond !="化骨绵掌毒发作")
				return notify_fail("这个人不是你杀的！\n");    
		}
		else  {
			if(killer->query("id")!=me->query("id"))
				return notify_fail("这个人不是你杀的！\n");
		}

		tname=obj->query("victim_name");
		tid=obj->query("victim_id");
		texp=obj->query("victim_exp"); 

		myexp=me->query("combat_exp");
		if((tname!=me->query("quest_kill/name"))
		 || (tid!=me->query("quest_kill/id"))
		 || (texp< myexp*2/3))
			return notify_fail("这个人不是要你杀的人! \n");

		if(present("suomingpai", obj))
			return notify_fail("你已经索过这个人的命了! \n");

		me->set("quest_kill/questing",0);
		kar=random(me->query_kar());
		if(kar>30) kar=30;
		times=(time()-me->query("quest_kill/start_time"))/60;

		if(times<3) times=3;
		
		i = texp*1000/(myexp+1)+(kar*50/times);
		if(i >= 2000) {
			j=random(sizeof(skill));
			k=0;
			while(1) {
				if(j==0) {
					if(me->query_skill("poison",1) >= 150) {
			   			break;
					}
					j++;
				}
				if(j==1) {
					if(me->query_skill("shenlong-yaoli",1) >= 200) {
			   			break;
					}
					j++;
				}
				if(j==2) {
					if(me->query_skill("force",1)>=200
					 && me->query_skill("force",1) < (me->query_skill("shenlong-yaoli",1)+100)) {
						break;
					}
					j++;
				}
				if(j==3) {
					if(me->query_skill("dulong-dafa",1)>=200 
					 && me->query_skill("dulong-dafa",1) < me->query_skill("force",1)) {
						break;
					}
					if(k==0) {
						j=0;
						k=1;
					}
					else {
						j=-1;
						break;
					}
				}
			}
			if(j!=-1)
				me->improve_skill(skill[j],i*2,1);
		}
		if ((i>2500) || (i<0)) i=2500;
		qnadd = 10 + (i/2+random(i/2))/15;
		if (qnadd > me->query("max_pot") ) qnadd = me->query("max_pot");
		adds = qnadd+ random(qnadd*2);
		adds = adds*2;
		qnadd = qnadd*2;

		i = 10+ i/4*3/15;
		if(wizardp(me)) tell_object(me,"get pot: "+i+"\n" );

         	i = me->query("max_pot")-me->query("potential");
		if ( i < qnadd ) qnadd = i;
		if (adds < 30) adds = 30;
                if (adds > 300) adds = 280+random(30);
                                
                adds = me->add_exp_combat(adds,"洪安通","神龙索命");
                //me->add("job_time/神龙索命",1);
                //me->add("combat_exp", adds);
                
		qnadd = adds/5 + random(adds/10);			
		me->add("potential", qnadd);
		if( me->query("potential") > me->query("max_pot"))
			me->set("potential", me->query("max_pot"));
		me->add("shen",-adds*2);

		tell_object(me,"你被奖励了"+chinese_number(adds)+"点经验，"
			+chinese_number(qnadd)+"点潜能，"+chinese_number(adds*2)+"点负神！\n");
// add 索命 Log By River
	        log_file("job/shenlong",sprintf("%8s%-10s索命任务(2)奖励经验%3d，潜能%2d，目前经验：%d。\n",
			me->name(1),"("+me->query("id")+")", adds ,qnadd, me->query("combat_exp")));

		if(me->query_temp("quest_kill/failin5",1) !=0)
			me->delete_temp("quest_kill/failin5");

		this_object()->move(obj);
		if(!me->query("quest_kill/quests"))
			me->set("quest_kill/quests",1);
		else
			me->add("quest_kill/quests",1);
		return 1;
     }
     return 0;    
}
