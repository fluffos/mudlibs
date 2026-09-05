// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "考功司衙门");
	set("long", @LONG
这里是考功司的衙门。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu");
	set("exits", ([
		"west" : __DIR__+query("yamen")+"court",
	
	]));
	setup();
}

void init()
{
	add_action("do_diao","diao");
	add_action("do_gongbu","gongbu");
}

int do_gongbu(string arg)
{
	object me=this_player(),pl;
	if (me->query_temp("songtasks/libu/task")!=4)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libucourt");
		return 1;
	}
	if (me->query_temp("songtasks/libu/4/finish"))
	{
		write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (!me->query_temp("songtasks/libu/diao_finish"))
	{
		write("没调阅过吏部的宗卷瞎公布什么啊？\n");
		return 1;
	}
	if (!me->query_temp("songtasks/libu/gongbu"))
	{
		write("没看过名单瞎公布什么啊？\n");
		return 1;
	}
	if (!arg)
	{
		write("你要公布的功勋最高的人是谁？\n");
		return 1;
	}
	if (member_array(arg,me->query_temp("songtasks/libu/gongbu"))==-1)
	{
		write("凭自己喜好乱公布？当朝廷法度不存在吗？\n");
		me->add("song/credit",-1);
		write(RED+"你的任务被取消了！\n你的大宋功勋度下降一点！\n"+NOR);
		me->delete_temp("songtasks");
		return 1;
	}
	pl=find_player(arg);
	if (!pl)
	{
		CHANNEL_D->do_channel(this_object(), "dasong", arg+"吏部此次考功最优。", -1);
		me->set_temp("songtasks/libu/4/finish",1);
		write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
		return 1;
	}
	else if (pl==me)
	{
        set("name", pl->query("name"));
        set("id", pl->query("id"));
		CHANNEL_D->do_channel(this_object(), "dasong", "不好意思，吏部此次考评小弟最优，呵呵。");
        delete("name");
        delete("id");
		tell_object(me,HIW+"你的大宋功勋增加一点！\n"+NOR);
	}
	else
	{
        set("name", pl->query("name"));
        set("id", pl->query("id"));
		CHANNEL_D->do_channel(me, "dasong", pl->query("name")+"吏部此次考核最优，额外加功勋一点。");
        delete("name");
        delete("id");
		tell_object(pl,HIY+me->query("name")+HIY+"代表吏部替你增加大宋功勋度一点。\n"NOR);
	}
	pl->add("song/credit",1);
	me->set_temp("songtasks/libu/4/finish",1);
	write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
	return 1;
}
int do_diao()
{
	object me=this_player(),*pl=({}),*officer;
	int i,diffcredit,max=0;
	if (me->query_temp("songtasks/libu/task")!=4)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libucourt");
		return 1;
	}
	if (me->query_temp("songtasks/libu/4/finish"))
	{
		write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (me->query_temp("songtasks/libu/diao_finish"))
	{
		write("你不是已经调阅过吏部的宗卷了吗？\n");
		return 1;
	}
	me->set_temp("songtasks/libu/diao_finish",1);
	officer = DASONG_D->song_players();
	if (officer)
	{
		write(sprintf("%-30s%-30s%-30s\n","官员","前次功勋","当前功勋"));
		for (i=0;i<sizeof(officer);i++)
		{
			write(sprintf("%-30s%-30d%-30d\n",COLOR_D->uncolor(officer[i]->query("name"))+capitalize(officer[i]->query("id")),officer[i]->query("song/precredit"),officer[i]->query("song/credit")));
			if (officer[i]->query("song/credit")<=0)
			continue;
			if (officer[i]->query("song/credit")-officer[i]->query("song/precredit")<=0)
			continue;
			diffcredit=(int)(officer[i]->query("song/credit"))-(int)(officer[i]->query("song/precredit"));
			officer[i]->set_temp("song/increasecredit",diffcredit);
			if (officer[i]->query_temp("song/increasecredit")>=max)
			{
				pl+=({officer[i]->query("id")});
				max=officer[i]->query_temp("song/increasecredit");
			}
        }
	}
	if (!pl)
	{
		write("大宋近期居然无人提升功勋，可叹可叹。\n");
		me->set_temp("songtasks/libu/4/finish",1);
		return 1;
	}
	else
	{
		write("你马上近期公布(gongbu)功勋积攒最快的人吧。如有雷同，任选一人！\n");
		me->set_temp("songtasks/libu/gongbu",pl);
		return 1;
	}
}