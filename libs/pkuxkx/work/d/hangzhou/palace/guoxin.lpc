// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
	set("short", HIB"管勾往来国信所"NOR);
	set("long", @LONG
这里是管勾往来国信所，负责往来国信的存档。
LONG
	);
    //set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"hetong",
		//"north" : __DIR__"yudao1",
		//"north" : __DIR__"yudao1",
		//"enter" : __DIR__"qinrui2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/guoxin" : 1,
        ])); 
	setup();
}

void init()
{
	add_action("do_teng","teng");
}
int lose(object me)
{
	tell_object(me,"国书也敢胡乱誊写？你的任务失败了！\n");
	return DASONG_D->task_finish(me,-5);
}
int check_word(object me,string word,int flag,string arg)
{
	if (flag==1)
	message_vision("$N很认真的在桌上的白纸上誊上一个“"HIR+arg+NOR+"”字。\n",me);
	if (flag==1)
		for (int i=1;i<11;i++)
			if (me->query_temp("songtasks/guoxin/line"+i))
			{
				if (strsrch(me->query_temp("songtasks/guoxin/line"+i),word)==-1)
				lose(me);
				if (i==me->query_temp("songtasks/guoxin/total_line")&&me->query_temp("songtasks/guoxin/line"+i)==me->query_temp("songtasks/guoxin/teng_words"))
				{
					me->set_temp("songtasks/guoxin/1/finish",1);
					tell_object(me,"任务完成，快去复命吧。\n");
				}
				return 1;//对了
			}
	if (flag==2)
	{
		me->delete_temp("songtasks/guoxin/teng_words");
		message_vision("$N另起一行，开始誊抄。\n",me);
		for (int i=1;i<11;i++)
		{
			if (!stringp(me->query_temp("songtasks/guoxin/line"+i)))
			continue;
			if (me->query_temp("songtasks/guoxin/line"+i)&&me->query_temp("songtasks/guoxin/line"+i)==word)
			{
				me->delete_temp("songtasks/guoxin/line"+i);
				tell_object(me,"你抄对了第"+chinese_number(i)+"行国书。\n");
				break;
			}
			else
			{
				lose(me);
				break;
			}
		}
		return 1;
	}
}
int do_teng(string arg)
{
	object me=this_player();
	string word;
	if (me->query_temp("songtasks/guoxin/task")!=1)
	return 0;
	if (strwidth(arg)!=2&&arg!="换行")
	return notify_fail("要逐字誊抄。\n");
	if (me->query_temp("songtasks/guoxin/1/finish"))
	return notify_fail("任务完成，快去复命吧。\n");
	if (arg!="换行")
	{
		if (!me->query_temp("songtasks/guoxin/teng_words"))
		{
			word=arg;
			me->set_temp("songtasks/guoxin/teng_words",word);
		}
		else
		{
			word=me->query_temp("songtasks/guoxin/teng_words");
			word+=arg;
			me->set_temp("songtasks/guoxin/teng_words",word);
		}
		return check_word(me,word,1,arg);
	}
	else
	{
		return check_word(me,me->query_temp("songtasks/guoxin/teng_words"),2,arg);
	}
}