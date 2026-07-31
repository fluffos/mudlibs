//rwm.c    ☆侠客☆(Xkxmud)为★侠客梦★特别制作的★侠客梦★巫师任务管理器
//☆侠客☆(Xkxmud)
//      /adm/object/rwm.c
//Time:001_2002.10.17
//Time:002_2002.10.18
//Time:003_2002.10.19
//Time:004_2002.10.20
//Time:005_2002.10.21

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;  

#define RENWU_DIR		"/data/"		//存储的路径
#define RENWU_FILENAME	"renwu"		//存储的文件名
#define SET_LVL		"(wizard)"		//管理巫师级别（admin）
#define SET_ID		"jhy"			//总负责人：海洋(jhy)
#define MAX_GTASK		5000			//每组说明的最大长度
mapping wizhood=([
	"(admin)":		HIW"【 天　帝 】"NOR,
	"(arch)":		HIY"【 大　神 】"NOR,
	"(wizard)":		HIG"【 神　仙 】"NOR,
	"(designer)":		GRN"【 天　师 】"NOR,
	"(creator)":		HIC"【 天　仙 】"NOR,
	"(caretaker)":	WHT"【 天　官 】"NOR,
	"(virtuoso)":		HIM"【 散　仙 】"NOR,
	"(apprentice)":	MAG"【 仙　人 】"NOR,
	"(immortal)":		CYN"【 半　仙 】"NOR,
	"(player)":		NOR"【 民　兵 】",
]);
//相关函数
void init();									//初始化函数
int user(string arg);							//判断是否有某 id 玩家存在
int group_master(object me);						//判断某玩家是否为某一组的组长
int group_member(string id,int num);					//判断某 id 是否为某一组组员
void desc();									//各组内按级别排序
int do_addgroup(string arg);						//添加组
int do_disgroup(string arg);						//删除组
int do_pgm1(string arg);							//任命某 id 为某组组长
int do_pgm2(string arg);							//添加某 id 为某组组员
int do_dismiss(string arg);							//解除某组内某一成员的职务
int do_function(string arg);						//给某组某 id 任命职务
int do_task(string arg);							//给某组某 id 分配任务
int do_grouptask(string arg);						//给某一小组分配任务及工作范围
string query_save_file()
{
	return RENWU_DIR+RENWU_FILENAME ;
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
	arg = replace_string(arg,"$HIB$",flag?HIG:"");
	arg = replace_string(arg,"$HIY$",flag?HIY:"");
	arg = replace_string(arg,"$HIR$",flag?HIR:"");
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
	set_name(HIR"★侠客梦★巫师任务管理器"NOR,({"rwm","renwu manager"}));
	set("unit","个");
	restore();
	set("value", 0);
	setup();
}
string short()
{
	mapping *groups;
	groups=query("groups");
	restore();
	desc();
	if(!pointerp(groups)||sizeof(groups)<1)
		return ::short()+HIC"[还没有巫师分组]"NOR;
	else
		return sprintf("%s "HIC"[现有"HIW" %d "HIC"个巫师分组]"NOR,::short(),sizeof(groups));
}
string long()
{
	int a,b,c,d,e;
	mapping *groups,*wizs;
	string temp1,temp2,temp3,temp4;
	object body,me=this_player();
	mapping wizstatus=SECURITY_D->query_wizstatus();
	string msg1=HIB"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"NOR;
	string msg2=HIW"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
	string msg3=HIR"┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅\n"NOR;
	restore();
	desc();
	groups=query("groups");
	write(HIR"★侠客梦★巫师组工作安排：\n"NOR);
//	write(msg1);
	write(msg2);
	printf(HIG"%s　%s　%s　%s\n"NOR,"【巫师等级】","【 巫　师 】","【 职　务 】","【负责范围及任务】");
	write(msg2);
	if(!wizstatus[SET_ID])	temp1=wizhood["(player)"];
	else	temp1=wizhood[wizstatus[SET_ID]];
	body=LOGIN_D->find_body(SET_ID);
	if(objectp(body)&&interactive(body)&&me->visible(body))
	temp2=HIB"("HIG+SET_ID+HIB")";
	else	temp2=HIB"("+SET_ID+")"NOR;
	a=strlen(temp2);
	for(b=0;b<20-a;b++)	temp2+=" ";
	temp3=HIR"【总负责人】"NOR;
	temp4=HIW"主管★侠客梦★的一切工作，负责分管各组组长的工作。"NOR;
	printf("%s %s\t　%s　%s\n"NOR,temp1,temp2,temp3,temp4);
	if(!pointerp(groups)||!sizeof(groups))
	{
		write(msg2);
		write(HIR"还没有巫师分组，各巫师现在都处于自由状态。\n"NOR);
		write(msg2);
//		write(msg1);
		return HIW"有任何问题请找相关 "HIR+SET_ID+HIW" 联系！\n"HIG"亮绿色显示为在线的巫师！\n"NOR;
	}
	else
	for(c=0;c<sizeof(groups);c++)
	{
		write(msg2);
		printf(BLINK HIG"第"+chinese_number(c+1)+"小组：\t"NOR HIW);
		write(groups[c]["task"]);
		write("\n");
		write(msg3);
		wizs=groups[c]["master"];
		if(!wizstatus[wizs[0]["id"]])	temp1=wizhood["(player)"];
		else	temp1=wizhood[wizstatus[wizs[0]["id"]]];
		body=LOGIN_D->find_body(wizs[0]["id"]);
		if(objectp(body)&&interactive(body)&&me->visible(body))
		temp2=HIB"("HIG+wizs[0]["id"]+HIB")";
		else	temp2=HIB"("+wizs[0]["id"]+")"NOR;
		a=strlen(temp2);
		for(b=0;b<20-a;b++)	temp2+=" ";
		temp3=HIR+wizs[0]["function"]+NOR;
		temp4=HIW+wizs[0]["task"]+NOR;
		printf("%s %s\t　%s　%s\n"NOR,temp1,temp2,temp3,temp4);
		for(d=0;d<sizeof(groups[c]["member"]);d++)
		{
			wizs=groups[c]["member"];
			if(!wizstatus[wizs[d]["id"]])	temp1=wizhood["(player)"];
			else	temp1=wizhood[wizstatus[wizs[d]["id"]]];
			body=LOGIN_D->find_body(wizs[d]["id"]);
			if(objectp(body)&&interactive(body)&&me->visible(body))
			temp2=HIB"("HIG+wizs[d]["id"]+HIB")";
			else	temp2=HIB"("+wizs[d]["id"]+")"NOR;
			a=strlen(temp2);
			for(b=0;b<20-a;b++)	temp2+=" ";
			temp3=HIR+wizs[d]["function"]+NOR;
			temp4=HIW+wizs[d]["task"]+NOR;
			printf("%s %s\t　%s　%s\n"NOR,temp1,temp2,temp3,temp4);
		}
	}
	write(msg2);
//	write(msg1);
	return HIW"有任何问题请找相关巫师或高级巫师联系，或请其他组别巫师代为转告！\n"HIG"亮绿色显示为在线的巫师！\n"NOR;
}
int user(string arg)
{
	object usr;
	usr=new(LOGIN_OB);
	usr->set("id",arg);
	if(!usr->restore()) 
	{
		destruct(usr);
		return 0;
	}        
	destruct(usr);
	return 1;
}
int group_master(object me)
{
	mapping *groups;
	groups=query("groups");
	if(!pointerp(groups)||!sizeof(groups))	return 0;
	for(int i=0;i<sizeof(groups);i++)
		if(groups[i]["master"][0]["id"]==me->query("id"))	return 1;
	return 0;
}
int group_member(string id,int num)
{
	mapping *groups;
	int temp;
	groups=query("groups");
	if(num<1||num>sizeof(groups))
		return notify_fail(HIC"没有这一组，请看清楚！\n"NOR);
	for(temp=0;temp<sizeof(groups[num-1]["member"]);temp++)
		if(id==groups[num-1]["member"][temp]["id"])	return 1;
	return 0;	
}
void desc()
{
	mapping *groups,*members,temp,wizstatus=SECURITY_D->query_wizstatus();
	int num,a,b;
	groups=query("groups");
	for(num=0;num<sizeof(groups);num++)
	{
		members=groups[num]["member"];
		a=sizeof(members);
		while(a--)
		{
			for(b=0;b<sizeof(members)-1;b++)
			{
				if(wiz_level(wizstatus[members[b]["id"]])<wiz_level(wizstatus[members[b+1]["id"]]))
				{
					temp=members[b];
					members[b]=members[b+1];
					members[b+1]=temp;
				}
			}
		}
	}
	set("groups",groups);
	save();
	restore();
}
int do_addgroup(string arg)
{
	mapping *groups;
	mapping group,masters;
	object me=this_player();
	string master,temp;
	restore();
	if(me->query("id")!=SET_ID)	return notify_fail(sprintf(HIC"想分组？请找 %s 联系吧！"NOR,SET_ID));
	if(!arg)	return notify_fail(HIC"指令格式：add <组长 id>\n"NOR);
	else if(arg=="list")	return notify_fail(long());
	else if(sscanf(arg,"%s %s",master,temp)==2)	return notify_fail(sprintf(HIC"你确信"HIW" %s "HIC"是你要任命的组长？\n",arg));
	else if(!user(arg))	return notify_fail(HIC"没有这个玩家。\n"NOR);
	else if(sscanf(arg,"%s",master)==1)
	{
		masters=allocate_mapping(4);
		masters["id"]=master;
		masters["task"]=HIY"负责全组工作的统筹和管理！"NOR;
		masters["function"]=HIY"【 组　长 】"NOR;	
		masters["join_time"]=time();
		group=allocate_mapping(4);
		group["master"]=({masters});
		group["member"]=({});
		group["found_time"]=time();
		group["task"]=HIB"尚未规划工作范围："NOR;
		groups=query("groups");
		if(!pointerp(groups)||!sizeof(groups))	groups=({group});
		else groups+=({group});
		set("groups",groups);
		tell_object(me,HIC"新建小组成功，请用 gtask 给该小组分配任务，pmaster 更改这个小组的组长，pmember 添加这个小组的组员！\n"NOR);
		save();
		restore();
		desc();
	}
	return 1;
}
int do_disgroup(string arg)
{
	object me=this_player();
	mapping *groups;
	string master,member;
	int num,mem;
	if(!arg||sscanf(arg,"%d",num)<1)
		return notify_fail(HIC"指令格式：del <组号>\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(me->query("id")!=SET_ID)
			return notify_fail(HIC"你没有删除巫师分组的权力。\n"NOR);
	master=HIC"该组组长为"HIG+groups[num-1]["master"][0]["id"]+HIC;
	if(!sizeof(groups[num-1]["member"]))	member="，没有组员！\n"NOR;
	else 
	{
		member="，组员有"HIG;
		for(mem=0;mem<sizeof(groups[num-1]["member"]);mem++)
		{
			member+= groups[num-1]["member"][mem]["id"];
			if(mem<sizeof(groups[num-1]["member"])-1)
				member+="，";
		}
		member+=HIC" ！\n"NOR;
	}		
       groups=groups-({groups[num-1]});
	set("groups",groups);
	write(HIR"删除第 "+num+" 个巫师分组……Ok！\n"NOR);
	write(master+member);
	save();
	restore();
	desc();
	return 1;
}
int do_pgm1(string arg)
{
	object me=this_player();
	mapping *groups,masters,*members;
	int num,temp;
	string temp_id;
	if(!arg||sscanf(arg,"%s %d",arg,num)!=2)
		return notify_fail(HIC"指令格式：pmaster <id> <组号>\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(!user(arg))	return notify_fail(HIC"没有这个玩家。\n"NOR);
	if(me->query("id")!=SET_ID)
			return notify_fail(HIC"你没有任命组长的权力。\n"NOR);
	if(groups[num-1]["master"][0]["id"]==arg)
		return notify_fail(HIG+arg+HIC" 已经是第"+chinese_number(num)+HIC"组的组长了！\n"NOR);
	members=groups[num-1]["member"];
	for(temp=0;temp<sizeof(members);temp++)
	{
		if(members[temp]["id"]==arg)
		{
			members-=({members[temp]});
			temp--;
		}
	}
	for(temp=0;temp<sizeof(members);temp++)
	{
		if(members[temp]["id"]==groups[num-1]["master"][0]["id"])
		{
			members-=({members[temp]});
			temp--;
		}
	}
	temp_id=groups[num-1]["master"][0]["id"];
	groups[num-1]["master"][0]["function"]=HIB"【 组　员 】"NOR;
	groups[num-1]["master"][0]["task"]=HIB"等待重新分配任务！"NOR;
	members+=({groups[num-1]["master"][0]});
	groups[num-1]["member"]=members;
	masters=allocate_mapping(4);
	masters["id"]=arg;
	masters["task"]=HIY"负责全组工作的统筹和管理！"NOR;
	masters["function"]=HIY"【 组　长 】"NOR;	
	masters["join_time"]=time();
	groups[num-1]["master"]=({masters});
	set("groups",groups);
	write(HIR"成功任命 "HIG+arg+HIR" 为第"HIG+chinese_number(num)+HIR"组组长！\n"NOR);
	write(HIG+temp_id+HIC" 自动降为第"HIG+chinese_number(num)+HIC"组组员！请重新为其分配任务！\n"NOR);
	save();
	restore();
	desc();
	return 1;
}
int do_pgm2(string arg)
{
	object me=this_player(),ob;
	mapping *groups,member;
	int num,g_num,m_num;
	if(!arg||sscanf(arg,"%s %d",arg,num)!=2)
		return notify_fail(HIC"指令格式：pmember <id> <组号>\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(!user(arg))	return notify_fail(HIC"没有这个玩家。\n"NOR);
	if(me->query("id")!=SET_ID)
	{
		ob=find_player(arg);
		if(!ob)	return notify_fail(HIC"该玩家不在线。\n"NOR);
		if(wiz_level(me)!=wiz_level("(admin)")&&!wizardp(ob))
			return notify_fail(HIC"想吸收非巫师成员？找"HIG+SET_ID+HIC"联系吧！\n"NOR);
		if(wiz_level(me)<wiz_level(ob))
			return notify_fail(HIC"想吸收比你级别高的巫师成员？找 "HIG+SET_ID+HIC" 联系吧！\n"NOR);
		if(!group_master(me))
			return notify_fail(HIC"你没有添加组员的权力。\n"NOR);
		if(groups[num-1]["master"][0]["id"]!=me->query("id"))	return notify_fail(HIC"你不是这个组的组长！\n"NOR);
		if(arg==me->query("id"))	return notify_fail(HIC"你已经是组长身份了，想降级？！\n"NOR);
		for(g_num=0;g_num<sizeof(groups);g_num++)
		{
			if(groups[g_num]["master"][0]["id"]==arg)
				return notify_fail(HIG+arg+HIC" 已经是第"HIG+chinese_number(g_num+1)+HIC"组的组长了!\n"NOR);
			if(!sizeof(groups[g_num]["member"]))	continue;
			if(group_member(arg,g_num+1))
				return notify_fail(HIG+arg+HIC" 已经是第"HIG+chinese_number(g_num+1)+HIC"组的组员了!\n"NOR);
		}
	}
	if(groups[num-1]["master"][0]["id"]==arg)
		return notify_fail(HIG+arg+HIC" 已经是第"+chinese_number(num)+HIC"组的组长了！\n"NOR);
	if(group_member(arg,num))
		return notify_fail(HIG+arg+HIC" 已经是第"HIG+chinese_number(num)+HIC"组的组员了!\n"NOR);
	member=allocate_mapping(4);
	member["id"]=arg;
	member["task"]=HIB"尚未分配任务！"NOR;
	member["function"]=HIB"【 组　员 】"NOR;
	member["join_time"]=time();
	groups[num-1]["member"]+=({member});
	set("groups",groups);
	write(HIR"成功添加 "HIG+arg+HIR" 为第 "HIG+chinese_number(num)+HIR" 组组员！\n"NOR);
	save();
	restore();
	desc();
	return 1;
}
int do_function(string arg)
{
	mapping *groups,members;
	string member,func;
	int num,temp;
	object me=this_player();
	restore();
	if(!arg||sscanf(arg,"%s %d %s",member,num,func)!=3)
		return notify_fail(HIC"指令格式：renming <id> <组号> <职务>\n"NOR);
	if(!user(member))	return notify_fail(HIC"没有这个玩家。\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(me->query("id")!=SET_ID&&!group_master(me))
		return notify_fail(HIC"想申请职务？请找组长联系吧！\n"NOR);
	if(me->query("id")!=SET_ID&&me->query("id")!=groups[num-1]["master"][0]["id"])
		return notify_fail(HIC"你不是这一组的组长！\n"NOR);
	if(!group_member(member,num)&&groups[num-1]["master"][0]["id"]!=member)
	{
		if(me->query("id")!=SET_ID)
			return notify_fail(HIG+member+HIC" 不是第"HIG+chinese_number(num)+HIC"组的组员！\n");
		members=allocate_mapping(4);
		members["id"]=member;
		members["task"]=HIB"尚未分配任务！"NOR;
		members["function"]=replace_color(func,1);
		members["join_time"]=time();
		groups[num-1]["member"]+=({members});
		set("groups",groups);
		tell_object(me,HIG+member+HIC" 不是第"HIG+chinese_number(num)+HIC"小组成员，自动将其分配入该小组！\n"NOR);
	}
	else if(!group_member(member,num))
	{
		groups[num-1]["master"][0]["function"]=replace_color(func,1);
		set("groups",groups);
		tell_object(me,HIG+member+HIC" 是第"HIG+chinese_number(num)+HIC"小组组长，任命职务成功！\n"NOR);
	}
	else	for(temp=0;temp<sizeof(groups[num-1]["member"]);temp++)
	{
		if(groups[num-1]["member"][temp]["id"]==member)
		{
			groups[num-1]["member"][temp]["function"]=replace_color(func,1);
			set("groups",groups);
			tell_object(me,HIG+member+HIC" 是第"HIG+chinese_number(num)+HIC"小组组员，任命职务成功！\n"NOR);
		}
	}
	save();
	restore();
	desc();
	return 1;
}
int do_task(string arg)
{
	mapping *groups,members;
	string member,task;
	int num,temp;
	object me=this_player();
	restore();
	if(!arg||sscanf(arg,"%s %d %s",member,num,task)!=3)
		return notify_fail(HIC"指令格式：mtask <id> <组号> <任务>\n"NOR);
	if(!user(member))	return notify_fail(HIC"没有这个玩家。\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(me->query("id")!=SET_ID&&!group_master(me))
		return notify_fail(HIC"想申请任务？请找组长联系吧！\n"NOR);
	if(me->query("id")!=SET_ID&&me->query("id")!=groups[num-1]["master"][0]["id"])
		return notify_fail(HIC"你不是这一组的组长！\n"NOR);
	if(!group_member(member,num)&&groups[num-1]["master"][0]["id"]!=member)
	{
		if(me->query("id")!=SET_ID)
			return notify_fail(HIG+member+HIC" 不是第"HIG+chinese_number(num)+HIC"组的组员！\n");
		members=allocate_mapping(4);
		members["id"]=member;
		members["task"]=replace_color(task,1);
		members["function"]=HIB"【 组　员 】"NOR;
		members["join_time"]=time();
		groups[num-1]["member"]+=({members});
		set("groups",groups);
		tell_object(me,HIG+member+HIC" 不是第"HIG+chinese_number(num)+HIC"小组成员，自动将其分配入该小组！\n"NOR);
	}
	else if(!group_member(member,num))
	{
		groups[num-1]["master"][0]["task"]=replace_color(task,1);
		set("groups",groups);
		tell_object(me,HIG+member+HIC" 是第"HIG+chinese_number(num)+HIC"小组组长，分配任务成功！\n"NOR);
	}
	else	for(temp=0;temp<sizeof(groups[num-1]["member"]);temp++)
	{
		if(groups[num-1]["member"][temp]["id"]==member)
		{
			groups[num-1]["member"][temp]["task"]=replace_color(task,1);
			set("groups",groups);
			tell_object(me,HIG+member+HIC" 是第"HIG+chinese_number(num)+HIC"小组组员，分配任务成功！\n"NOR);
		}
	}
	save();
	restore();
	desc();
	return 1;
}
int do_grouptask(string arg)
{
	object me=this_player();
	mapping *groups;
	int num;
	restore();
	if(!arg||sscanf(arg,"%d %s",num,arg)!=2)
		return notify_fail(HIC"指令格式：gtask <组号> <组说明>\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(me->query("id")!=SET_ID&&me->query("id")!=groups[num-1]["master"][0]["id"])
		return notify_fail(HIC"你不是这个组的组长！有事找 "HIG+SET_ID+HIC" 联系！\n"NOR);
	groups[num-1]["task"]=replace_color(arg,1);
	set("groups",groups);
	write(HIR"成功为第"HIG+chinese_number(num)+HIR"组分配任务！\n"NOR);
	save();
	restore();
	desc();
	return 1;
}
int do_dismiss(string arg)
{
	object me=this_player();
	mapping *groups;
	int num,temp;
	if(!arg||sscanf(arg,"%s %d",arg,num)!=2)
		return notify_fail(HIC"指令格式：pdown <id> <组号>\n"NOR);
	groups=query("groups");
	if(!arrayp(groups)||num<1||num>sizeof(groups))
		return notify_fail(HIC"目前没有这个巫师分组！\n"NOR);
	if(me->query("id")!=SET_ID&&me->query("id")!=groups[num-1]["master"][0]["id"])
		return notify_fail(HIC"你不是这个组的组长！有事找 "HIG+SET_ID+HIC" 联系！\n"NOR);
	if(me->query("id")==groups[num-1]["master"][0]["id"]&&me->query("id")==arg)
		return notify_fail(HIC"你就是这个组的组长！想辞职？请找 "HIG+SET_ID+HIC" 联系！\n"NOR);
	if(arg==groups[num-1]["master"][0]["id"])
		return notify_fail(HIC"解除组长职务！请先任命新组长！\n"NOR);
	if(!group_member(arg,num))
		return notify_fail(HIG+arg+HIC" 不是这个组的组员，麻烦你看清楚！\n"NOR);
	for(temp=0;temp<sizeof(groups[num-1]["member"]);temp++)
		if(arg==groups[num-1]["member"][temp]["id"])
		{
			groups[num-1]["member"]-=({groups[num-1]["member"][temp]});
			break;
		}
	set("groups",groups);
	write(HIR"成功将 "HIG+arg+HIR" 在第"HIG+chinese_number(num)+HIR"组内的职务解除了！\n"NOR);
	save();
	restore();
	desc();
	return 1;
}
int do_list()
{
	write(long());
	return 1;
}
int do_help()
{
	object me=this_player();
	if(me->query("id")==SET_ID)	write(HIC+@HELP
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
⒈添加组：	addgroup
⒉解散组：	delgroup <组号>
⒊任命组长：	pmaster <id> <组号>
⒋任命组员：	pmember <id> <组号>
⒌解除任务：	pdown <id> <组号>（对组长使用时必须先用 pmaster 任命新组长）
⒍分配职务：	renming <id> <组号> <职务>
⒎分配任务：	mtask <id> <组号> <任务>
⒏组说明：	gtask <组号> <说明内容>（可以很长，但要求工整，不要太乱）
⒐清单：	listme
⒑使用方法：	helpme
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
HELP+NOR);
	else if(group_master(me))	write(HIC+@HELP
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
⒈任命组员：	pmember <id> <组号>
⒉解除任务：	pdown <id> <组号>
⒊分配职务：	renming <id> <组号> <职务>
⒋分配任务：	mtask <id> <组号> <任务>
⒌组说明：	gtask <组号> <说明内容>（可以很长，但要求工整，不要太乱）
⒍清单：	listme
⒎使用方法：	helpme
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
HELP+NOR);
	else	write(HIC+@HELP
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
⒈清单：	listme
⒉使用方法：	helpme
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
HELP+NOR);
	return 1;
}
void init()
{
	object me=this_player();
	add_action("do_list","listme");			//列出任务分配表，adm 可以看到未被分配的巫师
	add_action("do_help","helpme");			//帮助文件
//此处应加判断，至少是组长才可以执行以下命令
	if(group_master(me)||me->query("id")==SET_ID)
	{
		add_action("do_pgm2","pmember");		//任命某 ID 为某组组员，同一巫师可在不同组，但如要降组长为组员，直接任命新组长
		add_action("do_dismiss","pdown");		//解除某一巫师在某一组的职务及任务，如果是组长，必须先任命新组长
		add_action("do_function","renming");	//给某组内某 ID 分配职务
		add_action("do_task","mtask");		//给某组内某 ID 分配任务
		add_action("do_grouptask","gtask");	//声明某组所负责的任务及范围，这个可以很长
	}
	if(me->query("id")==SET_ID)
	{
		add_action("do_addgroup","addgroup");	//添加一组
		add_action("do_disgroup","delgroup");	//解散某一组，慎用
		add_action("do_pgm1","pmaster");		//任命某 ID 为某组组长，原组长自动降为组员
	}
}
int query_autoload()
{
	object me=this_player();
	if(wiz_level(me)>=wiz_level(SET_LVL))	return 1;
	else return group_master(me);
}