//plan.c    ☆侠客☆(Xkxmud)编写的★侠客梦计划书★（原型出自bbsboard，重写了全部函数）
//☆侠客☆(Xkxmud)
//      /adm/object/plan.c
//Time:001_2002.10.05
//Time:002_2002.10.06
//Time:003_2002.10.07

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;  

#define MAX_PLAN		400		//最大计划数
#define DEBUG			1		//有关整理
#define MAX_TITLE_LEN	30		//标题长度限制
#define SET_LVL		"(admin)"	//管理巫师级别（admin）
#define COM_LVL		"(immortal)"	//普通巫师级别（immortal）
#define BAN_LVL		"(virtuoso)"	//禁止巫师级别（virtuoso）
#define PLAN_DIR		"/data/plan/"	//存储的路径
#define PLAN_FILENAME	"plan"		//存储的文件名
#define SET_RUMOR		1		//对谣言这部分加个限定，不用的话改成别的。

void init();
string* set_id= ({
        "jhy",
        "xkxmud",
});
string* ban_id= ({
});
int temp;					//定义几个变量，作为某些地方使用的临时变量
string temp1,temp2,temp3;
void do_dest()
{
	object me=this_player(),ob=this_object();
	if(SET_RUMOR==1)
		message("channel:rumor",HIM"【谣言】"+ "某人看到有人鬼鬼祟祟地从"+ob->query("temp")+"身上偷走了一件布衣！\n"NOR,users());
	destruct(ob);
}
string query_save_file()
{
	return PLAN_DIR+PLAN_FILENAME ;
}
string replace_color(string arg,int flag)
{
	arg = replace_string(arg,"$BLK$",flag?BLK:"");
	arg = replace_string(arg,"$RED$",flag?RED:"");
	arg = replace_string(arg,"$GRN$",flag?GRN:"");
	arg = replace_string(arg,"$YEL$",flag?YEL:"");
	arg = replace_string(arg,"$BLU$",flag?BLU:"");
	arg = replace_string(arg,"$MAG$",flag?MAG:"");
	arg = replace_string(arg,"$CYN$",flag?CYN:"");
	arg = replace_string(arg,"$WHT$",flag?WHT:"");
	arg = replace_string(arg,"$HIR$",flag?HIR:"");
	arg = replace_string(arg,"$HIG$",flag?HIG:"");
	arg = replace_string(arg,"$HIY$",flag?HIY:"");
	arg = replace_string(arg,"$HIB$",flag?HIB:"");
	arg = replace_string(arg,"$HIM$",flag?HIM:"");
	arg = replace_string(arg,"$HIC$",flag?HIC:"");
	arg = replace_string(arg,"$HIW$",flag?HIW:"");
	arg = replace_string(arg,"$HBRED$",flag?HBRED:"");
	arg = replace_string(arg,"$HBGRN$",flag?HBGRN:"");
	arg = replace_string(arg,"$HBYEL$",flag?HBYEL:"");
	arg = replace_string(arg,"$HBBLU$",flag?HBBLU:"");
	arg = replace_string(arg,"$HBMAG$",flag?HBMAG:"");
	arg = replace_string(arg,"$HBCYN$",flag?HBCYN:"");
	arg = replace_string(arg,"$HBWHT$",flag?HBWHT:"");
	arg = replace_string(arg,"$BBLK$",flag?BBLK:"");
	arg = replace_string(arg,"$BRED$",flag?BRED:"");
	arg = replace_string(arg,"$BGRN$",flag?BGRN:"");
	arg = replace_string(arg,"$BYEL$",flag?BYEL:"");
	arg = replace_string(arg,"$BBLU$",flag?BBLU:"");
	arg = replace_string(arg,"$BMAG$",flag?BMAG:"");
	arg = replace_string(arg,"$BCYN$",flag?BCYN:"");
	arg = replace_string(arg,"$BLINK$",flag?BLINK:"");
	arg = replace_string(arg,"$NOR$",flag?NOR:"");
	if(flag)	arg+=NOR;
	return arg;
}
void create()
{
	seteuid(getuid()); 
	set_name(HIR"★侠客梦计划书★"NOR,({"xkm plan","plan book","plan"}));
	set("long",read_file("/doc/help/xkx"));
	set("unit","本");
	set("no_drop",HIR"作为★侠客梦★的巫师，怎么可以乱丢东西，而且还是这么重要的计划书？？\n"NOR);
	set("no_get",HIG"★侠客梦★的计划书，随随便便就可以捡得起来吗？？\n"NOR);
	set("no_give",HIC"作为★侠客梦★的巫师，怎么可以把自己的工作计划书给别人呢？？\n"NOR);
	set("value", 0);
	setup();
}
string app(object me)
{
	//这几个判断的顺序不能随便改动，改变了可能判断不准。
	for(int i=0;i<sizeof(ban_id);i++)		//一些特殊 id 巫师即使权限不受限制，也没有使用的权力，正常情况下可以为空。
	{
		if(me->query("id")==ban_id[i])	return "ban";
	}
	for(int i=0;i<sizeof(set_id);i++)		//保留给某些特殊 id 巫师，即使权限不满足，也可以进行操作。
	{
		if(me->query("id")==set_id[i])	return "set";
	}
	if(SECURITY_D->get_status(me)==SET_LVL)
		return "set";
	else if(wiz_level(me)<wiz_level(COM_LVL)||SECURITY_D->get_status(me)==BAN_LVL)
		return "ban";
	else return "com";
}	
string short()
{
	object me=this_player();
	mapping *plans;
	int i,j,unread,last_read_time;
	plans=query("plans");
	if(!pointerp(plans)||!sizeof(plans))
		return ::short()+"[ 没有任何计划 ]";
	if(this_player())
	{
		last_read_time=(int)this_player()->query("board_last_read/"+(string)query("board_id"));
		for(unread=0,i=sizeof(plans)-1;i>=0;i--)
		{
			if(plans[i]["time"]<=last_read_time&&(plans[i]["owner"]==me->query("id")||app(me)=="set"))	break;
			if(plans[i]["owner"]==me->query("id")||app(me)=="set")	unread++;
		}
	}
	temp=0;
	for(i=0;i<sizeof(plans);i++)	if(plans[i]["owner"]==me->query("id")||app(me)=="set")	temp++;
	if(unread)
		return sprintf(HIC"%s"NOR" [ "HIW"%d"NOR" 个计划，"HIR"%d"NOR" 篇未读 ]",::short(),temp,unread);
	else
		return sprintf("%s [ "HIW"%d"NOR" 个计划 ]",::short(),temp);
}
string long()
{
	object me=this_player();
	mapping *plans;
	int me_author=1;
	int i,j,k,last_time_read;
	string msg,myid,type="";
	restore();
	plans=query("plans");
	if(!pointerp(plans)||!sizeof(plans))	return query("long");
	if(app(me)=="set")	me_author=0;
	for(i=0;i<sizeof(plans);i++)
	{
		if(plans[i]["owner"]==me->query("id"))
		{
			msg=query("long")+HIW"编号━━计划命题━━━━━━━━作者━━━追加内容━━━时间━━━\n"NOR;
			me_author=0;
			break;
		}
	}
	if(me_author!=0)	return query("long");
	last_time_read=this_player()->query("board_last_read/"+(string)query("board_id"));
	for(i=0;i<sizeof(plans);i++)
	{
		if(plans[i]["owner"]==me->query("id")||app(me)=="set")
		{
			if(app(me)=="set")	temp1=sprintf("%d"NOR"]",i+1);
			else
			{
				for(temp=0,k=0;k<=i;k++)	if(plans[k]["owner"]==me->query("id"))	temp++;
				temp1=sprintf("%d"NOR"]",temp);
			}				
			temp=strlen(temp1);
			for(k=0;k<15-temp;k++)	temp1+=" ";
			temp2=sprintf("%s",plans[i]["title"]);
			temp=strlen(temp2);
			for(k=0;k<=30-temp;k++)	temp2+=" ";
			temp3=sprintf("%s",plans[i]["author"]);
			temp=strlen(temp3);
			for(k=0;k<=12-temp;k++)	temp3+=" ";
			msg+=sprintf("%s["WHT"%s"NOR"　%s　%s　"WHT"%+5d"NOR"　　　　[%s]\n",
				(plans[i]["time"]>last_time_read?HIY:""),temp1,temp2,
				temp3,sizeof(plans[i]["re"]),ctime(plans[i]["time"])[0..15]);
			for (j=0;j<sizeof(plans[i]["re"]);j++)
			{
				if(app(me)=="set")	temp1=sprintf("%d.%d"NOR"]",i+1,j+1);
				else
				{
					for(temp=0,k=0;k<=i;k++)	if(plans[k]["owner"]==me->query("id"))	temp++;
					temp1=sprintf("%d.%d"NOR"]",temp,j+1);
				}				
				temp=strlen(temp1);
				for(k=0;k<15-temp;k++)	temp1+=" ";
				temp2=sprintf("%s",plans[i]["re"][j]["title"]);
				temp=strlen(temp2);
				for(k=0;k<=30-temp;k++)	temp2+=" ";
				temp3=sprintf("%s",plans[i]["re"][j]["author"]);
				temp=strlen(temp3);
				for(k=0;k<=12-temp;k++)	temp3+=" ";
				if(plans[i]["owner"]==plans[i]["re"][j]["owner"])	type="补充及修正";
				else if(wiz_level(plans[i]["lvl"])<wiz_level(plans[i]["re"][j]["lvl"]))	type="回复及批示";
				else	type="回复及建议";
				msg+=sprintf("%s["WHT"%s"NOR"　%s　%s　"WHT"%5s"NOR"　[%s]\n",
					(plans[i]["re"][j]["time"]>last_time_read?HIY:""),temp1,temp2,
					temp3,type,ctime(plans[i]["re"][j]["time"])[0..15]);
			}
		}
	}
	msg+=HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
	return msg;
}
void done_post(object me,mapping plan,string text)
{
	mapping *plans;
	string msg="";
	int i,j;
	restore();
//支持签名和颜色，用 set signature 设定，可以有颜色
	if(me->query("env/signature"))
		plan["msg"]=replace_color(text+"\n────────────────────────────────\n"+me->query("env/signature"),1);
	else plan["msg"]=replace_color(text,1);
	plans=query("plans");
	if(!pointerp(plans)||!sizeof(plans))	plans=({plan});
	else plans+=({plan});
	set("plans",plans);
	save();
	tell_object(me,HIW"新计划已经写好，看看有没有错，加油哦！！\n"NOR);
	return;
}
void done_re(object me,mapping report,int project,string text)
{
	mapping *plans,*reports;
	restore();
	if(me->query("env/signature"))
	{
		report["msg"]=replace_color(text+"\n---------------------------------\n"+me->query("env/signature"),1);
	}
	else report["msg"]=replace_color(text,1);
	plans=query("plans");
	reports=plans[project]["re"];
	if(!arrayp(reports))	reports=({report});
	else reports+=({report});
	plans[project]["re"]=reports;
	plans[project]["time"]=time();
	set("plans",plans);
	if(app(me)=="set")	tell_object(me, HIW"批示完毕！！\n"NOR);
	else tell_object(me, HIW"追加内容完毕，加油哦！！\n"NOR);
	save();
	return;
}
int do_post(string arg)
{
	mapping plan;
	object me=this_player();
	if(!arg)	return notify_fail(HIC"请给你的新计划指定一个标题。\n"NOR);
	if(strlen(arg)>MAX_TITLE_LEN)
		return notify_fail(HIC"计划的命题短一些，最好让人一目了然，谢谢！！\n"NOR);
//安全系统的一部分，正常情况下不会出现这种事
	if(app(me)=="ban")
	{
		init();
		return notify_fail(HIB"你是谁呀？能看到这一句证明你好厉害，不过还是不行！！\n你没有这个权限！\n"NOR);
	}
/*开辟空间，plan 包括六个元素{title,owner,author,time,msg,lvl} 在不确定时可以用 plan=([]) 代替，作用相同*/
	plan=allocate_mapping(6);
	plan["title"]=arg;
	plan["owner"]=me->query("id");
	plan["author"]=me->query("name");
	plan["lvl"]=SECURITY_D->get_status(me);
	plan["time"]=time();
	me->edit((:done_post,me, plan:));
	return 1;
}
int do_re(string arg)
{
	int num,i;
	string title;
	mapping plan, *plans;
	object me=this_player();
	if(!arg||sscanf(arg,"%d.%s",num,title)<1)
		return notify_fail(HIC"指令格式：replan <计划编号>.<回复标题>\n"NOR);
	plans=query("plans");
	if(app(me)!="set")
	{
		for(temp=0,i=0;i<sizeof(plans);i++)
			if(plans[i]["owner"]==me->query("id"))	temp++;
		if(temp==0||temp<num)	return notify_fail(HIC"你的计划书上目前没有这条计划！！\n"NOR);
		for(temp=0,i=0;i<sizeof(plans);i++)
		{
			if(plans[i]["owner"]==me->query("id"))	temp++;
			if(temp==num)
			{
				num=i+1;
				break;
			}
		}
	}
	if(!arrayp(plans)||num<1||num>sizeof(plans))
		return notify_fail(HIC"你的计划书上目前没有这条计划！！\n"NOR);
	if(strlen(title)>MAX_TITLE_LEN)
		return notify_fail(HIC"追加内容的标题短一些，最好让人一目了然，谢谢！！\n"NOR);
	if(app(me)=="ban")
	{
		init();
		return notify_fail(HIB"你是谁呀？能看到这一句证明你好厉害，不过还是不行！！\n你没有这个权限！\n"NOR);
	}
	if(app(me)!="set")	write(HIC"你要对自己的计划做出修正或补充吗？加油啊！！\n"NOR);
	if(!title)
	{
		if(app(me)=="set")	title="Re:"+plans[num-1]["title"];
		else title=sprintf("ADD:%d",temp);
	}
	plan=allocate_mapping(6);
	plan["title"]=title;
	plan["owner"]=me->query("id");
	plan["author"]=me->name(1);
	plan["lvl"]=SECURITY_D->get_status(me);
	plan["time"]=time();
	me->edit((:done_re,me,plan,num-1:));
	return 1;
}
int do_read(string arg)
{
	object me=this_player();
	int num, rep, last_read_time,i,last;
	mapping *plans;
	string myid,msg,file;
	last_read_time=me->query("board_last_read/"+query("board_id"));
	myid=query("board_id");
	plans=query("plans");
	if(!pointerp(plans)||!sizeof(plans))
		return notify_fail(HIC"你的计划书上目前没有这条计划，加油哦！！\n"NOR);
	if(!arg)	return notify_fail(HIC"指令格式：readplan <计划编号>[.<回复编号>]\n"NOR);
	else if(sscanf(arg,"%d.%d",num,rep)==2)
	{
		if(num<1||num>sizeof(plans))
			return notify_fail(HIC"你的计划书上目前没有这条计划，加油哦！！\n"NOR);
		else
		{
			if(app(me)!="set")
			{
				for(temp=0,i=0;i<sizeof(plans);i++)
					if(plans[i]["owner"]==me->query("id"))	temp++;
				if(temp==0||temp<num)	return notify_fail(HIC"你的计划书上目前没有这条计划！！\n"NOR);
				for(temp=0,i=0;i<sizeof(plans);i++)
				{
					if(plans[i]["owner"]==me->query("id"))	temp++;
					if(temp==num)
					{
						num=i+1;
						break;
					}
				}
			}
			else temp=num;		
			num--;
		}
		if(rep<1||rep>sizeof(plans[num]["re"]))	return notify_fail(HIC"没有这条追加内容。\n"NOR);
		else rep--;
		me->start_more(sprintf(
			"[ "HIW"编号："NOR"%3d | "HIW"回复编号："NOR"%3d] [ "HIW"原题："NOR"%-s ] \n"
			"[ "HIW"回复标题："NOR"%-s ]\n────────────────────────────────\n"
			"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
			HIW"作者："NOR" %s]\n",
			temp, rep + 1,
			plans[num]["title"],
			plans[num]["re"][rep]["title"],
			plans[num]["re"][rep]["msg"],
			ctime(plans[num]["re"][rep]["time"]),
			plans[num]["re"][rep]["author"]+"("+
			plans[num]["re"][rep]["owner"]+")"));
		if(plans[num]["time"]>last_read_time)
			me->set("board_last_read/"+query("board_id"),plans[num]["time"]);
		return 1;
	}
	else if(!sscanf(arg,"%d",num))
		return notify_fail(HIC"你要读第几个计划的追加内容？\n"NOR);
	if(num<1||num>sizeof(plans))
		return notify_fail(HIC"没有这个计划。\n"NOR);
	if(app(me)!="set")
	{
		for(temp=0,i=0;i<sizeof(plans);i++)
			if(plans[i]["owner"]==me->query("id"))	temp++;
		if(temp==0||temp<num)	return notify_fail(HIC"你的计划书上目前没有这条计划！！\n"NOR);
		for(temp=0,i=0;i<sizeof(plans);i++)
		{
			if(plans[i]["owner"]==me->query("id"))	temp++;
			if(temp==num)
			{
				num=i+1;
				break;
			}
		}
	}
	else temp=num;		
	num--;
	msg=sprintf(
		"[ "HIW"编号："NOR"%3d ] [ "HIW"作者："NOR"%s ] [ "HIW"时间："NOR"%-9s ]\n[ "
		HIW"标题："NOR"%-s ]\n────────────────────────────────\n%s\n"
		"──────────────────────────["HIW" 本 篇 完 "NOR"]\n",
		temp,plans[num]["author"]+"("+plans[num]["owner"]+")",ctime(plans[num]["time"])[0..9],
		plans[num]["title"],	plans[num]["msg"],);
	me->start_more(msg);
	if(plans[num]["time"]>last_read_time)
		me->set("board_last_read/"+query("board_id"),plans[num]["time"]);
	return 1;
}
int delete_post(string arg)
{
	object me=this_player();
	mapping *plans;
	int num,re_num,i;
	if(!arg||sscanf(arg,"%d.%d",num,re_num)<1)
		return notify_fail(HIC"指令格式：delplan <计划编号>[.<回复编号>]\n"NOR);
	plans=query("plans");
	if(!arrayp(plans)||num<1||num>sizeof(plans))
		return notify_fail(HIC"你的计划书上目前没有这条计划！！\n"NOR);
	else if(re_num)
	{
		if(re_num<1||!arrayp(plans[num-1]["re"])||re_num >sizeof(plans[num-1]["re"]))
			return notify_fail(HIC"没有这条追加内容。\n"NOR);
		else
		{
			if(app(me)!="set")
			{
				for(temp=0,i=0;i<sizeof(plans);i++)
					if(plans[i]["owner"]==me->query("id"))	temp++;
				if(temp==0||temp<num)	return notify_fail(HIC"你的计划书上目前没有这条计划！！\n"NOR);
				for(temp=0,i=0;i<sizeof(plans);i++)
				{
					if(plans[i]["owner"]==me->query("id"))	temp++;
					if(temp==num)
					{
						num=i+1;
						break;
					}
				}
			}
			else temp=num;		
			num--;
			re_num--;
			if(plans[num]["re"][re_num]["owner"]!=me->query("id")
				&&(app(me)!="set"||wiz_level(me)<wiz_level(plans[num]["re"][re_num]["lvl"])))
				return notify_fail(HIC"这条追加内容不是你写的，你权限不足。\n"NOR);
			else
			{
				if(sizeof(plans[num]["re"])==1)	plans[num]["re"]=({});
				else	plans[num]["re"]=plans[num]["re"]-({plans[num]["re"][re_num-1]});
				set("plans",plans);
				save();
				write(HIR"删除第 "+temp+" 号计划的第 "+(re_num+1)+" 号追加内容....Ok。\n"NOR);
				restore();
				return 1;
			}
		}
	}
	else
	{
		if(app(me)!="set")
		{
			for(temp=0,i=0;i<sizeof(plans);i++)
				if(plans[i]["owner"]==me->query("id"))	temp++;
			if(temp==0||temp<num)	return notify_fail(HIC"没有这个计划。\n"NOR);
			for(temp=0,i=0;i<sizeof(plans);i++)
			{
				if(plans[i]["owner"]==me->query("id"))	temp++;
				if(temp==num)
				{
					num=i+1;
					break;
				}
			}
		}
		else temp=num;		
		num--;
		if(plans[num]["owner"]!=me->query("id")
			&&(app(me)!="set"||wiz_level(me)<wiz_level(plans[num]["lvl"])))
			return notify_fail(HIC"这个计划不是你写的，你权限不足。\n"NOR);
		if(sizeof(plans)==1)	plans=({});
		else	plans=plans-({plans[num-1]});
		set("plans",plans);
		save();
		write(HIR"删除第 "+temp+"号计划....Ok。\n"NOR);
		restore();
		return 1;
	}
}
int do_list()
{
	write(long());
	return 1;
}
int do_help()
{
	write(HIC+@HELP
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
⒈添加计划：	postplan <计划标题>　  
⒉回复：	replan <计划编号>.<回复标题>	
⒊阅读：	readplan <计划编号>[.<回复编号>]
⒋删除：	delplan <计划编号>[.<回复编号>]
⒌清单：	listplan
⒍使用方法：	helplan
⒎支持签名：	set signature（可以使用颜色代码）
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
HELP+NOR);
	return 1;
}
void init()
{
	object me=this_player(),ob=this_object();
	if(app(me)=="ban")
	{
		ob->set_name("布衣",({"cloth"}));
		ob->delete("long");
		ob->set("temp",me->query("name"));
		remove_call_out("do_dest");
		call_out("do_dest", 1);
	}
	else
	{
		restore();
		add_action("do_post","postplan");
		add_action("do_re","replan");
		add_action("do_read","readplan");
		add_action("delete_post","delplan");
		add_action("do_list","listplan");
		add_action("do_help","helplan");
	}
}
int query_autoload()
{
	object me=this_player();
	if(app(me)!="ban")	return 1;
}