// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIR"将军府"NOR);
        set("long", @LONG
这里是镇江将军的府邸，闲人不许靠近。因为近来鸡笼山上一群山贼杀人越
货，无恶不作，镇江将军也十分头疼，现在悬赏武林高手去剿灭山寨。门口已经
贴上一张告示(notice)。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                
                "north" : __DIR__"w1",
]));
		set("item_desc",(["notice":"聘请武林高手剿灭鸡笼山贼，有意者请揭榜(jie)。——镇江将军。\n"]));
		set("objects",([__DIR__"npc/zhangshi":1]));
   setup();
}

void init()
{
	add_action("do_jie","jie");
	add_action("do_fail","fail");
}
int do_fail()
{
	object me=this_player();
	if (!me->query_temp("OustBandit"))
	{
		write("你没有参加清剿山寨的任务，别来将军府捣乱了。\n");
		return 1;
	}
	me->delete_temp("OustBandit");
	message_vision(HIC"趁着所有人不注意，$N"+HIC+"偷偷在榜单上划去了自己的名字。\n"NOR,me);
	return 1;
}
int do_jie()
{
	int start_bit,high_exp,low_exp;
	object *team,me=this_player();
	string lowest_pl_name="",pl_name="",low_pl_name="",high_pl_name="",cur_pl_name="",on_pl_name="",frequent_pl_name="",*ips=({});
	string psw="",code,word="中原长江洛阳清凉峰镇江杀手帮泰山江州曲阜南昌麒麟村东天目山岳阳襄阳西天目山北京灵州大石谷星宿康亲王府畲寨全真紫禁城丐帮扬州天坛灵鹫神龙岛日月神教晋阳张家口长江北岸黄河北岸建康府南城黄河南岸白驼山明教岳王墓丝绸之路牙山成都桃源昆明嘉兴苗疆泉州天龙寺平西王府福州峨嵋桃花岛归云庄峨眉后山苏州无量山姑苏慕容华山凌霄城临安府小山村大轮寺西湖大理城中武当山临安府提督府少林寺建康府北城古墓临安府皇宫中原信阳西湖梅庄长安";
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	if (!team=me->query_team())
	{
		write("这个任务十分凶险，不是一个人能完成的。\n");
		return 1;
	}
	if (!arrayp(team)||sizeof(team)<1)
	{
		write("这个任务十分凶险，不是一个人能完成的。\n");
		return 1;
	}
	if (sizeof(team)<3)
	{
		write("这个任务需要至少三个人来完成。\n");
		return 1;
	}
	if (sizeof(team)>5)
	{
		write("这个任务如果超过五个人，恐怕没进山就会被山贼发现。\n");
		return 1;
	}
	high_exp=me->query("combat_exp");
	low_exp=me->query("combat_exp");
	for (int i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("OustBandit/date")!=date)
		{
			team[i]->set("OustBandit/date",date);
			team[i]->set("OustBandit/times",0);
		}
		if (member_array(team[i]->query_temp("ip"),ips)==-1)
		ips+=({team[i]->query_temp("ip")});
		else
		{
			tell_object(me,"你的队友"+team[i]->query("name")+"和另一个队内玩家可能是同一人多重登录，不允许参加清剿山寨任务。\n");
			return 1;
		}
		if (team[i]&&environment(team[i])!=this_object())
		pl_name=team[i]->query("name");
		if (team[i]->query("combat_exp")<low_exp)
		{
			low_pl_name=team[i]->query("name");
			low_exp=team[i]->query("combat_exp");
		}
		if (team[i]->query("combat_exp")>high_exp)
		{
			high_pl_name=team[i]->query("name");
			high_exp=team[i]->query("combat_exp");
		}
		if (team[i]->query("combat_exp")<6000000)
		{
			lowest_pl_name=team[i]->query("name");
		}
		high_pl_name=team[i]->query("name");
		if (time()-team[i]->query("OustBandit/Last_Time")<7200&&team[i]->query("OustBandit/times")>9)
		cur_pl_name=team[i]->query("name");
		if (team[i]->query_temp("OustBandit"))
		on_pl_name=team[i]->query("name");
		if (team[i]->query("OustBandit/times")>19)
		frequent_pl_name=team[i]->query("name");
	}
	if (pl_name!="")
	{
		write("队员"+pl_name+"现在不在这里，把他找来或者踢出去再来揭榜吧。\n");
		return 1;
	}
	if (low_exp*3<high_exp)
	{
		write("队员"+low_pl_name+"和"+high_pl_name+"经验差距太大了，无法一起组队。\n");
		return 1;
	}
	if (cur_pl_name!="")
	{
		write("队员"+cur_pl_name+"刚刚参加过清剿山寨的任务。\n");
		return 1;
	}
	if (on_pl_name!="")
	{
		write("队员"+on_pl_name+"上次清剿山寨的任务尚未完成。\n");
		return 1;
	}
	if (lowest_pl_name!="")
	{
		write("队员"+lowest_pl_name+"经验低于6M，不能参加清剿山寨任务。\n");
		return 1;
	}
	if (frequent_pl_name!="")
	{
		write("队员"+frequent_pl_name+"今天已经参加过太多次清剿山寨任务。\n");
		return 1;
	}
	message_vision("$N排开众人，上前在招贤榜上写下了一行人的名字。\n",me);
	for (int i=0;i<sizeof(team);i++)
	{
		start_bit=random(strwidth(word));
		if (start_bit%2==1) start_bit+=1;
		code=word[start_bit..start_bit+1];
		psw+=code;
		team[i]->set_temp("OustBandit/team",team);
		tell_object(team[i],"将军府司直给你的勘合是");
		if (random(100)>35||wizardp(team[i]))
		tell_object(team[i],"("+(i+1)+")"+code+"。");
		else
		ANTIROBOT_D->mxpantirobot_ex(team[i],code);
		tell_object(team[i],"\n把你们几个人的勘合内容连起来，在南水门武将面前说(say)出来。\n");
	}
	for (int i=0;i<sizeof(team);i++)
	team[i]->set_temp("OustBandit/psw",psw);
	return 1;
}

