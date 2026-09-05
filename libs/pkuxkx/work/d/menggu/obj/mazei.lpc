 //Zine 新任务尝试
inherit ITEM;
#include <ansi.h>
void generate();
int fold();
int unfold(object me);
int sim_fight_standard(object me);
void create()
{
    set_name("马贼", ({ "ma zei","mazei","zei","robber" }));
	set_weight(50000);
	set("unit", "队");
	set("long", "这是一队马贼。\n");
	set("no_get", "你要怎么把整队马贼都拿起来？\n");
	set("value",1);
	set("material", "meat");
	set("operating",1);
	setup();
	generate();
	call_out("timing",3);
}

int is_mazei()
{
	return 1;
}
int self_dest()
{
	message_vision("$N队伍出来日久，却没有抢到什么东西，士气低落，各奔东西了！\n",this_object());
	if (this_object())
	{
		destruct(this_object());
	}
	return 1;
}
void generate()
{
	object station,robber;
	object ob=this_object(),*obs=({});
	int members;//马贼人数
	int level;//马贼级别
	int aggres;//马贼侵略性，比如是否群殴，单挑,ect
	members=2+random(11);
	level=1+random(18);//每40级1个lv提升
	aggres=1+random(3);//1群殴2单挑3智能型
	set("members",members);
	set("level",level);
	set("aggres",aggres);
	station=load_object("/d/menggu/zeiwo");
	for (int i=0;i<members;i++)
	{
		robber=new("/d/menggu/npc/robber"+random(9));
		robber->gene(ob);
		robber->move(station);
		obs+=({robber});
	}
	set("teamers",obs);
	return;
}

void init()
{
	add_action("do_look","look");
	add_action("do_look","l");
}

int do_look(string arg)
{
	object me=this_player(),ob=this_object();
	string *ids=ob->parse_command_id_list(),msg;
	string *lvs=({"不堪一击","勉勉强强","初出茅庐","普普通通","半生不熟","略有小成","鹤立鸡群","融会贯通","炉火纯青",
		"出类拔萃","神乎其技","非同凡响","无与伦比","所向披靡","举世无双","惊世骇俗","撼天动地","空前绝后",});
	string *lv_no=({"①","②","③","④","⑤","⑥","⑦","⑧","⑨","⑩","①①","①②","①③","①④","①⑤","①⑥","①⑦","①⑧",});
	int mylv;
	if (member_array(arg,ids)!=-1)
	{
		if (ob->query("members")>8)
		{
			msg="这是横行在这一带的一大股马贼。\n";
		}
		else if (ob->query("members")>5)
		{
			msg="这是横行在这一带的一大队马贼。\n";
		}
		else if (ob->query("members")>3)
		{
			msg="这是横行在这一带的一小股马贼。\n";
		}
		else
		{
			msg="这是横行在这一带的小队马贼。\n";
		}
		mylv=pow(me->query("combat_exp")/100.0,1.0/3)*10;
		if (ob->query("level")*40-mylv>120)
		{
			msg+="这队马贼的实力对你而言实在是"+RED+"深不可测"+NOR+"，轻易不要招惹他们。\n";
		}
		else
		{
			msg+="这队马贼的实力"+HIC+lvs[ob->query("level")-1]+NOR+lv_no[ob->query("level")-1]+"，打他们主意之前先掂量掂量。\n";
		}
		msg+="你可以对这队马贼选择出击(kill)。\n";
		tell_object(me,msg);
		return 1;
	}
	return 0;
}
int operating()
{
	return this_object()->query("operating");
}
string c_dir(string str)
{
	return str;
}
mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
  "enter":        "里",
        "out":          "外",
]);
int moving()
{
	object ob=this_object();
	mapping exits;
    string *dirs;
    int i;
	object target;
	if (ob->operating())
	{
		delete("no_show");
		if(!environment()) return 1;
		if(sizeof(environment()->query("exits")) == 0) return 1;
		if( !mapp(exits = environment()->query("exits")) ) return 1;
		dirs = keys(exits);
		i=random(sizeof(dirs));
        target = find_object(exits[dirs[i]]);
		if(objectp(target)&&!target->query("no_robber"))
		{
			tell_room(environment(),CYN+ob->query("name")+"的队伍向"+default_dirs[dirs[i]]+"开了过去。\n"+NOR);
			tell_room(target,RED+ob->query("name")+"的队伍疾驰了过来。\n"+NOR);
			ob->move(target);
		}
		return 1;
	}
	else
	{
		return 1;
	}
}
int timing()
{
	moving();
	call_out("timing",8+random(8));
	return 1;
}
int check()//在场无敌人
{
	object *robber,*enemy,target,ob=this_object();
	int flag=0,e_flag=0,i,mylv;
	robber=all_inventory(environment(ob));
	enemy=ob->query("enemy");
	for (i=0;i<sizeof(robber);i++)
	{
		if (robber[i]->query("belong")==ob&&robber[i]->query_enemy()!=({}))
		{
			flag=1;
		}
		if (member_array(robber[i],enemy)!=-1)
		{
			e_flag=1;
			target=robber[i];
		}
	}
	if (flag==0)
	{
		if (e_flag==0)
		{
			fold();
			message_vision("来犯之敌全被打败，马贼重新集结起来。\n",ob);
			return 1;	
		}
		mylv=to_int(pow(target->query("combat_exp")/100,0.333)*10);
		if (mylv>ob->query("level")*35+random(6))
		{
			fold();
			ob->add("escaped",1);
			if (ob->query("escaped")>1+random(2))
			{
				ob->set("aggres",1);
			}
			message_vision(WHT+"马贼见点子扎手，决定先行退避。\n"+NOR,ob);
			moving();
			return 1;	
		}
		else
		sim_fight_standard(target);
	}
	call_out("check",1);
	return 1;
}

int fight_intelligent(object me,object ob)
{
	int n;
	object *teamers=ob->query("teamers");
	for (int i=0;i<1+random(sizeof(teamers));i++)
	{
		n=random(sizeof(teamers));
		if (me&&environment(me)==environment(ob)&&teamers[n])
		{
			if (!teamers[n]->is_fighting(me))
			teamers[n]->kill_ob(me);
		}
	}
	if (ob->operating())
	return 1;
	else
	{
		call_out("fight_intelligent",6+random(8),me,ob);
		return 1;
	}
}

int sim_fight_intelligent(object me)
{
	object ob=this_object();
	fight_intelligent(me,ob);
}
int sim_fight_standard(object me)
{
	object ob=this_object(),*teamers;
	teamers=ob->query("teamers");
	for (int i=0;i<sizeof(teamers);i++)
	{
		if (teamers[i])
		teamers[i]->kill_ob(me);
	}
}

int fight_wheel(object me,object ob)
{
	object *teamers=ob->query("teamers");
	if (ob->operating())
	{
		return 1;
	}
	else
	{
		if (me&&environment(me)==environment(ob)&&teamers[0])
		{
			if (!teamers[0]->is_fighting(me))
			teamers[0]->kill_ob(me);
			me->kill_ob(teamers[0]);
			call_out("fight_wheel",1,me,ob);
			return 1;
		}
		return 1;
	}
}
int sim_fight_wheel(object me)
{
	object ob=this_object();
	fight_wheel(me,ob);
}
int fold()
{
	object *robber,ob=this_object();
	object station=load_object("/d/menggu/zeiwo");
	int i;
	robber=all_inventory(environment(ob));
	for (i=0;i<sizeof(robber);i++)
	{
		if (robber[i]->query("belong")==ob)
		{
			robber[i]->move(station);
		}
	}
	ob->delete("no_show");
	ob->set("operating",1);
	return 1;
}
int unfold(object me)
{
	object *robber,ob=this_object(),*teamers,*enemy=({});
	object station=load_object("/d/menggu/zeiwo");
	int i,flag=0;
	teamers=ob->query("teamers");
	if (teamers)
	{
		for (i=0;i<sizeof(teamers);i++)
		{
			if (objectp(teamers[i]))
			{
				flag=1;
				teamers[i]->move(environment(ob));
			}
		}
	}
	if (flag==0)
	{
		message_vision("$N被$n一下冲散了。\n",ob,me);
		destruct(ob);
		return 1;
	}
	ob->set("operating",0);
	if (ob->query("aggres")==2)
	sim_fight_wheel(me);
	else if (ob->query("aggres")==3)
	sim_fight_intelligent(me);
	else
	sim_fight_standard(me);
	ob->set("no_show",1);
	if (ob->query("enemy"))
	enemy=ob->query("enemy");
	enemy+=({me});
	ob->set("enemy",enemy);
	call_out("check",5);
	return 1;
}