#include <ansi.h>
inherit NPC;
int ask_fight();
void create()
{
    string name,*tmp,*pinying;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string color1=color[random(sizeof(color))];
    name=NAME_D->create_female_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title",color1+"朝廷钦犯"+NOR);
    set("gender","男性");
    set("age",40);
    set("attitute", "peaceful");
    set("str",20);
    set("int",20);
    set("con",20);
    set("dex",20);
    set("shen_type",-1);
    set("score",3000);
    set("max_qi",120);
    set("max_jing",100);
    set("neili",150);
    set("max_neili",150);
    set("jiali",3);
    set("combat_exp",50000);
    set("random_npc",1);
	set("uni_target",1);
    set_skill("force",40);
    set_skill("luoying-shenfa",30);
    set_skill("dodge",40);
    set_skill("claw",40);
    set_skill("parry",30);
    set_skill("bihai-shengong",30);
    set_skill("luoying-shenfa",40);
    set_skill("jiuyin-baiguzhao",50);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("claw","jiuyin-baiguzhao");
    map_skill("parry","jiuyin-baiguzhao");
    prepare_skill("claw","jiuyin-baiguzhao");
    add("inquiry", ([
                "逃犯" : (:ask_fight:),
        ]));
    setup();
    carry_object("/d/city/obj/cloth")->wear();
	call_out("dest",300);
}

int ask_fight()
{
        if (this_object()->query("uni_target")==this_player()) {
        	if (environment(this_object())->query("no_fight")) 
        	{
        		random_move();
        	}
        	else 
			{
				kill_ob(this_player());
				command("say 要来就来吧。");
			}
        } 
		else command("hmm");
        return 1;
}
int info_spread()
{
	object ob=this_object(),*obs,p1,p2,*benefit_people=({});
	if (!environment())
	{
		return 1;
	}
	obs = filter_array(children(USER_OB), (: userp :));
    obs = filter_array(obs, (: environment :));
    obs = filter_array(obs, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
	for (int i=0;i<sizeof(obs);i++)
	{
		if (obs[i]->query("mingpin")||obs[i]->query("ming/tj/pin"))
		{
			obs-=({obs[i]});
		}
	}
	if (!sizeof(obs))
	{
		return 1;
	}
	if (sizeof(obs))
	{
		p1=obs[random(sizeof(obs))];
		benefit_people+=({p1});
		tell_object(p1,"听说大明钦犯"+ob->name()+"正在此地的"+environment()->query("short")+"现踪，你去守着他，等大明的官差到了，好处不会少了你的。\n");
	}
	obs-=({p1});
	if (sizeof(obs))
	{
		p2=obs[random(sizeof(obs))];
		benefit_people+=({p2});
		tell_object(p2,"听说大明钦犯"+ob->name()+"正在此地的"+environment()->query("short")+"现踪，你去守着他，等大明的官差到了，好处不会少了你的。\n");
	}
	if (sizeof(benefit_people))
	{
		ob->set("benefit_people",benefit_people);
	}
	return 1;
}
int dest()
{
	if (this_object()&&environment(this_object()))
	{
		tell_room(environment(this_object()),this_object()->name()+"转身离开了这里。\n");
	}
	
	destruct(this_object());
	return 1;
}
int dest2()
{
	if (this_object()&&environment(this_object()))
	{
		tell_room(environment(this_object()),this_object()->name()+"被官差们押回了刑部大牢。\n");
	}
	
	destruct(this_object());
	return 1;
}
void die()
{
    object killer,*people,ob=this_object();
	object baoshi;
	string gem;
	int i= random(20);
    killer=ob->query("owner");
    if (killer->query_temp("mingtasks/xingbu/task")==4)
    {
        killer->set_temp("mingtasks/xingbu/task4finish",1);
		message_vision("$N被打晕后，众官差上前制伏了他。\n",ob);
		if (sizeof(ob->query("benefit_people")))
		{
			people=ob->query("benefit_people");
			for (int j=0;j<sizeof(people);j++)
			{
				if (present(people[j],environment())&&!people[j]->query_temp("xingbu_benefit"))
				{
					baoshi= new("/obj/gem/gem");
					if (i < 3) gem = "yan";
					else if (i < 6) gem = "mu";
					else if (i < 9) gem = "sui";
					else if (i < 12) gem = "jin";
					else if (i < 15) gem = "bing";	
					else if (i < 16) gem = "gu";
					else if (i < 17) gem = "yu";
					else if (i < 18) gem = "jiao";
					else gem = "jia";
					baoshi->set_level(1,9999,gem);
					baoshi->move(people[j]);
					people[j]->set_temp("xingbu_benefit",1);
					message_vision("$N乘乱捡起了一颗"+baoshi->query("name")+"。\n",people[j]);
				}
			}
		}
    }
	ob->delete("benefit_people");
	dest2();
	return ;
}

void unconcious()
{
	die();
}