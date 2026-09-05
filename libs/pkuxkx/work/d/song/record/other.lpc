inherit F_SAVE;
inherit F_DBASE;
#include <ansi.h>
#include <localtime.h>
#define SALARY_Records 10
#define DASONG "/data/business/dasong_other"
string query_save_file()
{
	return DASONG;
}
int records()
{
	return SALARY_Records;
}
void create()
{
    seteuid(getuid());
    restore();
}
int re_save(object ob,object me,int i)
{
	int j,k;
	for (j=1;j<i;j++)
	{
		k=j+1;
		ob->set("salary_record/"+me->query("id")+"/"+j,ob->query("salary_record/"+me->query("id")+"/"+k));
	}
}
int get_index(object ob,object me)
{
	for (int i=SALARY_Records;i>0;i--)
	{
		if (ob->query("salary_record/"+me->query("id")+"/"+i))
		{
			if (i<SALARY_Records)
				return i+1;
			else
				{
					re_save(ob,me,i);
					return i;
				}
		}
	}
	return 1;
}
int record(object me,string arg)
{
	int i;
	object ob=this_object();
	i=get_index(ob,me);
	ob->set("salary_record/"+me->query("id")+"/"+i,arg);
	ob->save();
	return 1;
}

int get_guanyin_from_players()
{
	object *ob,gy;
	int i;
	ob=DASONG_D->song_players();
	for (i=0;i<sizeof(ob);i++)
	{
		if (objectp(gy=ob[i]->query_temp("song_identification")))
		{
			destruct(gy);
			tell_object(ob[i],"朝廷即将使用新的官印，收回了你的旧官印。\n");
		}
	}
	return 1;
}
int guanyin_player(object me)
{
	int i,flag=0;
	object gy,common_gy;
	string theyin,officer;
	if (!me)
	return 1;
	if (!me->query("song/pro"))
	return 1;
	if (me->query("song/pro")=="文")
	{
		officer="小吏";
		theyin="/d/song/obj/guanyin";
	}
	else if (me->query("song/pro")=="武")
	{
		officer="军士";
		theyin="/d/song/obj/peijian";
	}
	else if (me->query("song/pro")=="宦")
	{
		officer="小黄门";
		theyin="/d/song/obj/fuchen";
	}
	common_gy=load_object(theyin);
	if (!objectp(gy=me->query_temp("song_identification"))||!gy->is_guanyin())
	{
		flag=1;
	}
	else if (!present(gy,me)||common_gy->query("version")>gy->query("version"))
	{
		destruct(gy);
		flag=1;
	}
	if (flag)
	{
		gy=new(theyin);
		gy->set("owner",me->query("id"));
		gy->move(me);
		tell_object(me,"一个"+officer+"慌慌张张地跑了过来：“"+me->query("name")+"大人，朝廷发放了新的"+gy->query("name")+"。”\n");
		tell_object(me,officer+"把你的"+gy->query("name")+"郑重地交了给你。\n");
	}
	return 1;
}
int guanyin_players()
{
	object *ob=DASONG_D->song_players();
	for (int i=0;i<sizeof(ob);i++)
	guanyin_player(ob[i]);
	return 1;
}

int get_officer()
{
	object goodworker=load_object("/d/song/npc/hu_shilang");
	object *ob=DASONG_D->song_players();
	int diffcredit;
	if (sizeof(ob))
	{
		for (int i=0;i<sizeof(ob);i++)
		{
			ob[i]->set("song/lastcredit",(int)ob[i]->query("song/credit"));
			diffcredit=(int)(ob[i]->query("song/credit"))-(int)(ob[i]->query("song/precredit"));
			ob[i]->set_temp("song/increasecredit",diffcredit);
			ob[i]->set("song/precredit",(int)ob[i]->query("song/credit"));
			if (ob[i]->query_temp("song/increasecredit")>goodworker->query_temp("song/increasecredit")&&ob[i]->query("song/pro")!="宦")
			goodworker=ob[i];
		}
		if (userp(goodworker))
		{
			message("chat",HIR"【大宋】吏部行文："+goodworker->query("name")+HIR+"("+goodworker->query("id")+")本季度功勋最为卓著！\n"+NOR,ob);
			goodworker->add("song/duty_promote/promote_time",-3600*3);
			tell_object(goodworker,"因为政绩出众，你在"+chinese_number(DASONG_D->get_my_pin(goodworker))+"品任上的迁转时间被缩短了。\n");
		}
	}
	return 1;
}

int salary_me()
{
	object ob;
	if (ob=DASONG_D->query("song_npcs/户部侍郎"))
	ob->salary_me();
	if (ob=DASONG_D->query("song_npcs/勾管内东门司"))
	ob->salary_me();
	return 1;
}

int promote_list(object me)
{
	string names="";
	if (this_object()->query("promote_list"))
	{
		names=this_object()->query("promote_list");
		names+="、";
		names+=me->query("name");
	}
	else
	names+=me->query("name");
	this_object()->set("promote_list",names);
	return 1;
}
int tell_promote()
{
	// object *ob= DASONG_D->song_players();
	if (this_object()->query("promote_list")==""||!this_object()->query("promote_list"))
	return 1;
	CHANNEL_D->do_channel(this_object(), "dasong", "吏部行文：近期"+this_object()->query("promote_list")+"等人获得提升！", -1);
	delete("promote_list");
	return 1;
}
int syn_record_daemon()
{
	DASONG_D->set("salary_record",query("salary_record"));
	DASONG_D->set("military_record",query("military_record"));
	DASONG_D->set("gov_record",query("gov_record"));
}

int multi_record(object me,int salary,string type,int flag)
{
	mixed* timeinfos= localtime(time());
	int wkday=timeinfos[LT_WDAY];
	if (wkday==2)
	delete("multi_record/no_renew");
	if (wkday==1)
	{
		if (!query("multi_record/no_renew"))
		{
			delete("salary_record");
			delete("military_record");
			delete("gov_record");
		}
		set("multi_record/no_renew",1);
	}
	if (flag==1)
	{
		add("salary_record/"+type+"/total",salary);
		add("salary_record/overall",salary);
		if (me->query("song/pro"))
		add("salary_record/"+type+"/"+me->query("song/pro")+"/sum",salary);
		if (type!="报效")
		log_file("user/song_players_benefit",sprintf("%s%s%s\n",me->query("id"),ctime(time()),MONEY_D->money_str(salary)));
	}
	if (flag==2)
	add("military_record/"+type+"/total",salary);
	if (flag==3)
	add("gov_record/"+type+"/total",salary);
	save();
	return 1;
}