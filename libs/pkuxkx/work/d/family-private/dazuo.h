#define DZ_BONUS1 5
#define DZ_BONUS2 15
#define DZ_BONUS3 40
#define DZ_BONUS4 80
#include <skill.h>
#include <ansi.h>

int exercising(object me);
int halt_exercise(object me, object who, string how);
int respirating(object me);
int halt_respirate(object me, object who, string how);
void init()
{
    object me=this_player();
    object ob=this_object();
    add_action("do_dazuo","dazuo");
    add_action("do_dazuo","exercise");
    add_action("do_tuna","tuna");
    add_action("do_tuna","respirate");
    add_action("do_develop","develop");
    if (!wizardp(me)&&me->query("family/family_name")!=ob->query("family"))
    {
        message_vision("因为不是"+ob->query("family")+"弟子，$N被人叉了出去。\n",me);
        me->move(__DIR__"shimen");
    }
    return;
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
    ob->add("dazuo_tuna_donate/"+me->query("id")+"/amount",amount);
    for (i=0;i<sizeof(ob->query("dazuo_tuna_donate_index"));i++)
    {
        if (ob->query("dazuo_tuna_donate_index/"+i)==me->query("id"))
        {
            index=i;
            flag=1;
        }
    }
    if (flag==0)
    {
        index=sizeof(ob->query("dazuo_tuna_donate_index"));
        ob->set("dazuo_tuna_donate_index/"+index,me->query("id"));
    }
    ob->add("overall_dazuo_tuna_donate",amount);
    message( "channel:" + "baowei",HIG + "【"+family+"】" + me->query("name")+HIG+"使用了"+chinese_number(amount)+"点门忠以发展"+family+"。\n"NOR,users());
    ob->save();
    return 1;
}

int rebuild()
{
    delete("realmap");
    set("short", WHT"石室"NOR);
	set("long",  "这里是一处石头砌成的静室，墙上画着几幅图(tu)。\n");
    set("exits", ([
                "south": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作打坐(dazuo)、吐纳(tuna)状。作为本派弟子可以用门忠增长(develop)这里的功能。\n",
	]));
    return 1;
}

int get_lv()
{
    object ob=this_object();
    object sm=load_object(__DIR__"shimen");
    int grade=ob->query("overall_dazuo_tuna_donate");
    int need=sm->get_average_user();
    int result,loss;
    mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
    ob->restore();
    ob->set("family",sm->query("family"));
    if (ob->query("dazuo_decrease_date")!=date)
    {
        loss=need*(5+random(3));
        ob->add("overall_dazuo_tuna_donate",-loss);
        ob->set("dazuo_decrease_date",date);
    }
    if (ob->query("overall_dazuo_tuna_donate")<0)
    {
        ob->set("overall_dazuo_tuna_donate",0);
    }
    if (need<5)
    {
        need=5;
    }
    if (ob->query("overall_dazuo_tuna_donate")>9000*need)
    {
        ob->set("dazuo_tuna_level",4);
    }
    else if (ob->query("overall_dazuo_tuna_donate")>6000*need)
    {
        ob->set("dazuo_tuna_level",3);
    }
    else if (ob->query("overall_dazuo_tuna_donate")>3000*need)
    {
        ob->set("dazuo_tuna_level",2);
    }
    else if (ob->query("overall_dazuo_tuna_donate")>1500*need)
    {
        ob->set("dazuo_tuna_level",1);
    }
    else
    {
        ob->set("dazuo_tuna_level",0);
    }
    ob->set("dz_bonus_1",DZ_BONUS1);
    ob->set("dz_bonus_2",DZ_BONUS2);
    ob->set("dz_bonus_3",DZ_BONUS3);
    ob->set("dz_bonus_4",DZ_BONUS4);
    ob->save();
    result=ob->query("dazuo_tuna_level");
    remove_call_out("get_lv");
    call_out("get_lv",3600,ob);
    return result;
}

int do_dazuo(string arg)
{
    object me=this_player();
	int exercise_cost;
	object where;
	string force;
	mapping msg;

	seteuid(getuid());
	where = environment(me);
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");

	if( !stringp(force = me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界你至少需要十点的气来打坐！\n");

	if( ( (int)me->query("qi") < exercise_cost+10 )  ||  ( (int)me->query("qi") < exercise_cost + (int)(exercise_cost/10) ) )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
		
  if (me->query_temp("neili_speedup") )
  	return notify_fail("你正在运行内功加速全身气血恢复，无法静下心来搬运真气。\n");
  	
  if ( time()-me->query("wrong_status")<0 )
    return notify_fail("你体力真气混乱，短时间内无法静下心来搬运真气。\n");

	msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["start_my_msg"]))
		write("你坐下来运气用功，一股内息开始在体内流动。\n");
	else
		write(msg["start_my_msg"]);
    
	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);

	if (!environment(me)->query("least_msg"))
	if (!msg || undefinedp(msg["start_other_msg"]))
		tell_room(environment(me),
			me->name() + "盘膝坐下，开始修炼内力。\n", ({ me }));
	else
		tell_room(environment(me),
			msg["start_other_msg"], ({ me }));

	me->start_busy( "exercising", "halt_exercise" );

	return 1;
}

int exercising(object me)
{
	int exercise_cost;
	int neili_gain,bonus;
  int wrpct;
	mapping msg;
	string force;
    object ob=this_object();
	if(!me)
		return 0;
	if(!living(me))
	{
		halt_exercise(me, me, "halt");
		return 0; // Added by iszt@pkuxkx, 2007-04-18, 防止晕了继续打坐死亡
	}
    if (ob->query("dazuo_tuna_level")==1)
    {
        bonus=DZ_BONUS1;
    }
    else if (ob->query("dazuo_tuna_level")==2)
    {
        bonus=DZ_BONUS2;
    }
    else if (ob->query("dazuo_tuna_level")==3)
    {
        bonus=DZ_BONUS3;
    }
    else if (ob->query("dazuo_tuna_level")==4)
    {
        bonus=DZ_BONUS4;
    }
    else
    {
        bonus=0;
    }
	exercise_cost = (int)me->query_temp("exercise_cost");
    if (!me->query_condition("family_private_area"))
    {
        bonus=0;
        tell_object(me,"你现在并不在加成状态下，可能导致此情况的原因包括：门派闭关区域未升级或未兑换门派贡献度。\n");
    }
	neili_gain = (1 + (int)me->query_skill("force") / 10)*(bonus+100)/100;
	if (exercise_cost < 1)
		return 0;
//      me->add("neili", neili_gain);
//      me->set_temp("exercise_cost", exercise_cost -= neili_gain);
//      me->add("qi", -neili_gain);
//      防止打坐假死bug iszt@pkuxkx, 2007-03-11
	exercise_cost -= neili_gain;
	if(exercise_cost < 0)
		neili_gain = neili_gain + exercise_cost; //e_c小于0时置为原来的值
        me->add("qi", -neili_gain);
        if(me->query("special_skill/constitution") && me->query("age")>=18)
        neili_gain += neili_gain / 2; //constitution特技能让打坐效率增加50%
    neili_gain = neili_gain * SPEWEEK_D->query_dz_bonus()/100;
	
    if(me->query("max_neili") <1000)
	{
        neili_gain += neili_gain ; //最大内力1000以下时打坐效率增加一倍
	}	
    neili_gain *=  to_int(REWARD_D->get_global_factor("dazuo"));

	me->set_temp("exercise_cost", exercise_cost);
	me->add("neili", neili_gain);

	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);

	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);

	if (!msg || undefinedp(msg["end_my_msg"]))
		tell_object(me, "你运功完毕，深深吸了口气，站了起来。\n");
	else
		tell_object(me, msg["end_my_msg"]);
	if (!environment(me)->query("least_msg"))
	if (!msg || undefinedp(msg["end_other_msg"]))
		tell_room(environment(me),
			me->name()+"运功完毕，深深吸了口气，站了起来。\n", ({me}));
	else
		tell_room(environment(me),
			msg["end_other_msg"], ({me}));

  wrpct=to_int(ceil(F_KUNGFU->kungfu_wrongpct(me)*10000));
  if ( wrpct>0 && random(10000)<wrpct ) 
  {
    me->set("neili", 0 );
    me->set("wrong_status",time()+60);
    message_vision( HIG"突然之间$N失去了对真气的控制，看来短时间内再也无法运转真气了。\n"NOR, me );
    return 0;
  }

	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_max_neili()) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write("你的内力增加了！！\n");
			return 0;
		}
	}
}

int halt_exercise(object me, object who, string how)
{
	if (!me) return 1;
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

int do_tuna(string arg)
{
	int respirate_cost;
	object where;
    object me=this_player();
	seteuid(getuid());
	where = environment(me);
	if (me->is_busy() || me->query_temp("pending/respirating"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中吐纳，好象只有神仙才能做到。\n");

	if( !arg || !sscanf(arg, "%d", respirate_cost) || respirate_cost < 10)
		return notify_fail("指令格式 respirate|tuna <数量> ，数量指耗费精的大小，最小 10 点。\n");

	if( ( (int)me->query("jing") < respirate_cost+10 )  ||  ( (int)me->query("jing") < respirate_cost + (int)(respirate_cost/10) ) )
		return notify_fail("你现在精不足，无法修行精力！\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	message_vision("$N盘膝坐下，开始吐纳炼精。\n", me);
	me->start_busy( "respirating", "halt_respirate" );
	return 1;
}

int respirating(object me)
{
	int respirate_cost,bonus;
    int jingli_gain;
    object ob=this_object();
	if (!me) return 0;
	if (respirate_cost < 1)
		return 0;
    if (ob->query("dazuo_tuna_level")==1)
    {
        bonus=DZ_BONUS1;
    }
    else if (ob->query("dazuo_tuna_level")==2)
    {
        bonus=DZ_BONUS2;
    }
    else if (ob->query("dazuo_tuna_level")==3)
    {
        bonus=DZ_BONUS3;
    }
    else if (ob->query("dazuo_tuna_level")==4)
    {
        bonus=DZ_BONUS4;
    }
    else
    {
        bonus=0;
    }
    respirate_cost = (int)me->query_temp("respirate_cost");
    if (!me->query_condition("family_private_area"))
    {
        bonus=0;
        tell_object(me,"你现在并不在加成状态下，可能导致此情况的原因包括：门派闭关区域未升级或未兑换门派贡献度。\n");
    }
    jingli_gain = (1 + (int)me->query_skill("force") / 10)*(bonus+100)/100;
	
//	me->add("jingli", jingli_gain);
//	me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
//	me->add("jing", -jingli_gain);
//	防止吐纳假死bug iszt@pkuxkx, 2007-01-17
        respirate_cost -= jingli_gain;
        if(respirate_cost < 0)
                jingli_gain = jingli_gain + respirate_cost; //r_c小于0时置为原来的值
        me->add("jing", -jingli_gain);
        if(me->query("special_skill/constitution") && me->query("age")>=18)
        jingli_gain += jingli_gain / 2; //constitution特技能让打坐效率增加50%
    jingli_gain = jingli_gain * SPEWEEK_D->query_dz_bonus()/100;
        if(me->query("max_jingli") <1000)
        jingli_gain += jingli_gain  ; //精力1000以下打坐效率增加一倍
        


        me->set_temp("respirate_cost", respirate_cost);
        me->add("jingli", jingli_gain);

	if (respirate_cost > 0)
		return 1;

	me->set_temp("pending/respirate", 0);
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
	if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		if ((int)me->query("max_jingli") > (int)me->query_skill("force",1) * 15) {
			write("你的精力修为已经达到了瓶颈，精力最大值为基本内功技能的15倍。\n");
			me->set("jingli", (int)me->query("max_jingli"));
			return 0;
		}
		else {
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("你的精力上限增加了！！\n");
			return 0;
		}

	}
}

int halt_respirate(object me, object who, string how)
{
	if (!me) return 1;
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
	me->set_temp("pending/respirate", 0);
	return 1;
}