//用以记录导师流派的一些信息以及一些功能实现
//Created by Zine@pkuxkx 2013/1/27
//转换成帮派信息，做了其他一些存储变更。 Modified Zine@pkuxkx 2015/1/30
inherit F_DBASE;
inherit F_SAVE;

#include <ansi.h>
#include <math.h>
int delele_group(int no);
string set_group_name(int no,string name);
string query_save_file()
{
    return "/data/group";
}
string *access_list()//允许加入帮派的地点，以前是单一房间，将变更为命令gjoin
{
	string* list=({""});
	return list;
}
void create()
{
    seteuid(getuid());
    restore();
}
//彻底取消导师概念和mark，所有帮派信息将用 "/data/group.o"以及每个帮派基地来保存，人身上只保存query("GroupNo")帮派编号，提高查询效率
int group_member(object me) //query("Groups/1/all_players")第一帮的所有人id
{
	if (!me->query("GroupNo")) return -1;//没有帮派
	else if (!query("Groups/"+me->query("GroupNo"))) return -2;//服务器没有记录
	else if (member_array(me->query("id"),query("Groups/"+me->query("GroupNo")+"/all_players"))==-1) //我不在帮派列表内
	{
		me->delete("GroupNo");
		return -3;
	}
	else if (member_array(me->query("id"),query("Groups/"+me->query("GroupNo")+"/first_class"))!=-1)//第一阶层帮主之类
	return 0;
	else if (member_array(me->query("id"),query("Groups/"+me->query("GroupNo")+"/second_class"))!=-1)//第二阶层副帮主之类
	return 1;
	else if (member_array(me->query("id"),query("Groups/"+me->query("GroupNo")+"/third_class"))!=-1)//第三阶层长老之类
	return 2;
	else if (member_array(me->query("id"),query("Groups/"+me->query("GroupNo")+"/fourth_class"))!=-1)//第四阶层堂主之类
	return 3;
	else if (member_array(me->query("id"),query("Groups/"+me->query("GroupNo")+"/fifth_class"))!=-1)//第五阶层帮众之类
	return 4;
	else
	return -4;
}
int valid_group(object me)//检查某人的帮派是否有空位。有则返回1，无则0
{
	int no,*capacity=({15,20,25,30,30,30});//一共6级帮会，每级别最大人数。
	if (group_member(me)<0) return 0;
	no=query("Groups/"+me->query("GroupNo")+"/level");
	if (no<0) no=0;
	if (no>sizeof(capacity)-1) no=sizeof(capacity)-1;
	if (sizeof(query("Groups/"+me->query("GroupNo")+"/all_players"))>=capacity[no])//达到人数上限
	return 0;
	return 1;
}
string group_name(object me)//返会我帮派的名字
{
	if (group_member(me)<0) return "";
	return query("Groups/"+me->query("GroupNo")+"/name");
}
string group_title(object me)//返回我帮派中的title
{
	if (group_member(me)<0) return "";
	return query("Groups/"+me->query("GroupNo")+"/titles")[group_member(me)];
}
string *group_members(object me)//返回我的团伙成员
{
	if (query("Groups/"+me->query("GroupNo")+"/all_players")&&arrayp(query("Groups/"+me->query("GroupNo")+"/all_players"))) 
	return query("Groups/"+me->query("GroupNo")+"/all_players");
	return ({});
}
int save_group_info(object me,int no,int gclass,int flag,string group_name)
{
	int i=0;
	string *names=({}),*classes=({"first","second","third","fourth","fifth"}),msg,*titles;
	if (flag==1)//加入
	{
		if (query("Groups/"+no+"/all_players")&&arrayp(query("Groups/"+no+"/"+classes[gclass]+"_class"))) 
		names=query("Groups/"+no+"/all_players");
		if (member_array(me->query("id"),names)==-1)
		names+=({me->query("id")});
		set("Groups/"+no+"/all_players",names);
		if (query("Groups/"+no+"/"+classes[gclass]+"_class")&&arrayp(query("Groups/"+no+"/"+classes[gclass]+"_class")))
		names=query("Groups/"+no+"/"+classes[gclass]+"_class");
		if (member_array(me->query("id"),names)==-1)
		names+=({me->query("id")});
		set("Groups/"+no+"/"+classes[gclass]+"_class",names);
		
		me->set("GroupNo",no);
		if (!gclass)//帮主建帮，建立阶级头像ca
		{
			titles=({"帮主","副帮主","长老","堂主","帮众"});
			set("Groups/"+no+"/titles",titles);
			set_group_name(no,group_name);
		}
		msg="恭喜！你成为了"+group_name(me)+"的"+group_title(me)+"。\n";
	}
	else if (flag==0)//踢出
	{
		msg="你离开了"+group_name(me)+"。\n";
		if (query("Groups/"+no+"/all_players")&&arrayp(query("Groups/"+no+"/"+classes[gclass]+"_class"))) 
		names=query("Groups/"+no+"/all_players");
		if (member_array(me->query("id"),names)!=-1)
		names-=({me->query("id")});
		set("Groups/"+no+"/all_players",names);
		if (query("Groups/"+no+"/"+classes[gclass]+"_class")&&arrayp(query("Groups/"+no+"/"+classes[gclass]+"_class")))
		names=query("Groups/"+no+"/"+classes[gclass]+"_class");
		if (member_array(me->query("id"),names)!=-1)
		names-=({me->query("id")});
		set("Groups/"+no+"/"+classes[gclass]+"_class",names);
		if (!gclass)//帮主退出，则帮派解散
		delele_group(me->query("GroupNo"));
		me->delete("GroupNo");
	}
	else
	{
		for (i=0;i<sizeof(classes);i++)
		{
			if (query("Groups/"+no+"/"+classes[i]+"_class")&&arrayp(query("Groups/"+no+"/"+classes[i]+"_class")))
			names=query("Groups/"+no+"/"+classes[i]+"_class");
			if (member_array(me->query("id"),names)!=-1)
			names-=({me->query("id")});
		}
		names=query("Groups/"+no+"/"+classes[gclass]+"_class");
		if (member_array(me->query("id"),names)==-1)
		names+=({me->query("id")});
	}
	save();
	tell_object(me,msg);
	return 1;
}
int delele_group(int no)
{
	object real=load_object("/d/parties/public/obj/real");
	mapping *entry=real->real_estate();
	string save_file="/data/business/real_estate_no/";
	save_file+=entry[no]["save_file"];
	rm(save_file);
	entry[no]["owner"]="N/A";
    entry[no]["owner_name"]="";
    entry[no]["entry_code"]="";
    real->save_entry(entry);
	real->save();
	CHANNEL_D->do_channel(this_object(), "jh", "曾经辉煌的"+query("Groups/"+no+"/name")+"，也没经受住时间的考验，只给人们留下了谈资。\n", -1);
	delete("Groups/"+no);
	save();
	return 1;
}
int auto_create(object me,object real,mapping *entry,int no,string group_name)
{
	object rm;
	string save_file="/data/business/real_estate_no/",passwd=ANTIROBOT_D->generaterandomcode()+ANTIROBOT_D->generaterandomcode();
	save_file+=entry[no]["save_file"];
	rm(save_file);
	entry[no]["owner"]=me->query("id");
    entry[no]["owner_name"]=me->query("name");
    entry[no]["entry_code"]=passwd;
    real->save_entry(entry);
    if (rm=load_object(entry[no]["entry"]))
    rm->get_lv();
    write(HIG+"恭喜！你的地产位于"+entry[no]["desc"]+"，进入那里的口令是"+HBWHT+HIR+passwd+NOR+HIG+"，可别忘记了！\n"+NOR);
    real->save();
	save_group_info(me,no,0,1,group_name);
	return 1;
}
int finish_create(string arg,object me,object real,mapping *entry,int vac_no,int *ava_nos,string group_name)
{
	int no;
	if (sscanf(arg, "%d", no)==1)
	{
		if (member_array(no,ava_nos)==-1)
			return auto_create(me,real,entry,vac_no,group_name);
		else
			return auto_create(me,real,entry,no,group_name);
	}
	return auto_create(me,real,entry,vac_no,group_name);
}
int create_group(object me,string arg)
{
	object real=load_object("/d/parties/public/obj/real");
	mapping *entry;
	int vacancy=0,vac_no,*ava_nos=({});
	string real_info="可用帮派地产列表\n";
	if (group_member(me)>=0)
	{
		tell_object(me,"你已经是帮会成员了，除非退出帮会，否则无法建立新帮会。\n");
		return 1;
	}
	entry=real->real_estate();
    for (int i=0;i<sizeof(entry);i++)
    {
        if (entry[i]["owner"]=="N/A")
		{
			vacancy=1;
			vac_no=i;
			break;
		}
    }
	if (!vacancy)
	{
		tell_object(me,"现在北侠已经容纳不下更多的帮派了。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要创建帮派需要一个响亮的名字。可支持颜色，如$HIW$斧头帮。\n");
		tell_object(me,"任何不符合武侠意境或引起歧义的名字会被巫师修改，政治色情粗鲁的名字将会受到额外惩罚。\n");
		return 1;
	}
	if( strwidth(arg) > 20 )
	{
		tell_object(me,"你帮会的名字太长了。\n");
		return 1;
	}
	arg = replace_string(arg, "\n", " ");
	arg = COLOR_D->replace_color(arg);
	for (int i=0;i<sizeof(entry);i++)
    {
        if (entry[i]["owner"]=="N/A")
		{
			ava_nos+=({i});
			real_info+=HIY+"编号【"+i+"】\t简介："+entry[i]["desc"]+"。\n"+NOR;
		}
    }
	tell_object(me,"你要建立的帮会叫做"+arg+NOR+"，请上述地产中选择，选择帮会所在。\n");
	tell_object(me,"请仔细阅读编号，如果输入的编号不在其列，将被自动指定帮会所在。\n");
    me->start_more(real_info);
	return input_to( (: finish_create :), me,real,entry,vac_no,ava_nos,arg);
}
int add_member(object me,object target)//加入帮派 me是要加入的人，target是有帮派的人 
{
	int result=group_member(target),no;
	if (result<0) 
	{
		tell_object(me,target->name()+"不是帮派中人。\n");
		return 1;
	}
	else if (result>3)
	{
		tell_object(me,target->name()+"是"+group_name(target)+"底层成员，不能作为你的引荐人。\n");
		return 1;
	}
	else
	{
		if (valid_group(target))
		{
			message_vision("$N在"+group_title(target)+"$n引荐之下，加入了"+group_name(target)+"。\n",me,target);
			CHANNEL_D->do_channel(this_object(), "jh", me->query("name")+"在"+group_title(target)+target->query("name")+"引荐之下，加入了"+group_name(target)+"。\n", -1);
			no=target->query("GroupNo");
			save_group_info(me,no,4,1,"");
		}
		else
		message_vision(group_name(target)+"人数已满，$N无法加入。\n",me);
		return 1;
	}
}
int del_member(object me,object target)//退出或踢出帮派 me是要退出的人，target是要求其退出的人
{
	int my_class=group_member(me),his_class=group_member(target);
	if (my_class<0||his_class<0) return 0;
	if (me==target) return save_group_info(me,me->query("GroupNo"),my_class,0,"");
	if (his_class>=my_class) return -1;
	if (my_class>4&&his_class>1) return -2;
	return save_group_info(me,me->query("GroupNo"),my_class,0,"");
}

int valid_cost(int no,int score)//检查某帮派的分是否够完成某事，no 是帮派编号，score是积分，如果扣则直接扣返回消耗积分，否则返回0
{
	if (query("Groups/"+no+"/score")>=score)
	{
		add("Groups/"+no+"/score",-score);
		save();
		return score;
	}
	return 0;
}
int add_score(int no,int score)//增减积分，返回剩余分数。返回0表示该帮派不存在
{
	if (query("Groups/"+no))
	{
		add("Groups/"+no+"/score",score);
		save();
		return query("Groups/"+no+"/score");
	}
	return 0;
}
object get_base(object me)//返回帮派基地，无基地则返回本文件
{
	object real;
    mapping *ent;
	if (group_member(me)<0) return this_object();
	real=load_object("/d/parties/public/obj/real");
	ent=real->real_estate();
	return load_object(ent[me->query("GroupNo")]["entry"]);
}
object get_base_by_id(string me)//wiz通过玩家姓名找他的帮派基地
{
	object pl=find_player(me);
	return get_base(pl);
}
string set_group_name(int no,string name)//设置帮派名称并返回，如果帮派不存在则返回“”
{
	if (query("Groups/"+no))
	{
		set("Groups/"+no+"/name",name);
		save();
		return query("Groups/"+no+"/name");
	}
	return "";
}
int group_level(int no,int new_level)//设置帮派级别，返回新级别，如帮派不存在返回-1
{
	if (query("Groups/"+no))
	{
		set("Groups/"+no+"/level",new_level);
		save();
		return query("Groups/"+no+"/level");
	}
	return -1;
}

int same_group(object ppa,object ppb)//在同一帮派内
{
	if (ppa->query("GroupNo")==ppb->query("GroupNo")&&group_member(ppa)>=0&&group_member(ppb)>=0)
	return 1;
	return 0;
}

