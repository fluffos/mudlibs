//newmap Zine Nov 11 2010
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIY"藏宝图"NOR , ({"bao tu","treasure indicator", "map"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "张");
    set("value", 0);
    set("long","这是一张胡一刀注释过闯王宝藏的藏宝图，不过很可惜，上面标识的地点你不认识。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
    set("correct",0);
  }
  setup();
  call_out("dest",1800);

}

void init()
{
   int i,count=0;
   object* all=all_inventory(environment());
   add_action("do_chakan","chakan");
   add_action("do_dig","xunbao");
   for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="bao tu")
        {
            count=count+1;
            if (count==2)
            {
                if (all[i]!=this_object())
                {
                    destruct(all[i]);
                    count=count-1;
                }
            }
        }
    }
    
    return;
}

int do_chakan(string arg)
{
    object me=this_player();
    object ob=this_object();
    object where;
    string fullplace;
    string* info;
    
    if (!present(ob,me))//防止看地上别人的图
    {
        return 0;
    }
    if (!arg || arg!=ob->query("id"))
    {
        tell_object(me,"你要看什么？\n");
        return 1;
    }
    
    if(query("owner") != me->query("id"))
    {
    	return notify_fail("你对着地图看又了看，什么也看不出来。\n");
    }

		        
    if (ob->query_temp("mapread"))
    {
        tell_object(me,"你已经查看过了，没看清楚吗？\n");//防止刷antirobot刷新地图
        return 1;
    }
    else
    {	  
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               TASK_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
        {
          where = TASK_D->random_place();
        }
        if(!objectp(where) || base_name(where) == "/adm/daemons/taskd")
        {
	        tell_object(me,"你看了又看，还是看不清楚地图。再试试吧。\n");
	        return 1;        	
        }
        ob->set("where",base_name(where));
        ob->set("location",TASK_D->place_belong(where));
        ob->set("room",where->query("short"));
        fullplace=TASK_D->place_belong(where)+COLOR_D->uncolor(where->query("short"));
                
        write(HIW"你打开了闯王藏宝图，仔细查看……原来宝藏在\n"NOR);        
        				       	
        ANTIROBOT_D->mxpantirobot_ex(me,fullplace);        
                
        ob->set_temp("mapread",1);
        return 1;
    }
}

int do_dig()
{
    object me=this_player();
    object ob=this_object();
    object room=environment(me);
    int reward,preward,rreward,lvl,index;
    string msg;
    ob->set("currentroom",room->query("short"));
    
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if(query("owner") != me->query("id"))
    {
    	return notify_fail("你对着地图看又了看，什么也看不出来。\n");
    }
    if (ob->query("questfinish"))//拿过奖励了
    {
        tell_object(me,"这张藏宝图已经没有任何价值了！\n");
        return 1;
    }
    if (TASK_D->place_belong(environment(me))==ob->query("location"))
    {
        ob->set("correct",1);
    }
    if (ob->query("correct") && ob->query("currentroom")==ob->query("room"))
    {
            lvl=8;
	        index=me->query("yidao/times")/250;
            if (index>=3) index=3;
            reward  = (int)me->query_skill("force",1);
            reward += (int)me->query_skill("dodge",1);
            reward += (int)me->query_skill("parry",1);
            reward += pow(me->query("combat_exp")/100.0,1.0/3)*10;
//奖励封顶，到经验400m左右不随经验上调奖励 by seagate@pkuxkx
            if ( reward>6000)
            	reward=6000;
            reward = 1000*lvl + reward + random(reward);
            reward += reward/2*index;
            reward =reward/2;
            if (me->query("hyd_addi_times")==50)
            {
                reward=reward*3;
                me->set("hyd_addi_times",0);
            }
            preward = reward/2+random(reward)/2;
	        rreward = (100+random(100))*lvl+75*index*lvl;
            reward = REWARD_D->add_exp(me,reward);
            me->add("exp/yidao",reward);
            preward = REWARD_D->add_pot(me,preward);
            me->add("pot/yidao",preward);
            rreward = REWARD_D->add_rep(me,rreward);
            
            msg=me->query("name")+"在胡一刀任务中获得经验奖励"+reward+"，潜能奖励"+preward+"，声望奖励"+rreward+"。";
            CHANNEL_D->do_channel(this_object(), "sys_misc", msg);
            if(random(10) == 0)
            {
                CHANNEL_D->do_channel(this_object(), "jh", me->query("name")+"发现了闯王宝藏的线索！\n", -1);
            }
            COMBAT_D->add("task_stat/yidao/cost_time",60);//附加任务时间不好计算，很多都不是直接做
            COMBAT_D->add("task_stat/yidao/exp",reward);
            COMBAT_D->add("task_stat/yidao/pot",preward);
            COMBAT_D->add("task_stat/yidao/repute",rreward);
            COMBAT_D->add("task_stat/yidao/expratio",to_float(reward)/me->query("combat_exp"));
            tell_object(me,HIR"你找到了闯王宝藏的线索\n"NOR);
            tell_object(me,HIY"因为找到闯王宝藏的线索，\n你的经验提高了" + chinese_number(reward) + "点，你的潜能提高了" + chinese_number(preward) + "点，你的江湖声望提高了" + chinese_number(rreward) + "点！\n"NOR);
            me->add_temp("hyd_addi_finish",1);
            me->add("hyd_addi_times",1);
            if (me->query_temp("hyd_addi_finish")==2)
            {
                if (me->query_temp("hyd_addi_give")==2)
                {
                    reward= reward/3;
                    reward = REWARD_D->add_exp(me,reward);
                    me->add("exp/yidao",reward);
                    preward = preward/3;
                    preward = REWARD_D->add_pot(me,preward);
                    //附加任务时间不好计算，很多都不是直接做
                    COMBAT_D->add("task_stat/yidao/exp",reward);
                    COMBAT_D->add("task_stat/yidao/pot",preward);
                    COMBAT_D->add("task_stat/yidao/expratio",to_float(reward)/me->query("combat_exp"));
                    me->add("pot/yidao",preward);
                    me->set_temp("hyd_addi_give",0);
                    me->set_temp("hyd_addi_finish",0);
                    tell_object(me,HIY"因为连续两次帮助胡一刀找到闯王宝藏的线索，\n你被额外奖励了" + chinese_number(reward) + "点经验，" + chinese_number(preward) + "点潜能！\n"NOR);
                }
                else
                {
                    me->set_temp("hyd_addi_give",0);
                    me->set_temp("hyd_addi_finish",0);
                }
            }
            ob->set("questfinish",1);
            me->set_temp("yidaonotrobot",2);
            me->delete("huyidaoaskhelp");
            me->delete("secondmap");
            ANTIROBOT_D->same_as_fullme(me);
            destruct(this_object());
            return 1;
    }
    
    if (base_name(environment(me))!=ob->query("where"))//错误地点
    {
        tell_object(me,"你反复对照藏宝图，发现这里的地形很像藏宝图上的描述，仔细寻找起来！\n");
        me->add_busy(2+random(2));
        return 1;
    }
    else
    {
        if (random(100)>70)//正确的地点也可能给假信息。
        {
            tell_object(me,"你反复对照藏宝图，发现这里的地形很像藏宝图上的描述，仔细寻找起来！\n");
            me->add_busy(random(2));
            return 1;
        }
        else  //奖励参考胡一刀正常拿全五张地图奖励的一半
        {
            lvl=8;
	        index=me->query("yidao/times")/250;
            if (index>=3) index=3;
            reward  = (int)me->query_skill("force",1);
            reward += (int)me->query_skill("dodge",1);
            reward += (int)me->query_skill("parry",1);
            reward += pow(me->query("combat_exp")/100.0,1.0/3)*10;
            reward = 1000*lvl + reward + random(reward);
            reward += reward/2*index;
            reward =reward/2;
            if (me->query("hyd_addi_times")==50)
            {
                reward=reward*3;
                me->set("hyd_addi_times",0);
            }
            preward = reward/2+random(reward)/2;
	        rreward = (100+random(100))*lvl+75*index*lvl;
            reward = REWARD_D->add_exp(me,reward);
            me->add("exp/yidao",reward);
            preward = REWARD_D->add_pot(me,preward);
            me->add("pot/yidao",preward);
            rreward = REWARD_D->add_rep(me,rreward);

            msg=me->query("name")+"在胡一刀任务中获得经验奖励"+reward+"，潜能奖励"+preward+"，声望奖励"+rreward+"。";
            CHANNEL_D->do_channel(this_object(), "sys_misc", msg);
            if(random(10) == 0)
            {
                CHANNEL_D->do_channel(this_object(), "jh", me->query("name")+"发现了闯王宝藏的线索！\n", -1);
            }
            COMBAT_D->add("task_stat/yidao/cost_time",60);//附加任务时间不好计算，很多都不是直接做
            COMBAT_D->add("task_stat/yidao/exp",reward);
            COMBAT_D->add("task_stat/yidao/pot",preward);
            COMBAT_D->add("task_stat/yidao/repute",rreward);
            COMBAT_D->add("task_stat/yidao/expratio",to_float(reward)/me->query("combat_exp"));
            tell_object(me,HIR"你找到了闯王宝藏的线索\n"NOR);
            tell_object(me,HIY"因为找到闯王宝藏的线索，\n你的经验提高了" + chinese_number(reward) + "点，你的潜能提高了" + chinese_number(preward) + "点，你的江湖声望提高了" + chinese_number(rreward) + "点！\n"NOR);
            me->add_temp("hyd_addi_finish",1);
            me->add("hyd_addi_times",1);
            if (me->query_temp("hyd_addi_finish")==2)
            {
                if (me->query_temp("hyd_addi_give")==2)
                {
                    reward= reward/3;
                    reward = REWARD_D->add_exp(me,reward);
                    me->add("exp/yidao",reward);
                    preward = preward/3;
                    preward = REWARD_D->add_pot(me,preward);
                    //附加任务时间不好计算，很多都不是直接做
                    COMBAT_D->add("task_stat/yidao/exp",reward);
                    COMBAT_D->add("task_stat/yidao/pot",preward);
                    COMBAT_D->add("task_stat/yidao/expratio",to_float(reward)/me->query("combat_exp"));
                    me->add("pot/yidao",preward);
                    me->set_temp("hyd_addi_give",0);
                    me->set_temp("hyd_addi_finish",0);
                    tell_object(me,HIY"因为连续两次帮助胡一刀找到闯王宝藏的线索，\n你被额外奖励了" + chinese_number(reward) + "点经验，" + chinese_number(preward) + "点潜能！\n"NOR);
                }
                else
                {
                    me->set_temp("hyd_addi_give",0);
                    me->set_temp("hyd_addi_finish",0);
                }
            }
            ob->set("questfinish",1);
            me->set_temp("yidaonotrobot",2);
            me->delete("huyidaoaskhelp");
            me->delete("secondmap");
            ANTIROBOT_D->same_as_fullme(me);
            destruct(this_object());
            return 1;
        }
    }
    
}

void dest()
{
    object ob=this_object();
    if (ob)
    {
        ob->unequip();
        destruct(ob);
    }
    return;
}
