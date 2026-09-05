#include <ansi.h>
inherit ROOM;

int record_npc(object xiao,object mrs_xiao,object guanjia,object jiading,object yahuan)
{
    object ob=this_object();
    ob->set("yanmen/xiao",xiao);
    ob->set("yanmen/mrs_xiao",mrs_xiao);
    ob->set("yanmen/guanjia",guanjia);
    ob->set("yanmen/jiading",jiading);
    ob->set("yanmen/yahuan",yahuan);
    return 1;
}
int liaoying(object me);
void init()
{
    object me=this_player();
    object env=this_object();
    object center=load_object(__DIR__"center");
    object xiao=center->query("yanmen/xiao");
    add_action("do_zheyan","zheyan");
    add_action("do_dig","dig");
    add_action("do_duanhou","duanhou");
    add_action("do_shishui","shishui");
    add_action("do_tanlu","tanlu");
    add_action("do_swim","swim");
    add_action("do_dazuo","dazuo");
    add_action("do_tuna","tuna");
    add_action("do_killall","killall");
    set("no_die",1);
    me->listen_to_die(this_object());
    if (!center->is_on()&&userp(me)&&!wizardp(me)&&environment(me)->query("road_no")!=19)
    {
        tell_object(me,"雁门关战役尚未开启，你先来到了辽军大营。\n");
        me->move(__DIR__"liaoguodaying");
        return;
    }
    
    if (env->query("road_no")==19&&(int)me->query_temp("yanmen/tanlu_suc")>=3&&center->is_on()&&xiao&&!center->query("yanmen/success"))
    {
        center->set("yanmen/success",1);
        tell_object(me,"军将听了你的消息，大吃一惊，立刻点起三军出发。\n");
        message("channel:baowei",HIR"【江湖传闻】"+me->query("name")+"送达信息到辽军大营，大队人马出，接应到萧远山。\n【江湖传闻】萧远山安全到达雁门关辽军大营，玩家任务成功！\n"NOR,users());
        message("channel:baowei",HIR"【江湖传闻】雁门关战场将在十分钟内关闭并论功行赏。\n"NOR,users());
        call_out("end",600,center);

    }
    if ((env->query("road_no")==71||env->query("road_no")==72||env->query("road_no")==73)&&(int)me->query_temp("yanmen/tanlu_suc")>=3)
    {
        liaoying(me);
    }
    if ((env->query("road_no")==71||env->query("road_no")==72||env->query("road_no")==73)&&(int)me->query_temp("yanmen/tanlu_suc")<3)
    {
        me->move(__DIR__"huanglu"+random(3));
        me->set_temp("yanmen/tanlu_suc",1);
        tell_object(me,"不知怎么的，你竟又绕回了原地，只得重新探路(tanlu)。\n");
    }
    return;
}

int do_hitall()
{
    int i;
	object* invs = all_inventory();
	for(i=0;i<sizeof(invs);i++)
	{
		if(!invs[i]->query_temp("yanmen/permit")&&living(invs[i]))
		{
			this_player()->fight_ob(invs[i]);
            invs[i]->fight_ob(this_player());
		}
	}
}

int do_killall()
{
    int i;
	object* invs = all_inventory();
	for(i=0;i<sizeof(invs);i++)
	{
		if(!invs[i]->query_temp("yanmen/permit")&&living(invs[i]))
		{
			this_player()->kill_ob(invs[i]);
		}
	}
}

int respirating(object me)
{
	int respirate_cost;
    int jingli_gain;
	if (!me) return 0;
	respirate_cost = (int)me->query_temp("respirate_cost");
	jingli_gain = 1 + (int)me->query_skill("force") / 10;
	if (respirate_cost < 1)
		return 0;

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
        if (time() > 1291593600 && time() < 1292198399)
        {
            //超级狂欢周，奖励加倍。
            jingli_gain *= 2;
        }


        me->set_temp("respirate_cost", respirate_cost);
        me->add("jingli", jingli_gain);

	if (respirate_cost > 0)
		return 1;

	me->set_temp("pending/respirate", 0);
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
	if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		
			me->set("jingli", (int)me->query("max_jingli")*2);
			tell_object(me,"在这里，心浮气躁，你的精力修为无法进步！\n");
			return 0;
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

int do_tuna(string arg)
{
    object me=this_player();
    int respirate_cost;
	object where;

	seteuid(getuid());
	where = environment(me);

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

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

int halt_exercise(object me, object who, string how)
{
	if (!me) return 1;
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

int exercising(object me)
{
	int exercise_cost;
	int neili_gain;
	mapping msg;
	string force;
  int wrpct;

	if(!me)
		return 0;
	if(!living(me))
	{
		halt_exercise(me, me, "halt");
		return 0; // Added by iszt@pkuxkx, 2007-04-18, 防止晕了继续打坐死亡
	}
	exercise_cost = (int)me->query_temp("exercise_cost");
	neili_gain = 1 + (int)me->query_skill("force") / 10;
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
		me->set("neili",(int)me->query("max_neili") * 2);
        tell_object(me,"在这里，心浮气躁，你的真气修为无法进步！\n");
	    return 0;
		}
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
int xiaoyuanshan_leave()
{
    object ob=this_object();
    object ctrl=load_object(__DIR__"yanmenguan");
    object xiao=ctrl->query("yanmen/xiao");
    object env;
    if (!xiao)
    {
        return 0;
    }
    env=environment(xiao);
    
    if (env->query("road_no")<=ob->query("road_no"))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int zheyan(object me)
{
    object ob=this_object();
    if (!me)
    {
        ob->delete("yanmen/zheyaning");
        return 1;
    }
    if (!living(me))
    {
        ob->delete("yanmen/zheyaning");
        return 1;
    }
    if (environment(me)!=ob)
    {
        ob->delete("yanmen/zheyaning");
        tell_object(me,"做事呢，这样随意就走开了，真是枉费大家对你的信任。\n");
        return 1;
    }
    if (ob->query("yanmen/zheyaning")>8+random(10))
    {
        ob->delete("yanmen/zheyaning");
        ob->set("yanmen/zheyan",1);
        me->set_temp("yanmen/event",1);
        tell_object(me,HIC+"大队过境的景象完全被遮掩住了，快去跟上大队吧。\n"+NOR);
        return 1;
    }
    message_vision("$N把路边的野草拨向另一个方向，掩饰大队过境的境况。\n",me);
    ob->add("yanmen/zheyaning",1);
    me->add_busy(3);
    call_out("zheyan",3,me);
    return 1;
}

int do_zheyan()
{
    object ob=this_object();
    object me=this_player();
    if (ob->query("road_no")!=2)
    {
        return 0;
    }
    if (ob->query("yanmen/zheyan"))
    {
        tell_object(me,"你的同伴已经把这里的痕迹遮掩的干干净净，再弄反而画蛇添足了。\n");
        return 1;
    }
    if (ob->query("yanmen/zheyaning"))
    {
        tell_object(me,"你的同伴正在遮掩这里的痕迹，多一个人反而画蛇添足了。\n");
        return 1;
    }
    if (me->query_temp("yanmen/event"))
    {
        tell_object(me,"你已经在雁门关战役中立下赫赫战功，这些许事情交给其他人去做吧。\n");
        return 1;
    }
    if (!xiaoyuanshan_leave())
    {
        tell_object(me,"萧远山夫妇还没有离开此处，你这是何意？\n");
        return 1;
    }
    ob->set("yanmen/zheyaning",1);
    zheyan(me);
    return 1;
}

int dig(object me)
{
    object ob=this_object();
    if (!me)
    {
        ob->delete("yanmen/diging");
        return 1;
    }
    if (!living(me))
    {
        ob->delete("yanmen/diging");
        return 1;
    }
    if (environment(me)!=ob)
    {
        ob->delete("yanmen/diging");
        tell_object(me,"做事呢，这样随意就走开了，真是枉费大家对你的信任。\n");
        return 1;
    }
    if (ob->query("yanmen/diging")>10+random(8))
    {
        ob->delete("yanmen/diging");
        ob->set("yanmen/dig",1);
        me->set_temp("yanmen/event",1);
        tell_object(me,HIC+"你在这里布置了一个精巧的陷阱，等着看好戏吧。\n"+NOR);
        return 1;
    }
    message_vision("$N仔细按照这里的地形，布置着一些东西。\n",me);
    ob->add("yanmen/diging",1);
    me->add_busy(3);
    call_out("dig",3,me);
    return 1;
}

int do_dig()
{
    object ob=this_object();
    object me=this_player();
    if (ob->query("road_no")!=5&&ob->query("road_no")!=6)
    {
        return 0;
    }
    if (ob->query("yanmen/dig"))
    {
        tell_object(me,"你的同伴已经在这里挖出了一处陷阱了。\n");
        return 1;
    }
    if (ob->query("yanmen/diging"))
    {
        tell_object(me,"你的同伴正在挖陷阱，你就不要添乱了。\n");
        return 1;
    }
    if (me->query_temp("yanmen/event"))
    {
        tell_object(me,"你已经在雁门关战役中立下赫赫战功，这些许事情交给其他人去做吧。\n");
        return 1;
    }
    if (!xiaoyuanshan_leave())
    {
        tell_object(me,"萧远山夫妇还没有离开此处，你这是何意？\n");
        return 1;
    }
    ob->set("yanmen/diging",1);
    dig(me);
    return 1;
}

int duanhou(object me)
{
    object ob=this_object();
    object killer;
    if (random(100)>49)
    {
        killer=new(__DIR__"npc/killer1");
    }
    else
    {
        killer=new(__DIR__"npc/killer2");
    }
    killer->do_copy(me);
    killer->move(environment(me));
    killer->do_kill(me);
    killer->set("mytarget",me);
}

int do_duanhou()
{
    object ob=this_object();
    object me=this_player();
    if (ob->query("road_no")<8||ob->query("road_no")>13)
    {
        return 0;
    }
    if (ob->query("yanmen/duanhou"))
    {
        tell_object(me,"你的同伴已经在这里清理过来敌了。\n");
        return 1;
    }
    if (me->query_temp("yanmen/event")>1)
    {
        tell_object(me,"你已经在雁门关战役中立下赫赫战功，这些许事情交给其他人去做吧。\n");
        return 1;
    }
    if (!xiaoyuanshan_leave())
    {
        tell_object(me,"萧远山夫妇还没有离开此处，你断得什么后？\n");
        return 1;
    }
    message_vision("$N道：敌人来势凶猛，我来断后，你们先走。\n",me);
    ob->set("yanmen/duanhou",1);
    me->add_temp("yanmen/event",2);
    me->add_busy(4);
    call_out("duanhou",3,me);
    return 1;
}

int xiao_swim()
{
    object ctrl=load_object(__DIR__"yanmenguan");
    object xiao=ctrl->query("yanmen/xiao");
    object mrs_xiao=ctrl->query("yanmen/mrs_xiao");
    object guanjia=ctrl->query("yanmen/guanjia");
    object jiading=ctrl->query("yanmen/jiading");
    object yahuan=ctrl->query("yanmen/yahuan");
    if (xiao&&living(xiao)&&environment(xiao)->query("road_no")!=15)
    {
        message_vision("$N还没有到这里呢，大家一起行动吧。\n",xiao);
        return 1;
    }
    if (mrs_xiao&&living(mrs_xiao)&&environment(mrs_xiao)->query("road_no")!=15)
    {
        message_vision("$N还没有到这里呢，大家一起行动吧。\n",mrs_xiao);
        return 1;
    }
    if (guanjia&&living(guanjia)&&environment(guanjia)->query("road_no")!=15)
    {
        message_vision("$N还没有到这里呢，大家一起行动吧。\n",guanjia);
        return 1;
    }
    if (jiading&&living(jiading)&&environment(jiading)->query("road_no")!=15)
    {
        message_vision("$N还没有到这里呢，大家一起行动吧。\n",jiading);
        return 1;
    }
    if (yahuan&&living(yahuan)&&environment(yahuan)->query("road_no")!=15)
    {
        message_vision("$N还没有到这里呢，大家一起行动吧。\n",xiao);
        return 1;
    }
    if (xiao&&living(xiao)&&environment(xiao)->query("road_no")==15)
    {
        xiao->swim();
    }
    if (mrs_xiao&&living(mrs_xiao)&&environment(mrs_xiao)->query("road_no")==15)
    {
        mrs_xiao->swim();
    }
    if (guanjia&&living(guanjia)&&environment(guanjia)->query("road_no")==15)
    {
        guanjia->swim();
    }
    if (jiading&&living(jiading)&&environment(jiading)->query("road_no")==15)
    {
        jiading->swim();
    }
    if (yahuan&&living(yahuan)&&environment(yahuan)->query("road_no")==15)
    {
        yahuan->swim();
    }
    return 1;
}

int shishui(object me)
{
    object ob=load_object(__DIR__"anliu");
    if (!me)
    {
        return 1;
    }
    if (!living(me))
    {
        return 1;
    }
    if (environment(me)!=ob)
    {
        tell_object(me,"做事呢，这样随意就走开了，真是枉费大家对你的信任。\n");
        return 1;
    }
    if (random(10)>6)
    {
        me->add_temp("yanmen/event",1);
        ob->set("yanmen/shishui",1);
        tell_object(me,"你在水中深潜多时，终于找到一条没有暗流的路，忙回到岸上，告之大家。\n");
        me->move(__DIR__"hetan");
        call_out("xiao_swim",2);
        return 1;
    }
    else
    {
        tell_object(me,"水下暗流太过强劲，你随波逐流，不知被冲向何处。\n");
        if (me->query("neili")<3000)
        {
            me->unconcious();
        }
        else
        {
            me->add("neili",-3000);
        }
        me->move(__DIR__"xiaolu");
        return 1;
    }
}

int do_shishui()
{
    object ob=this_object();
    object me=this_player();
    object ctrl=load_object(__DIR__"yanmenguan");
    object xiao=ctrl->query("yanmen/xiao");
    if (ob->query("road_no")!=15)
    {
        return 0;
    }
    if (ob->query("yanmen/shishui"))
    {
        tell_object(me,"你的同伴已经试水找到了一条避开暗流的前进方向，放心游(swim)过去吧。\n");
        return 1;
    }
    if (me->query_temp("yanmen/event")>1)
    {
        tell_object(me,"你已经在雁门关战役中立下赫赫战功，这些许事情交给其他人去做吧。\n");
        return 1;
    }
    if ((xiao&&environment(xiao)!=ob)||!xiao)
    {
        tell_object(me,"萧远山夫妇尚未到达，再等一等吧？\n");
        return 1;
    }
    message_vision("$N看着前面暗潮涌动的河水，一个漂亮的身姿跳了下去。\n",me);
    me->move(__DIR__"anliu");
    me->add_busy(3);
    call_out("shishui",3,me);
    return 1;
}

int huanglu(object me,string dir)
{
    object env=environment(me);
    object tl=load_object(__DIR__"tulu2");
    object nextroom;
    mapping exit=env->query("exits");
    if (!exit[dir])
    {
        return notify_fail("这个方向不通。\n");
    }
    if (find_object(exit[dir]))
    {
        nextroom=find_object(exit[dir]);
    }
    if (env->query("road_no")==18)
    {
        if (dir==tl->query("yanmen/step1"))
        {
            me->add_temp("yanmen/tanlu_suc",1);
        }
        else
        {
            me->set_temp("yanmen/tanlu_suc",0);
        }
    }
    if (env->query("road_no")==51||env->query("road_no")==52||env->query("road_no")==53)
    {
        if (dir==tl->query("yanmen/step2"))
        {
            me->add_temp("yanmen/tanlu_suc",1);
        }
        else
        {
            me->set_temp("yanmen/tanlu_suc",0);
        }
    }
    if (env->query("road_no")==61||env->query("road_no")==62||env->query("road_no")==63)
    {
        if (dir==tl->query("yanmen/step3"))
        {
            me->add_temp("yanmen/tanlu_suc",1);
        }
        else
        {
            me->set_temp("yanmen/tanlu_suc",0);
        }
    }
}

int do_tanlu(string dir)
{
    object me=this_player();
    object ob=this_object();
    object *all=all_inventory(ob);
    int i;
    if (!dir)
    {
        tell_object(me,"你要往哪个方向探路？\n");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (ob->query("road_no")==18&&all[i]&&all[i]->query("boss"))
        {
            tell_object(me,"不解决了"+all[i]->name()+"，你恐怕过不去。\n");
            return 1;
        }
    }
    
    if (ob->query("road_no")==18)
    {
        if (dir=="west"||dir=="西")
        {
            tell_object(me,"你决定往正西方向探路。\n");
            huanglu(me,"west");
            me->move(__DIR__"huanglu0");
            tell_room(ob,me->name()+"向正西方向走去。\n");
            return 1;
        }
        if (dir=="northwest"||dir=="西北")
        {
            tell_object(me,"你决定往西北方向探路。\n");
            huanglu(me,"northwest");
            me->move(__DIR__"huanglu1");
            tell_room(ob,me->name()+"向西北方向走去。\n");
            return 1;
        }
        if (dir=="southwest"||dir=="西南")
        {
            tell_object(me,"你决定往西南方向探路。\n");
            huanglu(me,"southwest");
            me->move(__DIR__"huanglu2");
            tell_room(ob,me->name()+"向西南方向走去。\n");
            return 1;
        }
    }
    if (ob->query("road_no")==51||ob->query("road_no")==52||ob->query("road_no")==53)
    {
        if (dir=="west"||dir=="西")
        {
            tell_object(me,"你决定往正西方向探路。\n");
            huanglu(me,"west");
            me->move(__DIR__"huanglu10");
            tell_room(ob,me->name()+"向正西方向走去。\n");
            return 1;
        }
        if (dir=="northwest"||dir=="西北")
        {
            tell_object(me,"你决定往西北方向探路。\n");
            huanglu(me,"northwest");
            me->move(__DIR__"huanglu11");
            tell_room(ob,me->name()+"向西北方向走去。\n");
            return 1;
        }
        if (dir=="southwest"||dir=="西南")
        {
            tell_object(me,"你决定往西南方向探路。\n");
            huanglu(me,"southwest");
            me->move(__DIR__"huanglu12");
            tell_room(ob,me->name()+"向西南方向走去。\n");
            return 1;
        }
    }
    if (ob->query("road_no")==61||ob->query("road_no")==62||ob->query("road_no")==63)
    {
        if (dir=="west"||dir=="西")
        {
            tell_object(me,"你决定往正西方向探路。\n");
            huanglu(me,"west");
            me->move(__DIR__"huanglu20");
            tell_room(ob,me->name()+"向正西方向走去。\n");
            return 1;
        }
        if (dir=="northwest"||dir=="西北")
        {
            tell_object(me,"你决定往西北方向探路。\n");
            huanglu(me,"northwest");
            me->move(__DIR__"huanglu21");
            tell_room(ob,me->name()+"向西北方向走去。\n");
            return 1;
        }
        if (dir=="southwest"||dir=="西南")
        {
            tell_object(me,"你决定往西南方向探路。\n");
            huanglu(me,"southwest");
            me->move(__DIR__"huanglu22");
            tell_room(ob,me->name()+"向西南方向走去。\n");
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int close_door()
{
    delete("exits/westup",);
	return 1;
}

int liaoying(object me)
{
    object room=load_object(__DIR__"liaoguodaying");
    if (query("exits/westup"))
    {
	    return notify_fail("快去辽军大营报信吧，萧远山夫妇可能快支持不住了。\n");
	}
    if (room)
    {
        set("exits/westup", __DIR__"liaoguodaying"); 
	    message_vision("终于被$N发现通向辽国大营的路途。\n",me);
		remove_call_out("close_door");
		call_out("close_door",20);
        return 1;
    }
    
}

int shooting(object me)
{
    int damage=(int)me->query("max_qi")/100*(4+random(3));
    if (!me)
    {
        return 0;
    }
    if (environment(me)->query("road_no")!=16)
    {
        return 0;
    }
    if (!living(me))
    {
        return 0;
    }
    tell_object(me,RED"你中箭了！\n"NOR);
    me->receive_damage("qi", damage);
    me->receive_wound("qi", damage);
    return 1;
}

int swim(object me)
{
    object ob=this_object();
    if (me->query_temp("yanmen/swim_finish")>3+random(2))
    {
        me->message_vision("$N成功地游向岸边。\n",me);
        me->move(__DIR__"hebian");
        me->delete_temp("yanmen/swim_finish");
        if (me->query("yanmen_npc"))
        {
            me->line_up();
        }
        return 1;
    }
    tell_object(me,"河岸上突然一阵乱箭射了过来。\n");
    if (random(2))
    {
        shooting(me);
    }
    me->add_temp("yanmen/swim_finish",1);
    message_vision("$N继续奋力向前游去。\n",me);
    me->add_busy(3);
    call_out("swim",3,me);
    return 1;
}

int do_swim()
{
    object ob=this_object();
    object me=this_player();
    object ctrl=load_object(__DIR__"yanmenguan");
    object xiao=ctrl->query("yanmen/xiao");
    
    if (ob->query("road_no")!=15)
    {
        return 0;
    }
    if (!ob->query("yanmen/shishui"))
    {
        tell_object(me,"这里暗流涌动，如果无人试水(shishui)找到一条安全路线，大家恐怕都要喂鱼了。\n");
        return 1;
    }
    if (!xiao->query("start_swim"))
    {
        tell_object(me,"萧远山夫妇尚未到达，等一等吧。\n");
        return 1;
    }
    message_vision("$N一个猛子扎进水里，奋力向前游去。\n",me);
    me->move(__DIR__"hezhong");
    me->add_busy(3);
    me->set_temp("yanmen/swim_start",1);
    call_out("swim",3,me);
    return 1;
}

int leave_check(object me)
{
    object *all_item=deep_inventory(me);
    object ob=this_object();
    object center=load_object("/d/jinyang/yanmenguan/center");
    string *list=center->query("list");
    int i,count=0;
    for (i=0;i<sizeof(all_item);i++)
    {
        if (all_item[i]->query("yanmen_item"))
        {
            destruct(all_item[i]);
            count=1;
        }
    }
    if (count==1)
    {
        tell_object(me,"离开"+ob->query("short")+"时，大辽的卫士顺走了你身上的一些战利品。\n");
    }
    if (!list)
    {
        return 1;
    }
    if (member_array(me->query("id"), list)!=-1 )
    {
        list-=({me->query("id")});
        center->set("list", list);
        me->delete_temp("yanmen/permit");
    }
    return 1;
}

int valid_leave(object me,string dir)
{
    object ob=this_object();
    object ctrl=load_object("/d/jinyang/yanmenguan/yanmenguan");
    object center=load_object(__DIR__"center");
    object xiao=ctrl->query("yanmen/xiao");
    object *all=all_inventory(ob);
    int i,remain;
    mixed *info;
    string arg;
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("mytarget")==me)
        {
            return notify_fail("不解决了"+all[i]->name()+"，你恐怕过不去。\n");
        }
    }
    if (!wizardp(me)&&time()-(int)me->query_temp("yanmen/last_go_step")<2)
    {
        return notify_fail("你气息不匀，稍稍歇息再走吧。\n");
    }
    if (ob->query("road_no")==17&&dir=="south")
    {
        return notify_fail("再退守河里？亏你想得出来。\n");
    }
    if (ob->query("road_no")==1&&dir=="southwest"&&(!xiao||!xiao->query("yanmen/task_init")))
    {
        return notify_fail("雁门关战役人数尚未足够或尚未开始，请耐心等待。\n");
    }
    if ((ob->query("road_no")==18||ob->query("huanglu"))&&(dir=="west"||dir=="northwest"||dir=="southwest")&&center->query("yanmen/success"))
    {
        me->move(__DIR__"liaoguodaying");
        return notify_fail("你护送萧远山有功，威风凛凛地来到的辽国大营。\n");
    }
    if ((ob->query("road_no")==18||ob->query("huanglu"))&&(dir=="west"||dir=="northwest"||dir=="southwest")&&!center->query("yanmen/success"))
    {
        return notify_fail("前面道路过于复杂，大队人马前行恐怕会迷失方向，不如派人前去探路(tanlu)。\n");
    }
    if (ob->query("road_no")==15&&dir=="northwest")
    {
        return notify_fail("前面河流暗流涌动，恐怕不太容易游(swim)过去。\n");
    }
    if (ob->query("road_no")==15&&dir=="east"&&me->query_temp("yanmen/swim_start"))
    {
        return notify_fail("前面河流暗流涌动，恐怕不太容易游(swim)过去。\n");
    }
    if (dir=="westup"&&(int)me->query_temp("yanmen/tanlu_suc")<3)
    {
        me->move(__DIR__"huanglu20");
        return notify_fail("你像个没头苍蝇一样地到处乱转。\n");
    }
    if (ob->query("road_no")==19&&dir=="out")
    {
        leave_check(me);
    }
    if (ob->query("road_no")==1&&dir=="northwest"&&center->query("is_on"))
    {
        arg="checking_start_ymg";
        info= filter_array(call_out_info(), (: $1[1]==$2 :), arg);
        info= filter_array(call_out_info(), (: $1[0]==$2 :), center);
        for (i=0;i<sizeof(info);i++)
        {
            remain= info[i][2];
        }
        return notify_fail("雁门关战役还需"+HIR+chinese_number(remain)+"秒"+NOR+"开始，届时方可离开或参战。\n");
    }
    if (ob->query("road_no")==1&&dir=="northwest"&&!me->query_temp("yanmen/want_to_leave"))
    {
        me->set_temp("yanmen/want_to_leave",1);
        return notify_fail("如果确定离开雁门关战役，请再次northwest。\n");
    }
    if (ob->query("road_no")==1&&dir=="northwest")
    {
        leave_check(me);
    }
    me->set_temp("yanmen/last_go_step",time());
    return ::valid_leave(me,dir);
}

int die_notify(object victim)
{
    object center=load_object(__DIR__"center");
    if (center->is_on())
    {
        victim->set_temp("revive_room",__DIR__"guandao");
    }
    return 0;
}