// 大明铁骑 Zine 3 Sep 2010

#include <ansi.h>
inherit NPC;
int ask_buzhen();
int ask_arrow();
int arrowing();
int ask_shouzhen();
int gen();
void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));	
	set("title", HIW"大明铁骑"NOR);
	set("gender", "男性");
	set("age", 20+random(30));
	set("long","他是大明骑兵部队的一员。\n");
	set("attitude", "peaceful");
	set("combat_exp", 5000000);
	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));
	set("skf_leader", "");
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("qi",20000);
	set("max_neili", 20000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set_temp("skf/huaquanpass",1);
	set_temp("skf/refugeeasked",1);
    set_temp("skf/migong",1);
    set_temp("skf/skf2",1);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("max_jingli", 20000);
	set_skill("dodge",500);
	set_skill("parry",500);
	set_skill("force",500);
	set_skill("strike",500);
	set_skill("taiyi-you",500);
	set_skill("taiyi-shengong",500);
	set_skill("taiyi-zhang",500);
	map_skill("force", "taiyi-shengong");
	map_skill("dodge", "taiyi-you");
	map_skill("strike", "taiyi-zhang");
	map_skill("parry", "taiyi-zhang");
	prepare_skill("strike", "taiyi-zhang");
    set("mingqi",1);
	set("uni_target",1);
	set("no_get", 1);
	set("inquiry", ([
            "name" : "我叫"+this_object()->query("name")+"。",
            "扬州" : "我们誓死保卫扬州城。",
            "史可法" : "史督师爱兵如子。",
			"here" : "这里就是扬州啊，你连这个都不知道？",
			"布阵" : (: ask_buzhen :),
            "buzhen" : (: ask_buzhen :),
            "收阵" : (: ask_shouzhen :),
            "shouzhen" : (: ask_shouzhen :),
			"放箭" : (: ask_arrow :),
			"fangjian" : (: ask_arrow :),
			
			
		]) );
	setup();		
	
	carry_object(__DIR__"items/cloth")->wear();
    carry_object(__DIR__"items/sword")->wield();
    call_out("start",1);
	call_out("dest2",660);

	
}
string *battlefield=({"/d/city/changjiang-2a","/d/city/changjiang-2b",
"/d/city/changjiang-2c","/d/city/changjiang-2d",});
int dest3()
{
    object pl;
	if(this_object());
    {
        if (pl=find_player(this_object()->query("skfleader")))
        {
            message_vision(HIW"$N得意洋洋，跟随主帅"+pl->query("name")+HIW+"，胜利班师回营了！\n"NOR,this_object());
        }
        destruct(this_object());
    }
}

int dest2()
{
	if(this_object());
    {
        message_vision(HIR"$N眼中一阵迷茫，如着了魔一般，疯狂地打马，转身回营了！\n"NOR,this_object());
	    destruct(this_object());
    }
}
int ask_shouzhen()
{
    object ob=this_object();
	object me=this_player();
	if (ob->query("skfleader") != me->query("id")) 
	{
		command("say 你是何人，竟敢指挥大明铁骑？" );
		return 1;
	}
    if (!ob->query("buzhen"))
    {
        tell_object(me,"根本就没有布阵，何来收阵之说？\n");
        return 1;
    }
    else
    {
        gen();
        return 1;
    }
}
int getnumber()
{
    int i,mbnumber,qbnumber;
    object *allob;
    object ob=this_object();
    if (!ob)
    {
        return 1;
    }
    if (environment(ob))
    {
        allob=all_inventory(environment(ob));
		for (i=0;i<sizeof(allob);i++)
        {
            if (allob[i]->query("mingqi"))
            {
                mbnumber=mbnumber+1;
            }
            if (allob[i]->query("id")==ob->query("skfleader"))
            {
                mbnumber=mbnumber+2;
            }
			if (allob[i]->query("qingqi"))
            {
                qbnumber=qbnumber+1;
            }
        }
        ob->set("qbnumber",qbnumber);
        ob->set("mbnumber",mbnumber);
        return 1;
    }
    else
    {
        return 1;
    }
}

int start()
{
	int i,count;
	object room=environment(this_object());
	object* all;
    object ob=this_object();
    object me;
    if (!room)
    {
		return 1;
    }
	if (ob->query("skfleader"))
    {
        me=find_player(ob->query("skfleader"));
    }
	if ((!me||base_name(environment(me))!=base_name(environment(ob)))&&!ob->query("buzhen"))
    {
        message_vision("$N眼中一阵迷茫，转身回营了。\n",ob);
        destruct(ob);
        return 1;
    }
	all=all_inventory(room);
    getnumber();
    if (this_object()->query("mbnumber")>this_object()->query("qbnumber") && this_object()->query("qbnumber"))
    {
        arrowing();
    }
	for (i=0;i<sizeof(all) ;i++ )
	{
		if(!objectp(all[i])||all[i]->query("mingqi")||all[i]->query("mingpin")||all[i]->query("ming/tj/pin")||!living(all[i])||all[i]->query("no_show")) 
		{
			count=count+1;
			continue;
		}
		if (all[i]->is_character())
        kill_ob(all[i]);
	}
	if (count>=sizeof(all)&&member_array(base_name(room),battlefield)!=-1)
	{
		if (room->query("owner")!="ming")
		{
			room->set("owner","ming");
			room->occupy_msg(room->query("owner"));
			message_vision("$N见敌人全被消灭，把大明旗帜插上。\n",ob);
		}
	}
    remove_call_out("start");
    call_out("start",10);
	return 1;
}

int copy(object me)
{
	object ob=this_object();
	int i,tempskill;
	int exp,qi;
    mapping skills;
	qi=me->query("max_qi");
	if (me->query("max_qi")>=20000)
	{
		qi=20000;
	}
    if (me->query("max_qi")<20000)
    {
        qi=me->query("max_qi");
    }
	exp = me->query("combat_exp");
	tempskill = to_int(pow(exp/100,0.333)*10);
    if (tempskill==0)
                 tempskill=10;
    skills = ob->query_skills();
    for (i=0;i<sizeof(skills);i++)
    {
        skills[keys(skills)[i]] = tempskill;
    }
	ob->set("combat_exp", exp);
	
	ob->set("max_qi",qi);
	ob->set("qi", qi);
	ob->set("max_jing", qi);
	ob->set("jing", qi);
	ob->set("max_neili", me->query("max_neili"));
	ob->set("neili", ob->query("neili"));
	ob->set("max_jingli", me->query("max_jingli"));
	ob->set("jingli", ob->query("jingli"));
    return 1;
}



void init()
{
	object ob=this_object();
    object me;
	if (!environment())
	{
		return;
	}
    if (ob->query("skfleader"))
    {
        me=find_player(ob->query("skfleader"));
    }
	if ((!me||base_name(environment(me))!=base_name(environment(ob)))&&!ob->query("buzhen"))
    {
        message_vision("$N眼中一阵迷茫，转身回营了。\n",ob);
        destruct(ob);
		return;
    }
	if (!environment()->shikefa_room())
	{
		destruct(ob);
	}
    return;
}

int gen()
{
    object ob=this_object();
	object me=find_player(ob->query("skfleader"));
    if (!me||base_name(environment(me))!=base_name(environment(ob)))
    {
        message_vision("$N眼中一阵迷茫，转身回营了。\n",ob);
        destruct(ob);
        return 1;
    }
    else
    {
        message_vision(HIC"$N穿戴好盔甲，骑上战马，列队跟上"+me->query("name")+"。\n"NOR,ob);
        command("follow " + me->query("id"));
        return 1;
    }
}
int ask_arrow()
{
    object me=this_player();
    object ob=this_object();
    if (!ob->query("buzhen"))
    {
        tell_object(me,"大明铁骑没有布阵完毕，暂时不能施射。\n");
        return 1;
    }
    if (ob->query("arrow"))
    {
        tell_object(me,"大明铁骑暂时不能施射。\n");
        return 1;
    }
    else
    {
        arrowing();
        return 1;
    }
}
int ask_buzhen()
{
	object ob=this_object();
	object me=this_player();
	string room=base_name(environment(ob)),*dir=({"e","s","w","n"});
	if (ob->query("skfleader") != me->query("id")) 
	{
		command("say 你是何人，尽管指挥大明铁骑？" );
		return 1;
	}
    if (ob->query("buzhen"))
    {
        tell_object(me,"已经布阵完成，不能再随便移动阵型了。\n");
        return 1;
    }
    if (member_array(room,battlefield)==-1)
    {
        tell_object(me,"尚未到达长江天险，切勿随意浪费军力。\n");
        return 1;
    }
    else
    {
        ob->set("buzhen",1);
        if (member_array(room,battlefield)!=-1)
        {
            me->add_temp("skf/buzhen/"+dir[member_array(room,battlefield)],1);
        }
        command("follow none");
        message_vision("你指挥"+ob->query("name")+"骑兵小队在这里布下防御阵型。\n",me);
        return 1;
    }
	
}

int dest(object tudou)
{
	if(tudou)
	destruct(tudou);
	return 1;
}

int refre()
{
    this_object()->set("arrowcount",0);
    this_object()->set("arrow",0);
	this_object()->set("no_arrow_notice",0);
    message_vision(HIW"$N休息充足，又可以开弓放箭了。\n"NOR,this_object());
	arrowing();
    return 1;
}

int arrowing()
{
	int i;
    object liveman;
    object ob=this_object();
	object room=environment(this_object());
	object* all=all_inventory(room);
    if (!this_object()->query("buzhen"))
    {
        return 0;
    }
    if (ob->query("arrowcount")>3)
    {
        call_out("refre",10);
		if (!ob->query("no_arrow_notice"))
		{
			message_vision(HIW"$N连射几轮手臂酸软，不得不停了下来。\n"NOR,ob);
			ob->set("no_arrow_notice",1);
		}
        return 1;
    }
    ob->set("arrow",1);
	for (i=0;i<sizeof(all);i++ )
	{
		if(!objectp(all[i])||all[i]->query("mingqi")||all[i]->query("mingpin")||all[i]->query("ming/tj/pin")||all[i]->query("no_show")||!living(all[i])) continue;
		else 
		{
			if (userp(all[i]))
			{
				tell_object(all[i],this_object()->query("name")+HIY"举起了硬弓，开始对你第一轮攒射。\n"NOR);
			}
			message_vision(RED"狼牙箭深深钻进$N的身体，一股血箭飙了出来。\n"NOR,all[i]);
			if (all[i]->query("qi")<1000)
			all[i]->die();
			else
			{
				all[i]->add("qi",-1000);
				liveman=all[i];
			}
		}
	}
	if (!liveman)
    return 1;
	message_vision(HIW"大明铁骑——$N平端弓弩，开始进行攒射。\n"NOR,ob);
    ob->add("arrowcount",1);
	call_out("arrowing",4);
	return 1;
}

