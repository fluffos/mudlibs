//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include <title.h>
#define HEADER HIY"┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR
#define TAIL   HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR 
#define LINE   HIY"┃━━━━━━━━━━━━━━━━━━━━━━━━━┃\n"NOR
#define SZ   HIY"██████████████████████████████████████████████\n"NOR
#define POSI_LINE HIG"--------------------------------------------------------------------------------------------------\n"NOR
#include "/d/yingtianfu/neicheng/npc/promote.h"

void create()
{
        set("short", "大通街");
        set("long", 
"这里一条正阳门前的一条大街，两帮是一些清水衙门。\n"

        );
        set("exits", ([
                
              
                
                "northwest" : __DIR__"tongzhen",
                "southwest" : __DIR__"qintian",
                "west" : __DIR__"jinyiwei",
                "east" : __DIR__"yudao1",
                
                
                
        ]));
        set("objects", ([
		
        __DIR__"npc/daming_npcx" : 1,
	    ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

int to_do_list(object me);
int is_ming_player(object me)
{
	if (!me)
    {
        return 0;
    }
    if (!userp(me))
    {
        return 0;
    }
    if (!me->query("mingpin"))
    {
        return 0;
    }
	return 1;
}
int modify_daming(object me)
{
    string vice_title,old_title="";
	string *colors=({HIR,RED,HIW,WHT,HIB,BLU,HIY,YEL,HIG,GRN,HIC,CYN,HIM,MAG});
	if (!is_ming_player(me))
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
int checK_position(object me)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
	mapping *title;
	if (!is_ming_player(me))
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
int judge_extra_room(object me)
{
	object ming=load_object("/d/yingtianfu/neicheng/shengzhi");
    string *names=({});
	if (!is_ming_player(me))
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
int notice(object me)
{
    int i,num,news_num,flag=0;
    mapping* notes;
    string msg;
    object notice;
    if (!is_ming_player(me))
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
int set_ming_title(object me)
{
    string title,*titles;
    if (!is_ming_player(me))
    {
        return 1;
    }
    /*title=TITLE_MING1;
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
		
    }*///不再强制要求使用大明title
	if (me->query("mingpin"))
	back_me_up(me);
    return 1;
}
int record(object me)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    string depart_name,*names=({});
    int i,flag=0;
    if (!is_ming_player(me))
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
int ability_gene(object me)
{
    int n,tongyu,lianbing,zhengwu,renji,zhihui,qinmian,hr_degree;
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    if (!is_ming_player(me))
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
int ability_improve(object me)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    string depart_name,msg;
    int i,flag=0;
    if (!is_ming_player(me))
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
            to_do_list(me);
        }
    }
    return 1;
}
int to_do_list(object me)
{
    object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i,flag=0;
    string msg="现在急需要你处理的事务：\n";
    if (!is_ming_player(me))
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
int valid_promote(object me)
{
	object qt;
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
	if (!is_ming_player(me))
    {
        return 1;
    }
	pin=me->query("mingpin")-1;
    if (pin==0)
    {
        return 1;
    }
	pro=me->query("ming/pro");
    if (!pro)
    {
        if (random(100)>49)
        {
			me->set("ming/pro","武");
        }
		else
		{
			me->set("ming/pro","文");
		}
		pro=me->query("ming/pro");
    }
	if (me->query("ming/credit")==0)
	{
		if (me->query("ming/pro")=="文"&&me->query("mingpin")<9)
		{
			me->set("mingpin",10);
			tell_object(me,"因为长期无所作为，你被一捋到底，贬官至"+chinese_number(me->query("mingpin")-1)+"品。\n");
			position_me(me);
		}
		if (me->query("ming/pro")=="武"&&me->query("mingpin")<7)
		{
			me->set("mingpin",8);
			tell_object(me,"因为长期无所作为，你被一捋到底，贬官至"+chinese_number(me->query("mingpin")-1)+"品。\n");
			position_me(me);
		}

		
		return 1;
	}
	if (!can_promote(me))
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
    if (me->query("ming/credit")<require["credit"]-(int)me->query("ming/designate_obtain")*require["designate_effect"])
    {
        return 1;
    }
	if (me->query("mingpin")==2&&!me->query("ming/2to1"))
	{
		return 1;
	}
	position_me(me);
	qt=load_object("/d/yingtianfu/neicheng/qintian");
	if (qt->query("promote_list"))
	{
		promote_list=qt->query("promote_list");
	}
	promote_list+=({me->query("name")+" "});
	qt->set("promote_list",promote_list);
	return 1;
}
int check_duty(object me)
{
	if (!me||!me->get_title(TITLE_MING2))
	return 1;
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (me->get_title(TITLE_MING2)==sanjie_title[i]["title"]&&me->query("ming/pro")!=sanjie_title[i]["pro"]&&me->query("mingpin")!=1)
		return reset_me_duty(me);
	}
	return 1;
}
int check_in(object me)
{
	call_out("check_duty",5,me);
	call_out("modify_daming",1,me);
	call_out("checK_position",4,me);
    call_out("judge_extra_room",2,me);
    call_out("notice",3,me);
    call_out("set_ming_title",2,me);
    call_out("record",1,me);
    call_out("ability_improve",2,me);
    call_out("to_do_list",6,me);
	call_out("valid_promote",10,me);
}