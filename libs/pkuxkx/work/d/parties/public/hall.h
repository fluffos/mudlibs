#define LV0 0
#define LV1 50
#define LV2 200
#define LV3 450
#define LV4 900
#define GROUP_MAX_LV 6
//基地操作扣分情况
#define RE_RANK_COST 100
#define NAME_GROUP_COST 200
#define CHANGE_PWD 100

#include "/d/parties/public/change_name.h"
#include "title.h"
//导师基地升级条件
int Recover;
int get_lv();
int group_title(object me);
int get_exit(int index);
int is_group_base()
{
	return 1;
}
string query_save_file()
{
	if (Recover)
	return "/data/business/real_estate_no/-1";
	else 
	return "/data/business/real_estate_no/"+query("number");
}
string *all_classes()
{
	return ({"宗主","副宗主","客卿","长老","使者","高级门徒","门徒"});
}
int ClearOutData(int number)
{
	int no;
	no=number+1;
	Recover=1;
	restore();
	set("number",number);
	set("exits", ([
                "north": "/d/parties/Real_"+no+"/dazuo",
                "southwest": "/d/parties/Real_"+no+"/lian",
                "southeast" : "/d/parties/Real_"+no+"/du",
                "west" : "/d/parties/Real_"+no+"/sleep",
                "east" : "/d/parties/Real_"+no+"/court",
        ]));
	Recover=0;
	save();
	get_exit(number);
}
int get_exit(int index)
{
    object real=load_object("/d/parties/public/obj/real");
    mapping *ent=real->real_estate();
    string exit=ent[index]["file"],*all_classes=all_classes(),*list;
	restore();
	set("test",ent[index]);
	set("owner",ent[index]["owner"]);
	set("base",ent[index]["file"]);
    set("true_exit",exit);
	set("exits/out",exit);
	delete("realmap");
	if (!query(all_classes[0])||(arrayp(query(all_classes[0]))&&member_array(query("owner"),query(all_classes[0]))==-1))
	{
		list=({query("owner")});
		set(all_classes[0],list);
	}
	call_out("get_lv",1);
    return 1;
}
mapping *premises()
{
	return 
		({
		(["lv":1,"score_consume":200,"donate_require":800,"old_apps_require":2,"current_apps_require":5,]),
		(["lv":2,"score_consume":300,"donate_require":1200,"old_apps_require":5,"current_apps_require":10,]),
		(["lv":3,"score_consume":500,"donate_require":1500,"old_apps_require":10,"current_apps_require":10,]),
		(["lv":4,"score_consume":600,"donate_require":2000,"old_apps_require":15,"current_apps_require":15,]),
		(["lv":5,"score_consume":1000,"donate_require":2500,"old_apps_require":20,"current_apps_require":15,]),
		(["lv":6,"score_consume":1100,"donate_require":3000,"old_apps_require":25,"current_apps_require":15,]),
		(["lv":7,"score_consume":1500,"donate_require":5000,"old_apps_require":25,"current_apps_require":20,]),
		(["lv":8,"score_consume":1600,"donate_require":7500,"old_apps_require":25,"current_apps_require":20,]),
		(["lv":9,"score_consume":2000,"donate_require":9500,"old_apps_require":25,"current_apps_require":20,]),
		(["lv":10,"score_consume":2500,"donate_require":10000,"old_apps_require":25,"current_apps_require":25,]),
	});
}
mapping *class_name()
{
	return
	({
	(["宗主":1,"副宗主":0,"客卿":0,"长老":0,"使者":0,"高级门徒":0,"门徒":20,]),//lv1
	(["宗主":1,"副宗主":0,"客卿":0,"长老":0,"使者":0,"高级门徒":0,"门徒":25,]),//2
	(["宗主":1,"副宗主":0,"客卿":0,"长老":0,"使者":0,"高级门徒":3,"门徒":25,]),//3
	(["宗主":1,"副宗主":0,"客卿":0,"长老":0,"使者":2,"高级门徒":5,"门徒":30,]),//4
	(["宗主":1,"副宗主":0,"客卿":0,"长老":1,"使者":3,"高级门徒":8,"门徒":30,]),//5
	(["宗主":1,"副宗主":0,"客卿":2,"长老":2,"使者":3,"高级门徒":8,"门徒":30,]),//6
	(["宗主":1,"副宗主":0,"客卿":2,"长老":3,"使者":5,"高级门徒":10,"门徒":30,]),//7
	(["宗主":1,"副宗主":1,"客卿":2,"长老":3,"使者":5,"高级门徒":10,"门徒":30,]),//8
	(["宗主":1,"副宗主":2,"客卿":3,"长老":5,"使者":5,"高级门徒":10,"门徒":30,]),//9
	(["宗主":1,"副宗主":3,"客卿":3,"长老":5,"使者":5,"高级门徒":10,"门徒":35,]),//10
	});
}

int notice_credit_cost(object me,int point)
{
	return GUIDER_D->finish(me,point);
}
string get_owner()
{
	set("宗主",({query("owner")}));
	save();
	return query("owner");
}
int get_rank(string arg)
{
	object ob=this_object();
	string *all_classes=all_classes();
	for (int i=0;i<sizeof(all_classes);i++)
	if (arrayp(ob->query(all_classes[i])))
	if (member_array(arg,ob->query(all_classes[i]))!=-1)
	return i;
	return -1;
}
int members_modify(string type)
{
	int i;
    int j;
	object *all_user;
	string *list;
	all_user = filter_array(children(USER_OB), (: userp :));
	all_user = filter_array(all_user, (: environment :));
    //i 被两层循环使用，导致死循环。
	for (i=0;i<sizeof(all_user);i++)
    {
        
        if (GUIDER_D->get_base(all_user[i])==this_object())
        {            
            group_title(all_user[i]);
        }
        else
        {
            if (arrayp(query(type))&&sizeof(query(type))>0)
            {         
                for (j=0;j<sizeof(list=query(type));j++)
                {                
                    if (find_player(list[j]))
                    {
                        group_title(find_player(list[j]));
                    }
                }
            }
        }
    }
	return 1;	
}
string can_promote(object me,string rank)
{
	string *all_classes=all_classes();
	int *exp_require=({0,100000000,80000000,50000000,5000000,1000000,0});
	int *old_apps=({0,1,0,1,0,0,0});
	int *must_promote_by_prelevel=({0,3,0,4,5,6,0});
	int *time_require=({0,240,0,120,72,24,0});//单位小时
	int level=member_array(rank,all_classes);
	if (level==-1)
	return rank+"不是一个合法的阶层头衔。\n";
	if (me->query("combat_exp")<exp_require[level])
	return me->query("name")+"的经验不满足升为"+rank+"的条件("+exp_require[level]+")。\n";
	if (old_apps[level]!=old_student(me)&&old_apps[level]==1)
	return rank+"必须从已经出师的学生中挑选。\n";
	if (rank==all_classes[2]&&(owner_access(me)||valid_access(me)||old_student(me)))
	return rank+"只能从宗派外请来。\n";
	if (rank!=all_classes[2]&&!owner_access(me)&&!valid_access(me)&&!old_student(me))
	return "宗派外请来的高手只能担任客卿一职。\n";
	if (must_promote_by_prelevel[level]!=0&&must_promote_by_prelevel[level]!=get_rank(me->query("id")))
	return rank+"的晋升前提是具有"+all_classes[must_promote_by_prelevel[level]]+"的头衔。\n";
	if (time()-me->query("group_title_time")<time_require[level]*3600)
	return me->query("name")+"距离上次晋升时间太短，尚需"+CHINESE_D->chinese_period(me->query("group_title_time")+time_require[level]*3600-time())+"方可再次晋升。\n";
	return "success";
}
string switch_customized_rank(string rank)
{
	object ob=this_object();
	string *my_classes,*all_classes;
	if (!my_classes=ob->query("my_classes"))
	return rank;
	all_classes=all_classes();
	if (member_array(rank,all_classes)==-1)
	return rank;
	return my_classes[member_array(rank,all_classes)];
}
string give_rank_color(string rank)
{
	string *colors=({HIY,HIW,HIG,HIC,HIM,HIR,HIB}),*all_classes=all_classes();
	int no=member_array(rank,all_classes);
	if (no==-1)
	return rank;
	return colors[no]+rank+NOR;
}
string notice_class_modify(object ob)
{
	string msg="";
	mapping my_class_name,*class_name=class_name();
	int i,j;
	mixed *positions,*ranks;
	string *all_classes=all_classes();
	if (!ob->query("group_level"))
	return "至少一级以上的宗派才可以使用这个命令";
	my_class_name=class_name[ob->query("group_level")-1];
	positions=values(my_class_name);
	ranks=keys(my_class_name);
	for (i=0;i<sizeof(all_classes);i++)
	for (j=0;j<sizeof(ranks);j++)
	if (ranks[j]==all_classes[i]&&positions[j]>0)
	msg+=give_rank_color(ranks[j])+NOR+":"+positions[j]+"位 ";
	return "【"+msg+"】";
}
string notice_class(int lv)
{
	string msg="",*all_classes=all_classes();
	mapping my_class_name,*class_name=class_name();
	int i,j;
	mixed *positions,*ranks;
	my_class_name=class_name[lv-1];
	positions=values(my_class_name);
	ranks=keys(my_class_name);
	for (i=0;i<sizeof(all_classes);i++)
	for (j=0;j<sizeof(ranks);j++)
	if (ranks[j]==all_classes[i]&&positions[j]>0)
	msg+=give_rank_color(ranks[j])+NOR+":"+positions[j]+"位 ";
		
	return "【"+msg+"】";
}

int synchro(object me)
{
	string group_name;
	if (!query("group_name"))
	{
		group_name=me->query("name")+"世家";
		set("group_name",group_name);
		GUIDER_D->set_group_name(me,group_name);
		save();
	}
    return 1;
}
int clear_title(object me,object ob)
{
	int rank;
	string *my_classes=({}),*all_classes=all_classes();
	rank=get_rank(me->query("id"));
	if (rank==-1)
	{
		if (ob->query("group_name"))
		tell_object(me,"你在"+ob->query("group_name")+"内的头衔被取消了。\n");
		else
		tell_object(me,"你在宗派内的头衔被取消了。\n");
		me->set_title(TITLE_GROUP);
		me->delete("group_title_by");
	}
	else
	{
		if (ob->query("my_classes"))
		my_classes=ob->query("my_classes");
		else
		for (int i=0;i<sizeof(all_classes);i++)
		my_classes+=({all_classes[i]});
		if (me->get_title(TITLE_GROUP)!=ob->query("group_name")+my_classes[rank])
		{
			if (ob->query("group_name"))
			tell_object(me,"你在"+ob->query("group_name")+"内阶层被转为"+my_classes[rank]+"。\n");
			else
			tell_object(me,"你在宗派内的阶层被转为"+my_classes[rank]+"。\n");
			me->set_title(TITLE_GROUP,ob->query("group_name")+my_classes[rank]);
			me->set("group_title_time",time());
		}
	}
	me->save();
	return 1;
}
int group_title(object me)
{
	object ob=this_object();
	int flag;
	string *list=({}),*classes=({}),*all_classes=all_classes();
	if ((objectp(GUIDER_D->get_base(me))&&ob!=GUIDER_D->get_base(me))||!objectp(GUIDER_D->get_base(me)))
	return 1;
	if ((valid_access(me)||old_student(me))&&!me->get_title(TITLE_GROUP))
	{
		if (ob->query("my_classes"))
		classes=ob->query("my_classes");
		else
		for (int i=0;i<sizeof(all_classes);i++)
		classes+=({all_classes[i]});
		me->set_title(TITLE_GROUP,ob->query("group_name")+classes[6]);
		me->set("group_title_time",time());
		me->save();
		if (arrayp(ob->query(all_classes[6])))
		list=ob->query(all_classes[6]);
		list+=({me->query("id")});
		ob->set(all_classes[6],list);
		ob->save();
	}
	clear_title(me,ob);
	return 1;
}

void init()
{
    add_action("do_eat","eat");
    add_action("do_drink","drink");
    add_action("do_query","query");
    add_action("do_gongxian","gongxian");
    add_action("do_blacklist","blacklist");
    add_action("do_change_passwd","change_password");
    add_action("do_remove_blacklist","remove_blacklist");
    add_action("do_gua","gua");
    add_action("do_gua","guashang");
    add_action("do_zhai","zhai");
	add_action("do_upgrade","upgrade");
	add_action("do_namerank","name_rank");
	add_action("do_namegroup","name_group");
	add_action("do_giverank","give_rank");
	add_action("do_clearrank","clear_rank");
	add_action("do_callsteward","wave");
	add_action("add_builder","add_builder");
	add_action("clear_builder","del_builder");
    if (owner_access(this_player())==1)
    synchro(this_player());
    group_title(this_player());
}
int do_callsteward()
{
	object ob,*all,me=this_player();
	if (get_rank(me->query("id"))==-1)
	return 0;
	all=all_inventory(this_object());
	for (int i=0;i<sizeof(all);i++)
		if (ob=all[i]->is_steward())
			ob->hello(me);
	if (!ob)
	{
		if (query("steward/due_date")&&time()>query("steward/due_date"))
		{
			tell_object(me,RED+"因为长期拖欠薪酬，老总管已经走人了。\n"+NOR);
			this_object()->delete("steward");
			this_object()->save();
			return 1;
		}
		message_vision("$N对着黑暗中招了招手。\n",me);
		ob=new("/d/parties/public/npc/zongguan");
		if (this_object()->query("steward/name")&&this_object()->query("steward/id"))
		ob->set_name(this_object()->query("steward/name"),this_object()->query("steward/id"));
		ob->move(this_object());
		ob->set("serve_place",this_object());
		message_vision("$N从黑暗中走了出来。\n",ob);
	}
	return 1;
}
int do_clearrank(string arg)
{
	object me=this_player(),pl,ob=this_object();
	string *list=({}),*all_classes=all_classes();
	if (!owner_access(me))	return 0;
	if (!arg)	return notify_fail("你要清理谁的宗派头衔？\n");
	if (get_rank(arg)==-1)	return notify_fail(arg+"并不在你的宗派里。\n");
	if (get_rank(arg)==0)	return notify_fail(arg+"作为一派宗主不能被这样除名。\n");
	if (valid_access(find_player(arg))||old_student(find_player(arg)))	return notify_fail(arg+"是你的学生或者出师的学生，只能用expellapp开除。\n");
	if (arrayp(query(all_classes[get_rank(arg)])))
	list=query(all_classes[get_rank(arg)]);
	list-=({arg});
	set(all_classes[get_rank(arg)],list);
	save();
	if (pl=find_player(arg))
	clear_title(pl,ob);
	tell_object(me,arg+"的头衔被你从宗派里取消了。\n");
	return 1;
}
int legal_old_rank(string rank,object ob)
{
	string *ranks,*all_classes=all_classes();
	mapping my_class_name,*class_name=class_name();
	my_class_name=class_name[ob->query("group_level")-1];
	if (member_array(COLOR_D->uncolor(rank),all_classes)==-1)
	return -2;
	if (my_class_name[rank]<=0)
	return -3;
	return member_array(COLOR_D->uncolor(rank),all_classes);
}
int my_authority(object me)
{
	object ob=this_object();
	mapping *class_name=class_name();
	ob->set_temp("my_class",class_name[ob->query("group_level")-1]);
	if (get_rank(me->query("id"))==-1)
	return 7;
	else
	return get_rank(me->query("id"));
}
int do_giverank(string arg)
{
	object me=this_player(),ob=this_object(),pl;
	string *list=({}),player,old_rank,rank,*my_classes=all_classes();
	int my_authority;
	mapping my_class_name;
	mixed *ranks,*positions;
	if (!ob->query("group_level"))
	return 0;
	if (!owner_access(me)&&!valid_access(me)&&!old_student(me))
	return 0;
	if (!arg||sscanf(arg, "%s as %s", player,rank)!=2)
	{
		write("给出宗派头衔的命令是 <某人> as <头衔>，可给头衔为宗主、副宗主、客卿、长老、使者、高级门徒、门徒。\n");
		write("拥有此头衔人数不能超过当前宗派等级的限制，且你必须拥有更高一级的头衔。\n");
		return 1;
	}
	if (legal_old_rank(rank,ob)==-2)
	{
		write("给出宗派头衔的命令是 <某人> as <头衔>，可给头衔为宗主、副宗主、客卿、长老、使者、高级门徒、门徒。\n");
		return 1;
	}
	if (legal_old_rank(rank,ob)==-3)
	{
		write(rank+"的头衔你的宗派级别未达到暂时不能给出。\n");
		return 1;
	}
	if (!pl=present(player,ob))
	{
		write("等"+player+"到了这里再说吧。\n");
		return 1;
	}
	if (GUIDER_D->get_base(pl)&&GUIDER_D->get_base(pl)!=ob)
	{
		write(pl->query("name")+"是别的宗派的人了。\n");
		return 1;
	}
	if (pl==me)
	{
		write("你不能授予自己头衔。\n");
		return 1;
	}
	if (my_authority(me)>=my_authority(pl))
	{
		write("你不可以给宗派内比你阶层更高或同阶的人一个新的头衔。\n");
		return 1;
	}
	if (my_authority(pl)==member_array(rank,my_classes))
	{
		write("现在"+pl->query("name")+"在宗派内的阶层就是"+rank+"。\n");
		return 1;
	}
	my_authority=my_authority(me);
	if (my_authority>=member_array(rank,my_classes))
	{
		write("你给出的头衔超出了你的权限范围。\n");
		return 1;
	}
	if (can_promote(pl,rank)!="success")
	{
		write(can_promote(pl,rank));
		return 1;
	}
	my_class_name=ob->query_temp("my_class");
	positions=values(my_class_name);
	ranks=keys(my_class_name);
	for (int i=0;i<sizeof(ranks);i++)
	{
		if (arrayp(ob->query(ranks[i]))&&member_array(player,ob->query(ranks[i]))!=-1)
		old_rank=ranks[i];
		if (arrayp(ob->query(rank)))
		{
			if (rank==ranks[i]&&sizeof(ob->query(rank))>=positions[i])
			{
				write("拥有此头衔人数已经达到了当前宗派等级的上限。\n");
				return 1;
			}
		}
	}
	if (ob->query(rank))
	list=ob->query(rank);
	list+=({player});
	ob->set(rank,list);
	if (old_rank)
	{
		list=ob->query(old_rank);
		list-=({player});
		ob->set(old_rank,list);
	}
	group_title(pl);
	if (rank=="客卿")
	pl->set("group_owner",me->query("id"));
	ob->save();
	message_vision("$N把$n在宗派中的阶层改变为"+switch_customized_rank(rank)+NOR+"。\n",me,pl);
	return 1;
}
int do_namegroup(string arg)
{
	object me=this_player(),ob=this_object();
	string g_name;
	if (!owner_access(me))
	return 0;
	if (!ob->query("group_level"))
	return 0;
	if (GUIDER_D->guider_score(me->query("id"))<NAME_GROUP_COST)
	return notify_fail("你的导师积分低于"+NAME_GROUP_COST+"点，无法进行此项操作。\n");
	if (!me->query_temp("namegroup_warning"))
	{
		me->set_temp("namegroup_warning",1);
		write("你即将重新命名你的宗派的名字，这个操作将消耗"+NAME_GROUP_COST+"导师积分，如确认请再次输入此命令。\n");
		write("命名方式类似nick，比如需要命名为"+HIR+"斧头帮"+NOR+"，则命令为name_group $HIR$斧头帮。\n");
		write(BLINK+HIR+"特别注意，为符合游戏世界的设定，名称必须带有武侠色彩或古雅的，否则宗派名称将被删除！\n"+NOR);
		return 1;
	}
	if (!arg||sscanf(arg, "%s",g_name)!=1)
	{
		write("命名宗派的格式为name_group <宗派新名称> 。\n");
		return 1;
	}
	if (strwidth(g_name)>20)
	{
		write("宗派名称最长十个字符。\n");
		return 1;
	}
	g_name= F_NAME->replace_color(g_name);
	write("你将宗派更名为"+g_name+"。\n"+NOR);
	shout(HIY+me->query("name")+"的宗派现更名为"+g_name+"。\n"+NOR);
	notice_credit_cost(me,NAME_GROUP_COST);
	ob->set("group_name",g_name);
	GUIDER_D->set_group_name(me,g_name);
	ob->save();
	members_modify("ALL");
	return 1;
}
int do_namerank(string arg)
{
	object me=this_player(),ob=this_object();
	string old_rank,new_rank,*my_classes=({}),*all_classes=all_classes();
	if (!owner_access(me))
	return 0;
	if (!ob->query("group_level"))
	return 0;
	if (GUIDER_D->guider_score(me->query("id"))<RE_RANK_COST)
	return notify_fail("你的导师积分低于"+RE_RANK_COST+"点，无法进行此项操作。\n");
	if (!me->query_temp("namerank_warning"))
	{
		me->set_temp("namerank_warning",1);
		write("你选择了重新命名你宗派内的结构，这项操作将会消耗"+RE_RANK_COST+"点导师积分，如确认请再次输入此命令。\n");
		write(HIR+"为避免重新命名再次消耗导师积分，请每步慎重输入。\n"+NOR);
		write("重新命名的格式为name_rank <已有头衔> to <新头衔>，如不知道本宗派已知头衔，可用query -rank查询。\n");
		return 1;
	}
	if (!arg||sscanf(arg, "%s to %s", old_rank,new_rank)!=2)
	{
		write("重新命名的格式为name_rank <已有头衔> to <新头衔>，如不知道本宗派已知头衔，可用query -rank查询。\n");
		return 1;
	}
	if (legal_old_rank(old_rank,ob)==-2)
	{
		write("已有头衔选择错误，重新命名的格式为name_rank <已有头衔> to <新头衔>，如不知道本宗派已知头衔，可用query -rank查询。\n");
		return 1;
	}
	if (strwidth(new_rank)>16)
	{
		write("宗派内头衔最长八个字符。\n");
		return 1;
	}
	if (ob->query("my_classes"))
	my_classes=ob->query("my_classes");
	else
	for (int i=0;i<sizeof(all_classes);i++)
	my_classes+=({all_classes[i]});
	write(HIC"你将宗派内的已有头衔"+old_rank+"替换成了"+F_NAME->replace_color(new_rank)+HIC+"。\n"NOR);
	me->delete_temp("namerank_warning");
	my_classes[member_array(old_rank,all_classes)]=F_NAME->replace_color(new_rank);
	ob->set("my_classes",my_classes);
	ob->save();
	notice_credit_cost(me,RE_RANK_COST);
	members_modify(old_rank);
	return 1;
}
string show_premise_detail(int para1,int para2)
{
	if (para1>=para2)
	return HIG+para1+"/"+para2+"\n"+NOR;
	else
	return RED+para1+"/"+para2+"\n"+NOR;
}
int show_premise(object ob,object me)
{
	int lv,i;
	mapping premise,*premises=premises();
	string msg;
	if (ob->query("group_level")>=GROUP_MAX_LV)
	{
		return notify_fail("目前宗派限制在"+GROUP_MAX_LV+"级，暂时不开放下一级提升。\n");
	}
	for (i=0;i<sizeof(premises);i++)
	{
		if (ob->query("group_level")+1==premises[i]["lv"])
		{
			premise=premises[i];
			break;
		}
	}
	if (ob->query("group_name"))
	msg=ob->query("group_name");
	else
	msg="这里";
	msg+="的等级是"+HIR+ob->query("group_level")+NOR+"级，升到下一级的条件：\n";
	if (owner_access(me))
	msg+="导师积分："+show_premise_detail(GUIDER_D->guider_score(query("owner")),premise["score_consume"]);
	msg+="捐赠程度："+show_premise_detail(ob->query("donate"),premise["donate_require"]);
	msg+="毕业学生："+show_premise_detail(sizeof(GUIDER_D->oldapp_list(query("owner"))),premise["old_apps_require"]);
	msg+="当前学生："+show_premise_detail(sizeof(GUIDER_D->app_list(query("owner"))),premise["current_apps_require"]);
	tell_object(me,msg);
	return premise["score_consume"];
}
int check_premise(object me,object ob)
{
	int lv;
	mapping premise,*premises=premises();
	lv=ob->query("group_level")+1;
	for (int i=0;i<sizeof(premises);i++)
	{
		if (lv==premises[i]["lv"])
		{
			premise=premises[i];
			break;
		}
	}
	if (GUIDER_D->guider_score(me->query("id"))<premise["score_consume"]||ob->query("donate")<premise["donate_require"]
		||sizeof(GUIDER_D->oldapp_list(query("owner")))<premise["old_apps_require"]||sizeof(GUIDER_D->app_list(query("owner")))<premise["current_apps_require"])
	return 0;
	GUIDER_D->finish(me,premise["score_consume"]);
	ob->add("donate",-premise["donate_require"]);
	return 1;
}
int do_upgrade()
{
	int pl_no=0,cost;
	object ob=this_object(),me=this_player(),*all_pl;
	if (!owner_access(me))
	return notify_fail("只有此间的主人才可以主持升级的仪式！\n");
	all_pl=all_inventory(this_object());
	for (int i=0;i<sizeof(all_pl);i++)
	{
		if (userp(all_pl[i]))
		pl_no+=1;
	}
	if (pl_no<5)
	return notify_fail("这么重要的仪式，还是请多些人来观礼吧。\n");
	if (ob->query("group_level")>=GROUP_MAX_LV)
	return notify_fail("导师新手基地目前只开放到"+HIW+chinese_number(GROUP_MAX_LV)+NOR+"级。\n");
	if (!check_premise(me,ob))
	return notify_fail("这里暂时不满足升级的全部条件，请用query -premise查询升级进程。\n");
	ob->add("group_level",1);
	ob->save();
	message_vision(HIC+"$N"+HIC+"在众人的注视下，把这里升级到"+chinese_number(ob->query("group_level"))+"级。\n"+NOR,me);
	tell_object(me,"现在在你的宗派里允许的阶层有"+notice_class_modify(ob)+"。\n");
	if (stringp(ob->query("group_name")))
	shout(HIC+ob->query("group_name")+HIC+"升级到了"+chinese_number(ob->query("group_level"))+"级。\n"+NOR);
	else
	shout(HIC+me->query("name")+HIC+"的导师门派升级到了"+chinese_number(ob->query("group_level"))+"级。\n"+NOR);
	tell_object(me,"需要消耗导师积分"+show_premise(ob,me)+"点。\n");
	return 1;
}
int entry_code(string arg,object me,object real,mapping *ent,int index)
{
    object rm;
    if (!arg)
    {
        tell_object(me,"你必须设定一个进入这处宅子的口令，否则还是使用旧指令进入！\n");
        write(HIC+"请输入新的口令！\n"+NOR);
        input_to( (: entry_code :), me,real,ent,index);
        return 1;
    }
    if (strwidth(arg)>30)
    {
        tell_object(me,"你设定进入这处宅子的口令不能过长！\n");
        write(HIC+"请输入新的口令！\n"+NOR);
        input_to( (: entry_code :), me,real,ent,index);
        return 1;
    }
    ent[index]["entry_code"]=arg;
    real->save_entry(ent);
    if (rm=load_object(ent[index]["entry"]))
	rm->get_lv();
    write(HIG+"恭喜！你的宅子设定新口令完成！是"+ent[index]["entry_code"]+"，可别忘了，也要记得告诉你的徒弟们！\n"+NOR);
	notice_credit_cost(me,CHANGE_PWD);
    real->save();
    return 1;
}

int do_change_passwd()
{
    object room,me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *ent;
    int i,index=-1;
    ent=real->real_estate();
    if (!owner_access(me))
    {
        write("只有此间的主人才可以修改进入的口令！\n");
        return 1;
    }
    for (i=0;i<sizeof(ent);i++)
    if (ent[i]["owner"]==me->query("id"))
	index=i;
    if (index<0)
	{
		if (me->query("id")=="zine")
		tell_object(me,"index为负！\n");
		return 0;
	}
	if ((int)GUIDER_D->guider_score(me->query("id"))<CHANGE_PWD)
    {
        write("你的新手导师积分不够了，改变口令需要"+CHANGE_PWD+"点导师积分！\n");
        return 1;
    }
    if (!me->query_temp("change_passwd_notice"))
    {
        me->set_temp("change_passwd_notice",1);
        write("改变口令需要消耗"+CHANGE_PWD+"点导师积分！如果确认请再次输入change_password。\n");
        return 1;
    }
    write(HIC+"请输入新的口令！\n"+NOR);
    input_to( (: entry_code :), me,real,ent,index);
    return 1;
}
int do_remove_blacklist(string arg)
{
	object me=this_player();
    string *denied,id;
    if (!owner_access(me))
    {
        tell_object(me,"只有此间的主人才能改变黑名单！\n");
        return 1;
    }
    if (!arg||sscanf(arg,"%s",id)!=1)
    {
        tell_object(me,"你要把谁从黑名单里去除？\n");
        return 1;
    }
    denied=query("denied");
    if (member_array(id,denied)<0)
    {
        tell_object(me,id+"并不在黑名单中！\n");
        return 1;
    }
    denied-=({id});
    set("denied",denied);
	save();
    write("你将"+id+"从黑名单中去掉了，以后他可以通过口令进来这里了！\n");
    return 1;
}

int do_blacklist(string arg)
{
    object me=this_player();
    string *denied=({}),id;
    if (!owner_access(me))
    {
        tell_object(me,"只有此间的主人才能设定黑名单！\n");
        return 1;
    }
    if (!arg||sscanf(arg,"%s",id)!=1)
    {
        tell_object(me,"你要把谁加入黑名单？\n");
        return 1;
    }
    if (id=="zine")
    {
        write("做梦！Zine是你能block的吗？\n");
        return 1;
    }
    if (query("denied"))
    denied=query("denied");
	denied+=({id});
    set("denied",denied);
    save();
    write("你将"+id+"加入了黑名单，以后他再也不能进来了！\n");
    return 1;
}

int do_gongxian(string arg)
{
    object me=this_player();
    int amount,got;
    string type,*types=({"dz","lian","du"}),*eff=({"打坐吐纳","练习外功","读书学习"});
    if (!old_student(me))
    {
        tell_object(me,"只有从这里学成的学生才可以贡献一些金钱。\n");
        return 1;
    }
    if( !arg || sscanf(arg, "%d to %s", amount,type)!=2)
    {
        tell_object(me,"贡献的格式是 gongxian <金> to <项目>，如：gongxian 500 to lian。\n");
        tell_object(me,"可贡献的项目有dz,lian,du三种！\n");
        return 1;
    }
    if (amount<=0)
    {
        tell_object(me,"你在实验什么bug呢？别异想天开了！\n");
        return 1;
    }
    if (amount>(int)me->query("balance")/10000)
    {
        tell_object(me,"理想很美好，可惜现实很残酷，你的存款只有"+MONEY_D->money_str(me->query("balance"))+"。\n");
        return 1;
    }
    if (amount+(int)me->query("newbie/donate_to_old_guider")>me->query("combat_exp")/100000)
    {
        tell_object(me,"你已经为师门捐赠了"+chinese_number(me->query("newbie/donate_to_old_guider"))+"两黄金了，量力而行啊！\n");
        tell_object(me,"在实战经验增加之前，你最多再捐赠"+RED+chinese_number((int)me->query("combat_exp")/100000-(int)me->query("newbie/donate_to_old_guider"))+NOR+"两黄金。\n");
        return 1;
    }
	if (member_array(type,types)==-1)
	{
		tell_object(me,"可贡献的项目只有dz,lian,du三种！\n");
        return 1;
	}
	me->add("balance",-amount*10000);
	me->add("newbie/donate_to_old_guider",amount);
	for (int i=0;i<sizeof(types);i++)
	{
		if (type==types[i])
		{
			tell_object(me,"你捐献了"+chinese_number(amount)+"两金，用以提升这里的"+eff[i]+"效率！\n");
			add("overall_"+types[i]+"_donate",amount/10);
		}
	}
	add("donate",amount);
    save();
	return 1;
}
int clear_room(object ob)
{
	object *all=all_inventory(ob);
	for (int i=0;i<sizeof(all);i++)
	if (!userp(all[i]))
	destruct(all[i]);
	tell_room(ob,ob->query("short")+"里的东西不为人注意，都滚落墙角，再也不见踪迹。\n");
}
int get_lv()
{
    object ob;
    int i,loss;
    mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]),*types=({"dz","lian","du"}),*rooms=({"lian","dazuo","du","sleep","court"});
    set("room_number",10000);
    if (query("new_names/10000"))
	set("short",query("new_names/10000"));
	if (query("new_longs/10000"))
	set("long",query("new_longs/10000"));
	delete("realmap");
    delete_temp("mixed_long");
	clear_room(this_object());
    if (query("decrease_date")!=date)
    {
		for (i=0;i<sizeof(types);i++)
		{
			loss=1+random(3);
			add("overall_"+types[i]+"_donate",-loss);
			if (query("overall_"+types[i]+"_donate")<0)
			set("overall_"+types[i]+"_donate",0);
			if (query("overall_"+types[i]+"_donate")>LV4&&query("overall_"+types[i]+"_level")<4)
			set(types[i]+"_level",4);
			else if (query("overall_"+types[i]+"_donate")>LV3&&query("overall_"+types[i]+"_level")<3)
			set(types[i]+"_level",3);
			else if (query("overall_"+types[i]+"_donate")>LV2&&query("overall_"+types[i]+"_level")<2)
			set(types[i]+"_level",2);
			else if (query("overall_"+types[i]+"_donate")>LV1&&query("overall_"+types[i]+"_level")<1)
			set(types[i]+"_level",1);
		}
        set("decrease_date",date);
    }
	save();
	for (i=0;i<sizeof(rooms);i++)
	{
		if (ob=load_object(__DIR__+rooms[i]))
		{
			ob->set("base",query("base"));
			ob->set("room_number",(i+1));
			if (query("new_names/"+(i+1)))
			ob->set("short",query("new_names/"+(i+1)));
			if (query("new_longs/"+(i+1)))
			ob->set("long",query("new_longs/"+(i+1)));
			ob->delete("realmap");
			ob->delete_temp("mixed_long");
			clear_room(ob);
			if (rooms[i]=="court")
			ob->retrieve();
		}
	}
	remove_call_out("get_lv");
    call_out("get_lv",3600,ob);
    return 1;
}

int level(int number)
{
    if (number==1)
    return LV2;
    else if (number==2)
	return LV3;
	else if (number==3)
	return LV4;
	else if (number==4)
	return LV4;
	else
	return LV1;
}
int rank_list(object ob,object me)
{
	string msg="本宗派",*list,id,*all_classes=all_classes();
	if (get_rank(me->query("id"))==-1)
	{
		tell_object(me,"这不是你该打听的事情。\n");
		return 1;
	}
	if (ob->query("group_name"))
	msg=ob->query("group_name");
	msg+="现有人员情况：\n";
	for (int i=0;i<sizeof(all_classes);i++)
	{
		if (arrayp(ob->query(all_classes[i])))
		msg+=all_classes[i]+":";
		for (int j=0;j<sizeof(list=ob->query(all_classes[i]));j++)
		{
			if (get_rank(id=list[j])==0)
			{
				id=HBYEL+HIW+list[j]+NOR;
			}
			msg+=id+",";
		}
		if (arrayp(list))
		msg+="\n";
	}
	tell_object(me,msg+"\n");
	return 1;
}
int steward(object ob,object me)
{
	string msg;
	if (!ob->query("steward"))
	{
		msg="这间新手基地并无一名总管。\n";
	}
	else if (time()>ob->query("steward/due_date"))
	{
		ob->delete("steward");
		ob->save();
		msg="这里的总管前些日子离开了。\n";
	}
	else
	{
		msg="这里的总管将服务至"+ctime(ob->query("steward/due_date"))+"。\n";
	}
	tell_object(me,msg);
	return 1;
}
int show_benefit(object me,int lv)
{
	string msg="";
	if (lv<1||lv>GROUP_MAX_LV)
	{
		msg+="查询级别"+HIW+lv+NOR+"超过导师基地允许的级别或小于1。\n";
	}
	else
	{
		msg+="升级到"+lv+"级后，你的宗派里允许的阶层有"+notice_class(lv)+"。\n";
	}
	tell_object(me,msg);
	return 1;
}
int do_query(string arg)
{
	object me=this_player();
	object ob=load_object(__DIR__"biguanchu");
	int dazuo,lian,du,lv;
	string msg;
	if (!valid_access(me)&&!owner_access(me)&&!old_student(me))
	{
		tell_object(me,"作为一个访客，还是不要乱打听人家的情况，这是江湖大忌！\n");
		return 1;
	}
	if (arg=="-premise")	return show_premise(ob,me);
	if (arg=="-rank")
	{
		tell_object(me,"现在这个宗派可以使用的阶层有"+notice_class_modify(ob)+"，你可以用name_rank命令改变你想要的阶层名称。\n");
		return 1;
	}
	if (arg=="-list")	return rank_list(ob,me);
	if (arg=="-steward") return steward(ob,me);
	if (arg&&sscanf(arg, "%d", lv)==1) return show_benefit(me,lv);
	dazuo=ob->query("dz_level");
	lian=ob->query("lian_level");
	du=ob->query("du_level");
    
	msg="加成效果如下：\n";
	msg+="打坐吐纳加成级别："+HIC+chinese_number(dazuo)+NOR+" 级\t";
	msg+=(int)ob->query("overall_dz_donate")+"/"+level(dazuo)+"\n";
	msg+="练习外功加成级别："+HIC+chinese_number(lian)+NOR+" 级\t";
	msg+=(int)ob->query("overall_lian_donate")+"/"+level(lian)+"\n";
	msg+="读书学习加成级别："+HIC+chinese_number(du)+NOR+" 级\t";
	msg+=(int)ob->query("overall_du_donate")+"/"+level(du)+"\n";
	tell_object(me,msg);
	return 1;
}

int do_eat()
{
    object me=this_player();
    if (me->query("food")>=(int)me->max_food_capacity()*4/5)
    {
        tell_object(me,"再吃就要撑破肚皮了。\n");
        return 1;
    }
    me->add("food",200+random(100));
    message_vision("$N拿起八仙桌上的果蔬，开始吃了起来。\n",me);
    return 1;
}

int do_drink()
{
    object me=this_player();
    if (me->query("water")>=(int)me->max_water_capacity()*4/5)
    {
        tell_object(me,"再喝就要撑破肚皮了。\n");
        return 1;
    }
    me->add("water",200+random(50));
    message_vision("$N拿起八仙桌上的水罐，慢慢喝了几口。\n",me);
    return 1;
}

//留言部分
string do_list()
{
    mapping *notes;
    int i;
    string msg,content;
	if (get_rank(this_player()->query("id"))<0||get_rank(this_player()->query("id"))>4)
	return "我是不会告诉你的。\n";
	notes = query("notes");
    if( !pointerp(notes) || !sizeof(notes) ) 
	msg="本宗派暂无任何留言。\n";
	else
	{
		msg="本宗派留言如下：\n";
		for(i=0;i<sizeof(notes);i++)
		{
			content=notes[i]["content"];
			if (strwidth(content)<40)
			content=content+"……";
			else
			content=content[0..39]+"……";
			msg+= sprintf("%s 作者：%s%s  内容：%s\n"NOR,"["+(i+1)+"]",notes[i]["author"],"("+notes[i]["authorid"]+")",content);
		}
    }
    return msg;
}

int post_limit()
{
	return query("group_level")*10+20;
}

string do_post(string arg)
{
    mapping note,*notes;
	if (get_rank(this_player()->query("id"))<0||get_rank(this_player()->query("id"))>4)
	return "你没权利在此留言。\n";
    if(!arg) return "留言必须得有内容。\n";
	if (sizeof(arg)>80) return "留言内容不可过长，如必要可分几次留言。\n";
	notes = query("notes");
	/*if (sizeof(notes)>=post_limit())
	return "本宗派的留言太多了，先删掉一些过时的吧。\n";*/
	note = allocate_mapping(3);
	note["content"] = COLOR_D->replace_color(arg);
	note["author"] = this_player()->query("name");
	note["authorid"] = geteuid(this_player());
    if( !pointerp(notes) || !sizeof(notes) )
	notes = ({ note });
    else
	notes += ({ note });
	set("notes", notes);
	save();
    return "留言完毕。\n";
}

string do_discard(string arg)
{
    mapping *notes;
    int num;

    if( !arg || sscanf(arg, "%d", num)!=1 )
	return "指令格式：discard <留言编号>\n";
    notes = query("notes");
    if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
	return "没有这个留言编号。\n";
    num--;
    if( notes[num]["authorid"] != (string) this_player(1)->query("id")
      && (get_rank(this_player()->query("id"))<0||get_rank(this_player()->query("id"))>5)
      && (string)SECURITY_D->get_status(this_player(1)) != "(admin)")
	return "这个留言不是你写的。\n";
	notes -= ({ notes[num] });
    set("notes", notes);
    save();
    return "删除第 " + (num+1) + " 号留言成功了。\n";
}

//自定义build部分
string * builder_list()
{
	string *list=({});
	if (query("builder_list"))
	list=query("builder_list");
	list+=({get_owner()});
	return list;
}

int add_builder(string arg)
{
	object me=this_player();
	string *list=({});
	if (get_owner()!=me->query("id"))
	return 0;
	if (!arg)
	return notify_fail("你要指定哪个id可以自定义建筑导师基地？\n");
	if (query("builder_list"))
	list=query("builder_list");
	if (sizeof(list))
	return notify_fail("你只能指定一人有权限自定义建筑导师基地。\n");
	list+=({arg});
	set("builder_list",list);
	save();
	tell_object(me,"你指定了"+arg+"可以自定义建筑导师基地。\n");
	return 1;
}

int clear_builder()
{
	object me=this_player();
	string *list=({});
	if (get_owner()!=me->query("id"))
	return 0;
	set("builder_list",list);
	save();
	tell_object(me,"你设定只有你自己可以自定义建筑导师基地。\n");
	return 1;
}
