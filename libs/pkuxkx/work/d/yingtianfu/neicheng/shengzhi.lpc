
inherit ROOM;
inherit F_SAVE;
#include <title.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#define DAMING "/data/business/daming"
string query_save_file()
{
        return DAMING;
}
#include <ansi.h>

void create()
{
        set("short", "圣旨发布处");
        set("long", "这里发布圣旨的地方。\n");
        set("exits", ([
        
        ]));
        
        set("no_reset",1);
        set("no_clean_up", 1);
        setup();
        "/clone/board/daming_notice_b"->foo();
}

void init()
{
	add_action("do_modify","modify");
	add_action("change_duty","duty");
}
int change_duty(string arg)
{
	object me=this_player(),pl;
	string id;
	int rank,diff;
	mapping title;
	if (me->query("id")!="zine")
	{
		return notify_fail("access denied,\n");
	}
	if (!arg||sscanf(arg,"%s for %d",id,rank)!=2)
	{
		return notify_fail("改变散阶的参数是：id for rank\n");
	}
	if (!pl=find_player(id))
	{
		return notify_fail("找不到玩家"+id+"\n");
	}
	if (!pl->query("mingpin"))
	{
		return notify_fail(id+"不是大明玩家\n");
	}
	if (!pl->query("ming/duty_rank"))
	{
		return notify_fail(id+"无散阶记录，无法升降散阶\n");
	}
	diff=rank;
	rank=pl->query("ming/duty_rank")+rank;
	if (rank<=0)
	{
		return notify_fail("rank negative.\n");
	}
	for (int i=0;i<sizeof(sanjie_title);i++)
	{
		if (sanjie_title[i]["rank"]==rank&&sanjie_title[i]["pro"]==me->query("ming/pro"))
		{
			title=sanjie_title[i];
			if (title["pin"]!=me->query("mingpin"))
			{
				return notify_fail("无法超越品级提升.\n");
			}
			else
			{
				pl->set("ming/duty_rank",title["rank"]);
				pl->set_title(TITLE_MING2,title["title"]);
			}
		}
	}
	tell_object(pl,"你的散阶被"+me->name()+"变更为"+pl->get_title(TITLE_MING2)+"。\n");
	tell_object(me,"你对"+id+"的实际变更级别操作为"+diff+"。\n");
	return 1;
}
int do_modify(string arg)
{
	object me=this_player(),ob=this_object();
	mapping *titles=({}),*titles2=upper_title,*titles3=lower_title;
	int i,j;
	if (me->query("id")!="zine")
	{
		return notify_fail("access denied,\n");
	}
	ob->restore();
	if (!arg||arg=="senior")
	{
		if (ob->query("give_titles"))
		titles=ob->query("give_titles");
		write(titles[sizeof(titles)-1]["title"]);
		write(titles2[sizeof(titles2)-1]["title"]);
		for (i=0;i<sizeof(titles);i++)
		{
			if (titles[i]["owner"]!="")
			{
				for (j=0;j<sizeof(titles2);j++)
				{
					if (titles2[j]["title"]==titles[i]["title"])
					{
						titles2[j]=titles[i];
					}
				}
			}
		}
		ob->set("give_titles",titles2);
		ob->save();
		return 1;
	}
	else if (arg=="junior")
	{
		if (ob->query("give_mediate_titles"))
		titles=ob->query("give_mediate_titles");
		for (i=0;i<sizeof(titles);i++)
		{
			if (titles[i]["vacacy"]>0)
			{
				for (j=0;j<sizeof(titles3);j++)
				{
					if (titles3[j]["title"]==titles[i]["title"])
					{
						titles3[j]=titles[i];
					}
				}
			}
		}
		ob->set("give_mediate_titles",titles3);
		ob->save();
		return 1;
	}
	else
	{
		return notify_fail("wrong .\n");
	}
}