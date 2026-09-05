inherit "/d/song/song_extra_room";
void create()
{
	set("short","看台");
	set("long","这里是演武场的看台，有三个演武擂台(leitai)。\n");
	set("item_desc", ([ 
	"leitai" : "如果你要看哪个演武场的比武，只需turn <方向>即可。\n",  
	])); 

	set("outdoors", "hangzhou");
	set("no_clean_up", 1);
	set("no_reset", 1);
}

void init()
{
	add_action("do_say",({"say","'"}));
	add_action("do_drop",({"drop"}));
	add_action("do_forbid",({"wield","unwield","study","learn","tuna","exercise","dz","apprentice","research","practice","xiulian"}));
	add_action("do_forbid2",({"kill","killall","hitall","hit"}));
	add_action("do_forbid3",({"quit","suicide"}));
	add_action("do_setjudge","setjudge");
	add_action("do_turn","turn");
}
int do_setjudge(string arg)
{
	string *list=({});
	object me=this_player(),pl;
	if (!wizardp(me))
	return 0;
	if (!pl=find_player(arg))
	{
		return notify_fail("你要选定的裁判此刻并不在线。\n");
	}
	if (this_object()->query("judge_list"))
	{
		list=this_object()->query("judge_list");
	}
	list+=({pl->query("id")});
	this_object()->set("judge_list",list);
	message_vision("$N将$n("+arg+")设定为此处的裁判官。\n",me,pl);
	return 1;
}
int do_say()
{
	return notify_fail("这里人声嘈杂，别人根本听不清说些什么。\n");
}

int do_drop()
{
	return notify_fail("这里人太多了，还是不要污染环境了。\n");
}

int do_forbid()
{
	return notify_fail("这里人太多了，不要在这里展示你的身手了，展示了也没人在意。\n");
}
int do_forbid2()
{
	return notify_fail("你刚有所行动，场边的大宋禁军用劲弩指了指你，你不得不老实下来。\n");
}
int do_forbid3()
{
	return notify_fail("选个人少点的地方离开游戏。\n");
}

int valid_leave(object me,string dir)
{
	if (!wizardp(me)&&(!this_object()->query("judge_list")||(this_object()->query("judge_list")&&member_array(me->query("id"),this_object()->query("judge_list"))==-1))&&dir!=this_object()->query("NON_bw_dir"))
	{
		return notify_fail("非比赛选手和裁判，不能进入比武擂台。\n");
	}
	return ::valid_leave(me,dir);
}

int do_turn(string arg)
{
	object me=this_player(),*user=({});
	string *dirs=keys(this_object()->query("exits"));
	if (member_array(this_object()->query("NON_bw_dir"),dirs)!=-1)
	dirs-=({this_object()->query("NON_bw_dir")});
	this_object()->set("legal_watch",dirs);
	if (member_array(arg,dirs)==-1)
	return notify_fail("你要转向哪个方向看比武？\n");
	if (this_object()->query("RELAY_"+arg)&&member_array(me,this_object()->query("RELAY_"+arg))==-1)
	return notify_fail("你决定看"+arg+"方向的比武。\n");
	if (this_object()->query("RELAY_"+arg)&&arrayp(this_object()->query("RELAY_"+arg)))
	user=this_object()->query("RELAY_"+arg);
	user+=({me});
	this_object()->set("RELAY_"+arg,user);
	tell_object(me,"你决定看"+arg+"方向的比武。\n");
	return 1;
}