//大宋任务辅助
#include <ansi.h>
#include <title.h>
int record(object me)
{
    object ob=load_object("/d/song/record/other");
    string depart_name,*names=({}),*new_names=({});
    int i,flag=0;
    if (!me->query("song/pro"))
	return 1;
	ob->set("dasong_officers/data/"+me->query("id")+"/name",me->query("name"));
	ob->set("dasong_officers/data/"+me->query("id")+"/id",me->query("id"));
	ob->set("dasong_officers/data/"+me->query("id")+"/position",me->query("song/title"));
	ob->set("dasong_officers/data/"+me->query("id")+"/profession",me->query("song/pro"));
	ob->set("dasong_officers/data/"+me->query("id")+"/credit",me->query("song/credit"));
	ob->set("dasong_officers/data/"+me->query("id")+"/excellent_records",me->query("song/suikao/overall"));
	ob->set("dasong_officers/data/"+me->query("id")+"/department",ob->get_my_depart(me));
	if (ob->query("all_the_dasong_officers"))
	names=ob->query("all_the_dasong_officers");
	if (ob->query("ALL_CHANGED_LIST_1"))
	new_names=ob->query("ALL_CHANGED_LIST_1");
	if (member_array(me->query("id"),new_names)==-1)
	{
		if (me->query("song/pro")=="武"&&me->get_title(TITLE_SONG3))
		me->set_title(TITLE_SONG3);
		new_names+=({me->query("id")});
		ob->set("ALL_CHANGED_LIST_1",new_names);
	}
	if (member_array(me->query("id"),names)==-1)
	{
		names+=({me->query("id")});
		ob->set("all_the_dasong_officers",names);
	}
	if (me->query("song/pro")!="文")
	{
		if (ob->query("pro_武"))
		names=ob->query("pro_武");
		if (member_array(me->query("id"),names)==-1)
		names+=({me->query("id")});
		ob->set("pro_武",names);
	}
	else
	{
		if (ob->query("pro_文"))
		names=ob->query("pro_文");
		if (me->query("song/pro")=="文"&&member_array(me->query("id"),names)==-1)
		names+=({me->query("id")});
		ob->set("pro_文",names);
	}
	ob->save();
	me->set("song/depart",ob->get_my_depart(me));
	if (me->query("song/depart"))
	depart_name=DASONG_D->classify_depart(me);
	for (i=100;i<301;i++) 
	{
		if (!ob->query(depart_name+"/officers/"+i)&&flag==0)
		flag=i;
		if (ob->query(depart_name+"/officers/"+i+"/id")==me->query("id"))
		return 1;
    }
	if (flag!=0)
	{
		ob->set(depart_name+"/officers/"+flag+"/id",me->query("id"));
		ob->set(depart_name+"/officers/"+flag+"/name",me->query("name"));
		ob->save();
	}
	return 1;
}
int back_me_up(object me)
{
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]),z="--";
	if (me->query("song/backup_data")==date||!me->query("song/pro"))
	return 1;
	me->set("song/backup_data",date);
	log_file("user/song_players_backup",sprintf("%s%s%s%s%s%s%s%s%s%s\n",date+":",me->query("id"),z,me->query("song/pro"),z,me->query("song/credit")+"点功勋",z,me->query("song/title"),z,"部门编号："+me->query("song/depart")));
	return 1;
}
object *song_players()
{
	object *ob=DASONG_D->song_all();
    ob = filter_array(ob, (: living :));
	return ob;
}
int npc_update_lower(mapping title,string the_title,object me)
{
    int i;
    object *npc;
    string npc_file;
	if (!stringp(npc_file=title["npc"])||npc_file=="")
	return 1;
    npc=livings();
    npc=filter_array(children(npc_file), (: clonep :));
    for (i=0;i<sizeof(npc);i++)
    {
        npc[i]->set_name(me->query("name"),({me->query("id")+" npc"}));
        npc->npc_renew(npc[i],me);
    }
    return 1;
}

int npc_player(object me)
{
	string title;
	mapping *lower_title=DASONG_D->lower_title();
	if (!me)
	return -1;
	if (!userp(me))
	return -1;
	if (!stringp(title=me->query("song/title")))
	return -1;
	for (int i=0;i<sizeof(lower_title);i++)
	if (lower_title[i]["title"]==title)
	return npc_update_lower(lower_title[i],title,me);
	return 1;
}

int get_unique_position(object me)
{
	if (DASONG_D->get_my_pin(me)>3)	
	return npc_player(me);
	return 1;
}
int force_suikao(object me)
{
	int age=me->query("mud_age");
	if (DASONG_D->get_my_pin(me)!=1&&me->query("song/suikao/time")&&me->query("mud_age")-me->query("song/suikao/time")>432000)
    {
		if (me->query("song/suikao/new_modify"))
		{
			tell_object(me,BLINK+HIR+"因为磨勘太少，你被取消晋升机会，并停发所有俸禄。\n"+NOR);
			me->set("song/suikao_longtime_not_in",1);
		}
		else
		{
			me->set("song/suikao/new_modify",1);
		}
    }
	return 1;
}

