//官印
//create by zine 29/3/2011
#include <ansi.h>
#include <title.h>
inherit ITEM;
inherit F_MORE;
#include "/d/yingtianfu/neicheng/npc/promote.h"
#define HEADER HIY"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR
#define TAIL   HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR 
#define LINE   HIY"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR
#define SZ   HIY"██████████████████████████████████████████████\n"NOR
#define POSI_LINE HIG"--------------------------------------------------------------------------------------------------\n"NOR
#define VER 13 //版本号，用来确定所有人的官印都是最新的
int check_env();
int to_do_list();
int do_gengxin()
{
	object ob,me=this_player(),env,gem;
	if (!identification(me,"太常寺卿")&&me->query("id")!="zine") return 0;
	env=environment(me);
	if (base_name(env)!="/d/yingtianfu/neicheng/taimiao")
	return notify_fail("只有在太庙才需要更替新的贡品。\n");
	if (me->query("mud_age")-me->query("ming/taichang_gem")<3600*12)
	return notify_fail("暂时太庙的贡品还很新，不需要换新的贡品。\n");
	me->set("ming/taichang_gem",me->query("mud_age"));
	gem=new("/obj/gem/gem");
	gem->move(me);
	message_vision("$N给太庙换上新的贡品和装饰，将一颗旧的$n收入囊中。\n",me,gem);
	return 1;
}
int judge_extra_room()
{
	object ming=load_object("/d/yingtianfu/neicheng/shengzhi");
    object me=environment(this_object());
    string *names=({});
	if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	if (ming->query("extra_home_list"))
	{
		names=ming->query("extra_home_list");
	}
	if (member_array(me->query("id"),names)==-1)
	{
		if (me->query("ming/extra_room_by_gongbu"))
		{
			me->delete("ming/extra_room_by_gongbu");
			tell_object(me,"工部拆除了你宅邸中扩建的部分。\n");
		}
	}
	else
	{
		if (!me->query("ming/extra_room_by_gongbu"))
		{
			me->set("ming/extra_room_by_gongbu",1);
			tell_object(me,"工部扩建了你的宅邸。\n");
		}
	}
	return 1;
}
int load_check_env()
{
	object check=load_object("/d/yingtianfu/neicheng/baihu");
	check->check_guanyin();
	return 1;
}

int modify_daming()
{
	object me=environment(this_object());
    string vice_title,old_title="";
	string *colors=({HIR,RED,HIW,WHT,HIB,BLU,HIY,YEL,HIG,GRN,HIC,CYN,HIM,MAG});
	if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
	if (me->get_title(TITLE_MING2)=="")
	vice_title=set_me_duty(me);
	else
	vice_title=promote_me_duty(me);
	old_title=me->get_title(TITLE_MING2);
	if (vice_title!="")
	{
		me->set_title(TITLE_MING2,vice_title);
		if (old_title!=""&&old_title!=me->get_title(TITLE_MING2))
		{
			me->set("ming/duty_promote/credit",me->query("ming/credit"));
			me->set("ming/duty_promote/promote_time",me->query("mud_age"));
			tell_object(me,"在朝中多年，你的散阶提升为"+me->get_title(TITLE_MING2)+"。\n");
		}
	}
	if (!me->get_title(TITLE_MING1))
	{
		me->set_title(TITLE_MING1,HIW+"大明 "+colors[random(sizeof(colors))]+me->query("ming/title")+NOR);
	}
	if (!me->query("ming/duty_rank"))
	{
		me->set("ming/duty_rank",get_duty_rank_no(me));
	}
	return 1;
}
int checK_position()
{
	object me=environment(this_object());
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
	mapping *title;
	if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
	ob->restore();
	if (ob->query("give_titles"))
	title=ob->query("give_titles");
	else
	title=upper_title;
	for (int i=0;i<sizeof(title);i++)
	{
		if (title[i]["title"]==me->query("ming/title")&&(title[i]["pin"]!=me->query("mingpin")||title[i]["pro"]!=me->query("ming/pro")))
		{
			me->set_temp("ming/hor_promote",2);
			position_me(me);
			return 1;
		}
	}
	if (me->query("mingpin")&&me->query("mingpin")<=3)
	{
		for (int i=0;i<sizeof(title);i++)
		{
			if (title[i]["title"]==me->query("ming/title")&&title[i]["pin"]==me->query("mingpin")&&title[i]["pro"]==me->query("ming/pro")&&title[i]["owner"]=="")
			{
				title[i]["owner"]=me->query("id");
				title[i]["owner_name"]=me->query("name");
				ob->set("give_titles",title);
				ob->save();
				return 1;
			}
		}
	}
}
int valid_promote()
{
	object pl=environment(this_object()),qt;
	mapping *promote_require=({
        (["pro":"文","pin":1,"credit":3500,"designate_effect":100,]),
		(["pro":"文","pin":2,"credit":1600,"designate_effect":40,]),
		(["pro":"文","pin":3,"credit":750,"designate_effect":15,]),
		(["pro":"文","pin":4,"credit":240,"designate_effect":10,]),
		(["pro":"文","pin":5,"credit":120,"designate_effect":0,]),
		(["pro":"文","pin":6,"credit":25,"designate_effect":0,]),
		(["pro":"文","pin":7,"credit":10,"designate_effect":0,]),
		(["pro":"文","pin":8,"credit":5,"designate_effect":0,]),
		(["pro":"武","pin":1,"credit":3500,"designate_effect":100,]),
		(["pro":"武","pin":2,"credit":2100,"designate_effect":40,]),
		(["pro":"武","pin":3,"credit":1250,"designate_effect":15,]),
		(["pro":"武","pin":4,"credit":650,"designate_effect":10,]),
		(["pro":"武","pin":5,"credit":220,"designate_effect":0,]),
		(["pro":"武","pin":6,"credit":25,"designate_effect":0,]),
	});
	int j,pin;
	string pro,*promote_list=({});
	mapping require;
	if (!pl)
    {
        return 1;
    }
    if (!userp(pl))
    {
        return 1;
    }
    if (!pl->query("mingpin"))
    {
        return 1;
    }
	pin=pl->query("mingpin")-1;
    if (pin==0)
    {
        return 1;
    }
	pro=pl->query("ming/pro");
    if (!pro)
    {
        if (random(100)>49)
        {
			pl->set("ming/pro","武");
        }
		else
		{
			pl->set("ming/pro","文");
		}
		pro=pl->query("ming/pro");
    }
	if (pl->query("ming/credit")==0)
	{
		if (pl->query("ming/pro")=="文"&&pl->query("mingpin")<9)
		{
			pl->set("mingpin",10);
			tell_object(pl,"因为长期无所作为，你被一捋到底，贬官至"+chinese_number(pl->query("mingpin")-1)+"品。\n");
			position_me(pl);
		}
		if (pl->query("ming/pro")=="武"&&pl->query("mingpin")<7)
		{
			pl->set("mingpin",8);
			tell_object(pl,"因为长期无所作为，你被一捋到底，贬官至"+chinese_number(pl->query("mingpin")-1)+"品。\n");
			position_me(pl);
		}

		
		return 1;
	}
	if (!can_promote(pl))
	{
		return 1;
	}
	for (j=0;j<sizeof(promote_require);j++)
	{
		if (pin==promote_require[j]["pin"]&&pro==promote_require[j]["pro"])
		{
			require=promote_require[j];
			break;
		}
	}
	if (!require)
	{
		return 1;
	}
    if (pl->query("ming/credit")<require["credit"]-(int)pl->query("ming/designate_obtain")*require["designate_effect"])
    {
        return 1;
    }
	if (pl->query("mingpin")==2&&!pl->query("ming/2to1"))
	{
		return 1;
	}
	position_me(pl);
	qt=load_object("/d/yingtianfu/neicheng/qintian");
	if (qt->query("promote_list"))
	{
		promote_list=qt->query("promote_list");
	}
	promote_list+=({pl->query("name")+" "});
	qt->set("promote_list",promote_list);
	return 1;
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
	call_out("modify_daming",1);
	call_out("checK_position",4);
    call_out("judge_extra_room",2);
	call_out("load_check_env",1);
    call_out("notice",3);
    call_out("set_ming_title",2);
    call_out("record",1);
    call_out("ability_improve",2);
    call_out("to_do_list",6);
	call_out("valid_promote",10);
}
int deal(string arg,object ob,object me,int i)
{
    object pl;
    if (arg=="yes"||arg=="y"||arg=="Yes"||arg=="Y")
    {
        ob->set("todo_list/"+me->query("ming/depart")+"/"+i+"/state","同意");
        tell_object(me,"你同意了这个请求。\n");
        if (pl=find_player(ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/from")))
        {
            tell_object(pl,"你的"+ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/what")+"要求，被"+me->query("name")+"同意了。\n");
        }
    }
    else
    {
        ob->set("todo_list/"+me->query("ming/depart")+"/"+i+"/state","拒绝");
        tell_object(me,"你拒绝了这个请求。\n");
        if (pl=find_player(ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/from")))
        {
            tell_object(pl,"你的"+ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/what")+"要求，被"+me->query("name")+"拒绝了。\n");
        }
    }
    ob->save();
    for (i=0;i<1000;i++)
    {
        if (ob->query("todo_list/"+me->query("ming/depart")+"/"+i)&&ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/state")=="pending")
        {
            to_do_list();
        }
    }
    return 1;
}
int to_do_list()
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    object me=environment(this_object());
    int i,flag=0;
    string msg="现在急需要你处理的事务：\n";
    if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
    if (me->query("mingpin")>3)
    {
        return 1;
    }
    ob->restore();
    for (i=0;i<1000;i++)
    {
        if (ob->query("todo_list/"+me->query("ming/depart")+"/"+i)&&ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/state")=="pending")
        {
            msg+="["+i+"]";
            msg+=ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/from")+"\t";
            msg+=ob->query("todo_list/"+me->query("ming/depart")+"/"+i+"/what");
            tell_object(me,"请选择处理意见。(Yes or No)");
            input_to( (: deal :),ob,me,i);
            return 1;
        }
    }
}

int ability_gene(object me)
{
    int n,tongyu,lianbing,zhengwu,renji,zhihui,qinmian,hr_degree;
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    if (!me)
    {
        return 1;
    }
    if (!me->is_character())
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
    me->set("ming/ability/generate",1);
    ob->restore();
    hr_degree=ob->query("daming_overall/hr/backup_degree");
    if (!hr_degree)
    {
        hr_degree=50;
    }
    if (me->query("ming/pro")=="武")
    {
        n=random(20);
        tongyu=hr_degree+n;
        zhengwu=hr_degree-n;
        n=random(20);
        lianbing=hr_degree+n;
        renji=hr_degree-n;
        n=random(20);
        if (random(2))
        {
            n=0-n;
        }
        zhihui=hr_degree+n;
        qinmian=hr_degree-n;
        me->set("ming/ability/tongyu",tongyu);
        me->set("ming/ability/zhengwu",zhengwu);
        me->set("ming/ability/lianbing",lianbing);
        me->set("ming/ability/renji",renji);
        me->set("ming/ability/zhihui",zhihui);
        me->set("ming/ability/qinmian",qinmian);
    }
    else if (me->query("ming/pro")=="文")
    {
        n=random(20);
        tongyu=hr_degree-n;
        zhengwu=hr_degree+n;
        n=random(20);
        lianbing=hr_degree-n;
        renji=hr_degree+n;
        n=random(20);
        if (random(2))
        {
            n=0-n;
        }
        zhihui=hr_degree-n;
        qinmian=hr_degree+n;
        me->set("ming/ability/tongyu",tongyu);
        me->set("ming/ability/zhengwu",zhengwu);
        me->set("ming/ability/lianbing",lianbing);
        me->set("ming/ability/renji",renji);
        me->set("ming/ability/zhihui",zhihui);
        me->set("ming/ability/qinmian",qinmian);
    }
    else
    {
        if (random(100)>49)
        {
            n=random(20);
            tongyu=hr_degree-n;
            zhengwu=hr_degree+n;
            n=random(20);
            lianbing=hr_degree-n;
            renji=hr_degree+n;
            n=random(20);
            if (random(2))
            {
                n=0-n;
            }
            zhihui=hr_degree-n;
            qinmian=hr_degree+n;
        }
        else
        {
            n=random(20);
            tongyu=hr_degree+n;
            zhengwu=hr_degree-n;
            n=random(20);
            lianbing=hr_degree+n;
            renji=hr_degree-n;
            n=random(20);
            if (random(2))
            {
                n=0-n;
            }
            zhihui=hr_degree+n;
            qinmian=hr_degree-n;
        }
        me->set("ming/ability/tongyu",tongyu);
        me->set("ming/ability/zhengwu",zhengwu);
        me->set("ming/ability/lianbing",lianbing);
        me->set("ming/ability/renji",renji);
        me->set("ming/ability/zhihui",zhihui);
        me->set("ming/ability/qinmian",qinmian);
    }
    return 1;
}
int zhuicha(object me,string arg)
{
	object env,target;
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	if (!environment(me))
	{
		return 1;
	}
	tell_object(me,HIW+"派出追查"+arg+"的人陆续回报：\n"+NOR);
	target=find_player(arg);
	if (!target)
	{
		target=find_living(arg);
		if (!target)
		{
			tell_object(me,arg+"极有可能已经不在人世了。\n");
			return 1;
		}
	}
	if (wizardp(target))
	{
		tell_object(me,"这个人行踪不定，没人能找到他。\n");
		return 1;
	}
	env=environment(target);
	if (!env)
	{
		tell_object(me,"这个人恐怕没人能找到。\n");
		return 1;
	}
	else
	{
		me->add("ming/zhuicha/times",1);
		tell_object(me,target->name()+"现在躲在"+HBWHT+HIR+env->query("short")+NOR+"，那里的描述是：\n    "+env->query("long"));
		return 1;
	}
}
int do_zhuicha(string arg)
{
	mixed tm=localtime(time());
	object me=this_player();
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	int times,period;
	if (!arg)
	{
		tell_object(me,"你要追查什么？\n");
		return 1;
	}
	if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
	{
		return 0;
	}
	if (me->query("mingpin")&&me->query("mingpin")>4)
	{
		tell_object(me,"只有四品官员及以上才可以调动朝廷的力量追查某人！\n");
		return 1;
	}
	if (me->query("ming/zhuicha/day")!=day)
	{
		me->set("ming/zhuicha/day",day);
		me->set("ming/zhuicha/times",0);
	}
	if (arg==me->query("id"))
	{
		tell_object(me,"你要追查自己？\n");
		return 1;
	}
	if (identification(me,"刑部尚书"))
	{
		times=3;
		period=-10;
	}
	if (identification(me,"刑部左侍郎"))
	{
		times=1;
		period=-6;
	}
	if (identification(me,"刑部右侍郎"))
	{
		times=1;
		period=-6;
	}
	times=times+8-(int)me->query("mingpin");
	if (me->query("mingpin")&&me->query("ming/zhuicha/times")>times)
	{
		tell_object(me,"今日你可以动员的力量已经全部派出追查了。\n");
		return 1;
	}
	message_vision(HIW"$N派出大量人手开始在各地追查"+arg+"的消息。\n"NOR,me);
	period=period+15+random(15);
	call_out("zhuicha",period,me,arg);
	return 1;
}
string level_ability(int point)
{
    if (point>90)
    {
        return HIY+"人中龙凤"+NOR;
    }
    else if (point>80)
    {
        return HIY+"国士无双"+NOR;
    }
    else if (point>70)
    {
        return HIB+"栋梁之才"+NOR;
    }
    else if (point>60)
    {
        return HIB+"可造之材"+NOR;
    }
    else if (point>50)
    {
        return HIG+"中人之资"+NOR;
    }
    else if (point>40)
    {
        return HIG+"下下之选"+NOR;
    }
    else
    {
        return WHT+"不堪造就"+NOR;
    }
}
int zengke(object li)
{
    if (living(li))
    {
        li->add_lists();
    }
    return 1;
}
int do_diaoren(string arg)
{
	mixed tm=localtime(time());
	object ming,people,me=this_player();
	string pl,posi,msg;
	string month=sprintf("%d-%d", tm[5], tm[4]+1);
	mapping *title;
	int i,flag=0,flag2=0,count=0,pin;
	if (!identification(me,"保和殿大学士")&&!identification(me,"文华殿大学士")&&!identification(me,"武英殿大学士")&&!identification(me,"文渊阁大学士")
		&&!identification(me,"体仁阁大学士")&&!identification(me,"东阁大学士")&&!identification(me,"五军都督府 大都督")&&!identification(me,"五军都督府 左都督")
		&&!identification(me,"五军都督府 右都督")&&!identification(me,"五军都督府 都督同知")&&me->query("id")!="zine") return 0;
	if (me->query("ming/diaoren/month")!=month)
	{
		me->set("ming/diaoren/month",month);
		me->set("ming/diaoren/times",0);
	}
	if (me->query("ming/diaoren/month")==month&&me->query("ming/diaoren/times")>=3&&me->query("id")!="zine")
	{
		tell_object(me,"本月，你已调任过至少三名官员的职务了。\n");
		return 1;
	}
	if (!arg)
	{
		msg="目前可调任的高级职位有：\n";
		for (i=0;i<sizeof(upper_title);i++)
		{
			if (upper_title[i]["pro"]==me->query("ming/pro"))
			{
				msg+="㊣"+upper_title[i]["title"];
				count+=1;
				if (count%4==0&&count!=0)
				{
					msg+="\n";
				}
			}
		}
		msg+="\n";
		tell_object(me,msg);
		return 1;
	}
	if( sscanf(arg, "%s to %s", pl, posi)!=2 )
	{
		tell_object(me,"调任的格式是diaoren <人名> to <职位>。\n");
		return 1;
	}
	if (!people=find_player(pl))
	{
		tell_object(me,arg+"并不在线！\n");
		return 1;
	}
	if (!people->query("mingpin"))
	{
		tell_object(me,people->name()+"并不是大明官员。\n");
		return 1;
	}
	if (people->query("mingpin")>3&&me->query("id")!="zine")
	{
		tell_object(me,people->name()+"这样的低级官员，你就不用插手了。\n");
		return 1;
	}
	if (people->query("mingpin")<2&&me->query("id")!="zine")
	{
		tell_object(me,people->name()+"这个级别的官员，需要廷推议定。\n");
		return 1;
	}
	if (people->query("ming/pro")!=me->query("ming/pro")&&me->query("id")!="zine")
	{
		tell_object(me,"文臣不管武将，武将不管文臣，这是祖制。\n");
		return 1;
	}
	if (month==people->query("ming/neige_change")&&me->query("id")!="zine")
	{
		tell_object(me,"本月调令刚刚生效，此刻不宜调动"+people->query("name")+"。\n");
		return 1;
	}
	for (i=0;i<sizeof(upper_title);i++)
	{
		if (posi==upper_title[i]["title"])
		{
			flag=1;
			pin=upper_title[i]["pin"];
		}
	}
	if (flag==0)
	{
		tell_object(me,"大明无"+posi+"这样的官衔。\n");
		return 1;
	}
	if (pin!=people->query("mingpin"))
	{
		tell_object(me,WHT+people->name()+WHT+"的官品与"+posi+"的官品不符。\n"+NOR);
		return 1;
	}
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	title=ming->query("give_titles");
	for (i=0;i<sizeof(title);i++)
	{
		if (posi==title[i]["title"]&&title[i]["owner"]!="")
		{
			if (title[i]["owner"]==people->query("id"))
			{
				tell_object(me,people->query("name")+"不正在"+posi+"的位置上吗？\n");
				return 1;
			}
			flag2=1;
		}
	}
	if (flag2==1)
	{
		tell_object(me,posi+"此刻并无空缺。\n");
		return 1;
	}
	people->set("ming/neige_change",month);
	people->set_temp("ming/hor_promote",3);
	people->set_temp("ming/hor_promote_title",posi);
    position_me(people);
	message_vision("$N签署内阁调令，将$n调任为"+posi+"。\n",me,people);
	if (me->query("ming/pro")=="武")
	{
		message("daming",HIW"【大明】"+me->query("ming/title")+me->query("name")+HIW+"("+capitalize(me->query("id"))+")签署五军都督府调令，将"+people->query("name")+HIW+"("+capitalize(people->query("id"))+")职位变更为"+posi+"。\n"NOR,users());
	}
	else
	{
		message("daming",HIW"【大明】"+me->query("ming/title")+me->query("name")+HIW+"("+capitalize(me->query("id"))+")签署内阁调令，将"+people->query("name")+HIW+"("+capitalize(people->query("id"))+")职位变更为"+posi+"。\n"NOR,users());
	}
	people->delete_temp("ming/hor_promote");
	people->delete_temp("ming/hor_promote_title");
	return 1;
}
int do_designate(string arg)
{
	mixed tm=localtime(time());
	object pl,me=this_player();
	string month=sprintf("%d-%d", tm[5], tm[4]+1),title="";
	if (!identification(me,"保和殿大学士")&&!identification(me,"文华殿大学士")&&!identification(me,"武英殿大学士")&&!identification(me,"文渊阁大学士")
		&&!identification(me,"体仁阁大学士")&&!identification(me,"东阁大学士")&&!identification(me,"五军都督府 大都督")&&!identification(me,"五军都督府 左都督")
		&&!identification(me,"五军都督府 右都督")&&!identification(me,"五军都督府 都督同知")&&me->query("id")!="zine") return 0;
	if (me->query("ming/designate/month")!=month)
	{
		me->set("ming/designate/month",month);
		me->set("ming/designate/times",0);
	}
	if (me->query("ming/designate/month")==month&&me->query("ming/designate/times")>=3)
	{
		tell_object(me,"本月，你已至少行文吏部嘉奖三名官员了，不得滥用！\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要行文吏部嘉奖哪名官员？\n");
		return 1;
	}
	if (!present(arg,environment(me)))
	{
		tell_object(me,arg+"现在似乎不在这里！\n");
		return 1;
	}
	pl=present(arg,environment(me));
	if (!userp(pl))
	{
		tell_object(me,"你行文吏部嘉奖的应该是一个玩家吧？机会难得，不要浪费！\n");
		return 1;
	}
	if (pl==me)
	{
		tell_object(me,"嘉奖自己？当心被罢了官！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你最好等"+arg+"清醒过来，当面行文吏部嘉奖他！\n");
		return 1;
	}
	if (!pl->query("mingpin"))
	{
		tell_object(me,"你行文吏部嘉奖的至少需要是四品以上的官员，吏部才有记录。\n");
		return 1;
	}
	if (pl->query("mingpin")>4)
	{
		tell_object(me,"这么小的官，你正式发文吏部，似乎有点小题大作！\n");
		return 1;
	}
	if (pl->query("mingpin")<2)
	{
		tell_object(me,"一品大员嘉奖一品大员？有点奇怪！\n");
		return 1;
	}
	if (pl->query("ming/designate_obtain"))
	{
		tell_object(me,arg+"已经被吏部嘉奖了，此次提升将容易得多。\n");
		return 1;
	}
	if (pl->query("ming/designated"))
	{
		tell_object(me,"这种简拔程序一人一生使用一次，足矣！\n");
		return 1;
	}
	me->add("ming/designate/times",1);
	pl->set("ming/designated",1);
	pl->set("ming/designate_obtain",1);
	message_vision("$N行文吏部嘉奖$n，$n将获得更多升迁时的便利。\n",me,pl);
	if (me->query("ming/title"))
	{
		title=me->query("ming/title");
	}
	message("daming",HIW"【大明】"+title+me->query("name")+HIW+"("+capitalize(me->query("id"))+")行文吏部，嘉奖"+pl->query("name")+HIW+"("+capitalize(pl->query("id"))+")。\n"NOR,users());
	return 1;
}
int song(object me,string arg)
{
	object weapon;
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	if (!environment(me))
	{
		return 1;
	}
	weapon=new(__DIR__+arg);
	if (weapon)
	{
		weapon->move(me);
		message_vision(HIW"大明兵部给$N送来了"+weapon->query("name")+"。\n"+NOR,me);
	}
	return 1;
}
int do_song(string arg)
{
	mixed tm=localtime(time());
	object me=this_player();
	string month=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]),*weapons=({"sword","blade","halberd","spear","hammer","axe","dagger","whip","fork","staff"});
	if (!identification(me,"五军都督府 都督佥事")&&!identification(me,"三大营都指挥使")&&!identification(me,"三大营都指挥同知")
		&&!identification(me,"京卫指挥使司 指挥使")&&!identification(me,"京卫指挥使司 指挥同知")&&!identification(me,"京卫指挥使司 指挥佥事")&&me->query("id")!="zine") return 0;
	if (me->query("ming/weapon_acquire/month")!=month)
	{
		me->set("ming/weapon_acquire/month",month);
		me->set("ming/weapon_acquire/times",0);
	}
	if (me->query("mingpin")<3&&me->query("ming/weapon_acquire/month")==month&&me->query("ming/weapon_acquire/times")>=4)
	{
		tell_object(me,"今天，兵部的人已经送武器来了四趟，实在是抽不出人再来了。\n");
		return 1;
	}
	if (me->query("mingpin")<4&&me->query("ming/weapon_acquire/month")==month&&me->query("ming/weapon_acquire/times")>=2)
	{
		tell_object(me,"今天，兵部的人已经送武器来了两趟，实在是抽不出人再来了。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要兵部送来何种武器？(sword、blade、halberd、spear、hammer、axe、dagger、whip、fork、staff)\n");
		return 1;
	}
	if (member_array(arg,weapons)==-1)
	{
		tell_object(me,"你要兵部送来何种武器？(sword、blade、halberd、spear、hammer、axe、dagger、whip、fork、staff)\n");
		return 1;
	}
	call_out("song",6+random(5),me,arg);
	me->add("ming/weapon_acquire/times",1);
	message_vision("$N发信让兵部尽快给你送来"+arg+"。\n",me);
	return 1;
}
int do_congrong(string arg)//投笔从戎
{
	mixed tm=localtime(time());
	object pl,me=this_player();
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]),month=sprintf("%d-%d",tm[5],tm[4]+1);
	if (!identification(me,"兵部尚书")&&!identification(me,"兵部左侍郎")&&!identification(me,"兵部右侍郎")&&me->query("id")!="zine") return 0;
	if (me->query("ming/bing_congrong/day")!=day)
	{
		me->set("ming/bing_congrong/day",day);
		me->set("ming/bing_congrong/times",0);
	}
	if (identification(me,"兵部尚书")&&me->query("ming/bing_congrong/times")>=2)
	{
		tell_object(me,"你今天已经劝说至少两名文臣转为武将了，再转朝堂上就没人了。\n");
		return 1;
	}
	if ((identification(me,"兵部左侍郎")||identification(me,"兵部右侍郎"))&&me->query("ming/bing_congrong/times")>=1)
	{
		tell_object(me,"你今天已经劝说至少一名文臣转为武将了，再转朝堂上就没人了。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要劝说哪位大明文臣投笔从戎？\n");
		return 1;
	}
	if (!pl=present(arg,environment(me)))
	{
		tell_object(me,arg+"现在似乎并不在这里！\n");
		return 1;
	}
	if (!userp(pl))
	{
		tell_object(me,"你只能劝说大明文臣投笔从戎！\n");
		return 1;
	}
	if (pl==me)
	{
		tell_object(me,"你要劝说自己？真纠结啊！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你要等"+arg+"清醒过来再劝说他吧！\n");
		return 1;
	}
	if (!pl->query("mingpin"))
	{
		tell_object(me,"你只能劝说大明文臣投笔从戎！\n");
		return 1;
	}
	if (pl->query("mingpin")>7)
	{
		tell_object(me,"你只能劝说大明中、高文臣投笔从戎！\n");
		return 1;
	}
	if (pl->query("ming/pro")!="文")
	{
		tell_object(me,"你只能劝说大明文臣投笔从戎！\n");
		return 1;
	}
	if (pl->query("ming/change_pro/month")==month)
	{
		tell_object(me,pl->query("name")+"本月刚刚转职过。\n");
		return 1;
	}
	if (!present("guan yin",pl))
	{
		tell_object(me,pl->query("name")+"的官印并不在身，暂时无法转为武将。\n");
		return 1;
	}
	message_vision("$N对$n道：今日国家有难大丈夫……安能久事笔研间乎？\n",me,pl);
	pl->set_temp("ming/wen_to_wu",time());
	tell_object(pl,me->name()+"建议你转为武将，请在60秒内决定是否接受(yes/no)？\n");
	me->add("ming/bing_congrong/times",1);
	return 1;
}
int do_ruku(string arg)//刀枪入库
{
	mixed tm=localtime(time());
	object pl,me=this_player();
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]),month=sprintf("%d-%d",tm[5],tm[4]+1);
	if (!identification(me,"兵部尚书")&&me->query("id")!="zine") return 0;
	if (me->query("ming/bing_ruku/day")!=day)
	{
		me->set("ming/bing_ruku/day",day);
		me->set("ming/bing_ruku/times",0);
	}
	if (me->query("ming/bing_ruku/times")>=2)
	{
		tell_object(me,"你今天已经劝说至少两名武将转为文臣了，再转就没人保疆卫国了。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要劝说哪位大明武将刀枪入库？\n");
		return 1;
	}
	if (!pl=present(arg,environment(me)))
	{
		tell_object(me,arg+"现在似乎并不在这里！\n");
		return 1;
	}
	if (!userp(pl))
	{
		tell_object(me,"你只能劝说大明武将刀枪入库！\n");
		return 1;
	}
	if (pl==me)
	{
		tell_object(me,"你要劝说自己？真纠结啊！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你要等"+arg+"清醒过来再劝说他吧！\n");
		return 1;
	}
	if (!pl->query("mingpin"))
	{
		tell_object(me,"你只能劝说大明武将刀枪入库！\n");
		return 1;
	}
	/*if (pl->query("mingpin")>3)
	{
		tell_object(me,"你只能劝说大明高级武将刀枪入库！\n");
		return 1;
	}*/
	if (pl->query("ming/pro")!="武")
	{
		tell_object(me,"你只能劝说大明武将刀枪入库！\n");
		return 1;
	}
	if (pl->query("ming/change_pro/month")==month)
	{
		tell_object(me,pl->query("name")+"本月刚刚转职过。\n");
		return 1;
	}
	if (!present("guan yin",pl))
	{
		tell_object(me,pl->query("name")+"的官印并不在身，暂时无法转为文臣。\n");
		return 1;
	}
	message_vision("$N对$n道：今日天下太平已久，真个是：马放南山，刀枪入库，五谷丰登，万民乐业。将军转为文臣更可为国效力。\n",me,pl);
	pl->set_temp("ming/wu_to_wen",time());
	tell_object(pl,me->name()+"建议你转为文臣，请在60秒内决定是否接受(yes/no)？\n");
	me->add("ming/bing_ruku/times",1);
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
int do_yes()
{
	mixed tm=localtime(time());
	object me=this_player();
	string month=sprintf("%d-%d",tm[5],tm[4]+1);
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
			me->set("ming/change_pro/month",month);
			me->delete_temp("ming/wu_to_wen");
			me->set("ming/pro","文");
			me->set_temp("ming/hor_promote",2);
			position_me(me);
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
			me->set("ming/change_pro/month",month);
			me->set("ming/pro","武");
			me->delete_temp("ming/wen_to_wu");
			me->set_temp("ming/hor_promote",2);
			position_me(me);
			message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")决定投笔从戎，就此转为"+me->query("ming/title")+"！\n"NOR,users());
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
int do_chazhang(string arg)
{
	mixed tm=localtime(time());
	object pl,me=this_player();
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	int n,money=250000+random(250000);
	if (!identification(me,"户部尚书")&&!identification(me,"户部左侍郎")&&!identification(me,"户部右侍郎")&&me->query("id")!="zine") return 0;
	if (!arg)
	{
		tell_object(me,"你要调查哪位大明官员的入账？\n");
		return 1;
	}
	if (!pl=find_player(arg))
	{
		tell_object(me,arg+"现在似乎并不在线！\n");
		return 1;
	}
	if (!userp(pl))
	{
		tell_object(me,"你只能调查大明官员的账目！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你要等"+arg+"清醒过来才能继续调查他！\n");
		return 1;
	}
	if (!pl->query("mingpin"))
	{
		tell_object(me,"你只能调查大明官员的账目！\n");
		return 1;
	}
	if (pl->query("ming/tj/pin"))
	{
		tell_object(me,"外官不得查问内廷账目。\n");
		return 1;
	}
	if (pl==me)
	{
		tell_object(me,"你要查自己的账？\n");
		return 1;
	}
	if (pl->query("ming/chazhang/day")==day)
	{
		tell_object(me,pl->query("name")+"本日已经被调查过一次账目了。\n");
		return 1;
	}
	pl->set("ming/chazhang/day",day);
	tell_object(me,"你查出"+pl->query("name")+"经手的账目，竟有"+MONEY_D->money_str(money)+"的亏空，鉴于同僚的关系，你赶紧通知他补上了漏洞！\n");
	tell_object(pl,WHT+me->query("name")+WHT+"查问了你经手的出入账目。\n"+NOR);
	tell_object(pl,WHT+me->query("name")+WHT+"查出你经手账目的"+MONEY_D->money_str(money)+"亏空，通知了你。\n");
	if (pl->query("balance")>=money)
	{
		pl->add("balance",-money);
		tell_object(pl,"你补上了这个窟窿，运用朝中的人脉，不仅化险为夷，还受到了嘉奖。\n");
		n=2+random(6);
		pl->add("ming/credit",n);
		tell_object(pl,HIC"你的大明功勋增加了"+chinese_number(n)+"点。\n"NOR);
	}
	else
	{
		tell_object(pl,"虽然知道这个窟窿，一时之间你也凑不出那么多钱，这下被朝廷斥责了。\n");
		n=2+random(6);
		pl->add("ming/credit",-n);
		tell_object(pl,WHT"你的大明功勋减少了"+chinese_number(n)+"点。\n"NOR);
	}
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")正在查问"+pl->query("name")+HIW+"("+capitalize(pl->query("id"))+")的经手账目！\n"NOR,users());
	return 1;
}
int do_kuojian(string arg)
{
	object ming,pl,me=this_player();
	string *names=({}),*list=({}),msg="大明已扩建宅邸的官员列表：\n";
	int i;
	if (!identification(me,"工部尚书")&&!identification(me,"工部左侍郎")&&!identification(me,"工部右侍郎")&&me->query("id")!="zine") return 0;
	if (time()-me->query("ming/enlarge_house_command")<3600)
	{
		tell_object(me,"你刚刚为一位大明官员扩建过豪宅，这时候工部没人了，稍等等吧。\n");
		return 1;
	}
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	if (ming->query("extra_home_list"))
	{
		list=ming->query("extra_home_list");
	}
	if (!arg)
	{
		if (sizeof(list)==0)
		{
			msg="大明暂时尚无任何官员扩建宅邸。如需扩建某位官员宅邸，请输入kuojian <id>。\n";
			tell_object(me,msg);
			return 1;
		}
		for (i=0;i<sizeof(list);i++)
		{
			msg+=list[i]+"\t";
		}
		msg+="\n";
		tell_object(me,msg);
		return 1;
	}
	if (ming->query("all_the_daming_officers"))
	{
		names=ming->query("all_the_daming_officers");
	}
	if (member_array(arg,names)==-1)
	{
		tell_object(me,"你只能为大明官员扩建宅邸！\n");
		return 1;
	}
	if (sizeof(list)>=10)
	{
		tell_object(me,"已经扩建了至少十处的宅邸，再建大明财力支持不住了！\n");
		return 1;
	}
	if (member_array(arg,list)!=-1)
	{
		tell_object(me,arg+"已经被扩建过宅邸了！\n");
		return 1;
	}
	list+=({arg});
	ming->set("extra_home_list",list);
	ming->save();
	me->set("ming/enlarge_house_command",time());
	tell_object(me,"你将为"+arg+"扩建宅邸！\n");
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")开始扩建"+arg+"的宅邸！\n"NOR,users());
	return 1;
}
int do_chaichu(string arg)
{
	object ming,pl,me=this_player();
	string *list=({});
	if (!identification(me,"工部尚书")&&me->query("id")!="zine") return 0;
	if (!arg)
	{
		tell_object(me,"你要拆除哪位大明官员扩建的宅邸？\n");
		return 1;
	}
	if (time()-me->query("ming/enlarge_house_command")<3600)
	{
		tell_object(me,"你刚刚下令为一位大明官员扩建或拆除过宅邸，这时候工部没人了，稍等等吧。\n");
		return 1;
	}
	ming=load_object("/d/yingtianfu/neicheng/shengzhi");
	ming->restore();
	if (ming->query("extra_home_list"))
	{
		list=ming->query("extra_home_list");
	}
	if (member_array(arg,list)==-1)
	{
		tell_object(me,arg+"并没有被扩建过宅邸。\n");
		return 1;
	}
	list-=({arg});
	ming->set("extra_home_list",list);
	ming->save();
	me->set("ming/enlarge_house_command",time());
	tell_object(me,"你将"+arg+"的宅邸拆除扩建的部分！\n");
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")开始拆除"+arg+"宅邸的扩建部分！\n"NOR,users());
	return 1;
}
int do_yinbu(string arg)
{
	mixed tm=localtime(time());
	object pl,me=this_player();
	string month=sprintf("%d-%d", tm[5], tm[4]+1);
	if (!identification(me,"吏部尚书")&&!identification(me,"吏部左侍郎")&&!identification(me,"吏部右侍郎")&&me->query("id")!="zine") return 0;
	if (me->query("ming/yinbu/month")!=month)
	{
		me->set("ming/yinbu/month",month);
		me->set("ming/yinbu/times",0);
	}
	if (identification(me,"吏部尚书")&&me->query("ming/yinbu/month")==month&&me->query("ming/yinbu/times")>=2)
	{
		tell_object(me,"本月，你已至少荫补了两名候补官员了。大明名额有限，不得滥用！\n");
		return 1;
	}
	if (identification(me,"吏部左侍郎")&&me->query("ming/yinbu/month")==month&&me->query("ming/yinbu/times")>=1)
	{
		tell_object(me,"本月，你已至少荫补了一名候补官员了。大明名额有限，不得滥用！\n");
		return 1;
	}
	if (identification(me,"吏部右侍郎")&&me->query("ming/yinbu/month")==month&&me->query("ming/yinbu/times")>=1)
	{
		tell_object(me,"本月，你已至少荫补了一名候补官员了。大明名额有限，不得滥用！\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要荫补哪位作为大明候补官员？\n");
		return 1;
	}
	if (!present(arg,environment(me)))
	{
		tell_object(me,arg+"现在似乎不在这里！\n");
		return 1;
	}
	pl=present(arg,environment(me));
	if (!userp(pl))
	{
		tell_object(me,"你总得荫补一个玩家吧？机会难得，不要浪费！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你要等"+arg+"清醒过来才能荫补他！\n");
		return 1;
	}
	if (pl->query("gender")!="男性")
	{
		tell_object(me,"他这样的性别怎么立足朝堂之上呢？\n");
		return 1;
	}
	if (pl->query("family/family_name")=="朝廷")
	{
		tell_object(me,"你是想叛国吗？居然收清廷的人？\n");
		return 1;
	}
	if (pl->query("ming/in_wait_list"))
	{
		tell_object(me,arg+"本来就是我朝候补官员，候补什么？\n");
		return 1;
	}
	if (pl->query("mingpin"))
	{
		tell_object(me,arg+"本来就是我朝官员，候补什么？\n");
		return 1;
	}
	if (pl->query("ming/tj/pin"))
	{
		tell_object(me,arg+"本来就是我朝一名太监，候补什么？\n");
		return 1;
	}
	me->add("ming/yinbu/times",1);
	pl->set("ming/in_wait_list",1);
	tell_object(me,"你将"+arg+"荫补为大明候补官员！\n");
	tell_object(pl,me->query("name")+HIW+"将你荫补为大明官员，只需十次史可法任务即可获得进入大明的机会！\n"+NOR);
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")荫补"+pl->query("name")+HIW+"("+capitalize(pl->query("id"))+")为大明候补官员！\n"NOR,users());
	return 1;
}
int do_zengke()
{
    object qt,li,me=this_player();
    if (!identification(me,"礼部尚书")&&!identification(me,"礼部左侍郎")&&!identification(me,"礼部右侍郎")) return 0;
    qt=load_object("/d/yingtianfu/neicheng/qintian");
    if (!qt)
    {
        tell_object(me,"时下时局实在不宜增开科考。\n");
        return 1;
    }
    if (!li=qt->query("li"))
    {
        tell_object(me,"时下时局实在不宜增开科考。\n");
        return 1;
    }
    if (!living(li))
    {
        tell_object(me,"时下时局实在不宜增开科考。\n");
        return 1;
    }
    if (me->query("ming/energy")<100)
    {
        tell_object(me,"你现在的行动力不足，无法增开科考。\n");
        return 1;
    }
    if (identification(me,"礼部尚书"))
    {
        if (time()-me->query("ming/zengke/time")>3600*24*7)
        {
            me->set("ming/zengke/time",time());
            me->set("ming/zengke/times",1);
            me->add("ming/energy",-100);
            li->add_lists();
        }
        else
        {
            if (me->query("ming/zengke/times")<2)
            {
                me->add("ming/zengke/times",1);
                me->add("ming/energy",-100);
                li->add_lists();
            }
            else
            {
                tell_object(me,"这段时间内你已经增开了两场科考，再等等吧！\n");
            }
        }
        return 1;
    }
    if (identification(me,"礼部左侍郎"))
    {
        if (time()-me->query("ming/zengke/time")>3600*24*7)
        {
            me->set("ming/zengke/time",time());
            tell_object(me,"上峰已经答应了你的请求，将尽快增开科考！\n");
            me->add("ming/energy",-100);
            call_out("zengke",20+random(40),li);
        }
        else
        {
            tell_object(me,"这段时间内你已经增开过科考了，再等等吧！\n");
        }
        return 1;
    }
    if (identification(me,"礼部右侍郎"))
    {
        if (time()-me->query("ming/zengke/time")>3600*24*7)
        {
            me->set("ming/zengke/time",time());
            tell_object(me,"上峰已经答应了你的请求，将尽快增开科考！\n");
            me->add("ming/energy",-100);
            call_out("zengke",20+random(40),li);
        }
        else
        {
            tell_object(me,"这段时间内你已经增开过科考了，再等等吧！\n");
        }
        return 1;
    }
}

int ability_improve()
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    object me=environment(this_object());
    string depart_name,msg;
    int i,flag=0;
    if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
    ob->restore();
    if (!me->query("ming/ability/generate"))
    {
        ability_gene(me);
    }
    if (me->query("ming/ability/last_report")<me->query("age"))
    {
        depart_name=classify_depart(me);
        msg=HIW+"\n\n今年吏部的报告出来了，关于你的情况：\n"+NOR;
        msg+=HIW+"统御："+level_ability(me->query("ming/ability/tongyu"))+"、";
        msg+=HIW+"练兵："+level_ability(me->query("ming/ability/lianbing"))+"、";
        msg+=HIW+"政务："+level_ability(me->query("ming/ability/zhengwu"))+"、";
        msg+=HIW+"人际："+level_ability(me->query("ming/ability/renji"))+"、";
        msg+=HIW+"智慧："+level_ability(me->query("ming/ability/zhihui"))+"、";
        msg+=HIW+"勤勉："+level_ability(me->query("ming/ability/qinmian"))+"。\n\n";
        tell_object(me,msg);
        me->set("ming/ability/last_report",me->query("age"));
        for (i=100;i<301;i++) 
        {
            if (ob->query(depart_name+"/officers/"+i+"/id")==me->query("id"))
            {
                ob->set(depart_name+"/officers/"+i+"/ability_tongyu",me->query("ming/ability/tongyu"));
                ob->set(depart_name+"/officers/"+i+"/ability_lianbing",me->query("ming/ability/lianbing"));
                ob->set(depart_name+"/officers/"+i+"/ability_zhengwu",me->query("ming/ability/zhengwu"));
                ob->set(depart_name+"/officers/"+i+"/ability_renji",me->query("ming/ability/renji"));
                ob->set(depart_name+"/officers/"+i+"/ability_zhihui",me->query("ming/ability/zhihui"));
                ob->set(depart_name+"/officers/"+i+"/ability_qinmian",me->query("ming/ability/qinmian"));
                ob->save();
                return 1;
            }
        }
    }
}

int record()
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    object me=environment(this_object());
    string depart_name,*names=({});
    int i,flag=0;
    if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    if (!me->query("mingpin"))
    {
        return 1;
    }
    ob->restore();
    ob->set("daming_officers/data/"+me->query("id")+"/name",me->query("name"));
    ob->set("daming_officers/data/"+me->query("id")+"/id",me->query("id"));
    ob->set("daming_officers/data/"+me->query("id")+"/position",me->query("ming/title"));
    ob->set("daming_officers/data/"+me->query("id")+"/profession",me->query("ming/pro"));
    ob->set("daming_officers/data/"+me->query("id")+"/credit",me->query("ming/credit"));
    ob->set("daming_officers/data/"+me->query("id")+"/excellent_records",me->query("ming/suikao/overall"));
    ob->set("daming_officers/data/"+me->query("id")+"/department",ob->get_my_depart(me));
	if (ob->query("all_the_daming_officers"))
	{
		names=ob->query("all_the_daming_officers");
	}
	if (member_array(me->query("id"),names)==-1)
	{
		names+=({me->query("id")});
	}
	ob->set("all_the_daming_officers",names);
    ob->save();
    me->set("ming/depart",ob->get_my_depart(me));
    if (me->query("ming/depart"))
    {
        depart_name=classify_depart(me);
    }
    for (i=100;i<301;i++) 
    {
        if (ob->query(depart_name+"/officers/"+i+"/id")==me->query("id"))
        {
            flag=1;//有记录
        }
    }
    if (flag==0)
    {
        for (i=100;i<301;i++) 
        {
            if (!ob->query(depart_name+"/officers/"+i))
            {
                ob->set(depart_name+"/officers/"+i+"/id",me->query("id"));
                ob->set(depart_name+"/officers/"+i+"/name",me->query("name"));
                ob->save();
                return 1;
            }
        }
    }
    return 1;
}

int back_me_up(object me)
{
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]),z="--";
	if (me->query("ming/backup_data")==date)
	{
		return 1;
	}
	me->set("ming/backup_data",date);
	log_file("user/ming_players_backup",sprintf("%s%s%s%s%s%s%s%s%s%s%s%s\n",date+":",me->query("id"),z,me->query("mingpin")+"品",z,me->query("ming/pro"),z,me->query("ming/credit")+"点功勋",z,me->query("ming/title"),z,"部门编号："+me->query("ming/depart")));
	return 1;
}
int set_ming_title()
{
    object me=environment(this_object());
    string title,*titles;
    if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    title=TITLE_MING1;
    if (title)
    {
		titles=me->query("multi_title");
		if (titles)
		{
			if (member_array(title,titles)==-1)
			{
				me->set("multi_title", ({title}));
			}
		}
		else
		{
			me->set("multi_title", ({title}));
		}
		
    }
	if (me->query("mingpin"))
	back_me_up(me);
    return 1;
}

int notice()
{
    int i,num,news_num,flag=0;
    mapping* notes;
    string msg;
    object me=environment(this_object()),notice;
    if (!me)
    {
        return 1;
    }
    if (!userp(me))
    {
        return 1;
    }
    notice=load_object("/clone/board/daming_notice_b");
    num=me->query("ming/news_notice/num");
    notes=notice->query("notes");
	if (me->query("mingpin")!=1&&me->query("ming/suikao/time")&&me->query("mud_age")-me->query("ming/suikao/time")>3600*24*2)
	{
		if (me->query("ming/suikao/time")&&me->query("mud_age")-me->query("ming/suikao/time")>3600*24*4)
		{
			tell_object(me,BLINK+HIR+"你已经超过四次没有参加岁考了，如果超过五次不进行岁考，极有可能被赶出中枢，外放地方。\n"+NOR);
			return 1;
		}
		tell_object(me,"你已经超过两次没有参加岁考了，如果超过五次不进行岁考，极有可能被赶出中枢，外放地方。\n");
		return 1;
	}
    if (!notes)
    {
        return 1;
    }
    news_num=sizeof(notes)-1;
    msg="\n\n"SZ+HIY"奉天承运，皇帝诏曰：\n"NOR;
    me->set("ming/news_notice/num",news_num);
    for (i=num;i<=news_num;i++)
    {
		if (i!=num)
		{
			msg+=HBWHT+HIR+"【大明更新】"+notes[i]["title"]+NOR;
			msg+="\n";
		}
        flag=1;
        if (num==news_num)
        {
            flag=0;
        }
    }
    msg+=sprintf("\n%100s\n",HIY+"钦此"+NOR);
    msg+=SZ;
    if (flag==1)
    {
        tell_object(me,msg);
    }
    return 1;
}

int do_unarrest(string arg)
{
    object me=this_player(),target;
    mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
    if (!me->query("mingpin"))
    {
        return 0;
    }
    if (me->query("mingpin")>4)
    {
        return 0;
    }
    if (me->query("ming/unarrest/date")==date)
    {
        tell_object(me,"你今天已经帮助"+me->query("ming/unarrest/target_name")+"疏通过一次了，要适可而止。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要帮被疏通解除通缉？\n");
        return 1;
    }
    if (!target=find_player(arg))
    {
        tell_object(me,"找不到"+arg+"这个人！\n");
        return 1;
    }
    if (!living(target))
    {
        tell_object(me,"等他醒过来再说吧。\n");
        return 1;
    }
    if (target==me)
    {
        tell_object(me,"替自己疏通？实在有些难于启齿啊。\n");
        return 1;
    }
    if (!present(target,environment(me)))
    {
        tell_object(me,target->query("name")+"在哪？叫到面前才能帮他疏通。\n");
        return 1;
    }
    if (target->query("mingpin")&&me->query("mingpin")-target->query("mingpin")>1)
    {
        tell_object(me,"大人物的事情，小虾米就别掺和了！\n");
        return 1;
    }
    if (!target->query_condition("killer"))
    {
        tell_object(me,target->query("name")+"根本没被通缉。\n");
        return 1;
    }
    me->set("ming/unarrest/date",date);
    me->set("ming/unarrest/target_name",target->query("name"));
    target->apply_condition("killer", 1);
    message_vision(HIW"$N拍着胸脯对$n道：放心，包在我身上了！一会我就给刑部打个招呼去。\n"NOR,me,target);
    return 1;
}

int valid_greet(object ob,object me)
{
    int i,flag=1;
    if (ob==me)
    {
        return 0;
    }
    if( !ob->visible(me) ) 
    {
        return 0;
    }
    if (!me->visible(ob))
    {
        return 0;
    }
    if (!sizeof(ob->query_temp("daming/greet")))
    {
        return 1;
    }
    for (i=0;i<sizeof(ob->query_temp("daming/greet"));i++)
    {
        if (ob->query_temp("daming/greet/"+i+"/target")==me)
        {
            if (time()-ob->query_temp("daming/greet/"+i+"/time")>300)
            {
                return i+2;
            }
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

int check_env()
{
    object ob=this_object();
    object me=environment(ob);
    if (!me)
    {
        return 1;
    }
    else if (userp(me)&&me->query("mingpin"))
    {
        flatter(me);
		if (me->query("ming/tj")&&me->query("gender")=="男性")
		{
			me->delete("ming/tj");
		}
        return 1;
    }
    else
    {
        return 1;
    }
}

int query_autoload() { return 1; }

int dest(object ob)
{
    if (ob)
    destruct(ob);
}

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
        {
            tell_object(me,id+"现在不在！\n");
            return 1;
        }
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
        {
            tell_object(me,id+"现在不在！\n");
            return 1;
        }
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
    {
        return 0;
    }
    if (time()<(int)me->query("ming/energy_recover_time"))
    {
        tell_object(me,"你的行动力还需"+chinese_number(me->query("ming/energy_recover_time")-time())+"秒，才能使用官印恢复。\n");
        return 1;
    }
    recover=(10-(int)me->query("mingpin"))*15;
    me->set("ming/energy_recover_time",time()+(2400-re_time*10));
    me->set("ming/energy",recover);
    tell_object(me,"你的行动力恢复为"+chinese_number(recover)+"点。\n");
    return 1;
}
int do_vote(string arg)
{
	mixed tm=localtime(time());
	object ob,me=this_player();
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	string user;
	if (!identification(me,"左都御史")&&!identification(me,"右都御史")&&!identification(me,"左副都御史")&&!identification(me,"右副都御史")) return 0;
	if (me->query("ming/yushi_vote/day")!=day)
	{
		me->set("ming/yushi_vote/day",day);
		me->set("ming/yushi_vote/times",0);
	}
	if ((identification(me,"左都御史")||identification(me,"右都御史"))&&me->query("ming/yushi_vote/times")>=2)
	{
		return 0;
	}
	if ((identification(me,"左副都御史")||identification(me,"右副都御史"))&&me->query("ming/yushi_vote/times")>=1)
	{
		return 0;
	}
	if (!arg)
	{
		return 0;
	}
	if ((identification(me,"左都御史")||identification(me,"左副都御史"))&&sscanf(arg, "unchblk %s", user) == 1)
	{
		if (!ob=find_player(user))
		{
			return 0;
		}
		else
		{
			if (ob->query("chblk_chat"))
			{
				ob->delete("chblk_chat");
				tell_object(me,"你发动大明言官的力量打开了"+ob->name()+"的聊天频道。\n");
				message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")发动大明都察院的力量打开了"+ob->query("name")+HIW+"("+capitalize(ob->query("id"))+")的聊天频道！\n"NOR,users());
				me->add("ming/yushi_vote/times",1);
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else if ((identification(me,"右都御史")||identification(me,"右副都御史"))&&sscanf(arg, "chblk %s", user) == 1)
	{
		if (!ob=find_player(user))
		{
			return 0;
		}
		else
		{
			if (!ob->query("chblk_chat"))
			{
				ob->set("chblk_chat",1);
				tell_object(me,"你发动大明言官的力量关闭了"+ob->name()+"的聊天频道。\n");
				message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")发动大明都察院的力量关闭了"+ob->query("name")+HIW+"("+capitalize(ob->query("id"))+")的聊天频道！\n"NOR,users());
				me->add("ming/yushi_vote/times",1);
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
}

int do_yayun()
{
	object me=this_player();
	object env,from,cart;
	if (!me->query_temp("mingtasks/gongbu/yuhen"))
	{
		return 0;
	}
	if (!me->query_temp("mingtasks/gongbu/yuhen_from"))
	{
		return 0;
	}
	if (me->query_temp("mingtasks/gongbu/yuhen_cart_obtain"))
	{
		return 0;
	}
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
void init()
{
    object ob=this_object();
    object belong=environment(ob);
    
    set("long",HIW+"这是一具白玉刻成的大明"+chinese_number(belong->query("mingpin"))+"品官员的官印，侧面刻着"+belong->query("name")+HIW+"。\n"+NOR);
    add_action("do_players","players");
    //add_action("do_daming","daming");//聊天通道
    add_action("do_zhao","zhao");
    add_action("do_query","query");
    add_action("do_qing","yaoqing");
	add_action("do_yayun","yayun");
    add_action("do_position","positions");
	add_action("do_accept","accept");
	add_action("do_repair_daming","repairdm");
	add_action("do_reward","reward");
		add_action("do_refuse","refuse");
		add_action("do_recover","recover");
		add_action("do_zengke","zengke");
		add_action("do_yinbu","yinbu");
		add_action("do_designate","jiajiang");
		add_action("do_song","song");
		add_action("do_zhuicha","zhuicha");
		add_action("do_diaoren","diaoren");
		add_action("do_chazhang","chazhang");
		add_action("do_kuojian","kuojian");
		add_action("do_chaichu","chaichu");
		add_action("do_ruku","ruku");
		add_action("do_congrong","congrong");
		add_action("do_yes","yes");
		add_action("do_no","no");
		add_action("do_vote","vote");
		add_action("do_send_guanyin","fa");
		add_action("do_get_guanyin","shou");
	add_action("do_unarrest","shutong");
	add_action("do_gengxin","gengxin");
	if (userp(belong)&&belong->query("mingpin")==1)
	{
		add_action("do_kanyu","kanyu"); //堪舆
		add_action("do_tandu","tandu"); //贪渎
		add_action("do_wencai","wencai");//文采
		add_action("do_tupo","tupo"); //突破
		add_action("do_buqu","buqu"); //不屈
		add_action("do_jili","jili"); //激励
		add_action("do_wachu","wachu");
	}
	if (userp(belong)&&belong->query("ming/suikao/time")+3600*24>=belong->query("mud_age"))
	{
		add_action("do_kanyu","kanyu"); //堪舆
		add_action("do_tandu","tandu"); //贪渎
		add_action("do_wencai","wencai");//文采
		add_action("do_tupo","tupo"); //突破
		add_action("do_buqu","buqu"); //不屈
		add_action("do_jili","jili"); //激励
		add_action("do_wachu","wachu");
	}
    if (!userp(belong))
    {
        call_out("dest",1,ob);
        return;
    }
    if (belong->query("gender")!="男性")
    {
        call_out("dest",1,ob);
        return;
    }
    if (!belong->query("mingpin"))
    {
        call_out("dest",1,ob);
        return;
    }
}

int do_get_guanyin()
{
    object *ob,*obs,gy,me=this_player();
    int i,j,flag;
	if (me->query("id")!="zine")
	{
		return 0;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: $1->query("mingpin"):) );
    ob = filter_array(ob, (: living :));
    for (i=0;i<sizeof(ob);i++)
    {
        flag=0;
        obs=all_inventory(ob[i]);
        for (j=0;j<sizeof(obs);j++)
        {
            if (obs[j]->query("guanyin")&&!obs[j]->is_character())
            {
                destruct(obs[j]);
                tell_object(ob[i],"朝廷即将使用新的官印，收回了你的旧官印。\n");
            }
        }
    }
    return 1;
}

int do_send_guanyin()
{
    object *ob,*obs,gy,me=this_player();
    int i,j,flag;
	if (me->query("id")!="zine")
	{
		return 0;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: $1->query("mingpin"):) );
    ob = filter_array(ob, (: living :));
    for (i=0;i<sizeof(ob);i++)
    {
        flag=0;
        obs=all_inventory(ob[i]);
        for (j=0;j<sizeof(obs);j++)
        {
            if (obs[j]->query("guanyin"))
            {
                flag=1;
            }
        }
        if (flag==0&&ob[i]->query("gender")=="男性")
        {
            gy=new("/d/yingtianfu/neicheng/obj/guanyin");
            gy->set("owner",ob[i]->query("id"));
            gy->move(ob[i]);
            tell_object(ob[i],"你正觉得少带了些什么，一个小吏慌慌张张地跑了过来：“"+ob[i]->query("name")+"大人，您忘了您老人家的官印了。”\n");
            tell_object(ob[i],"小吏把你的官印郑重地交了给你。\n");
        }
    }
    return 1;
}
int afterwa(object me)
{
    object room=environment(me);
    object bei;
    if (!room->query("goodplace"))
    {
        tell_object(me,"你挖了半天，似乎什么也没发现。\n");
        return 1;
    }
    tell_object(me,"你往下挖了三尺，似乎遇到一个硬碑。\n");//出现
    bei=new(__DIR__"bei");
    
    bei->set("owner",me->query("id"));
    bei->set("pin",(int)me->query("mingpin"));
    bei->move(room);
    if (room->query("no_reset"))
    {
        bei->set("roomno_reset",1);
    }
    room->set("no_reset",1);
    room->set("no_clean_up", 1);
    return 1;
}

int do_wachu()
{
    object me=this_player();
    object env=environment(me);
    object shibei;
    if (!me->query("mingpin"))
    {
        return 0;
    }
    if (me->query("ming/special")!="fengshui")
    {
        return 0;
    }
    if (present("shi bei",env))
    {
        shibei=present("shi bei",env);
    }
    if (shibei && shibei->query("is_shibei"))
    {
        tell_object(me,"你要挖的东西不是已经在这里了？\n");
        return 1;
    }
	if (me->query("neili")<500)
	{
		tell_object(me,"你现在内力不够，怎能徒手挖穿这里？\n");
        return 1;
	}
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    message_vision("$N开始用手吃力地在地上挖着什么。\n",me);
    me->add("neili",-500);
    remove_call_out("afterwa");
    call_out("afterwa",3,me);
    return 1;
}

int do_qing(string arg)
{
    object me=this_player();
    object target;
    if (!me->query_temp("mingtasks/libu/target"))
    {
        return 0;
    }
    if (me->query_temp("mingtasks/libu/qinged")>2)
    {
        tell_object(me,"你已经尝试过请"+me->query_temp("mingtasks/libu/targetname")+"出山了。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    target=find_player(me->query_temp("mingtasks/libu/target"));
    if (!target||!living(target)||base_name(environment(target))!=base_name(environment(me)))
    {
        tell_object(me,"你要请的贤士不在这里。\n");
        return 1;
    }
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
int do_reward(string arg)
{
	object ruyi,me=this_player(),target;
	if (me->query("id")!="zine")
	{
		return 0;
	}
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
int do_query(string arg)
{
    object me=this_player();
    string who,msg,info;
    int mins;
    msg="\n\n";
    msg+=HEADER;
    info=HIY"              ★★★"+HIW+"大  明"+HIY+"★★★\n"NOR;
    msg+=info;
    msg+=LINE;
	if (stringp(arg))
	{
		if (wizardp(me)&&find_player(arg))
		{
			me=find_player(arg);
			if (!me->query("mingpin"))
			{
				me=this_player();
			}
		}
	}
	if (me==this_player())
	{
		who="你";
	}
	else 
	{
		who="他";
	}
	if (me->query("mingpin"))
    {
        info="  【品级】"+who+"是大明"+get_major(me->get_title(TITLE_MING2))+chinese_number(me->query("mingpin"))+"品官员。\n";
        msg+=info;
    }
    if (!me->query("mingpin"))
    {
        info="  【品级】无。\n";
        msg+=info;
    }
    if (me->query("ming/title"))
    {
        info="  【官职】"+who+"的官职是"+me->query("ming/title")+"。\n";
        msg+=info;
    }
    if (!me->query("ming/title"))
    {
        info="  【官职】无。\n";
        msg+=info;
    }
	if (me->get_title(TITLE_MING2))
    {
        info="  【散阶】"+who+"的散阶是"+me->get_title(TITLE_MING2)+"。\n";
        msg+=info;
    }
    if (!me->get_title(TITLE_MING2))
    {
        info="  【散阶】无。\n";
        msg+=info;
    }
	if (me->get_title(TITLE_MING3))
    {
        info="  【爵位】"+who+"的爵位是"+me->get_title(TITLE_MING3)+"。\n";
        msg+=info;
    }
    if (!me->get_title(TITLE_MING3))
    {
        info="  【爵位】无。\n";
        msg+=info;
    }
	if (me->query("mingpin")!=1)
	{
		if (me->query("ming/taskstime"))
		{
			mins=((int)me->query("mud_age")-(int)me->query("ming/taskstime"))/60;
			if (mins<1)
			{
				mins=1;
			}
			info="  【政务】"+who+"上次做大明任务是在"+chinese_number(mins)+"分钟之前。\n";
			if (mins>1440)
			{
				info="  【政务】"+who+"上次做大明任务是在很久之前了。\n";
			}
			msg+=info;
		}
		if (!me->query("ming/taskstime"))
		{
			info="  【政务】无任务记录。\n";
			msg+=info;
		}
	}
    if (me->query("ming/salary"))
    {
        mins=((int)me->query("mud_age")-(int)me->query("ming/salary"))/60;
        if (mins<1)
        {
            mins=1;
        }
        info="  【俸薪】"+who+"上次领取俸薪是在"+chinese_number(mins)+"分钟之前。\n";
        msg+=info;
    }
    if (!me->query("ming/salary"))
    {
        info="  【俸薪】无俸薪领取记录。\n";
        msg+=info;
    }
	if (me->query("mud_age")-me->query("ming/duty_salary")>=3600*48)
    {
        info="  【职贴】"+who+"现在就可以去通政司领取(ling)职贴。\n";
        msg+=info;
    }
    else
    {
		mins=(3600*48-(int)me->query("mud_age")+(int)me->query("ming/duty_salary"))/60;
        if (mins<1)
        {
            mins=1;
        }
        info="  【职贴】尚需"+chinese_number(mins)+"分钟后"+who+"才能领取职贴。\n";
        msg+=info;
    }
	if (me->query("mingpin")!=1)
	{
		if (me->query("ming/suikao"))
		{
			if (me->query("mud_age")-me->query("ming/suikao/time")<3600*24)
			info="  【岁考】"+who+"尚未到下次岁考的时候。\n";
			else
			info="  【岁考】"+who+"现在就可以进行岁考了。\n";
			msg+=info;
		}
		if (!me->query("ming/suikao"))
		{
			info="  【岁考】无上次岁考记录。\n";
			msg+=info;
		}
	}
    if (me->query("ming/special"))
    {
        if (me->query("ming/special")=="fengshui")
        {
            info="  【特技】风水。天机难测，万象始生。\n";
        }
        if (me->query("ming/special")=="tanlan")
        {
            info="  【特技】贪婪。贪狼一出，天下尽墨。\n";
        }
        if (me->query("ming/special")=="wenqu")
        {
            info="  【特技】文曲。文曲下凡，国泰民安。\n";
        }
        if (me->query("ming/special")=="tuji")
        {
            info="  【特技】突击。其势如火，疾不可阻。\n";
        }
        if (me->query("ming/special")=="qunzhan")
        {
            info="  【特技】群战。百战不屈，骄阳似我。\n";
        }
        if (me->query("ming/special")=="guwu")
        {
            info="  【特技】鼓舞。借势助力，顺乎天意。\n";
        }
        msg+=info;
    }
    if (!me->query("ming/special"))
    {
        info="  【特技】无。\n";
        msg+=info;
    }
    msg+=LINE;
    info="                   "+me->query("name")+"\n";
    msg+=info;
    msg+=TAIL;
    tell_object(this_player(),msg);
    return 1;
}

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
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!env->query("zhao"))
    {
        tell_object(me,"你开始仔细搜寻失落的残图，却一无所获。\n");
        return 1;
    }
    else
    {
        tell_object(me,"你找到失落于此地的残图，仔细注释后，觉得自己可以回户部交差了。\n");
        me->set_temp("mingtasks/hubu/task1finish",1);
        return 1;
    }

}

int do_position()
{
    object me=this_player();
    object ob,pl;
    mapping *titles;
    string col=HIG"|"NOR,msg=sprintf("\n%|122s%s%s",HBRED+HIW+"大明高级官员列表\n"+NOR,"\n",POSI_LINE),*msg_wen=({}),*msg_wu=({});
    int i;
    if (time()-this_object()->query("query_position")<5)
    {
		tell_object(me,"请勿频繁使用此命令查询。\n");
		return 1;
    }
    if (!ob=load_object("/d/yingtianfu/neicheng/shengzhi"))
    {
        tell_object(me,"吏部的人正忙着年末岁考，暂时无法受理你的查询。\n");
        return 1;
    }
    ob->restore();
    titles=ob->query("give_titles");
    if (!titles)
    {
        tell_object(me,"吏部的人正忙着年末岁考，暂时无法受理你的查询。\n");
        return 1;
    }
    for (i=0;i<sizeof(titles);i++)
    {
        if (titles[i]["owner"]!="")
        {
            if (titles[i]["pro"]=="文")
            {
                msg_wen+=({sprintf("%s%-50s%s",col,HIB+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"],col)});
            }
            else
            {
                msg_wu+=({sprintf("%s%-50s%s",col,HIR+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"],col)});
            }
        }
    }
	if (sizeof(msg_wen)>sizeof(msg_wu))
	{
		for (i=0;i<sizeof(msg_wu);i++)
		{
			msg+=msg_wen[i]+msg_wu[i]+"\n";
		}
		for (i=sizeof(msg_wu);i<sizeof(msg_wen);i++)
		{
			msg+=msg_wen[i]+sprintf("%s%-50s%s%|12s%s",col,HIR+""+NOR,col,"",col)+"\n";
		}
	}
	else if (sizeof(msg_wu)>sizeof(msg_wen))
	{
		for (i=0;i<sizeof(msg_wen);i++)
		{
			msg+=msg_wen[i]+msg_wu[i]+"\n";
		}
		for (i=sizeof(msg_wen);i<sizeof(msg_wu);i++)
		{
			msg+=sprintf("%s%|48s",col," ")+msg_wu[i]+"\n";
		}
	}
	else
	{
		for (i=0;i<sizeof(msg_wen);i++)
		{
			msg+=msg_wen[i]+msg_wu[i]+"\n";
		}
	}
	msg+=POSI_LINE;
    tell_object(me,msg);
	this_object()->set("query_position",time());
    return 1;
}

int refreshmingchat(object me)
{
    me->delete_temp("ming/stopchatting");
    return 1;
}

string get_pin(object pl)
{
    int pin;
    string msg;
	if (pl->query("mingpin"))
	{
		pin=pl->query("mingpin");
	}
    else if (pl->query("ming/tj/pin"))
    {
		pin=pl->query("ming/tj/pin");
    }
	else
	{
		pin=7;
	}
        if (pin>=5)
        {
            msg=CYN+get_major(pl->get_title(TITLE_MING2))+chinese_number(pin)+"品"+NOR;
        }
        else if (pin>2)
        {
            msg=RED+get_major(pl->get_title(TITLE_MING2))+chinese_number(pin)+"品"+NOR;
        }
        else
        {
            msg=HIR+get_major(pl->get_title(TITLE_MING2))+chinese_number(pin)+"品"+NOR;
        }
    return msg;
}
int do_players()
{
        object me=this_player();
        string dm_title,title,str, name, str1, *option,extra;
        object *ob, *list;
        int i, j,len;
        int *tmp, *tmp2;

        if(!wizardp(me) && time()-me->query_temp("scan_time") < 5)
                return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
        title="「" +HIW+ "大明在线官员列表" + NOR + "」";
        str =sprintf("%|94s\n", title);
        str += "———————————————————————————————————————\n";

        ob = filter_array(children(USER_OB), (: userp :));
        ob = filter_array(ob, (: environment :));
        ob = filter_array(ob, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
        list = sort_array(ob,"sort_user");
                j = sizeof(list);
                while( j-- ) 
                {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if( !me->visible(list[j]) ) continue;
                        if (!list[j]->query("ming/title")) continue;
						dm_title=list[j]->query("ming/title");
						if (list[j]->query("ming/pro")=="文")
						{
							dm_title=HIB+dm_title+NOR;
							extra=HBBLU+HIW+"●文臣●"+NOR;
						}
						else if (list[j]->query("ming/pro")=="武")
						{
							dm_title=HIR+dm_title+NOR;
							extra=HBRED+HIW+"●武将●"+NOR;
						}
						else if (list[j]->query("ming/tj/pin"))
						{
							dm_title=HIM+dm_title+NOR;
							extra=HBMAG+HIW+"●中官●"+NOR;
						}
						else
						{
							dm_title=HIG+dm_title+NOR;
							extra=HBGRN+HIW+"●散官●"+NOR;
						}
                        if (list[j]->query("mingpin"))
                        {
                            dm_title=HIW+"大明 "+get_pin(list[j])+" "+dm_title;
							if (list[j]->query("mingpin")==1)
							{
								dm_title=dm_title+HIY+"★"+NOR;
							}
							if (list[j]->query("ming/juewei_1"))
							{
								dm_title=dm_title+HIY+"★★★"+"  "+list[j]->get_title(TITLE_MING3)+NOR;
							}
							else if (list[j]->query("ming/juewei_2"))
							{
								dm_title=dm_title+HIY+"★★"+"  "+list[j]->get_title(TITLE_MING3)+NOR;
							}
							else if (list[j]->query("ming/juewei_3"))
							{
								dm_title=dm_title+HIY+"★"+"  "+list[j]->get_title(TITLE_MING3)+NOR;
							}
							else
							{
								if (list[j]->query("mingpin")==1)
								{
									dm_title=dm_title+HIY+"  ☆"+NOR;
								}
							}
                        }
						if (list[j]->query("ming/tj/pin"))
                        {
                            dm_title=HIW+"大明 "+get_pin(list[j])+" "+dm_title;
                        }
                        str+= sprintf("%|26s%s%|35s%s%s",COLOR_D->uncolor(list[j]->query("name"))+"("+capitalize(list[j]->query("id"))+")","|",extra,"|",dm_title);
                        str+="\n";
                        
                }
       
    

        str += "———————————————————————————————————————\n";
        
        tell_object(me,str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        if( !ob1->query("mingpin") && ob2->query("mingpin") )
                return -1;
        if( !ob2->query("mingpin") && ob1->query("mingpin") )
                return 1;
        if( ob1->query("mingpin") && ob2->query("mingpin") &&ob1->query("mingpin") !=ob2->query("mingpin"))
                return (int)ob2->query("mingpin") - (int)ob1->query("mingpin");
        if( ob1->query("ming/tj/pin") && ob2->query("ming/tj/pin")&&ob1->query("ming/tj/pin") !=ob2->query("ming/tj/pin") )
                return (int)ob2->query("ming/tj/pin") - (int)ob1->query("ming/tj/pin");
		if( ob1->query("ming/credit") && ob2->query("ming/credit") )
                return (int)ob1->query("ming/credit") - (int)ob2->query("ming/credit");
        return strcmp(ob2->query("id"), ob1->query("id"));
}

int do_daming(string arg)
{
    object me=this_player();
    object *ob;
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
    if (!arg)
    {
        arg="……";
    }
    if (!me->query("mingpin"))
    {
        return notify_fail("只有大明官员才可以使用这个频道。\n");
    }
    if (me->query_temp("ming/stopchatting"))
    {
        return notify_fail("歇会儿再说吧，老用大明朝廷的名义也不太合适。\n");
    }
    me->set_temp("ming/stopchatting",1);
    call_out("refreshmingchat",5,me);
    message("chat",HIW"【大明】"+me->query("name")+"("+capitalize(me->query("id"))+"):"+HIW+arg+"\n"+NOR,ob);
    return 1;
}

int specialpermit(object me)
{
    if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (time()>1304121599)//测试期
    {
        tell_object(me,"大明特技测试时间已过，请等待正式开放！\n");
        return 1;
    }
}

int afterkanyu(object me,string arg)
{
        object target,env,qt,goodplace;
		object uniob;
        env=environment(me);
        if (!arg)//测有额外加成xiulian的地方。
        {
           
            qt=load_object("/d/yingtianfu/neicheng/qintian");
            if (!qt)
            {
                tell_object(me,"现在推算不到修炼内功的灵地。\n");
                return 1;
            }
            if (qt)
            {
                if (qt->query("good_place"))
                {
                    goodplace=load_object(qt->query("good_place"));
                }
                if (!qt->query("good_place"))
                {
                    tell_object(me,"现在推算不到修炼内功的灵地。\n");
                    return 1;
                }
                
            }
            if (TASK_D->place_belong(env)!=TASK_D->place_belong(goodplace))
            {
                tell_object(me,"似乎在"+TASK_D->place_belong(base_name(goodplace))+"有帮助修炼内功的东西。\n");
                return 1;
            }
            if (TASK_D->place_belong(env)==TASK_D->place_belong(goodplace)&&base_name(env)!=base_name(goodplace))
            {
                tell_object(me,"似乎帮助修炼内功的东西周围的环境是\n"+goodplace->query("long")+"\n");
                return 1;
            }
            if (TASK_D->place_belong(env)==TASK_D->place_belong(goodplace)&& base_name(env)==base_name(goodplace))
            {
                tell_object(me,"就是这里了，似乎有帮助修炼内功的东西，你可以把它挖出(wachu)来。\n");
                return 1;
            }
        }
        if (arg)
        {
            target=find_player(arg);
            if (!target)
            {
                target=find_living(arg);
                if (!target)
                {
                tell_object(me,"似乎什么也没有找到。\n");
                return 1;
                }
            }
            if (wizardp(target))
            {
                tell_object(me,"这个人行踪不定，很难感应到。\n");
                return 1;
            }
			if(target->query("is_tasknpc"))
			{
				write(HIY"你费了半天的力气，就是推算不出"+target->name(1)+"的位置。\n"NOR);
				return 1;
			}

			if (target->query("hide"))
			{
				write(HIY"此人已经隐姓埋名，你费了半天的力气，就是推算不出其位置。\n"NOR);
				return 1;
			}
			if((objectp(uniob=target->query("uni_target")))&& (uniob->query("id")!=me->query("id"))) 
			{        
					write(HIY"你费了半天的力气，就是推算不出"+target->name(1)+"的位置。\n"NOR);
					return 1;
			}
            env=environment(target);
            {
                if (!env)
                {
                    tell_object(me,"这个人行踪不定，很难推算出。\n");
                    return 1;
                }
                else if (random(100)>1)
                {
                    tell_object(me,"你似乎推算出这个人身处的环境是\n"+env->query("long")+"。\n");
                    tell_object(target,"似乎有人在用风水之术窥测你的位置。\n");
                    return 1;
                }
                else
                {
                    tell_object(me,"这个人行踪不定，很难推算出。\n");
                    return 1;
                }
            }
        }
}
int do_kanyu(string arg)
{
    object me=this_player();
    object room=environment(me);
    if (me->query("ming/special")!="fengshui")
    {
        return 0;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    /*if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (me->query("ming/suikao/time")<me->query("age"))
    {
        tell_object(me,"今年参加完岁考才能继续使用大明特技。\n");
        return 1;
    }*/
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
    
    else
    {
        message_vision(WHT"$N掐起手指，默念着什么。\n"NOR,me);
        me->add_busy(3);
        remove_call_out("afterkanyu");
        call_out("afterkanyu",4,me,arg);
        return 1;
    }
}

int do_tandu()
{
    object me=this_player();
    object room=environment(me);
    object baoshi;
    string gem;
    int i,repute,lv;
    if (me->query("ming/special")!="tanlan")
    {
        return 0;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }
	/*
    if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (me->query("ming/suikao/time")<me->query("age"))
    {
        tell_object(me,"今年参加完岁考才能继续使用大明特技。\n");
        return 1;
    }*/
    if (time()-me->query("mingspecialtandu")<3600*6)
    {
        tell_object(me,"虽然贪污不会被问斩，频繁使用贪渎还是不好。\n");
        return 1;
    }
    if (me->query("repute")<=50000)
    {
        tell_object(me,"你的声望太低了，这时候再行贪墨之事，当心被朝廷革职查办。\n");
        return 1;
    }
    else
    {
        
            i = random(20);
			if (i < 3) gem = "yan";
			else if (i < 6) gem = "mu";
			else if (i < 9) gem = "sui";
			else if (i < 12) gem = "jin";
			else if (i < 15) gem = "bing";
			else if (i < 16) gem = "gu";
			else if (i < 17) gem = "yu";
			else if (i < 18) gem = "jiao";
			else gem = "jia";
            baoshi = new("/obj/gem/gem");
            baoshi->set_level(4900,9999,gem);
            lv=baoshi->query("level");
            if (lv==1)
            {
                repute=100;
            }
            if (lv==2)
            {
                repute=300;
            }
            if (lv==3)
            {
                repute=900;
            }
            if (lv==4)
            {
                repute=2700;
            }
            if (lv==5)
            {
                repute=8100-random(1000);
            }
            if (lv==6)
            {
                repute=24300-random(4000);
            }
            if (lv==7)
            {
                repute=72900-random(10000);
            }
            if (lv==8)
            {
                repute=218700-random(35000);
            }
            if (me->query("repute")>repute)
            {
                baoshi->move(me);
                me->add("repute",-repute);
                message_vision("$N任上大力搜刮民脂民膏，获得"+baoshi->query("name")+"一枚，其人声望大幅下降。\n",me);
                tell_object(me,"你搜刮到了一枚"+baoshi->query("name")+"。\n");
                tell_object(me,"因为搜刮民脂民膏的行为，你的声望下降了"+chinese_number(repute)+"点。\n");
                me->set("mingspecialtandu",time());
                return 1;
            }
		    if (me->query("repute")<=repute)
            {
                repute=me->query("repute")*10;
                me->set("repute",0);
                MONEY_D->pay_player(me,repute);
                tell_object(me,"你吩咐下属搜刮来的钱财已经全部打入你的账上，可惜你的声名变得一塌糊涂。\n");
                me->set("mingspecialtandu",time());
                return 1;
            }
            
        }
        return 1;
    
}

int wencaicheck(object me)
{
    int k=(int)me->query_temp("mingspecial/wencaiamount");
    if (me->is_fighting())
    {
        me->delete_temp("mingspecial/wencaiamount");
        me->add_temp("apply/intelligence",-k);
        tell_object(me,"战斗中你再也不能像平常那样文思泉涌了。\n");
        return 1;
    }
    remove_call_out("wencaicheck");
    call_out("wencaicheck",1,me);
    return 1;
}

int do_wencai()
{
    object me=this_player();
    object room=environment(me);
    int k;
    if (me->query("ming/special")!="wenqu")
    {
        return 0;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }/*
    if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (me->query("ming/suikao/time")<me->query("age"))
    {
        tell_object(me,"今年参加完岁考才能继续使用大明特技。\n");
        return 1;
    }*/
    if (me->query_temp("mingspecial/wencaiamount"))
    {
        tell_object(me,"你已经在使用文才特技了。\n");
        return 1;
    }
    
    else
    {
        k=(int)me->query_int();
        me->set_temp("mingspecial/wencaiamount",k);
        me->add_temp("apply/intelligence",k);
        message_vision(HIC"$N凝神思索，片刻之后，全是文采激扬。\n"NOR,me);
        remove_call_out("wencaicheck");
        call_out("wencaicheck",1,me);
        return 1;
    }
}


int tupo(object me)
{
    if (me)
    {
        me->delete_temp("mingspecial/tupo");
        tell_object(me,"突破特技使用过良久，你的气息终于调匀下来。\n");
        return 1;
    }
}
int do_tupo()
{
    object me=this_player();
    object room=environment(me);
    
    if (me->query("ming/special")!="tuji")
    {
        return 0;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }/*
    if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (me->query("ming/suikao/time")<me->query("age"))
    {
        tell_object(me,"今年参加完岁考才能继续使用大明特技。\n");
        return 1;
    }*/
    if (!me->is_fighting())
    {
        tell_object(me,"你不在战斗中，还要怎么突破？走过去就可以了。\n");
        return 1;
    }
    
    else
    {
        mapping exits;
        string *dirs;
        string dir;
        object dest;
        int i;

        if(!environment(me)) 
        {
            tell_object(me,"此地诡异非常，没有可以突破的方向。\n");
            return 1;
        }
        if(sizeof(environment(me)->query("exits")) == 0) 
        {
            tell_object(me,"此地诡异非常，没有可以突破的方向。\n");
            return 1;
        }
        if( !mapp(exits = environment(me)->query("exits")) ) 
        {
            tell_object(me,"此地诡异非常，没有可以突破的方向。\n");
            return 1;
        }
        if ((int)me->query("neili")<(int)me->query("max_neili")/2)
        {
            tell_object(me,"你的内力太少，根本无法突破！\n");
            return 1;
        }
        if (me->query_temp("mingspecial/tupo"))
        {
            tell_object(me,"你刚刚使用过突破特技，现在气血汹涌。\n");
            return 1;
        }
        if (random(100)>10)
        {
            dirs = keys(exits);
            dir = dirs[random(sizeof(dirs))];
            dest = exits[dir];
            message_vision(HIR"$N大喝一声，不顾敌人攻击，开始奋力突破。\n"NOR,me);
            me->set("neili",0);
            tell_room(dest,me->query("name")+"大喝一身，冲了过来。\n");
            me->move(dest);
            me->set_temp("mingspecial/tupo",1);
            remove_call_out("tupo");
            call_out("tupo",5+random(10),me);
            return 1;
        }
        else
        {
            tell_object(me,"你陷入战团，全未能突破出去。\n");
            me->set_temp("mingspecial/tupo",1);
            remove_call_out("tupo");
            call_out("tupo",3+random(5),me);
            return 1;
        }
        
    }
}

int buqu(object me)
{
    int ap,dp;
    if (me)
    {
        if (!me->is_fighting())
        {
        
            ap=(int)me->query_temp("mingspecial/buquap");
            dp=(int)me->query_temp("mingspecial/buqudp");
            me->delete_temp("mingspecial/buquap");
            me->delete_temp("mingspecial/buqudp");
            me->delete_temp("mingspecial/buqu");
            if (wizardp(me))
            {
                tell_object(me,"ap:"+ap+"dp:"+dp+"\n");
            }
            me->add_temp("apply/attack", -ap);
            me->add_temp("apply/damage", -ap);
            me->add_temp("apply/armor",  -dp);
            me->add_temp("apply/parry",  -dp);
            me->add_temp("apply/dodge",  -dp);
            tell_object(me,"力战之后，你不由精神略显萎靡。\n");
            if (me->query("neili")>=2000)
            {
                me->add("neili",-2000);
            }
            if (me->query("neili")<2000)
            {
                me->add("max_neili",-1);
            }
            return 1;
        }
        else
        {
            remove_call_out("buqu");
            call_out("buqu",1,me);
            return 1;
        }
    }
}

int do_buqu()
{
    object me=this_player();
    object room=environment(me);
    object *enemy; //对手
    int count,ap,dp; //对手的数量
    if (me->query("ming/special")!="qunzhan")
    {
        return 0;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (!me->is_fighting())
    {
        tell_object(me,"没有对手，你怎么发挥乱战中的优势呢？\n");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }/*
    if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (me->query("ming/suikao/time")<me->query("age"))
    {
        tell_object(me,"今年参加完岁考才能继续使用大明特技。\n");
        return 1;
    }*/
    if (me->query_temp("mingspecial/buqu"))
    {
        tell_object(me,"你正在使用群战特技。\n");
        return 1;
    }
    else
    {
        enemy=me->query_enemy();
        count=sizeof(enemy);
        ap=10-(int)me->query("mingpin");
        ap=ap*ap;
        dp=(10-(int)me->query("mingpin"))*count;
        if (wizardp(me))
            {
                tell_object(me,"ap:"+ap+"dp:"+dp+"\n");
            }
        me->add_temp("apply/attack", ap);
        me->add_temp("apply/damage", ap);
        me->add_temp("apply/armor",  dp);
        me->add_temp("apply/parry",  dp);
        me->add_temp("apply/dodge",  dp);
        me->set_temp("mingspecial/buquap",ap);
        me->set_temp("mingspecial/buqudp",dp);
        me->add("neili",500+random(500));
        message_vision(RED"$N陷入敌人围攻却傲然不惧，攻守之间反更见自如。\n"NOR,me);
        me->set_temp("mingspecial/buqu",1);
        remove_call_out("buqu");
        call_out("buqu",1,me);
        return 1;
    }
}

int do_jili()
{
    object me=this_player();
    object room=environment(me);
    int ap,dp,i,count=0;
    object *all=all_inventory(room);
    if (me->query("ming/special")!="guwu")
    {
        return 0;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    
    if (!me->query("mingpin"))
    {
        tell_object(me,"你在哪里捡的官印？\n");
        return 1;
    }/*
    if (me->query("mingpin")>4)
    {
        tell_object(me,"你的官品并不足以让你使用这个特技！\n");
        return 1;
    }
    if (me->query("ming/suikao/time")<me->query("age"))
    {
        tell_object(me,"今年参加完岁考才能继续使用大明特技。\n");
        return 1;
    }*/
    if (me->query("neili")<5000)
    {
        tell_object(me,"你此刻体力虚弱，不能使用鼓舞特技。\n");
        return 1;
    }
    else
    {
        ap=7-(int)me->query("mingpin");
        ap=ap*ap;
        dp=10-(int)me->query("mingpin");
        dp=dp*dp;
        message_vision(MAG"$N慷慨陈词：国家危难之际，匹夫当以颈上热血以报！\n"NOR,me);
        me->add("neili",-2000);
        me->add_busy(random(5));
        for (i=0;i<sizeof(all);i++)
        {
            if ((all[i]->query("mingpin")||all[i]->query("ming/tj/pin")||(all[i]->is_army()&&all[i]->query("side")=="ming"))&&!all[i]->query_temp("mingspecial/jiligot"))
            {
                count=count+1;
                if (all[i]->is_character())
                {
                    all[i]->add_temp("apply/attack", ap);
                    all[i]->add_temp("apply/damage", ap);
                    all[i]->add_temp("apply/armor",  dp);
                    all[i]->add_temp("apply/parry",  dp);
                    all[i]->set_temp("mingspecial/jiligot",1);
                    all[i]->set_temp("mingspecial/jiliap",ap);
                    all[i]->set_temp("mingspecial/jilidp",dp);
                    all[i]->apply_condition("damingjili", 2+random(15-(int)me->query("mingpin")));
                    tell_object(all[i],"听了"+me->query("name")+"的鼓舞之辞，你不由热血澎湃起来。\n");
                }
                if (all[i]->is_army()&&me->query("ming/energy")>10)
                {
                    me->add("ming/energy",-10);
                    tell_object(me,"你消耗了10点行动力，激励了"+all[i]->query("name")+"的士气！\n");
                    all[i]->add("shiqi",10);
                    message_vision(HIW"$N中众人应道：“天佑大明！”\n"NOR,all[i]);
                }
            }
        }
        if (count==0)
        {
            tell_object(me,"你喊了半天，发现周身根本没有大明的人！\n");
        }
        return 1;
    }
}


