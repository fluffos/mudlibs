//官印
//create by zine 29/3/2011
#include <ansi.h>
#include <title.h>
inherit ITEM;
inherit F_MORE;
#define VER 11 //版本号，用来确定所有人的官印都是最新的
int query_autoload() { return 1; }
int check_in();
int dest()
{
    if (this_object())
    destruct(this_object());
}
int ver()
{
	return query("version");
}

void create()
{	
	set_name(WHT"官印"NOR, ({ "guan yin","yin"}));
	set_weight(50);
	set("long", "这是一具官印。\n");
	set("material", "jade");
	set("unit", "具");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("guanyin",1);
    set("no_store",1);
	set("version",VER);
	setup();
	call_out("check_in",1);
}

void init()
{
    object belong=environment(this_object());
	set("long",HIW+"这是一具白玉刻成的大明"+chinese_number(belong->query("mingpin"))+"品官员的官印，侧面刻着"+belong->query("name")+HIW+"。\n"+NOR);
	add_action("do_reward","reward");
	add_action("do_yes","yes");
	add_action("do_no","no");
	add_action("do_recover","recover");
	add_action("do_refuse","refuse");
	add_action("do_accept","accept");
    add_action("do_yayun","yayun");
    add_action("do_zhao","zhao");
    add_action("do_qing","qing");
	add_action("do_qing","yaoqing");
	add_action("do_tongzhi","tongzhi");
	add_action("do_ming","ming");
    if (belong&&!userp(belong))
    {
        call_out("dest",1);
        return;
    }
    if (belong->query("gender")!="男性")
    {
        call_out("dest",1);
        return;
    }
    if (!belong->query("mingpin"))
    {
        call_out("dest",1);
        return;
    }
}
int do_ming(string arg)
{
	int count=0;
	string cmd="",*commands=({});
	if (!arg)
	return notify_fail("大明命令格式ming <命令>，可用ming -cmds查询现有所有大明命令。\n");
	if (arg=="-cmds")
	{
		commands=DAMING_D->all_command();
		write("大明可用指令：\n");
		for (int k=0;k<sizeof(commands);k++)
		{
			write(commands[k]+" ");
			count+=1;
			if (count%6==0)
			{
				write("\n");
			}
		}
		write("\n具体命令帮助，可用ming <命令> -h获得。\n");
		return 1;
	}
	DAMING_D->find_command(arg);
	if (DAMING_D->warning())
	{
		write("大明命令参数里包含命令保留关键字，可能造成大明命令失败！\n");
	}
	cmd=DAMING_D->get_cmd();
	arg=DAMING_D->get_parameter();
	if (cmd=="")
	{
		return notify_fail("并无此条大明命令，可用ming -cmds查询现有所有大明命令。\n");
	}
	if( stringp(cmd) 
		&& call_other(cmd, "main", this_player(), arg))
	return 1;
}
int valid_greet(object ob,object me)
{
    int i,flag=1;
    if (ob==me)
	return 0;
    if( !ob->visible(me) ) 
	return 0;
    if (!me->visible(ob))
	return 0;
    if (!sizeof(ob->query_temp("daming/greet")))
	return 1;
    for (i=0;i<sizeof(ob->query_temp("daming/greet"));i++)
    {
        if (ob->query_temp("daming/greet/"+i+"/target")==me)
        {
            if (time()-ob->query_temp("daming/greet/"+i+"/time")>300)
			return i+2;
            flag=0;
        }
    }
    return flag;
}

int flatter(object me)
{
    int i,j,k;
    object env,*ob;
    string ob_name,my_name;
    env=environment(me);
    ob=all_inventory(env);
    ob = filter_array(ob, (: userp :));
    ob = filter_array(ob, (: living :));
    ob = filter_array(ob, (: $1->query("mingpin") :) );
    for (i=0;i<sizeof(ob);i++)
    {
        if (valid_greet(ob[i],me)==1)
        {
            ob_name=COLOR_D->uncolor(ob[i]->query("name"));
            my_name=COLOR_D->uncolor(me->query("name"));
            j=sizeof(ob[i]->query_temp("daming/greet"));
            if (ob[i]->query("mingpin")-me->query("mingpin")>3)
            {
                ob[i]->set_temp("daming/greet/"+j+"/target",me);
                ob[i]->set_temp("daming/greet/"+j+"/time",time());
                message("vision", CYN+ob_name+"见到"+my_name+"，立刻拜倒下去：“下官"+ob_name+"拜见大人！”\n"+NOR,
                        env, ({ob[i]}) );
                tell_object(ob[i],"你见到"+my_name+"，立刻参拜下去。\n");
            }
            else if (ob[i]->query("mingpin")>me->query("mingpin"))
            {
                ob[i]->set_temp("daming/greet/"+j+"/target",me);
                ob[i]->set_temp("daming/greet/"+j+"/time",time());
                message("vision", HIC+ob_name+"见到"+my_name+"，长揖下去：“下官"+ob_name+"见过大人！”\n"+NOR,
                        env, ({ob[i]}) );
                tell_object(ob[i],"你见到"+my_name+"，立刻上前行礼相见。\n");
            }
            else if (ob[i]->query("mingpin")==me->query("mingpin"))
            {
                ob[i]->set_temp("daming/greet/"+j+"/target",me);
                ob[i]->set_temp("daming/greet/"+j+"/time",time());
                message("vision", HIW+ob_name+"见到"+my_name+"，互相一拱手：“多日不见了！”\n"+NOR,
                        env, ({ob[i]}) );
                tell_object(ob[i],"你见到同僚"+my_name+"，上前去打了个招呼。\n");
            }
            else
            {
                return 1;
                //tell_object(me,ob[i]->name()+"的官职比你高，按理是应该你去参见人家的。\n");
            }
        }
        if (valid_greet(ob[i],me)>=2)
        {
            k=valid_greet(ob[i],me)-2;
            ob_name=COLOR_D->uncolor(ob[i]->query("name"));
            my_name=COLOR_D->uncolor(me->query("name"));
            if (ob[i]->query("mingpin")-me->query("mingpin")>3)
            {
                ob[i]->set_temp("daming/greet/"+k+"/time",time());
                message("vision", CYN+ob_name+"见到"+my_name+"，立刻拜倒下去：“下官"+ob_name+"拜见大人！”\n"+NOR,
                        env, ({ob[i]}) );
                tell_object(ob[i],"你见到"+my_name+"，立刻参拜下去。\n");
            }
            else if (ob[i]->query("mingpin")>me->query("mingpin"))
            {
                ob[i]->set_temp("daming/greet/"+k+"/time",time());
                message("vision", HIC+ob_name+"见到"+my_name+"，长揖下去：“下官"+ob_name+"见过大人！”\n"+NOR,
                        env, ({ob[i]}) );
                tell_object(ob[i],"你见到"+my_name+"，立刻上前行礼相见。\n");
            }
            else if (ob[i]->query("mingpin")==me->query("mingpin"))
            {
                ob[i]->set_temp("daming/greet/"+k+"/time",time());
                message("vision", HIW+ob_name+"见到"+my_name+"，互相一拱手：“多日不见了！”\n"+NOR,
                        env, ({ob[i]}) );
                tell_object(ob[i],"你见到同僚"+my_name+"，上前去打了个招呼。\n");
            }
            else
            {
                return 1;
                //tell_object(me,ob[i]->name()+"的官职比你高，按理是应该你去参见人家的。\n");
            }
        }
    }
    return 1;
}

int load_check_env(object me)
{
	if (!me)
	return 1;
	remove_call_out("load_check_env");
	call_out("load_check_env",4,me);
	if (me->query("ming/tj")&&me->query("gender")=="男性")
	me->delete("ming/tj");
	if (userp(me)&&living(me)&&me->query("mingpin")&&environment(me)!=me->query_temp("ming_flatter_place"))
    {
		flatter(me);
		me->set_temp("ming_flatter_place",environment(me));
        return 1;
    }
	if (stringp(me->query_temp("apply/short")))
	{
		if (time()-me->query_temp("ming_multi_title")>3600&&strsrch(me->query_temp("apply/short"),"大明")!=-1)
		{
			me->delete_temp("apply/short");
			me->delete_temp("ming_multi_title");
		}
	}
	return 1;
}
int check_in()
{
	object check_station,me=environment(this_object());
	if (!me)
	return 1;
	if (userp(me)&&check_station=load_object("/d/yingtianfu/neicheng/datong2"))
	check_station->check_in(me);
	load_check_env(me);
	return 1;
}
int do_no()
{
	object me=this_player();
	if (me->query_temp("ming/wu_to_wen"))
	{
		tell_object(me,"你拒绝了刀枪入库转为文臣的建议。\n");
		me->delete_temp("ming/wu_to_wen");
		return 1;
	}
	else if (me->query_temp("ming/wen_to_wu"))
	{
		tell_object(me,"你拒绝了投笔从戎转为武将的建议。\n");
		me->delete_temp("ming/wen_to_wu");
		return 1;
	}
	else
	{
		return 0;
	}
}
int change_pro(object me)
{
	mixed tm=localtime(time());
	string month=sprintf("%d-%d",tm[5],tm[4]+1);
	object qintian=load_object("/d/yingtianfu/neicheng/qintian");
	me->set("ming/change_pro/month",month);
	me->set_temp("ming/hor_promote","change_pro");
	qintian->position_me(me);
	return 1;
}
int do_yes()
{
	object me=this_player();
	if (me->query_temp("ming/wu_to_wen"))
	{
		if (time()-me->query_temp("ming/wu_to_wen")>60)
		{
			me->delete_temp("ming/wu_to_wen");
			return 0;
		}
		else
		{
			message_vision("$N决定接受建议，转为文臣。\n",me);
			me->delete_temp("ming/wu_to_wen");
			me->set("ming/pro","文");
			change_pro(me);
			message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")决定刀枪入库，就此转为"+me->query("ming/title")+"！\n"NOR,users());
			return 1;
		}
	}
	else if (me->query_temp("ming/wen_to_wu"))
	{
		if (time()-me->query_temp("ming/wen_to_wu")>60)
		{
			me->delete_temp("ming/wen_to_wu");
			return 0;
		}
		else
		{
			message_vision("$N决定接受建议，转为武将。\n",me);
			me->set("ming/pro","武");
			me->delete_temp("ming/wen_to_wu");
			change_pro(me);
			message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")决定投笔从戎，就此转为"+me->query("ming/title")+"！\n"NOR,users());
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
int do_reward(string arg)
{
	object ruyi,me=this_player(),target;
	if (me->query("id")!="zine")
	return 0;
	if (!target=find_player(arg))
	{
		return notify_fail(arg+"并不在线。\n");
	}
	if (!target->query("mingpin"))
	{
		return notify_fail(arg+"并不是大明官员。\n");
	}
	ruyi=new(__DIR__"ruyi");
	ruyi->set("onwer",target->query("id"));
	ruyi->set("long","这是一张的大明皇帝亲题的嘉奖令，上面写着"HIW+target->query("name")+NOR+"在其"+chinese_number(target->query("age"))+"岁时，为大明立下不朽功绩，以资奖励。\n");
	ruyi->move(target);
	tell_object(me,"你发了一张"+ruyi->query("name")+"给"+target->name()+"。\n");
	tell_object(target,"你被大明授予了一张"+ruyi->query("name")+"，以奖励你发现的问题。\n");
	tell_object(target,"只要将嘉奖令交给吏部高级官员，可获得功勋奖励。\n");
	return 1;
}
//任务命令
int do_zhao()
{
    object me=this_player();
    object env=environment(me);
    if (!env)
    {
        return 0;
    }
    if (!me->query_temp("mingtasks/hubu/task"))
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (!env->query("zhao"))
    return notify_fail("你开始仔细搜寻失落的残图，却一无所获。\n");
	if (me->query_temp("mingtasks/hubu/task1finish"))
	return notify_fail("你已经找到了失落的残图，快回去复命吧。\n");
    else
    {
        tell_object(me,"你找到失落于此地的残图，仔细注释后，觉得自己可以回户部交差了。\n");
        me->set_temp("mingtasks/hubu/task1finish",1);
        return 1;
    }

}
int do_qing(string arg)
{
    object me=this_player();
    object target;
    if (!me->query_temp("mingtasks/libu/target"))
    return 0;
    if (me->query_temp("mingtasks/libu/qinged")>2)
    return notify_fail("你已经尝试过请"+me->query_temp("mingtasks/libu/targetname")+"出山了。\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    target=find_player(me->query_temp("mingtasks/libu/target"));
    if (!target||!living(target)||base_name(environment(target))!=base_name(environment(me)))
    return notify_fail("你要请的贤士不在这里。\n");
    else
    {
        message_vision("$N对着$n深深一揖：先生可愿出山复兴我大明？\n",me,target);
        me->set_temp("mingtasks/libu/task1finish",1);
        me->add_temp("mingtasks/libu/qinged",1);
        target->set_temp("mingtasks/libu/theone",1);
        target->set_temp("mingtasks/libu/introducer",me->query("id"));
        tell_object(me,"只要"+target->query("name")+"跟你回到应天府，必得大功一件。\n");
        tell_object(target,"看来"+me->query("name")+"真心诚意邀请你出山，如果愿意，可以随他回"+BLINK+HIC+"吏部衙门"+NOR+"答应(daying)大明的要求，往里可能你就进不去了。\n");
        return 1;
    }
}
int do_tongzhi(string arg)
{
    object me=this_player();
    object target;
    if (!me->query_temp("mingtasks/libu2/find_officer"))
    return 0;
    if (me->query_temp("mingtasks/libu2/jinjian")=="finish")
    return notify_fail("你已经通知了该官员，可以回礼部复命了。\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (!arg||arg!=me->query_temp("mingtasks/libu2/find_officer"))
    return notify_fail("你要通知的官员是"+me->query_temp("mingtasks/libu2/find_officer")+"。请输入 tongzhi "+me->query_temp("mingtasks/libu2/find_officer")+"。\n");
    if (!target=present(arg,environment(me)))
    return notify_fail(arg+"不在这里。\n");
    else
    {
        message_vision("$N对着$n拱了拱手，道：“大人该去觐见陛下了，先去礼部点个卯吧。”\n",me,target);
		message_vision("$N道：“兄弟话带到了，还有要事在身，先告辞了。”\n",me);
        me->set_temp("mingtasks/libu2/jinjian","finish");
        target->set_temp("ming_libu2_jinjian",time());
        tell_object(target,"在五分钟内赶回礼部尚书处，你将获得额外大明功勋奖励。\n");
        return 1;
    }
}
int do_yayun()
{
	object me=this_player();
	object env,from,cart;
	if (!me->query_temp("mingtasks/gongbu/yuhen"))
	return 0;
	if (!me->query_temp("mingtasks/gongbu/yuhen_from"))
	return 0;
	if (me->query_temp("mingtasks/gongbu/yuhen_cart_obtain"))
	return 0;
	env=environment(me);
	from=me->query_temp("mingtasks/gongbu/yuhen_from");
	if (env==from||(TASK_D->place_belong(env)==TASK_D->place_belong(from)&&env->query("short")==from->query("short")))
	{
		cart=new(__DIR__"cart");
		cart->set("owner",me->query("id"));
		cart->set_long(me);
		cart->move(environment(me));
		me->set_temp("mingtasks/gongbu/yuhen_cart_obtain",1);
		message_vision("$N来到预定的地点，发现民伕们早围在$n旁等候自己，只等自己领队(ling)前行了。\n",me,cart);
		return 1;
	}
	return 0;
}
//高级官员普遍命令
int decide(object me,string id,string what,string decision)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i;
    ob->restore();
    for (i=0;i<1000;i++)
    {
        if (ob->query("todo_list/"+me->query("ming/depart")+"/"+i)
            &&ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/from")==id
            &&ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/what")==what)
        {
            ob->set("todo_list/"+me->query("ming/depart")+"/"+i+"/state",decision);
        }
    }
    ob->save();
    return 1;
}
int do_accept()
{
    object pl,me=this_player();
    string id,what,then_rank;
    if (me->query_temp("ming_to_do_list"))
    {
        id=me->query_temp("ming_to_do_list/from");
        what=me->query_temp("ming_to_do_list/what");
        then_rank=me->query_temp("ming_to_do_list/then_rank");
        if (pl=find_player(me->query_temp(id))&&pl->query("ming/title")==then_rank)
        {
            tell_object(me,"你同意了"+id+"的请求。\n");
            decide(me,id,what,"同意");
            return 1;
        }
        else
		return notify_fail(id+"现在不在！\n");
    }
    else if (time()-me->query_temp("ming_adv_tasks/task_pending_time")>30)
    {
        return 0;
    }
    else
    {
        me->set_temp("ming_adv_tasks/task_pending_time","yes");
        if (pl=me->query_temp("ming_adv_tasks/task_giver"))
        {
            tell_object(me,"你接受了"+pl->query("name")+"分派的任务。\n");
            tell_object(pl,me->query("name")+"接受了你分派的任务。\n");
            pl->delete_temp("ming_adv_tasks/task_give_pending");
        }
        return 1;
    }
}
int do_refuse()
{
    object pl,me=this_player();
    string id,what,then_rank;
    if (me->query_temp("ming_to_do_list"))
    {
        id=me->query_temp("ming_to_do_list/from");
        what=me->query_temp("ming_to_do_list/what");
        then_rank=me->query_temp("ming_to_do_list/then_rank");
        if (pl=find_player(me->query_temp(id))&&pl->query("ming/title")==then_rank)
        {
            tell_object(me,"你拒绝了"+id+"的请求。\n");
            decide(me,id,what,"拒绝");
            return 1;
        }
        else
		return notify_fail(id+"现在不在！\n");
    }
    else if (time()-me->query_temp("ming_adv_tasks/task_pending_time")>30)
    {
        return 0;
    }
    else
    {
        
        if (pl=me->query_temp("ming_adv_tasks/task_giver"))
        {
            tell_object(me,"你拒绝了"+pl->query("name")+"分派的任务。\n");
            tell_object(pl,me->query("name")+"拒绝了你分派的任务。\n");
            pl->delete_temp("ming_adv_tasks/task_give_pending");
        }
        me->delete_temp("ming_adv_tasks");
        return 1;
    }
}
int do_recover()
{
    object me=this_player();
    int recover;
    int re_time=(int)me->query("ming/ability/qinmian");
    if (!me->query("mingpin"))
	return 0;
    if (time()<(int)me->query("ming/energy_recover_time"))
	return notify_fail("你的行动力还需"+chinese_number(me->query("ming/energy_recover_time")-time())+"秒，才能使用官印恢复。\n");
    recover=(10-(int)me->query("mingpin"))*15;
    me->set("ming/energy_recover_time",time()+(2400-re_time*10));
    me->set("ming/energy",recover);
    tell_object(me,"你的行动力恢复为"+chinese_number(recover)+"点。\n");
    return 1;
}