//部队，部队不能被kill，只能人数减少
//create by zine 29/3/2011
//tactic阵型，copy一些三国志的东西。
//query("effective_time")//出征时间 降士气、训练度，战斗中增加的训练度超过降的
#include <ansi.h>
inherit ITEM;
string *tactics=({"圆形","锋矢","雁行","长蛇","铁桶"});
int *tactic_attack_ability=({4,6,5,6,1});
int *tactic_defense_ability=({5,2,4,1,7});
int *tactic_move_ability=({2,4,3,5,1});
int fighting_escape_loss();
int valid_attribute(int n);
int sim_war(object ob,object *enemy,int state);
int do_jiezhan(object ob,object me,string arg);
int do_lead(object ob,object me,string arg);
int do_forward(object ob,object me,string arg);
int end_army(object ob);
string *slogans,*slogan_ids;
mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
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
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);

int is_army()
{
    return 1;
}

void init()
{
    add_action("do_changetactic","bianzhen");
    add_action("do_jz","jiezhan");
    add_action("do_lead_army","lead");
    add_action("do_go_forward","qianjin");
    add_action("do_go_forward","forward");
    add_action("do_duzhan","duzhan");
    add_action("do_query","look");
    add_action("do_query","l");
	add_action("do_dismiss","dismiss");
}
int do_dismiss()
{
	object me=this_player(),ob=this_object();
	if (!ob->query("leaders")||!arrayp(ob->query("leaders"))||me->query_temp("lead_army")!=ob) 
	{
		tell_object(me,"这只军队不归你统属。\n");
		return 1;
	}
	if (member_array(me,ob->query("leaders"))==-1)
	{
		tell_object(me,"这只军队不归你统属。\n");
		return 1;
	}
	if (sizeof(ob->query("leaders"))>1)
	{
		tell_object(me,"这只军队不只归你统属，你无权直接解散它。\n");
		return 1;
	}
	message_vision("$N一声令下，$n就地解散。\n",me,ob);
	destruct(ob);
}
int cost_energy(object me,object ob,int n)
{
    string side=ob->query("side");
    int point=me->query(side+"/energy");
    if (point>n)
    {
        me->add(side+"/energy",-n);
        return 1;
    }
    return 0;
}
int check_available_army(object me)
{
	object army,*leaders;
	if (!army=me->query_temp("lead_army"))
    {
        tell_object(me,"此刻你麾下并没有一支军队。\n");
        return -1;
    }
    if (!army->is_army())
    {
        tell_object(me,"此刻你麾下并没有一支军队。\n");
        return -1;
    }
    if (army->query("leaders"))
    {
        leaders=army->query("leaders");
    }
    else
    {
        leaders=({});
    }
    if (member_array(me,leaders)==-1)
    {
        tell_object(me,"做梦吧你？还想指挥这只军队？\n");
        return -1;
    }
	if (environment(army)!=environment(me))
	{
		tell_object(me,army->query("name")+"并不在你身旁。\n");
		return -1;
	}
	me->set_temp("ARMY",army);
	return 1;
}
int do_du_zhan(object ob,object me)
{
    if (ob->query_temp("be_duzhan"))
    {
        tell_object(me,"督战的命令已经下达了。\n");
        return 1;
    }
    if (!cost_energy(me,ob,10))
    {
        tell_object(me,"你现在的行动力并不够下达这个命令。\n");
        return 1;
    }
    message_vision(HIR"$N下令亲兵出列督战，擅自退后者斩！\n"NOR,me);
    ob->set_temp("be_duzhan",time()+(int)me->query("ming/ability/tongyu"));
    return 1;
}

int do_duzhan()
{
	object me=this_player(),army;
	object *leaders;
	if (check_available_army(me)==-1)
	return 1;
	army=me->query_temp("ARMY");
	army->do_du_zhan(army,me);
    return 1;
}

int do_go_forward(string arg)
{
    object me=this_player(),ob=this_object(),army;
    object *leaders;
    if (check_available_army(me)==-1)
	return 1;
	army=me->query_temp("ARMY");
    if( me!=army->query("follow")) 
	return notify_fail("想指挥"+army->query("name")+"？先lead这只队伍吧。\n");
    army->do_forward(army,me,arg);
    return 1;
}

int do_forward(object ob,object me,string arg)
{
    object env, obj;
    object* inv;
    int i;
    string dir, dest, target;
    mapping exit;
    if(!arg) 
	{
		tell_object(me,"你要带领"+ob->query("name")+"去向哪个方向？\n");
		return 1;
	}
    if( sscanf(arg, "%s",dir) != 1 )
    return command(query_verb()+" "+arg);
    if( me->is_busy() )
	{
		tell_object(me,"你现在正忙着哩。\n");
	}
    if(time()-ob->query("move_time")<ob->query("move_ability"))
	{
		tell_object(me,ob->query("name")+"大队人马，没法行军那么快。\n");
		return 1;
	}
    if ( me->is_fighting()) 
	{
		tell_object(me,"你还是先把对手解决了再说吧！\n");
		return 1;
	}
    env = environment(me);
    if(!env)
	{
		tell_object(me,"你要带领军队去那里？\n");
		return 1;
	}
    if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
	{
		tell_object(me,"这个方向没有道路。\n");
		return 1;
	}
    dest = exit[dir];
    if( !(obj = find_object(dest)) ) call_other(dest, "???");
    if( !(obj = find_object(dest)) )
	{
		tell_object(me,"此路不通。\n");
		return 1;
	}
    if( !undefinedp(default_dirs[dir]) )
    target = default_dirs[dir];
    else
    target = obj->query("short");
    inv=all_inventory(environment(ob));
    for(i=0;i<sizeof(inv);i++)
    { 
        if (inv[i]->is_army()&&ob->query("enemy")&&member_array(inv[i],ob->query("enemy"))!=-1)
        {
            if (inv[i]->query("fighters")>ob->query("fighters")*3&&random(2))
            {
                message_vision(WHT +"$N被$n重重包围，突围失败。\n" NOR, ob,inv[i]);
                return 1;
            }
            if (inv[i]->query("fighters")<ob->query("fighters")/3&&random(5))
            {
                message_vision(WHT +"$N被$n拖住了，无法正常行军离开。\n" NOR, inv[i],ob);
                return 1;
            }
            if(me->follow_path(dir)) 
            {
                message("vision", HIW "\n"+ob->query("name")+"在"+ me->name() + "的带领下，强行从战斗中撤离，向" + target + "进发。\n" NOR, env);
                message("vision", HIW +ob->query("name")+"从战斗中强行撤离，向"+ target + "进发。\n" NOR, env);  
                ob->fighting_escape_loss();
                ob->move(environment(me));
            }
        }
        else if( !living(inv[i]) || !interactive(inv[i]) ) continue;
	    else if(inv[i] != me && inv[i]->query_temp("guards/exit") == dir )
        {
            inv[i]->delete_temp("guards/exit");
            message_vision("$N大军到处，$n吓得屁滚尿流，连忙从路上让开。\n",me,inv[i]);
        }
    }
    if(me->follow_path(dir)) 
    {
        message("vision", HIW "\n"+ob->query("name")+"在"+ me->name() + "的带领下，向" + target + "进发。\n" NOR, env);
        message("vision", HIW +ob->query("name")+"向"+ target + "进发。\n" NOR, env);  
        ob->move(environment(me));
        ob->set("move_time",time()+7);
    }
	else
    {
        tell_object(me,"这个方向过不去。\n");
    }
	return 1;
    
}

int do_lead_army(string arg)
{
    object me=this_player(),ob=this_object(),army;
    object *leaders;
	if (!arg)
	{
		tell_object(me,"你要率领那支军队？\n");
		return 1;
	}
    if (check_available_army(me)==-1)
	return 1;
	army=me->query_temp("ARMY");
    army->do_lead(army,me,arg);
    return 1;
}

int do_lead(object ob,object me,string arg)
{
    if (member_array(arg,ob->parse_command_id_list())!=-1)
    {
        message_vision(HIC+"$N"+HIC+"开始率领$n"+HIC+"前进。\n"+NOR,me,ob);
        ob->set("follow",me);
        return 1;
    }
    return 0;
}

int change_tactic(object ob,int n)
{
    ob->set("tactic",tactics[n]);
    ob->set("attack_ability",tactic_attack_ability[n]);
    ob->set("defense_ability",tactic_defense_ability[n]);
    ob->set("move_ability",tactic_move_ability[n]);
    message_vision("$N变阵成功！\n",ob);
    return 1;
}

int do_changetactic(string arg)
{
    object me=this_player(),ob=this_object(),army;
    if (check_available_army(me)==-1)
	return 1;
	army=me->query_temp("ARMY");
    army->do_change_tactic(army,me,arg);
    return 1;
}

int do_change_tactic(object ob,object me,string arg)
{
    string tac="";
    int i,n,delay;
    for (i=0;i<sizeof(tactics);i++)
    {
        tac+=" "+tactics[i]+" ";
    }
    if (!arg||member_array(arg,tactics)==-1)
    {
        tell_object(me,"你只可以变阵为"+tac+"中的一种。\n");
        return 1;
    }
    if (arg==ob->query("tactic"))
    {
        tell_object(me,"此刻已经是"+arg+"阵型了。\n");
        return 1;
    }
    message_vision("$N一声令下，$n开始转变为"+arg+"阵。\n",me,ob);
    ob->set("attack_ability",1);
    ob->set("defense_ability",1);
    ob->set("move_ability",1);//变阵时最弱
    n=member_array(arg,tactics);
    delay=26-(int)ob->query("train_degree")/10-(int)ob->query("junji")/8; //变阵速度和军纪、训练度有关，军纪影响更大。
    remove_call_out("change_tactic");
    call_out("change_tactic",delay,ob,n);
    return 1;
}
int weapon_index(string my_weapons,string weapons)
{
    int result=2;
    if (my_weapons=="枪")
    {
        if (weapons=="刀")
        {
            result=1;
        }
        if (weapons=="马")
        {
            result=3;
        }
        if (weapons=="弓")
        {
            result=3;
        }
    }
    if (my_weapons=="刀")
    {
        if (weapons=="枪")
        {
            result=3;
        }
        if (weapons=="马")
        {
            result=1;
        }
        if (weapons=="弓")
        {
            result=3;
        }
    }
    if (my_weapons=="马")
    {
        if (weapons=="刀")
        {
            result=3;
        }
        if (weapons=="枪")
        {
            result=1;
        }
        if (weapons=="弓")
        {
            result=3;
        }
    }
    if (my_weapons=="弓")
    {
        if (weapons=="刀")
        {
            result=2;
        }
        if (weapons=="枪")
        {
            result=2;
        }
        if (weapons=="马")
        {
            result=2;
        }
    }
    return result;
}
int fighting_escape_loss()
{
    object ob=this_object(),*enemy=({});
    if (ob->query("enemy"))
    {
        enemy=ob->query("enemy");
    }
    if (enemy)
    {
        sim_war(ob,enemy,2);
    }
    return 1;
}

int check_shiqi(object ob)
{
    int lost=ob->query("lost_fighters"),base=ob->query("origin_fighters");
    if (ob->query("fighters")<1)
    {   
		call_out("end_army",1,ob);
        return 1;
    }
    if (lost>base/3)
    {
        ob->add("shiqi",-(1+random(5)));
        ob->set("lost_fighters",0);
        ob->set("origin_fighters",ob->query("fighters"));
        message_vision(RED"大批战士阵亡，$N士气大降！\n"NOR,ob);
        return 1;
    }
}

int sim_war_detail(int my_junji,int my_train,int my_shiqi,int my_attack,int my_defense,int my_move,int my_leaders,int junji,int train,int shiqi,int attack,int defense,int move,int leaders,int weapon_index,object ob,object enemy,int state)
{
    int my_fighters,fighters,loss,my_overall,overall,attack_degree,vs_lead;
    string msg;
    my_fighters=ob->query("fighters");
    fighters=enemy->query("fighters");
    my_attack=my_attack*to_int((sqrt(to_float(my_fighters))*5+sqrt(to_float(fighters))*2)/8);
    attack=attack*to_int((sqrt(to_float(fighters))*5+sqrt(to_float(my_fighters))*2)/8);
    my_defense=my_defense*to_int((sqrt(to_float(my_fighters))*3+sqrt(to_float(fighters))*1)/10);
    defense=attack*to_int((sqrt(to_float(fighters))*3+sqrt(to_float(my_fighters))*1)/10);
    if (environment(ob)!=environment(enemy))
    {
        message_vision("$N从战斗中撤离。\n",ob);
        return 1;
    }
    attack_degree=my_attack*3/2-defense;
    attack_degree=valid_attribute(attack_degree);
    if (!leaders)
    {
        vs_lead=5;
    }
    else
    {
        vs_lead=my_leaders/leaders;
        vs_lead=valid_attribute(vs_lead);

    }
    my_overall=(my_junji*3+my_shiqi*2)*attack_degree*7*vs_lead/shiqi/move/4;
    if (ob->query_temp("be_duzhan"))
    {
        my_overall=my_overall*2;
    }
    my_overall=my_overall/3+random(my_overall*2/3);
    attack_degree=attack-my_defense*2;
    attack_degree=valid_attribute(attack_degree);
    if (!my_leaders)
    {
        vs_lead=5;
    }
    else
    {
        vs_lead=leaders/my_leaders;
        vs_lead=valid_attribute(vs_lead);
    }
    overall=(junji*3+shiqi*2)*attack_degree/my_shiqi/my_move/15;
    overall=overall/3+random(overall*2/3);
    if (my_overall>fighters)
    my_overall=fighters;
    if (overall>my_fighters)
    overall=my_fighters;
    if (state==2)
    {
        overall=overall*2;
        my_overall=1;
    }
    my_overall=valid_attribute(my_overall);
    overall=valid_attribute(overall);
    if (ob->query("weapon")=="弓")//远程攻击无损
    {
        overall=0;
        my_overall=my_overall/2;
    }
    if (time()-enemy->query("fanji_time")>=5)
    {
        ob->add("fighters",-overall);
        ob->add("lost_fighters",overall);
        enemy->set("fanji_time",time());
        msg="被反击中，$N损失了"+chinese_number(overall)+"名战士。\n";
    }
    else
    {
        msg="\n";
    }
    enemy->add("fighters",-my_overall);
    enemy->add("lost_fighters",my_overall);
    check_shiqi(ob);
    check_shiqi(enemy);
    if (!enemy)
    {
        return 1;
    }
    if (state==2)
    {
        message_vision("$N在战斗中撤离，被$n乘胜追击，共损失了"+chinese_number(overall)+"名战士。\n",ob,enemy);
        return 1;
    }
    message_vision("$N的攻击造成了$n"+chinese_number(my_overall)+"人的伤亡！\n",ob,enemy);
    if (overall>0)
    {
        message_vision(msg,ob);
    }
    return 1;
}

int valid_attribute(int n)
{
    if (n<1)
    {
        n=1;
    }
    return n;
}
int sim_war(object ob,object *enemy,int state)
{
    int my_junji,my_train,my_shiqi,my_attack,my_defense,my_move,my_leaders=0,my_leader_num=1;
    int junji,train,shiqi,attack,defense,move,i,leaders=0,leader_num=1,weapon_index;
    string *me_leaders,enemy_leaders,my_weapons,weapons;
    object leader,enemy_leader;
    my_junji=valid_attribute(ob->query("junji"));
    my_train=valid_attribute(ob->query("train_degree"));
    my_shiqi=valid_attribute(ob->query("shiqi"));
    my_attack=valid_attribute(ob->query("attack_ability"));
    my_defense=valid_attribute(ob->query("defense_ability"));
    if (ob->query("fighters")<20)//人数不够，无阵型效果
    {
        my_attack=1;
        my_defense=1;
    }
    my_move=valid_attribute(ob->query("move_ability"));
    my_weapons=ob->query("weapon");
    if (ob->query("leaders"))
    {
        me_leaders=ob->query("leaders");
    }
    for (i=0;i<sizeof(me_leaders);i++)
    {
        if (present(me_leaders[i],environment(ob)))
            {
                my_leaders+=me_leaders[i]->query("ming/ability/tongyu");
                my_leader_num+=1;
            }
    }
    my_leaders=my_leaders/my_leader_num;
    for (i=0;i<sizeof(enemy);i++)
    {
        if (objectp(enemy[i])&&present(enemy[i],environment(ob)))
        {
            junji=valid_attribute(enemy[i]->query("junji"));
            train=valid_attribute(enemy[i]->query("train_degree"));
            shiqi=valid_attribute(enemy[i]->query("shiqi"));
            attack=valid_attribute(enemy[i]->query("attack_ability"));
            defense=valid_attribute(enemy[i]->query("defense_ability"));
            move=valid_attribute(enemy[i]->query("move_ability"));
            weapons=enemy[i]->query("weapon");
            if (enemy[i]->query("leaders"))
            {
                enemy_leaders=enemy[i]->query("leaders");
                if (enemy_leaders[0])
                {
                    leaders=enemy_leaders[0]->query("ming/ability/tongyu");//for simple
                }
                else
                {
                    leaders=20+random(20);
                }
            }
            weapon_index(my_weapons,weapons);
            sim_war_detail(my_junji,my_train,my_shiqi,my_attack,my_defense,my_move,my_leaders,junji,train,shiqi,attack,defense,move,leaders,weapon_index,ob,enemy[i],state);
        }
        else
        {
            enemy-=({enemy[i]});
            ob->set("enemy",enemy);
        }
    }
    return 1;
}

int jiezhan(object ob)
{
    object *enemy;
    if (!ob->query("enemy"))
    {
        message_vision("$N解除战斗状态。\n",ob);
        return 1;
    }
    enemy=ob->query("enemy");
    if (!sizeof(enemy))
    {
        message_vision("$N解除战斗状态。\n",ob);
        return 1;
    }
    sim_war(ob,enemy,1);
    remove_call_out("jiezhan");
    call_out("jiezhan",1+random(3),ob);
    return 1;
}

int do_jz(string arg)
{
    object me=this_player();
    object army;
    if (check_available_army(me)==-1)
	return 1;
	if (!arg)
	{
		tell_object(me,"你要和哪支敌军交战？\n");
		return 1;
	}
	army=me->query_temp("ARMY");
    army->do_jiezhan(army,me,arg);
    return 1;
}

int jiezhan_each_other(object army_a,object army_b)
{
    object *enemy=({});
	if (!objectp(army_a)||!objectp(army_b))
	return 1;
    if (army_a->query("enemy"))
    {
        enemy=army_a->query("enemy");
    }
    if (member_array(army_b,enemy)==-1)
    {
        enemy+=({army_b});
    }
    army_a->set("enemy",enemy);
    army_a->jiezhan(army_a);
    if (army_b->query("enemy"))
    {
        enemy=army_b->query("enemy");
    }
    else
    {
        enemy=({});
    }
    if (member_array(army_a,enemy)==-1)
    {
        enemy+=({army_a});
    }
    army_b->set("enemy",enemy);
    army_b->jiezhan(army_b);
    message_vision("$N和$n开始互相攻战。\n",army_a,army_b);
    return 1;
}

int do_jiezhan(object ob,object me,string arg)
{
    object *enemy=({}),*all_army,others,env;
    int i;
    env=environment(ob);
    if (!arg)
    {
        all_army=all_inventory(env);
        for (i=0;i<sizeof(all_army);i++)
        {
            if (all_army[i]->is_army()&&all_army[i]->query("side")!=ob->query("side"))
            {
                jiezhan_each_other(ob,all_army[i]);
            }
        }
        if (!sizeof(enemy))
        {
            message_vision("$N开始进入临战状态，此处并无可战之敌。\n",ob);
            return 1;
        }
        return 1;
    }
    else
    {
        if (!others=present(arg,env))
        {
            tell_object(me,"这里并没有敌军"+arg+"。\n");
            return 1;
        }
        if (!others->is_army())
        {
            tell_object(me,arg+"并不是一只军队，无法宣战。\n");
            return 1;
        }
        if (others->query("side")==ob->query("side"))
        {
            tell_object(me,others->query("name")+"是友军，你要干嘛？\n");
            return 1;
        }
        jiezhan_each_other(ob,others);
        return 1;
    }
}

int set_army()
{
    object ob=this_object();
    int n;
    if (!ob->query("tactic"))
    {
        n=random(sizeof(tactics));
        ob->set("tactic",tactics[n]);
        ob->set("attack_ability",tactic_attack_ability[n]);
        ob->set("defense_ability",tactic_defense_ability[n]);
        ob->set("move_ability",tactic_move_ability[n]);
    }
    ob->set("origin_fighters",ob->query("fighters"));
    return 1;
}

int unique_slogan(int flag,string unit)
{
    object ob=this_object();
    object *armys;
    int i;
    string *used_names=({}),*used_ids=({}),*hao=({"甲","乙","丙","丁","戊","己","庚","辛"});
	if (!flag||flag<0||flag>sizeof(slogans))
	{
		armys=filter_array(children(__DIR__"army"), (: clonep :));
		for (i=0;i<sizeof(armys);i++)
		{
			if (armys[i]->query("name"))
			{
				used_names+=({armys[i]->query("name")});
				used_ids+=({armys[i]->query("id")});
			}
		}
		used_names=slogans-used_names;
		used_ids=slogan_ids-used_ids;
		if (!sizeof(used_names))
		{
			ob->set_name(slogans[random(sizeof(slogans))],({slogan_ids[random(sizeof(slogan_ids))],"army","ying"}));
			return 1;
		}
		else
		{
			i=random(sizeof(used_names));
			if (unit=="营")
			ob->set_name(used_names[i]+hao[random(sizeof(hao))]+"营",({used_ids[i]+" ying","army","ying"}));
			else
			ob->set_name(used_names[i],({used_ids[flag],"army","ying"}));
			return 2;
		}
	}
	else
	{
		if (unit=="营")
		ob->set_name(slogans[flag-1]+hao[random(sizeof(hao))]+"营",({slogan_ids[flag-1]+" ying","army","ying"}));
		else
		ob->set_name(slogans[flag-1],({slogan_ids[flag-1],"army","ying"}));
		return 2;
	}
}

int set_leader(object leader,int flag,string unit,string weapon)//return 0(leader过多),1设定正常，2无此pl,3pl已有指挥部队,4已在leaders中。
{
    object ob=this_object();
    object *leaders=({});
    if (!leader)//无此人
    {
        return 2;
    }
    if (ob->query("leaders"))
    {
        leaders=ob->query("leaders");
    }
    if (leader->query_temp("lead_army")&&leader->query_temp("lead_army")!=ob)
    {
        return 3;
    }
    if (member_array(leader,leaders)!=-1)
    {
        return 4;
    }
    if (sizeof(leaders)>=3)//leader不能多于3
    {
        return 0;
    }
	ob->set("weapon",weapon);
    leader->set_temp("lead_army",ob);
    leaders+=({leader});
    ob->set("leaders",leaders);
    ob->set("follow",leader);
    ob->unique_slogan(flag,unit);
    return 1;
}

int present_leaders(object ob)
{
    object *leaders;
    int i;
    if (!ob->is_army())
    {
        return 0;
    }
    if (!ob->query("leaders"))
    {
        return 0;
    }
    leaders=ob->query("leaders");
    if (sizeof(leaders)<1)
    {
        return 0;
    }
    for (i=0;i<sizeof(leaders);i++)
    {
        if (present(leaders[i],environment(ob)))
        {
            return 1;
        }
    }
    return 0;
}
int end_army(object ob)
{
	object me;
	message_vision(WHT+"最后一名战士战死沙场，$N"+WHT+"化为乌有。\n"+NOR,ob);
	if (ob->query("opposite_leader"))
	me=ob->query("opposite_leader");
	if (me&&userp(me)&&me->query_temp("songtasks/"+me->query_temp("songtasks/general_war")+"/task")==3&&environment(me)==environment(ob)&&objectp(me->query_temp("ARMY"))&&
		environment(me->query_temp("ARMY"))==environment(ob))
	{
		me->set_temp("songtasks/"+me->query_temp("songtasks/general_war")+"/3/finish",1);
		message_vision("$N见已击溃"+ob->query("name")+"，于是命令副手带领"+me->query_temp("ARMY")->query("name")+"回营休整了。\n",me);
		DASONG_D->multi_record(me,1,"击溃敌军",2);
		destruct(me->query_temp("ARMY"));
	}
	destruct(ob);
	return 1;
}
int check()
{
    object ob=this_object();
    int n,fighters=(int)ob->query("fighters");
    if (ob->query("train_degree")>100)//军纪、士气、训练度最高为100
    {
        ob->set("train_degree",100);
    }
    if (ob->query("junji")>100)
    {
        ob->set("junji",100);
    }
    if (ob->query("shiqi")>100)
    {
        ob->set("shiqi",100);
    }
    if (time()>ob->query_temp("be_duzhan")&&ob->query_temp("be_duzhan"))
    {
        ob->delete_temp("be_duzhan");
        message_vision(WHT"一鼓作气，再而衰，三而竭，即使被督战，$N也已到了极限。\n"NOR,ob);
    }
    if (ob->query("liang")<=0&&time()-ob->query("liang_escape_time")>30)
    {
        ob->set("liang",0);
        n=random(fighters/20);
        n=valid_attribute(n);
        ob->add("fighters",-n);
        ob->add("shiqi",-(1+random(5)));
        ob->set("liang_escape_time",time());
        message_vision("军粮耗尽，$N开始出现逃兵，士气下降。\n",ob);
    }
    if (ob->query("xiang")<=0&&time()-ob->query("xiang_escape_time")>30)
    {
        ob->set("xiang",0);
        ob->add("shiqi",-(1+random(4)));
        ob->set("xiang_escape_time",time());
        message_vision("军饷告罄，$N士气变得低落。\n",ob);
    }
    if (ob->query("shiqi")<30&&time()-ob->query("escape_time")>60)
    {
        n=random(fighters/20);
        n=valid_attribute(n);
        if (!present_leaders(ob))
        {
            n=n*(2+random(2));
        }
        ob->add("fighters",-n);
        ob->set("escape_time",time());
        message_vision("士气低落，$N开始出现逃兵。\n",ob);
    }
    if (ob->query("junji")<30&&time()-ob->query("escape_time")>60)
    {
        n=random(fighters/20);
        n=valid_attribute(n);
        if (!present_leaders(ob))
        {
            n=n*(2+random(2));
        }
        ob->add("fighters",-n);
        ob->set("escape_time",time());
        message_vision("军纪涣散，$N开始出现逃兵。\n",ob);
    }
    if (ob->query("effective_time")>60&&ob->query("effective_time")%60==1&&ob->query("shiqi_loss")!=ob->query("effective_time"))
    {
        n=1;
        if (!present_leaders(ob))
        {
            n=n*(2+random(2));
        }
        ob->add("shiqi",-n);
        ob->set("shiqi_loss",ob->query("effective_time"));
        message_vision("出征在外日久，$N的士气下降了"+chinese_number(n)+"点。\n",ob);
    }
    if (ob->query("effective_time")>60&&ob->query("effective_time")%95==1&&ob->query("train_loss")!=ob->query("effective_time"))
    {
        n=1;
        if (!present_leaders(ob))
        {
            n=n*(2+random(2));
        }
        ob->add("train_degree",-n);
        ob->set("train_loss",ob->query("effective_time"));
        message_vision("出征在外日久，$N的训练度下降了"+chinese_number(n)+"点。\n",ob);
    }
    if (ob->query("effective_time")>60&&ob->query("effective_time")%60==1&&ob->query("liang_loss")!=ob->query("effective_time"))
    {
        n=fighters*3;
        if (ob->query_temp("be_duzhan"))
        {
            n=n*2;
        }
        ob->add("liang",-n);
        ob->set("liang_loss",ob->query("effective_time"));
    }
    if (ob->query("effective_time")>60&&ob->query("effective_time")%60==1&&ob->query("xiang_loss")!=ob->query("effective_time"))
    {
        n=fighters*3;
        if (ob->query_temp("be_duzhan"))
        {
            n=n*2;
        }
        ob->add("xiang",-n);
        ob->set("xiang_loss",ob->query("effective_time"));
    }
    if (fighters<1)
    {
		call_out("end_army",1,ob);
		return 1;
    }
    ob->add("effective_time",random(2));//出征时间
    remove_call_out("check");
    call_out("check",1);
    return 1;
}

string level_detail(int number)
{
    if (number>90)
    {
        return "百战之师";
    }
    else if (number>70)
    {
        return "精锐之师";
    }
    else if (number>50)
    {
        return "狼虎之师";
    }
    else if (number>30)
    {
        return "乌合之众";
    }
    else
    {
        return "残兵败将";
    }
}

int detail_army(object army,object me)
{
    int fighters=(int)army->query("fighters");
    int shiqi=(int)army->query("shiqi");
    int junji=(int)army->query("junji");
    int liang=(int)army->query("liang");
    int xiang=(int)army->query("xiang");
    int train=(int)army->query("train_degree");
    string tactic=army->query("tactic");
    string weapon=army->query("weapon");
    string msg;
    string col="|";
    msg="这支"+army->query("name")+"的详细情况如下：\n";
    msg+=sprintf("%-8s%-20s%s","【士兵】",chinese_number(fighters)+"人",col);
    msg+=sprintf("%-8s%-20s%s","【训练】",level_detail(train),"\n");
    msg+=sprintf("%-8s%-20s%s","【装备】",weapon,col);
    msg+=sprintf("%-8s%-20s%s","【阵型】",tactic,"\n");
    msg+=sprintf("%-8s%-20s%s","【军粮】",chinese_number(liang)+"份",col);
    msg+=sprintf("%-8s%-20s%s","【军饷】",chinese_number(xiang)+"钱","\n");
    msg+=sprintf("%-8s%-20s%s","【军纪】",level_detail(junji),col);
    msg+=sprintf("%-8s%-20s%s","【士气】",level_detail(shiqi),"\n");
    tell_object(me,msg);
    return 1;
}

int general_army(object army,object me)
{
    string fighters=chinese_number(army->query("fighters"));
    int shiqi=(int)army->query("shiqi");
    string tactic=army->query("tactic");
    string weapon=army->query("weapon");
    string msg;
    fighters=fighters[0..3];
    msg="这是一支使用"+weapon+"做主要武器的"+army->query("name")+"，大约"+fighters+"余人，是一支"+level_detail(shiqi)+"。\n";
	if (army->query("opposite_leader")==me)
	msg+=HIW+"这似乎就是你正在寻机要消灭的那支"+army->query("name")+HIW+"。\n"+NOR;
	tell_object(me,msg);
    return 1;
}


int do_query_army(object army,object me)
{
    object *leaders=({});
    if (army->query("leaders"))
    {
        leaders=army->query("leaders");
    }
    if (member_array(me,leaders)!=-1)
    {
        detail_army(army,me);
    }
    else
    {
        general_army(army,me);
    }
    return 1;
}

int do_query(string arg)
{
    object army,me=this_player();
    object env=environment(this_object());
    if (!arg)
    {
        return 0;
    }
    if (!army=present(arg,env))
    {
        return 0;
    }
    if (!army->is_army())
    {
        return 0;
    }
    army->do_query_army(army,me);
    return 1;
}