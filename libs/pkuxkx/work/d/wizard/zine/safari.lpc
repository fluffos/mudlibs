#include <room.h>
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
int safari(object me,string bang);
int safari_xx(object me,string bang);
int gene(string bang);
string look_bang();
#define SHED 11//分割经验和次数的点
int get_shed()
{
	return SHED;
}
mapping *safari = ({
            ([  "id":1,"short_name":"襄阳保卫任务经验","name":"exp/xytask","desc":"通过襄阳保卫获得经验","per_day":150000,"max":100000,"min":50000,]),
            ([  "id":2,"short_name":"鄱阳湖寻宝经验  ","name":"exp/pyh","desc":"通过鄱阳湖获得经验","per_day":100000,"max":66000,"min":33000,]),
            //([  "id":3,"name":"exp/banhejob","desc":"通过萧半和任务获得经验","per_day":80000,"max":48000,"min":24000,]),
            ([  "id":3,"short_name":"胡一刀任务经验  ","name":"exp/yidao","desc":"通过胡一刀任务获得经验","per_day":480000,"max":320000,"min":160000,]),
            ([  "id":4,"short_name":"TASK任务经验    ","name":"exp/task","desc":"通过TASK获得经验","per_day":40000,"max":25000,"min":12500,]),
            ([  "id":5,"short_name":"韩员外任务经验  ","name":"exp/hyw","desc":"通过韩员外任务获得经验","per_day":400000,"max":250000,"min":125000,]),
            ([  "id":6,"short_name":"护镖任务经验    ","name":"exp/hubiao","desc":"通过护镖任务获得经验","per_day":500000,"max":12000,"min":8000,]),
            ([  "id":7,"short_name":"送信任务经验    ","name":"exp/songxin","desc":"通过送信任务获得经验","per_day":40000,"max":25000,"min":12500,]),
            ([  "id":8,"short_name":"萧峰任务经验    ","name":"exp/xiaofeng","desc":"通过萧峰任务获得经验","per_day":520000,"max":340000,"min":170000,"mirror":({9,16})]),
            ([  "id":9,"short_name":"慕容任务经验    ","name":"exp/murong","desc":"通过慕容任务获得经验","per_day":150000,"max":35000,"min":20000,]),
			([  "id":10,"short_name":"韩世忠任务经验  ","name":"exp/hansz","desc":"通过韩世忠任务获得经验","per_day":500000,"max":320000,"min":150000,"mirror":({7,12})]),
			([  "id":11,"short_name":"都府行刺任务经验","name":"exp/mzj","desc":"通过都府行刺任务获得经验","per_day":280000,"max":200000,"min":120000,]),
   //         ([  "id":12,"name":"newjobs/completed/xiaobanhe","desc":"完成萧半和任务一定次数","per_day":1,"max":1,"min":1,"index":75,]),
           
            ([  "id":12,"short_name":"韩员外任务次数  ","name":"newjobs/completed/hyw","desc":"完成韩员外任务一定次数","per_day":80,"max":50,"min":25,"index":5,]),
            ([  "id":13,"short_name":"萧峰任务次数    ","name":"jobs/completed/xiaofeng","desc":"完成萧峰任务一定次数","per_day":80,"max":50,"min":25,"index":5,"mirror":({9,16})]),
            ([  "id":14,"short_name":"胡一刀任务次数  ","name":"jobs/completed/huyidao","desc":"完成胡一刀任务一定次数","per_day":50,"max":34,"min":17,"index":8,]),
            ([  "id":15,"short_name":"护镖任务次数    ","name":"jobs/completed/hubiao","desc":"完成护镖任务一定次数","per_day":100,"max":10,"min":5,"index":4,]),
            ([  "id":16,"short_name":"TASK任务次数    ","name":"jobs/completed/task","desc":"完成TASK任务一定次数","per_day":50,"max":34,"min":17,"index":7,]),
			([  "id":17,"short_name":"韩世忠任务次数  ","name":"jobs/completed/hansz","desc":"完成韩世忠任务一定次数","per_day":80,"max":50,"min":25,"index":5,"mirror":({7,12})]),
            ([  "id":18,"short_name":"万安塔四以上次数","name":"newjobs/completed/wat","desc":"完成万安塔四层以上一定次数","per_day":30,"max":20,"min":10,"index":6,]),
			([  "id":19,"short_name":"鄱阳湖寻宝次数  ","name":"newjobs/completed/pyh","desc":"完成鄱阳湖任务一定次数","per_day":4,"max":3,"min":1,"index":50,]),
			([  "id":20,"short_name":"都府行刺任务次数","name":"newjobs/completed/mzj","desc":"完成都府行刺任务一定次数","per_day":30,"max":20,"min":12,"index":5,]),
        });
mapping * ret_safari()
{
	return safari;
}
int * mirror(int number)
{
	if (!safari[number]["mirror"]||!arrayp(safari[number]["mirror"]))
	return ({});
	else
	return safari[number]["mirror"];
}
mapping *query_all_safari()
{
	return safari;
}
mapping query_safari()
{
    return safari[random(sizeof(safari))];
}
mapping query_certain_safari(int i)
{
    return safari[i];
}
mapping alpha_to_word=(["a":"甲","b":"乙","c":"丙","d":"丁","e":"戊","f":"己",]);
mapping word_to_alpha=(["甲":"a","乙":"b","丙":"c","丁":"d","戊":"e","己":"f",]);
mapping get_safari(string arg)
{
    mapping option;
    int exp,times,diff,number,*mirrors;
    int *list=query("list"+arg);
	number=list[random(sizeof(list))];
	list-=({number});
	mirrors=mirror(number);
	if (mirrors!=({})&&arrayp(mirrors))
	for (int i=0;i<sizeof(mirrors);i++)
	if (member_array(mirrors[i],list)!=-1)
	list-=({mirrors[i]});
	set("list"+arg,list);
    option=query_certain_safari(number);
    diff=random(option["max"]-option["min"]);
    if (number<SHED)//exp
    {
        
        exp=1+option["min"]+diff;
        option["require_exp"]=exp*(2+random(2));
        option["days"]=to_float(exp)/(float)option["per_day"];
    }
    else//times
    {
        times=option["min"]+diff;
        option["require_times"]=times*(2+random(3));
        option["days"]=to_float(times)/(float)option["per_day"];
        option["times"]=option["require_times"]*option["index"];
    }
   
    return option;
}


void create()
{
        set("short", HIY"铜雀台"NOR);
        set("long", @LONG
这里是古铜雀台，相传三国时曹操击败袁绍在这里修建了铜雀台。这里每隔
一段时间会发布一些奇怪的任务，好事的武林中人来往不绝。金榜(bang)上不定
时辰会有些奇怪的任务。
LONG
        );
        set("exits", ([
			"north" : __DIR__"dating",
			"down" : "/d/beijing/tongque",
            
        ]));
        set("item_desc", ([
		"bang" : (:look_bang:), 
	    ]));
        set("no_reset",1);
        set("no_clean_up", 1);
        set("outdoors", "changjiang");
        set("generate_list",0);
        setup();
        call_out("gettime",1);
}

string look_bang()
{
    int i,safari=0,complete=0,lv=0;
    string msg,name,name2,name3;
    object *user = filter_array(children(USER_OB), (: userp :));
    user = filter_array(user, (: environment :));
    //user = filter_array(user, (: $1->query("safari_credit") :) );
    msg="一面金榜，你可以用list看一下现在的任务，如果中意，自然可以揭榜(pick)。\n";
    if (!user)
    {
        return msg;
    }
    else
    {
        for (i=0;i<sizeof(user);i++)
        {
            if (wizardp(user[i]))
            {
                continue;
            }
            if (user[i]->query("safari_credit")>safari)
            {
                safari=(int)user[i]->query("safari_credit");
                name=user[i]->query("name");
            }
			if (user[i]->query("newjobs/completed/safari")>complete)
			{
				complete=(int)user[i]->query("newjobs/completed/safari");
				name2=user[i]->query("name");
			}
			if (user[i]->query("tqt/challenge_level")>lv)
			{
				lv=(int)user[i]->query("tqt/challenge_level");
				name3=user[i]->query("name");
			}
        }
		if (name)
        msg+="当前拥有铜雀台积分最高的玩家是"+name+NOR+"。\n";
		else
		msg+="当前无人拥有铜雀台积分！\n";
		if (name2)
		msg+="当前完成铜雀台任务次数最多的玩家是"+name2+NOR+"。\n";
		else
		msg+="当前无人完成过铜雀台任务！\n";
		if (name3)
		msg+="当前完成铜雀台静室二层挑战最高级别的玩家是"+name3+NOR+"。\n";
		else
		msg+="当前无人在铜雀台静室二层挑战过！\n";
        return msg;
    }
}
int pre_gene(object ob)
{
	int i,j,*list=({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19});
	string *bangs=({"a","b","c","d","e","f"});
	for (i=0;i<sizeof(bangs);i++)
	{
		delete("calc_"+bangs[i]);
		set("list"+bangs[i],list);
		gene(bangs[i]);
		delete("posi_"+bangs[i]);
	}
}
int gettime()
{
    object ob=this_object(),*all_npc;
    int time=time();
    int i;
    mixed* timeinfos=localtime(time);
    int hour=timeinfos[LT_HOUR];
    if (hour==5||hour==9||hour==13||hour==17||hour==19||hour==21||hour==23||hour==1)
    {
        pre_gene(ob);
        CHANNEL_D->do_channel(this_object(), "jh", "铜雀台上刮起了大风，之后一切都归于平静。\n", -1);
        ob->set("list_updated",1);
    }
    if (!ob->query("list_updated"))
    {
         pre_gene(ob);
    }
    set("generate_list",1);
	all_npc=all_inventory(this_object());
	for (i=0;i<sizeof(all_npc);i++)
	{
		if (!userp(all_npc[i])&&all_npc[i]->is_character())
		{
			destruct(all_npc[i]);
		}
	}
	remove_call_out("gettime");
    call_out("gettime",3600);
    return 1;
}

void init()
{
    add_action("do_list","list");
	if (this_player()->query("ProfessionalClass"))
	return;
    add_action("do_pick","pick");
	add_action("do_pick_xx","pick_xx");
	add_action("do_confirm","confirm");
    add_action("do_abandon","abandon");
    add_action("do_complete","complete");
}

int give_reward(object me)
{
    string msg;
    object guwan,locker,xian;
    int i;
//tqt休闲台这里要改
	if (!me->query("safari"))
    {
        return 0;
    }

    msg=HIW+"恭喜你！成功完成铜雀台任务，你获得了：\n";
    msg+="\t"+chinese_number(me->query("safari/reward/exp"))+"点经验、"+chinese_number(me->query("safari/reward/pot"))+"点潜能以及"+chinese_number(me->query("safari/reward/rep"))+"点声望。\n";
    msg+="\t你之前被扣的一万点经验被返还一万五千点。\n";
    msg+=HIG+"\t你的报酬已经被转入各大钱庄你的户头了，正疑惑间，几个大汉武士抬出一个红木箱。\n"NOR;
    me->add("combat_exp",15000+me->query("safari/reward/exp"));
    me->add("potential",me->query("safari/reward/pot"));
    me->add("repute",me->query("safari/reward/rep"));
    me->add("balance",me->query("safari/reward/gold"));
    locker=new("/d/wizard/obj/locker");
    for (i=0;i<me->query("safari/reward/guwan");i++)
    {
        if (random(100)>49)
        {
            guwan=new("/d/guiyunzhuang/obj/guwan");
        }
        else
        {
            guwan=new("/d/guiyunzhuang/obj/zihua");
        }
        guwan->move(locker);
    }
    locker->set("owner",me->query("id"));
	locker->set("name", me->query("name")+"的"+HIR+"储物箱"+NOR);
	locker->set("id", me->query("id")+"'s box");
    locker->move(this_object());
    me->add("newjobs/completed/safari",1);
    if (me->query("safari/safari_xx"))
    {
	
		me->add("safari_xx_credit",i);
		if (me->query("safari_xx_credit")>=2)
		{
			me->add("safari_credit",1);
			write("恭喜你，因为你完成了两次休闲玩法铜雀台任务，被自动兑换成常规铜雀台积分。\n");
			me->set("safari_xx_credit",0);
		}
    }
	else
	{
		me->add("safari_credit",1);
	}
	if (me->query("tqt/double_credit")>0)
	{
		me->add("tqt/double_credit",-1);
		me->add("safari_credit",1);
		tell_object(me,"因为处在铜雀台双倍积分状态，你被额外增加了一点铜雀台积分。\n");
	}
    me->delete("safari");
    tell_object(me,msg);
    if ((int)me->query("newjobs/completed/safari")%10==0)
    {
        xian=load_object("/d/city/npc/xian");
        if (xian) //加个广告
        {
            xian->adv_tell(me);
        }
        tell_object(me,HIW+"你总共完成了"+chinese_number(me->query("newjobs/completed/safari"))+"次铜雀台任务。\n"+NOR);
    }
    return 1;
}

int do_complete()
{
    object me=this_player();
    int i;
    if (!me->query("safari"))
    {
        tell_object(me,"你没有揭过榜。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (time()>me->query("safari/duedate"))
    {
        tell_object(me,"很遗憾，你的铜雀台任务超时了。\n");
        return 1;
    }
    for (i=0;i<sizeof(safari);i++)
        {
            if (me->query("safari/"+safari[i]["name"])&&me->query(safari[i]["name"])<me->query("safari/"+safari[i]["name"]))
            {
                tell_object(me,"很遗憾，你的"+HIR+BLINK+"“"+safari[i]["desc"]+"”"+NOR+"，并未完成预先目标。\n");
                return 1;
            }
        }
	if (!me->query("biography/jobs/safari"))
	{
		me->set("biography/jobs/safari",time());//个人传记记录第一次完成任务时间ZINE
	}
    me->add_busy(5);
    give_reward(me);
	log_file("user/safari_credit",sprintf("%s\n",me->query("id")+"在"+ctime(time())+"完成铜雀台任务。"));
    return 1;
}

int do_abandon(string arg)
{
    object me=this_player();
	if (arg) return notify_fail("你要放弃甚么？\n");
    if (!me->query("safari"))
    {
        tell_object(me,"你没有揭过榜。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    me->delete("safari");
    me->set("safari_init_time",time());
    tell_object(me,"你放弃了上次铜雀台的任务，你被允许下次揭榜的时间被推迟了。\n");
    return 1;
}

int do_confirm()
{
    object me=this_player();
    object ob=this_object();
    if (me->query("safari"))
    {
        tell_object(me,"你上次任务必须完成(complete)或放弃(abandon)后方可继续揭榜。\n");
        return 1;
    }
    if (stringp(me->query_temp("safari/pre_posi")))
    {
		if (query("posi_"+me->query_temp("safari/pre_posi"))=="invalid")
		{
			tell_object(me,alpha_to_word[me->query_temp("safari/pre_posi")]+"榜的任务在你迟疑之间，已经被人揭下了。\n");
			return 1;
		}
        tell_object(me,"你揭下了"+alpha_to_word[me->query_temp("safari/pre_posi")]+"榜的任务。\n");
        set("posi_"+me->query_temp("safari/pre_posi"),"invalid");
        me->set("safari/posi"+me->query_temp("safari/pre_posi"),1);
        me->add("combat_exp",-10000);
		if (me->query_temp("safari/safari_xx"))
		{
			me->set("safari/safari_xx",1);
			me->delete_temp("safari/safari_xx");
	        safari_xx(me,me->query_temp("safari/pre_posi"));

		}
		else
		{
	        safari(me,me->query_temp("safari/pre_posi"));
		}
		me->delete_temp("safari/pre_posi");
        return 1;
    }
    else
    {
        return 0;
    }
}
int invalid_bang(object me,string arg)
{
	string *bangs=({"甲","乙","丙","丁","戊","己"});
	if (!query("generate_list"))
    {
        tell_object(me,"榜单正在生成，请稍候！\n");
        return 1;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("combat_exp")<10000000)
    {
        tell_object(me,"这次任务非同儿戏，至少需要一千万经验才有尝试资格。\n");
        return 1;
    }
    if (me->query("safari"))
    {
        tell_object(me,"你上次任务必须完成(complete)或放弃(abandon)后方可继续揭榜。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你准备看哪块榜？\n");
        return 1;
    }
    if (member_array(arg,bangs)==-1)
    {
        tell_object(me,"目前只有甲、乙、丙、丁、戊、己六块榜。\n");
        return 1;
    }
	if (arg=="己"&&(strsrch(STATISTIC_D->lookup(me->query("id")),"天")==-1&&
	strsrch(STATISTIC_D->lookup(me->query("id")),"地")==-1&&strsrch(STATISTIC_D->lookup(me->query("id")),"风云")==-1))
	{
		tell_object(me,"己榜只对天、地、风云上榜高手开放。\n");
		return 1;
	}
    if (query("posi_"+word_to_alpha[arg])=="invalid")
    {
        tell_object(me,arg+"榜已经被揭下了。\n");
        return 1;
    }
	return 0;
}
int do_list(string arg)
{
    object me=this_player();
    if (invalid_bang(me,arg)==1)
    {
		return 1;
    }
	safari(me,word_to_alpha[arg]);
	return 1;
}
int do_pick(string arg)
{
    object me=this_player();
    if (invalid_bang(me,arg)==1)
    {
		return 1;
    }
	//tqt休闲台这里改下：改为4天
    if (time()-me->query("safari_init_time")<3600*72)
    {
        tell_object(me,"距离你上次揭榜不足三天，你现在不被允许揭榜。\n");
        return 1;
    }
	tell_object(me,"你希望揭下"+arg+"榜的任务吗？请用confirm命令确认。\n");
	tell_object(me,BLINK+CYN+"揭榜将暂扣一万经验，如果完成任务后将返还一万五千点经验。\n"+NOR);
	me->delete_temp("safari/safari_xx");
	me->set_temp("safari/pre_posi",word_to_alpha[arg]);
	return 1;
}

int do_pick_xx(string arg)
{
    object me=this_player();
    if (invalid_bang(me,arg)==1)
    {
		return 1;
    }
	//tqt休闲台这里改下：改为4天
    if (time()-me->query("safari_init_time")<3600*96)
    {
        tell_object(me,"距离你上次揭榜不足四天，你现在不被允许揭榜。\n");
        return 1;
    }
	tell_object(me,"你希望揭下"+arg+"榜的任务吗？请用confirm命令确认。\n");
	tell_object(me,BLINK+CYN+"揭榜将暂扣一万经验，如果完成任务后将返还一万五千点经验。\n"+NOR);
	me->set_temp("safari/safari_xx",1);
	me->set_temp("safari/pre_posi",word_to_alpha[arg]);
	return 1;
}

int gene(string bang)
{
    int i,safari_number=random(5)+4;
    float total_day=1.0;
	mapping op,*ops=({});
	for (i=safari_number;i>0;i--)
	{
		op=get_safari(bang);
		ops+=({op});
		total_day+=op["days"];
	}
	set(bang+"_day",to_int(total_day));
	//tqt休闲台加时间
	if (query(bang+"_day") > 1)
	{
		set(bang+"_xx_day",2*query(bang+"_day")-1);
	}
	else
	{
		set(bang+"_xx_day",2);
	}
	set("SAFARI_"+bang,ops);
    return 1;
}

int calc_gold(int r_base_time)
{
    int result=r_base_time*1250+random(r_base_time)*300;
    return result;
}

int calc_guwan(int r_base_time)
{
    int result=to_int(r_base_time/370);
    return result;
}

int calc_exp(int r_base_exp)
{
    int result=r_base_exp/25+random(r_base_exp/30)+1+random(4000);
    return result;
}

int calc_pot(int r_base_exp)
{
    int result=r_base_exp/30+random(r_base_exp/20)+1+random(3000);
    return result;
}

int calc_rep(int r_base_exp)
{
    int result=random(r_base_exp/80)+1+random(1000);
    return result;
}

int safari(object me,string bang)
{
    string msg;
    int i,r_base_time,r_base_exp,r_exp,r_pot,r_rep,r_gold,r_guwan;
	mapping *ops;
	ops=query("SAFARI_"+bang);
    msg=HIC+"在"+chinese_number(query(bang+"_day"))+"日内，完成：\n";
	for (i=0;i<sizeof(ops);i++)
	{
		if (ops[i]["require_exp"])
		{
			msg+="\t☆"+ops[i]["desc"]+"共需："+HIR+chinese_number(ops[i]["require_exp"])+HIC+"点\n";
			r_base_exp+=ops[i]["require_exp"];
		}
		else
		{
			msg+="\t★"+ops[i]["desc"]+"共需："+HBWHT+HIR+chinese_number(ops[i]["require_times"])+NOR+HIC+"次\n";
			r_base_time+=ops[i]["times"];
		}
	}
    msg+=RED+"\t以上任务均须在规定时间内完成，否则铜雀台任务失败。\n"+NOR;
    if (!query("calc_"+bang))
    {
        r_exp=calc_exp(r_base_exp);
        r_pot=calc_pot(r_base_exp);
        r_rep=calc_rep(r_base_exp);
        r_gold=calc_gold(r_base_time);
        r_guwan=calc_guwan(r_base_time);
        if (r_guwan<1)
        {
            r_guwan=1;
        }
        set("s"+bang+"/exp",r_exp);
        set("s"+bang+"/pot",r_pot);
        set("s"+bang+"/rep",r_rep);
        set("s"+bang+"/gold",r_gold);
        set("s"+bang+"/guwan",r_guwan);
        set("calc_"+bang,1);
    }
    
    msg+=HIM+"如果按时完成上述任务，可额外获得"+chinese_number(query("s"+bang+"/exp"))+"点经验、"+chinese_number(query("s"+bang+"/pot"))+"点潜能以及"+chinese_number(query("s"+bang+"/rep"))+"点声望。\n"+NOR;
    msg+=HIM+"此外还可获得"+MONEY_D->money_str(query("s"+bang+"/gold"))+"和"+chinese_number(query("s"+bang+"/guwan"))+"件古玩。\n"+NOR;
	msg+=HIG+"如果需要休闲玩法，请使用pick_xx命令摘取此榜单，在"+chinese_number(query(bang+"_xx_day"))+"日内完成即可，休闲玩法下，奖励为常规台的二分之一。\n"+NOR;
    if (query("posi_"+bang)=="invalid"&&!me->query("safari/posi"+bang))
    {
        tell_object(me,alpha_to_word[bang]+"榜的任务已经被人揭走了。\n");
        return 1;
    }
    tell_object(me,msg);
    if (me->query("safari/posi"+bang))
    {
        me->delete("safari/posi"+bang);
		if (me->query("safari/safari_xx"))
		{
			me->set("safari/duedate",time()+(int)query(bang+"_xx_day")*24*3600);
		}
		else
		{
			me->set("safari/duedate",time()+(int)query(bang+"_day")*24*3600);
		}
        me->set("safari_init_time",time());
		for (i=0;i<sizeof(ops);i++)
		{
			if (ops[i]["require_exp"])
			{
				me->add("safari/"+ops[i]["name"],ops[i]["require_exp"]);
			}
			else
			{
				me->add("safari/"+ops[i]["name"],ops[i]["require_times"]);
			}
		}
		me->set("safari/reward_base_exp",r_base_exp);
		me->set("safari/reward_base_time",r_base_time);

		if (me->query("safari/safari_xx"))
		{
			me->set("safari/reward/exp",query("s"+bang+"/exp")/2);
			me->set("safari/reward/pot",query("s"+bang+"/pot")/2);
			me->set("safari/reward/rep",query("s"+bang+"/rep")/2);
			me->set("safari/reward/gold",query("s"+bang+"/gold")/2);
			me->set("safari/reward/guwan",query("s"+bang+"/guwan")/2);

		}
		else
		{
			me->set("safari/reward/exp",query("s"+bang+"/exp"));
			me->set("safari/reward/pot",query("s"+bang+"/pot"));
			me->set("safari/reward/rep",query("s"+bang+"/rep"));
			me->set("safari/reward/gold",query("s"+bang+"/gold"));
			me->set("safari/reward/guwan",query("s"+bang+"/guwan"));
		}
    }

    if (me->query("safari"))
    {
        for (i=0;i<sizeof(safari);i++)
        {
            if (me->query("safari/"+safari[i]["name"]))
            {
                me->add("safari/"+safari[i]["name"],me->query(safari[i]["name"]));
            }
        }
    }
    
    return 1;
}

int safari_xx(object me,string bang)
{
    string msg;
    int i,r_base_time,r_base_exp,r_exp,r_pot,r_rep,r_gold,r_guwan;
	mapping *ops;
	ops=query("SAFARI_"+bang);
    msg=HIC+"休闲玩法：在"+chinese_number(query(bang+"_xx_day"))+"日内，完成：\n";
	for (i=0;i<sizeof(ops);i++)
	{
		if (ops[i]["require_exp"])
		{
			msg+="\t☆"+ops[i]["desc"]+"共需："+HIR+chinese_number(ops[i]["require_exp"])+HIC+"点\n";
			r_base_exp+=ops[i]["require_exp"];
		}
		else
		{
			msg+="\t★"+ops[i]["desc"]+"共需："+HBWHT+HIR+chinese_number(ops[i]["require_times"])+NOR+HIC+"次\n";
			r_base_time+=ops[i]["times"];
		}
	}
    msg+=RED+"\t以上任务均须在规定时间内完成，否则铜雀台任务失败。\n"+NOR;
    if (!query("calc_"+bang))
    {
        r_exp=calc_exp(r_base_exp);
        r_pot=calc_pot(r_base_exp);
        r_rep=calc_rep(r_base_exp);
        r_gold=calc_gold(r_base_time);
        r_guwan=calc_guwan(r_base_time);
        if (r_guwan<1)
        {
            r_guwan=1;
        }
        set("s"+bang+"/exp",r_exp);
        set("s"+bang+"/pot",r_pot);
        set("s"+bang+"/rep",r_rep);
        set("s"+bang+"/gold",r_gold);
        set("s"+bang+"/guwan",r_guwan);
        set("calc_"+bang,1);
    }
    
    msg+=HIM+"如果按时完成上述任务，可额外获得"+chinese_number(query("s"+bang+"/exp")/2)+"点经验、"+chinese_number(query("s"+bang+"/pot")/2)+"点潜能以及"+chinese_number(query("s"+bang+"/rep")/2)+"点声望。\n"+NOR;
    msg+=HIM+"此外还可获得"+MONEY_D->money_str(query("s"+bang+"/gold")/2)+"和"+chinese_number(query("s"+bang+"/guwan")/2)+"件古玩。\n"+NOR;
	msg+=HIG+"在休闲玩法下，奖励为常规台的二分之一。\n"+NOR;
    if (query("posi_"+bang)=="invalid"&&!me->query("safari/posi"+bang))
    {
        tell_object(me,alpha_to_word[bang]+"榜的任务已经被人揭走了。\n");
        return 1;
    }
    tell_object(me,msg);
    if (me->query("safari/posi"+bang))
    {
        me->delete("safari/posi"+bang);
		me->set("safari/duedate",time()+(int)query(bang+"_xx_day")*24*3600);
        me->set("safari_init_time",time());
		for (i=0;i<sizeof(ops);i++)
		{
			if (ops[i]["require_exp"])
			{
				me->add("safari/"+ops[i]["name"],ops[i]["require_exp"]);
			}
			else
			{
				me->add("safari/"+ops[i]["name"],ops[i]["require_times"]);
			}
		}
		me->set("safari/reward_base_exp",r_base_exp);
		me->set("safari/reward_base_time",r_base_time);
		me->set("safari/reward/exp",query("s"+bang+"/exp")/2);
		me->set("safari/reward/pot",query("s"+bang+"/pot")/2);
		me->set("safari/reward/rep",query("s"+bang+"/rep")/2);
		me->set("safari/reward/gold",query("s"+bang+"/gold")/2);
		me->set("safari/reward/guwan",query("s"+bang+"/guwan")/2);
    }

    if (me->query("safari"))
    {
        for (i=0;i<sizeof(safari);i++)
        {
            if (me->query("safari/"+safari[i]["name"]))
            {
                me->add("safari/"+safari[i]["name"],me->query(safari[i]["name"]));
            }
        }
    }
    
    return 1;
}

