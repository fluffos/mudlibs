//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "吏部大厅");
        set("long", 
"这里吏部衙门的大厅，许多官员正在这里办事。\n"

        );
        set("exits", ([
                
              
                
                
                
                "out" : __DIR__"li_room2",
                
                
                
        ]));
        
        set("objects", ([
        __DIR__"npc/daming_npca" : 1,
	    ]));
        setup();
   
}

void init()
{
	add_action("do_guidang","guidang");
	add_action("do_chaxun","chaxun");
	add_action("do_fa","fa");
	add_action("do_diao","diao");
	add_action("do_gongbu","gongbu");
}
int profile(object me)
{
	object ob=load_object("/d/yingtianfu/neicheng/shengzhi");
	if (!ob)
		{
			tell_object(me,"吏部的宗卷似乎被人破坏了。\n");
			return 0;
		}
		ob->restore();
		me->set_temp("mingtasks/libu/zongjuan",ob->query("daming_officers/data"));
		me->set_temp("mingtasks/libu/zongjuan_id",ob->query("all_the_daming_officers"));
	return 1;
}
int do_gongbu(string arg)
{
	object me=this_player(),pl;
	if (me->query_temp("mingtasks/libu/task")!=4)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libu");
		return 1;
	}
	if (me->query_temp("mingtasks/libu/task4finish"))
	{
		write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (!me->query_temp("mingtasks/libu/diao_finish"))
	{
		write("没调阅过吏部的宗卷瞎公布什么啊？\n");
		return 1;
	}
	if (!me->query_temp("mingtasks/libu/gongbu"))
	{
		write("没看过名单瞎公布什么啊？\n");
		return 1;
	}
	if (!arg)
	{
		write("你要公布的功勋最高的人是谁？\n");
		return 1;
	}
	if (member_array(arg,me->query_temp("mingtasks/libu/gongbu"))==-1)
	{
		write("凭自己喜好乱公布？当朝廷法度不存在吗？\n");
		me->add("ming/credit",-1);
		write(RED+"你的任务被取消了！\n你的大明功勋下降一点！\n"+NOR);
		me->delete_temp("mingtasks");
		return 1;
	}
	pl=find_player(arg);
	if (!pl)
	{
		CHANNEL_D->do_channel(me, "daming", arg+"吏部此次考核最优。\n");
		me->set_temp("mingtasks/libu/task4finish",1);
		write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
		return 1;
	}
	else if (pl==me)
	{
		CHANNEL_D->do_channel(me, "daming", "不好意思，吏部此次考评小弟最优，呵呵。\n");
		tell_object(me,HIW+"你的大明功勋增加一点！\n"+NOR);
	}
	else
	{
		CHANNEL_D->do_channel(me, "daming", pl->query("name")+"吏部此次考核最优，额外加功勋一点。\n");
		tell_object(pl,HIY+me->query("name")+HIY+"代表吏部替你增加功勋一点。\n"NOR);
	}
	pl->add("ming/credit",1);
	me->set_temp("mingtasks/libu/task4finish",1);
	write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
	return 1;
}
int do_diao()
{
	object me=this_player(),*pl=({}),*officer;
	int i,diffcredit,max=0;
	if (me->query_temp("mingtasks/libu/task")!=4)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libu");
		return 1;
	}
	if (me->query_temp("mingtasks/libu/task4finish"))
	{
		write(HIG+"调阅宗卷的任务完成，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (me->query_temp("mingtasks/libu/diao_finish"))
	{
		write("你不是已经调阅过吏部的宗卷了吗？\n");
		return 1;
	}
	me->set_temp("mingtasks/libu/diao_finish",1);
	officer = filter_array(children(USER_OB), (: userp :));
	officer = filter_array(officer, (: environment :));
	officer = filter_array(officer, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
	if (officer)
	{
		write(sprintf("%-30s%-30s%-30s\n","官员","前次功勋","当前功勋"));
		for (i=0;i<sizeof(officer);i++)
		{
			write(sprintf("%-30s%-30d%-30d\n",COLOR_D->uncolor(officer[i]->query("name"))+capitalize(officer[i]->query("id")),officer[i]->query("ming/precredit"),officer[i]->query("ming/credit")));
			if (officer[i]->query("ming/credit")<=0)
			continue;
			if (officer[i]->query("ming/credit")-officer[i]->query("ming/precredit")<=0)
			continue;
			diffcredit=(int)(officer[i]->query("ming/credit"))-(int)(officer[i]->query("ming/precredit"));
			officer[i]->set_temp("ming/increasecredit",diffcredit);
			if (officer[i]->query_temp("ming/increasecredit")>=max)
			{
				pl+=({officer[i]->query("id")});
				max=officer[i]->query_temp("ming/increasecredit");
			}
        }
	}
	if (!pl)
	{
		write("大明近期居然无人提升功勋，可叹可叹。\n");
		me->set_temp("mingtasks/libu/task4finish",1);
		return 1;
	}
	else
	{
		write("你马上近期公布(gongbu)功勋积攒最快的人吧。如有雷同，任选一人！\n");
		me->set_temp("mingtasks/libu/gongbu",pl);
		return 1;
	}
}
int do_guidang()
{
	object me=this_player();
	mapping person_data;
	string name,title,pro,excel,credit,*ids;
	if (me->query_temp("mingtasks/libu/task")!=2)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libu");
		return 1;
	}
	if (time()-me->query_temp("mingtasks/libu/zongjuan_time")<2)
	{
		write("你当是看闲书吗？专心点！\n");
		return 1;
	}
	if (me->query_temp("mingtasks/libu/task2finish"))
	{
		write(HIG+"这些宗卷基本归档完成了，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (!me->query_temp("mingtasks/libu/zongjuan"))
	{
		if (profile(me)==0)
		{
			return 1;
		}
	}
	ids=me->query_temp("mingtasks/libu/zongjuan_id");
	person_data=me->query_temp("mingtasks/libu/zongjuan/"+ids[random(sizeof(ids))]);
	name=person_data["name"];
	title=person_data["position"];
	pro=person_data["profession"];
	excel=chinese_number(person_data["excellent_records"]);
	credit=chinese_number(person_data["credit"]);
	message_vision("$N开始翻阅吏部的宗卷……\n",me);
	write(WHT+"你读到："+name+"，"+title+"，"+pro+"职官员");
	if (me->query("mingpin")&&me->query("mingpin")<3)
	{
		write(excel+"次仕途优评。");
		if (me->query("mingpin")<2)
		{
			write("功勋"+excel+"点");
		}
	}
	write("。\n"+NOR);
	me->set_temp("mingtasks/libu/zongjuan_time",time());
	me->add_temp("mingtasks/libu/zongjuan_degree",1);
	if (me->query_temp("mingtasks/libu/zongjuan_degree")>8+random(8))
	{
		me->set_temp("mingtasks/libu/task2finish",1);
		write(HIG+"这些宗卷基本归档完成了，你可以回去复命了。\n"+NOR);
	}
	return 1;
}
int suici(object me,object pl)
{
	object baoshi;
	string gem;
	int grade,i;
	i = random(20);
	baoshi= new("/obj/gem/gem");
	if (i < 3) gem = "yan";
	else if (i < 6) gem = "mu";
	else if (i < 9) gem = "sui";
	else if (i < 12) gem = "jin";
	else if (i < 15) gem = "bing";	
	else if (i < 16) gem = "gu";
	else if (i < 17) gem = "yu";
	else if (i < 18) gem = "jiao";
	else gem = "jia";
	if (pl->query("ming/juewei_1"))
	{
		baoshi->set_level(9816,9999,gem);
	}
	else if (pl->query("ming/juewei_2"))
	{
		baoshi->set_level(9446,9999,gem);
	}
	else
	{
		baoshi->set_level(8336,9999,gem);
	}
	baoshi->move(pl);
	CHANNEL_D->do_channel(me, "daming", pl->query("name")+"受岁赐宝石一枚。");
	tell_object(pl,HIY+me->query("name")+HIY+"代表朝廷岁赐"+baoshi->query("name")+HIY+"一枚予你。\n"NOR);
	return 1;
}
int do_fa(string arg)
{
	object me=this_player(),pl;
	string *ids;
	if (me->query_temp("mingtasks/libu/task")!=3)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libu");
		return 1;
	}
	if (me->query_temp("mingtasks/libu/task3finish"))
	{
		write(HIG+"既然以及做完勋爵的岁赐，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (!me->query_temp("mingtasks/libu/chaxun_finish"))
	{
		write("你连查都不查就发出岁赐？当国库是你家开的啊？\n");
		return 1;
	}
	if (!me->query_temp("mingtasks/libu/xuejue"))
	{
		write("按例今年无人可获得岁赐，你要发给谁？\n");
		return 1;
	}
	if (!arg)
	{
		write("你要发岁赐给谁？\n");
		return 1;
	}
	ids=me->query_temp("mingtasks/libu/xuejue");
	if (member_array(arg,ids)==-1)
	{
		write(arg+"在岁赐名单中吗？\n");
		return 1;
	}
	if (!pl=find_player(arg))
	{
		write(arg+"已经离开了，他的岁赐就省下了。\n");
		ids-=({arg});
		me->set_temp("mingtasks/libu/xuejue",ids);
		return 1;
	}
	suici(me,pl);
	ids-=({arg});
	if (!sizeof(ids))
	{
		me->set_temp("mingtasks/libu/task3finish",1);
		write(HIG+"勋爵的岁赐发放完毕，你可以回去复命了。\n"+NOR);
		return 1;
	}
	me->set_temp("mingtasks/libu/xuejue",ids);
	return 1;
}
int do_chaxun()
{
	object me=this_player();
	object *ob;
	string *names=({}),*ids=({}),msg;
	int i,count=0;
	if (me->query_temp("mingtasks/libu/task")!=3)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libu");
		return 1;
	}
	if (me->query_temp("mingtasks/libu/task3finish"))
	{
		write(HIG+"既然以及做完勋爵的岁赐，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (me->query_temp("mingtasks/libu/chaxun_finish"))
	{
		write("你不是已经查完了吗？快点发(fa)出岁赐吧。\n");
		return 1;
	}
	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	ob = filter_array(ob, (: $1->query("mingpin")||$1->query("ming/tj/pin") :) );
	ob = filter_array(ob, (: $1->query("ming/juewei_1")||$1->query("ming/juewei_2")||$1->query("ming/juewei_3") :) );
	me->set_temp("mingtasks/libu/chaxun_finish",1);
	if (!sizeof(ob))
	{
		write("你发现按例居然没有勋爵可以享有岁赐，没想到这么容易完成了任务，回去复命吧。\n");
		me->set_temp("mingtasks/libu/task3finish",1);
		return 1;
	}
	msg=(HIW+"你发现如下官员按例应发放岁赐：");
	for (i=0;i<sizeof(ob);i++)
	{
		if (ob[i]==me)
		{
			continue;
		}
		if (time()-ob[i]->query("ming/xunjue_suici")>3600*24)
		{
			names+=({ob[i]->query("name")});
			msg+=(ob[i]->query("name")+"("+capitalize(ob[i]->query("id"))+")"+" ");
			ids+=({ob[i]->query("id")});
			ob[i]->set("ming/xunjue_suici",time());
			count=1;
		}
	}
	if (count==0)
	{
		write("你发现按例居然没有勋爵可以享有岁赐，没想到这么容易完成了任务，回去复命吧。\n");
		me->set_temp("mingtasks/libu/task3finish",1);
		return 1;
	}
	me->set_temp("mingtasks/libu/xuejue",ids);
	msg+=("\n那就赶紧发放(fa <id>)下去吧。\n");
	tell_object(me,msg);
	return 1;
}