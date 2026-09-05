
inherit ROOM;
inherit F_SAVE;
#define DASONG "/data/business/dasong"
string query_save_file()
{
        return DASONG;
}
#include <ansi.h>
int get_task_giver();
void create()
{
        set("short", "圣旨发布处");
        set("long", "这里发布圣旨的地方。\n");
        set("exits", ([
        
        ]));
        
        set("no_reset",1);
        set("no_clean_up", 1);
        setup();
        "/clone/board/dasong_notice_b"->foo();
		restore();
		get_task_giver();
}
int get_task_giver()
{
	mixed tm=localtime(time());
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	string *wen=({"同中书门下平章事","参知政事","门下侍郎","中书侍郎"});
	string *wu=({"枢密使","枢密副使","知枢密院事","同知枢密院事"});
	string *huan=({"入内内侍省都都知"});
	if (query("task_giver_date")!=day)
	{
		set("task_giver_date",day);
		set("task_giver_wu",wu[random(sizeof(wu))]);
		set("task_giver_wen",wen[random(sizeof(wen))]);
		set("task_giver_huan",huan[random(sizeof(huan))]);
	}
	remove_call_out("get_task_giver");
	call_out("get_task_giver",3600);
	return 1;
}
int give_jue(string arg)
{
	object pl;
	if (this_player()->query("id")!="zine")
	return 0;
	if (!pl=find_player(arg))
	{
		return notify_fail("并无"+arg+"此人。\n");
	}
	if (!pl->query("song/pro")&&!pl->query_temp("song/non_song_give_jue"))
	{
		pl->set_temp("song/non_song_give_jue",1);
		return notify_fail(arg+"不是大宋官员？确定要封爵吗？确定请再输入一次。\n");
	}
	DASONG_D->give_jue(pl,0);
	return 1;
}
string get_dasong_positions()
{
	object ob=this_object(),pl;
    mapping *titles;
    string line=HIG"--------------------------------------------------------------------------------------------------\n"NOR;
	string col=HIG"|"NOR,msg=sprintf("\n%|122s%s%s",HBRED+HIR+"大宋高级官员列表\n"+NOR,"\n",line),*msg_wen=({}),*msg_wu=({});
    int i,j;
    titles=ob->query("give_titles");
    if (!titles)
    return "吏部的人正忙着岁考的官员磨勘，暂时无法受理你的查询。\n";
    for (i=0;i<sizeof(titles);i++)
    {
		if (arrayp(titles[i]["owner"])&&sizeof(titles[i]["owner"]))
		{
			if (titles[i]["pro"]=="文")
			msg_wen+=({sprintf("%s%-50s%s",col,HIB+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"][0],col)});
			else
			msg_wu+=({sprintf("%s%-50s%s",col,HIR+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"][0],col)});
		}
        else if (titles[i]["owner"]!="")
        {
			if (arrayp(titles[i]["owner"]))
			{
				for (j=0;j<sizeof(titles[i]["owner"]);j++)
				{
					if (titles[i]["pro"]=="文")
					msg_wen+=({sprintf("%s%-50s%s",col,HIB+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"][j],col)});
					else
					msg_wu+=({sprintf("%s%-50s%s",col,HIR+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"][j],col)});
				}
			}
			else
			{
				if (titles[i]["pro"]=="文")
				msg_wen+=({sprintf("%s%-50s%s",col,HIB+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"],col)});
				else
				msg_wu+=({sprintf("%s%-50s%s",col,HIR+titles[i]["title"]+NOR,col)+sprintf("%|12s%s",titles[i]["owner"],col)});
			}
		}
    }
	if (sizeof(msg_wen)>sizeof(msg_wu))
	{
		for (i=0;i<sizeof(msg_wu);i++)
		msg+=msg_wen[i]+msg_wu[i]+"\n";
		for (i=sizeof(msg_wu);i<sizeof(msg_wen);i++)
		msg+=msg_wen[i]+sprintf("%s%-50s%s%|12s%s",col,HIR+""+NOR,col,"",col)+"\n";
	}
	else if (sizeof(msg_wu)>sizeof(msg_wen))
	{
		for (i=0;i<sizeof(msg_wen);i++)
		msg+=msg_wen[i]+msg_wu[i]+"\n";
		for (i=sizeof(msg_wen);i<sizeof(msg_wu);i++)
		msg+=sprintf("%s%|48s",col," ")+msg_wu[i]+"\n";
	}
	else
	{
		for (i=0;i<sizeof(msg_wen);i++)
		msg+=msg_wen[i]+msg_wu[i]+"\n";
	}
	msg+=line;
    return msg;
}

void CLEAR_ALLOCATE()
{
	if (query("TopLevel/ZhengShi/time")&&time()-query("TopLevel/ZhengShi/time")>1209600)
	delete("TopLevel/Zhengshi");
	if (query("TopLevel/SanSi/time")&&time()-query("TopLevel/SanSi/time")>1209600)
	delete("TopLevel/SanSi");
	if (query("TopLevel/ShuMi/time")&&time()-query("TopLevel/ShuMi/time")>1209600)
	delete("TopLevel/ShuMi");
	save();
}