#define L_BONUS1 10
#define L_BONUS2 30
#define L_BONUS3 60
#define L_BONUS4 100

#include <ansi.h>
#include <weapon.h>;

string *all_valid_skills=({"claw","finger","strike","cuff","unarmed","hand","leg","sword","blade","staff","whip","axe","spear","hammer","halberd","dagger","throwing","dodge"});
void init()
{
    object me=this_player();
    object ob=this_object();
    add_action("do_lian","lian");
    add_action("do_lian","practice");
    add_action("do_develop","develop");
    if (!wizardp(me)&&me->query("family/family_name")!=ob->query("family"))
    {
        message_vision("因为不是"+ob->query("family")+"弟子，$N被人叉了出去。\n",me);
        me->move(__DIR__"shimen");
    }
    return;
}

int rebuild()
{
    delete("realmap");
    set("short", WHT"石室"NOR);
	set("long",  "这里是一处石头砌成的静室，墙上画着几幅图(tu)。\n");
    set("exits", ([
                "north": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作练功(lian)状。作为本派弟子可以用门忠增长(develop)这里的功能。\n",
	]));
    return 1;
}

int do_develop(string arg)
{
    object ob=this_object();
    string family=ob->query("family");
    object me=this_player();
    int i,index,amount,flag=0;
    if( !arg || !sscanf(arg, "%d", amount))
    {
        tell_object(me,"你要贡献多少门忠给"+family+"用以升级"+ob->query("short")+"？\n");
        return 1;
    }
    if (me->query("family/family_name")!=family)
    {
        tell_object(me,"你不是"+family+"弟子，还是请回吧。\n");
        return 1;
    }
    if (amount<=0)
    {
        tell_object(me,"你在实验什么bug呢？别异想天开了！\n");
        return 1;
    }
    if (amount>(int)me->query("score"))
    {
        tell_object(me,family+"虽然很期望门下弟子为本门多做贡献，可也不希望门下弟子做出超出自己能力范围的事情，你的门忠只有"+chinese_number(me->query("score"))+"点，因此你只能贡献出"+chinese_number(me->query("score"))+"点！\n");
        return 1;
    }
    ob->restore();
    me->add("score",-amount);
    me->add("family_donate_degree",amount);
    tell_object(me,"你使用了"+chinese_number(amount)+"点，以发展"+family+"的闭关之所在。\n");
    ob->add("practice_donate/"+me->query("id")+"/amount",amount);
    for (i=0;i<sizeof(ob->query("practice_donate_index"));i++)
    {
        if (ob->query("practice_donate_index/"+i)==me->query("id"))
        {
            index=i;
            flag=1;
        }
    }
    if (flag==0)
    {
        index=sizeof(ob->query("practice_donate_index"));
        ob->set("practice_donate_index/"+index,me->query("id"));
    }
    ob->add("overall_practice_donate",amount);
    message( "channel:" + "baowei",HIG + "【"+family+"】" + me->query("name")+HIG+"使用了"+chinese_number(amount)+"点门忠以发展"+family+"。\n"NOR,users());
    ob->save();
    return 1;
}

int get_lv()
{
    object ob=this_object();
    object sm=load_object(__DIR__"shimen");
    int grade=ob->query("overall_practice_donate");
    int need=sm->get_average_user();
    int result,loss;
    mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
    ob->restore();
    ob->set("family",sm->query("family"));
    if (ob->query("lian_decrease_date")!=date)
    {
        loss=need*(5+random(3));
        ob->add("overall_practice_donate",-loss);
        ob->set("lian_decrease_date",date);
    }
    if (ob->query("overall_practice_donate")<0)
    {
        ob->set("overall_practice_donate",0);
    }
    if (need<5)
    {
        need=5;
    }
    if (ob->query("overall_practice_donate")>9000*need)
    {
        ob->set("practice_level",4);
    }
    else if (ob->query("overall_practice_donate")>6000*need)
    {
        ob->set("practice_level",3);
    }
    else if (ob->query("overall_practice_donate")>3000*need)
    {
        ob->set("practice_level",2);
    }
    else if (ob->query("overall_practice_donate")>1500*need)
    {
        ob->set("practice_level",1);
    }
    else
    {
        ob->set("practice_level",0);
    }
    ob->set("l_bonus_1",L_BONUS1);
    ob->set("l_bonus_2",L_BONUS2);
    ob->set("l_bonus_3",L_BONUS3);
    ob->set("l_bonus_4",L_BONUS4);
    ob->save();
    result=ob->query("practice_level");
    remove_call_out("get_lv");
    call_out("get_lv",3600,ob);
    return result;
}

int do_lian(string arg)
{
    object me=this_player();
    object ob=this_object();
	object where = environment(me);
	object weapon,weapon2;
	string skillname, sname;
	int skill, skill_basic,times,i,realtimes,bonus;
	string *kongshou_skill = ({"claw","finger","strike","cuff","unarmed","hand","leg","array"});

	seteuid(getuid());
	weapon = me->query_temp("weapon");
	weapon2 = me->query_temp("secondary_weapon");

	if(me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if(me->is_fighting() ) return notify_fail("临阵磨枪？来不及啦。\n");
	if(me->query("lingjiu/last_xiulian_time"))
		return notify_fail("你现在正在恢复武功，没有精力研究武功。\n");

	if(!arg || (sscanf(arg, "%s %d", arg, times)< 2 ))
		return notify_fail("指令格式：practice|lian <技能> <次数>\n");
	if(times <1 || times>50) return notify_fail("练习次数应该在 1-50 次！\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");
/*
//这个设定除了让full更有难度之外无任何实际意义
	if (arg == "parry" && me->query_skill(skillname, 1) > me->query_skill(arg, 1) / 5 * 4
		&& skillname != "flatter" )
		return notify_fail("你的基本招架已经对练习"+to_chinese(skillname)+"无所助益了。\n");
*/

	if (member_array(arg, kongshou_skill) != -1) 
	{
		if ((weapon || weapon2)) 
			return notify_fail("你必须空手才能练习"+to_chinese(skillname)+"。\n");
	}
	else if ( arg == "force" )
		return notify_fail("特殊内功无法练习，你可以通过(learn)或者(xiulian)来提高。\n");
        else if ( arg == "iron-cloth" )
                return notify_fail("特殊硬功无法练习，你可以通过(learn)来提高。\n");
	//暂时不限制dodge 和parry
        else if ( arg != "dodge" && arg != "parry" && arg != "throwing")
	{
		if (!weapon || ((string)weapon->query("skill_type") != arg)) 
			if (!weapon2 || ((string)weapon2->query("skill_type") != arg)) 
				return notify_fail("你要装备 "+arg+" 类武器才能练习"+to_chinese(skillname)+"。\n");
	}
	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

        if( skill_basic == skill )
                return notify_fail("你需要提高基本功，不然练得再多也没有用。\n");
        if( skill_basic <= skill )
		return notify_fail(sprintf("你的%s的级别还没有%s的级别高，不能通过练习来提高了。\n",
			to_chinese(arg), to_chinese(skillname)));
		//判断是否是自创武功
	if( !find_object(SKILL_D(skillname)) && file_size(SKILL_D(skillname)+".lpc") < 0)
		return notify_fail("自创武功必须到闭关室用selfpractice和selfthinking练习。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
    if (ob->query("practice_level")==1)
    {
        bonus=L_BONUS1;
    }
    else if (ob->query("practice_level")==2)
    {
        bonus=L_BONUS2;
    }
    else if (ob->query("practice_level")==3)
    {
        bonus=L_BONUS3;
    }
    else if (ob->query("practice_level")==4)
    {
        bonus=L_BONUS4;
    }
    else
    {
        bonus=0;
    }
    if (!me->query_condition("family_private_area"))
    {
        bonus=0;
        tell_object(me,"你现在并不在加成状态下，可能导致此情况的原因包括：门派闭关区域未升级或未兑换门派贡献度。\n");
    }
	realtimes=0;
	for(i=0;i<times;i++)
	{
		if( SKILL_D(skillname)->practice_skill(me) )
		{
			me->improve_skill(skillname, (skill_basic/5 +1)*(bonus+100)/100, skill_basic > skill? 0: 1);
			realtimes++;
		}
		else break;
	}
	if (realtimes)
	{
		if (!environment(me)->query("least_msg"))
		if (!random(3)) tell_room(environment(me),
			me->name() +
			"正在专心练习" +
			to_chinese(skillname) + "。\n", ({ me }));
		write ("你" + ((realtimes == 1)?"试着":"反复") + "练习" + to_chinese(skillname));
		if (stringp(sname = SKILL_D(skillname)->query_skill_name(random(me->query_skill(skillname,1)))))
			write ("中「" + sname + "」这一招");
		write( "，获得了" + ((realtimes == 1)?"少许":"不少") + "进步！\n");
        if (bonus)
        {
            write(HIW"你在这里获得了额外门派修炼的加成。\n"NOR);
        }
	}
	else
	{
		if (SKILL_D(skillname)->practice_skill(me))
		{
			write( HIR "你太累了，没有办法练习"+ to_chinese(skillname) +"。\n" NOR);
		}
		else return 0;
	}
	return 1;  
}                          
