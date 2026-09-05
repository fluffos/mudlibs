//统计一些整个服务器的基本情况，汇总一下。
//Zine@pkuxkx 2013-4-14

inherit F_DBASE;
inherit F_SAVE;
#include <net/dns.h>
#include <ansi.h>
#include <localtime.h>
#include <title.h>
void get_TIME();
void get_ips();
int sort_player();
void grant_top5();
string lookup(string id);
mapping * ret_list(int no);
mixed * LIST0;
mixed * LIST1;
mixed * LIST2;
mixed * LIST3;
mixed * LIST4;
string * TOP5;
string query_save_file()
{
    return "/data/statistic";
}

void create()
{
    seteuid(getuid());
    restore();
	get_TIME();
	grant_top5();
}
void generate_report(string day)
{
	string msg=day+"北侠综合情况汇总\n";
	mapping task_type=(["TASK":"TASK","HYW":"韩员外","SONGXIN":"华山送信",]);
	log_file("wiz/statistic_report",sprintf("%s",msg));
}
void clear_vote(int flag)
{
	if (flag||time()>query("rank_vote/vote_expire"))
	{
		delete("rank_vote");
	}
}
void get_TIME()
{
	mixed tm=localtime(time());
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	if (day!=query("STATISTIC_DATA"))
	{
		generate_report(day);
		set("STATISTIC_DATA",day);
		delete("task_record");
		delete("death_record");
		delete("achieve_record");
		save();
	}
	clear_vote(0);
	get_ips();
	sort_player();
	remove_call_out("get_TIME");
	call_out("get_TIME",600);
	return;
}
void task_record(string task_type,int exp,int pot,int rep,int finish)
{
	add("task_record/"+task_type+"/exp",exp);
	add("task_record/"+task_type+"/pot",pot);
	add("task_record/"+task_type+"/rep",rep);
	if (finish)
	add("task_record/"+task_type+"/total_finish",1);
	add("task_record/total_finish",1);
	save();
}

void death_record(string victim_type)
{
	add("death_record/"+victim_type,1);
	save();
}

void achieve_record(string achieve_type)
{
	add("achieve_record/"+achieve_type,1);
	save();
}

int temp_digital(string type,int self_decrease)
{
	if (self_decrease)
	{
		add(type,-1);
		save();
		return query(type)+1;
	}
	return query(type);
}
int query_only_ip(object *ob)
{       
        int i,j,k,count,total;

        total=sizeof(ob);
        reset_eval_cost();
        for ( i=0; i<sizeof(ob); i++)
        {
                count=1;k=sizeof(ob);
                for (j=k-1; j>i;j--)
                        if (query_ip_number(ob[i])==query_ip_number(ob[j]) )
                        {
                                ob=ob-({ob[j]});
                                count++;
                                k=sizeof(ob);
                        }
                total=total-count+1;
        }
        return total;
}
void get_ips()
{
	int ips,i,j,k,count,total;
	object *ob=users();
	total=sizeof(ob);
	reset_eval_cost();
	for ( i=0; i<sizeof(ob); i++)
	{
		count=1;
		k=sizeof(ob);
		for (j=k-1; j>i;j--)
		if (query_ip_number(ob[i])==query_ip_number(ob[j]) )
		{
			ob=ob-({ob[j]});
			count++;
			k=sizeof(ob);
		}
		total=total-count+1;
	}
	log_file("wiz/independant_ip",sprintf("%s",ctime(time())+"，实际登陆有 "+total+" 人。\n"));
	return;
}
void save_player(object me,int low,int high,int capacity,mixed *list,string save_path)
{
	int k,lowest_exp=high;
	string *ids=({});
	if (query(save_path)) 
	list=query(save_path);
	if (me->query("combat_exp")<low||me->query("combat_exp")>high) 
	{
		if (sizeof(list)>0)
		for (int i=0;i<sizeof(list);i++)
		{
			if (list[i]["id"]==me->query("id"))
			{
				list-=({list[i]});
				break;
			}
		}
		set(save_path,list);
		save();
		return;
	}
	if (sizeof(list)>0)
	for (int i=0;i<sizeof(list);i++)
	{
		ids+=({list[i]["id"]});
		if (list[i]["id"]==me->query("id"))
		list[i]["exp"]=me->query("combat_exp");
		if (list[i]["exp"]<lowest_exp)
		{
			lowest_exp=list[i]["exp"];
			k=i;
		}
	}
	if (member_array(me->query("id"),ids)==-1)
	{
		if (sizeof(list)<capacity) 
		{
			list+=({(["id":me->query("id"),"exp":me->query("combat_exp")])});
		}
		else
		{
			if (me->query("combat_exp")>lowest_exp)
			{
				list-=({list[k]});
				list+=({(["id":me->query("id"),"exp":me->query("combat_exp")])});
			}
		}
		set(save_path,list);
		save();
	}
}

void grant_top5()
{
	TOP5=({});
	for (int i=0;i<5;i++)
		TOP5+=({LIST4[i]["id"]});
}

int sort_ppl(mapping list1,mapping list2)
{
	return list2["exp"]-list1["exp"];
}

int sort_player()
{
	mixed *list,tm=localtime(time());
	string *querys=({"_10_50","_50_100","_100_400","_400_800","_800"});
	list=query("Players"+querys[tm[1]/12]);
	list=sort_array(list,"sort_ppl");
	switch(tm[1]/12)
	{
		case 0:
		LIST0=list;
		break;
		case 1:
		LIST1=list;
		break;
		case 2:
		LIST2=list;
		break;
		case 3:
		LIST3=list;
		break;
		case 4:
		LIST4=list;
		break;
	}
	return tm[1];
}
string * ret_top5()
{
	return TOP5;
}
mapping * ret_list(int no)
{
	switch(no)
	{
		case 0:
		return LIST0;
		case 1:
		return LIST1;
		case 2:
		return LIST2;
		case 3:
		return LIST3;
		case 4:
		return LIST4;
	}
	return ({});
}
int legal_usertitle(object me)
{
	int mark=0;
	if (!LIST4||sizeof(LIST4)<1) return 1;
	for (int i=0;i<sizeof(LIST4);i++)
		if (me->query("id")==LIST4[i]["id"])
			mark=1;
	return mark;
}
void TopSlot(object me)
{
	string arg;
	if (member_array(me->query("id"),({STATISTIC_D->ret_list(0)[0]["id"],STATISTIC_D->ret_list(0)[1]["id"],STATISTIC_D->ret_list(0)[2]["id"],
STATISTIC_D->ret_list(1)[0]["id"],STATISTIC_D->ret_list(1)[1]["id"],STATISTIC_D->ret_list(1)[2]["id"],
STATISTIC_D->ret_list(2)[0]["id"],STATISTIC_D->ret_list(2)[1]["id"],STATISTIC_D->ret_list(2)[2]["id"],
STATISTIC_D->ret_list(3)[0]["id"],STATISTIC_D->ret_list(3)[1]["id"],STATISTIC_D->ret_list(3)[2]["id"]}))==-1)
		me->set_title(TITLE_BANG);
	else
	{
		arg=lookup(me->query("id"));
		arg=replace_string(arg,me->query("id"),"");
		arg=replace_string(arg,"在","");
		arg=replace_string(arg,"\n","");
		arg=replace_string(arg,"第一位。","状元");
		arg=replace_string(arg,"第二位。","榜眼");
		arg=replace_string(arg,"第三位。","探花");
		if (strsrch(arg,"地")) arg=HIY+arg+NOR;
		if (strsrch(arg,"风云")) arg=HIC+arg+NOR;
		if (strsrch(arg,"龙虎")) arg=CYN+arg+NOR;
		if (strsrch(arg,"六合")) arg=HIG+arg+NOR;
		me->set_title(TITLE_BANG,arg);

	}
}
void register_user(object me)
{
	mixed *list=({});
//	delete guider
//	if (SECURITY_D->get_status(me->query("id")) == "(guider)")
//	{
//		seteuid(ROOT_UID);
//		SECURITY_D->set_status(me, "(player)");
//		tell_object(me,HIR"再次感谢你在作为导师期间为北侠做出的贡献！\n"NOR);
//		seteuid(getuid());
//	}
	if (wizardp(me)||me->query("combat_exp")<10000000) return;
	save_player(me,10000000,50000000,50,list,"Players_10_50");
	save_player(me,50000000,100000000,50,list,"Players_50_100");
	save_player(me,100000000,400000000,50,list,"Players_100_400");
	save_player(me,400000000,800000000,50,list,"Players_400_800");
	save_player(me,800000000,8000000000,20,list,"Players_800");
	if (!legal_usertitle(me))
	me->set_title(TITLE_USER);
	TopSlot(me);
}
string *top5rank()
{
	if (query("top5_rankwords")&&arrayp(query("top5_rankwords")))
	return query("top5_rankwords");
	else
	return ({});
}
void save_rankword(string arg)
{
	string *words=({});
	if (query("top5_rankwords")&&arrayp(query("top5_rankwords")))
	words=query("top5_rankwords");
	words+=({arg});
	set("top5_rankwords",words);
	save();
}
string position(string id,int n)
{
	mapping *list;
	string *bang_names=({"六合","龙虎","风云","地","天"});
	list=ret_list(n);
	for (int i=0;i<sizeof(list);i++)
		if (list[i]["id"]==id)
			return id+"在"+bang_names[n]+"榜第"+(i+1)+"位。\n";
	return "";
}
string lookup(string id)
{
	for (int i=0;i<5;i++)
		if (position(id,i)!="")
		return position(id,i);
	return "";
}
string * hide_list()
{
	if (query("hide_list")&&arrayp(query("hide_list")))
	return query("hide_list");
	else
	return ({});
}
void access_me(string id,int flag)
{
	string *list=({});
	if (query("hide_list")&&arrayp(query("hide_list"))) list=query("hide_list");
	if (flag)
	{
		if (member_array(id,hide_list())!=-1)
		{
			list-=({id});
			set("hide_list",list);
			save();
		}
	}
	else
	{
		if (member_array(id,hide_list())==-1)
		{
			list+=({id});
			set("hide_list",list);
			save();
		}
	}
}
void save_WalkMsg(object me,int no)
{
	string *list=({});
	if (query("WalkMsg/"+no)&&arrayp(query("WalkMsg/"+no))) list=query("WalkMsg/"+no);
	if (member_array(me->query("id"),list)==-1)
	{
		list+=({me->query("id")});
		set("WalkMsg/"+no,list);
		save();
	}
}
