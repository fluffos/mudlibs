#include <ansi.h>
#include <title.h>
#define FORCE_PROMOTE 324
mapping *upper()
{
	return "/d/song/config/all_positions"->upper();
}
mapping *lower()
{
	return "/d/song/config/all_positions"->lower();
}
mapping *countys()
{
	return "/d/song/config/all_positions"->countys();
}
string *jues()
{
	return "/d/song/config/all_positions"->jues();
}
//+1 1 1 1 1 1开国郡公+2 2 开国侯-3 +4 +5 -5
int get_jue_rank(string jue)
{
	string *jues=jues();
	for (int i=0;i<sizeof(jues);i++)
	{
		if (strsrch(jue,jues[i])!=-1)
		{
			return i+1;
		}
	}
	return 0;
}
string get_jue(int rank)
{
	string *jues=jues();
	if (rank<1||rank>12)
	return "";
	return jues[rank-1];
}
mapping *get_prop_map(object ob,string path,mapping *inits)
{
	if (ob->query(path))
	return ob->query(path);
	else
	return inits;
}
//王 嗣王 郡王 国公 郡公 开国公 开国郡公 开国县公 开国侯 开国伯 开国子 开国男
//为王、嗣王、郡王、国公、郡公、开国公、开国郡公、开国县公、开国侯、开国伯、开国子、开国男。公、侯、伯、子、男都带本郡县开国，到封国公时，则称某国公。初次只封小国、然后改移大国。

int get_combine_title(object me,int rank,int flag)
{
	object ob=load_object("/d/song/record/other");
	mapping *inits,*prepares=({}),prepare,*new_mapping,*clear_map=({});
	int * guo=({1,2,4});
	string path,*jues=jues();
	if (flag==0&&rank==0)//上国的亲王无可封
	return 1;
	if (member_array(rank,guo)==-1)
	{
		path="juewei/juns";
		inits=countys();
	}
	else if (!flag)
	{
		path="juewei/lower_guos";
		inits=lower();
	}
	else
	{
		path="juewei/upper_guos";
		inits=upper();
	}
	new_mapping=get_prop_map(ob,path,inits);
	for (int i=0;i<sizeof(new_mapping);i++)
	{
		if (new_mapping[i]["owner"]==me->query("id"))
		{
			prepare=new_mapping[i];
			break;
		}
		if (new_mapping[i]["owner"]=="")
		prepares+=({new_mapping[i]});
	}
	if (!prepare)
	{
		if (sizeof(prepares)<1)
		{
			tell_object(me,"现在整个帝国的爵位已经全部分封出去了。\n");
			return 1;
		}
		else
		prepare=prepares[random(sizeof(prepares))];
	}
	clear_map=ob->query("juewei/"+me->query("song/xunjue/rank_from"));
	for (int i=0;i<sizeof(clear_map);i++)
	{
		if (clear_map[i]["owner"]==me->query("id"))
		{
			clear_map[i]["owner"]="";
			clear_map[i]["owner_name"]="";
		}
	}
	if (rank==2)
	rank=1;
	me->set("song/xunjue/rank",rank);
	me->set("song/xunjue/title",prepare["title"]+jues[rank-1]);
	me->set("song/xunjue/rank_from",replace_string(path,"juewei/",""));
	for (int i=0;i<sizeof(new_mapping);i++)
	{
		if (new_mapping[i]["title"]==prepare["title"])
		{
			new_mapping[i]["owner"]=me->query("id");
			new_mapping[i]["owner_name"]=me->query("name");
		}
	}
	if (!me->query("song/salary_jue"))
	me->set("song/salary_jue",me->query("mud_age"));
	me->set_title(TITLE_SONG5,me->query("song/xunjue/title"));
	tell_object(me,"你被授予了"+me->get_title(TITLE_SONG5)+"的爵位。\n");
	ob->set(path,new_mapping);
	ob->save();
	return 1;	
}
int give_jue(object me,int flag)
{
	int rank=me->query("song/xunjue/rank");
	if (!rank)
	return get_combine_title(me,12,flag);
	else if (me->query("song/xunjue/rank_from")=="lower_guos")
	return get_combine_title(me,rank,1);
	else
	return get_combine_title(me,rank-1,0);
}

int give_jue_out(string name,int flag)
{
	object pl;
	if (!pl=find_player(name))
	return notify_fail("CANNOT FIND "+name+".\n");
	if (member_array(pl,DASONG_D->song_players())==-1&&flag!=FORCE_PROMOTE)
	return notify_fail(name+" IS NOT A SONG PLAYER.\n");
	return give_jue(pl,flag);
}
int calculate_promote_times(object me,float index)
{
	int times=0,i;
	float *need=({10000,5000,3000,1000}),credit=to_float(me->query("song/credit"));
	for (i=0;i<sizeof(need);i++)
	{
		if (credit>need[i]*index&&!me->query("song/xunjue/promote_chance/at_"+to_int(need[i])))
		{
			times+=1;
			me->set("song/xunjue/promote_chance/at_"+to_int(need[i]),1);
		}
	}
	return times;
}
int if_give_jue(object me)
{
	int times;
	string pro=me->query("song/pro");
	if (pro=="武")
	times=calculate_promote_times(me,0.75);
	else if (pro=="文")
	times=calculate_promote_times(me,1.0);
	else
	times=calculate_promote_times(me,1.5);
	if (!times)
	return 1;
	for (int i=0;i<times;i++)
	{
		give_jue(me,0);
	}
	return 1;
}

int salary(object me,int period)
{
	float *salary_index=({3.0,2.8,2.5,2.0,1.8,1.5,1.4,1.3,1.1,1.0,0.8,0.75});
	if (me->query("song/xunjue/rank")<1||me->query("song/xunjue/rank")>12)
	return 0;
	return to_int(to_float(period)*salary_index[me->query("song/xunjue/rank")-1]);
}
int reset_my_jue(object me)
{
	int rank=me->query("song/xunjue/rank");
	if (rank<1||rank>12)
	return 1;
	me->delete("song/xunjue/rank");
	me->set_title(TITLE_SONG5);
	for (int i=12;i>=rank;i--)
	give_jue(me,0);
	return 1;
}