inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_step();
void create()
{
	set("long","这里是比武场，场角放着武器架。场边有台阶(taijie)通向看台。\n");
	set("item_desc", ([ 
	"taijie" : (:look_step:),
	])); 
	set("outdoors", "hangzhou");
	set("no_die", 1);
	set("no_clean_up", 1);
	set("objects", ([
        "/d/song/npc/mes" : 1,
		"/d/song/obj/jia" : 1,
        ]));
	setup();
}
int move_back(object usr)
{
	object *inv,locker=this_object()->query(usr->query("id")+"BOX");
	if (locker)
	{
		locker->delete("no_show");
		locker->move(load_object(this_object()->query("kantai")));
	}
	inv=all_inventory(usr);
	for (int i=0;i<sizeof(inv);i++)
	if (inv[i]->query("long")&&strsrch(inv[i]->query("long"),"，大宋的制式武器。")!=-1&&!inv[i]->query("value"))
	destruct(inv[i]);
	usr->move(load_object(this_object()->query("kantai")));
	this_object()->delete(usr->query("id")+"BOX");
	tell_object(usr,"比赛结束，你回到了看台。\n");
	return 1;
}
int declare(object usr,string status)
{
	if (usr)
	{
		if (status=="win")
		{
			message( "channel:" + "baowei",HIR + "【大宋演武场】" + usr->query("name")+HIR+"取得了比武的胜利。\n"NOR,users());
			move_back(usr);
		}
		if (status=="lose")
		{
			message( "channel:" + "baowei",HIR + "【大宋演武场】" + usr->query("name")+HIR+"输掉了这场比武。\n"NOR,users());
			move_back(usr);
		}
	}
	return 1;
}
int die_notify(object me)
{
	object killer = me->get_damage_origin_object();
	if (userp(me))
	{
		if (me->query("qi")<10) me->set("qi",10);
		if (me->query("eff_qi")<10) me->set("eff_qi",10);
		if (me->query("max_qi")<10) me->set("max_qi",10);
		if (me->query("jing")<10) me->set("jing",10);
		if (me->query("max_jing")<10) me->set("max_jing",10);
		if (me->query("eff_jing")<10) me->set("eff_jing",10);
		me->remove_all_killer();
		me->remove_all_enemy();
		message_vision("场边的医官及时救起了$N。\n",me);
		if (userp(killer))
		{
			declare(me,"lose");
			declare(killer,"win");
			killer->remove_all_killer();
			killer->remove_all_enemy();
		}
		return 486;
	}
	return 1;
}

void init()
{
	add_action("do_invite",({"qing","invite"}));
	add_action("do_setmatch","setmatch");
	add_action("do_send","send");
	add_action("do_down","down");
	add_action("do_declare","declare");
	add_action("forbid",({"kill","killall","hit","hitall","steal","beg"}));
	this_player()->listen_to_die(this_object());	
}
int judge_permit(object me)
{
	object kantai;
	kantai=load_object(this_object()->query("kantai"));
	if (wizardp(me))
	return 2;
	if (arrayp(kantai->query("judge_list"))&&member_array(me->query("id"),kantai->query("judge_list"))!=-1)
	return 1;
	return 0;
}
int prepare(object me)
{
	object locker=new("/d/wizard/obj/locker"),*inv=all_inventory(me),cloth;
	for (int i=0;i<sizeof(inv);i++)
	{
		inv[i]->move(locker);
	}
	locker->set("owner",me->query("id"));
	locker->set("name", me->query("name")+"的储物箱");
	locker->set("id", me->query("id")+"'s box");
	locker->set("no_show",1);
    locker->move(this_object());
	this_object()->set(me->query("id")+"BOX",locker);
	message_vision("$N把身上其他各种杂物装进储物箱，交付值场裁判。\n",me);
	cloth=new("/clone/cloth/cloth");
	cloth->move(me);
	"/cmds/std/wear"->do_wear(me,cloth);
	return 1;
}
int do_send(string arg)
{
	object me=this_player(),pl,kantai;
	if (!judge_permit(me))
	return 0;
	kantai=load_object(this_object()->query("kantai"));
	if (!kantai)
	return notify_fail("看台错误！\n");
	if (!arg||!pl=present(arg,this_object()))
	return notify_fail("你要送走的玩家不在这里。\n");
	if (!userp(pl))
	return notify_fail("你要送走的玩家不在这里。\n");
	message_vision("$N提高音量：“请"+pl->query("name")+"下台等候。”\n",me);
	move_back(pl);
	message_vision("$N潇洒地一跃下了"+this_object()->query("short")+"。\n",pl);
	return 1;
}
int do_invite(string arg)
{
	object me=this_player(),pl,kantai;
	if (!judge_permit(me))
	return 0;
	kantai=load_object(this_object()->query("kantai"));
	if (!kantai)
	return notify_fail("看台错误！\n");
	if (!arg||!pl=present(arg,kantai))
	return notify_fail("你要邀请参赛的玩家必须在看台上等候。\n");
	if (!userp(pl)||!pl->query_temp("BIWU_Checkin"))
	return notify_fail("你要邀请参赛的玩家必须是参数选手且在看台上等候。\n");
	message_vision("$N提高音量：“请"+pl->query("name")+"上台比武。”\n",me);
	pl->move(this_object());
	prepare(pl);
	message_vision("$N见提及自己，翻身跃上了"+this_object()->query("short")+"。\n",pl);
	return 1;
}
int do_setmatch(string arg)
{
	object me=this_player();
	int plnum,exp_low,exp_high;
	if (!wizardp(me))
	return 0;
	if (!arg||(sscanf("players %d",plnum)!=1&&sscanf("range %d to %d",exp_low,exp_high)!=2))
	return notify_fail("你可以设置的比赛设定格式为setmatch players <人数>：可上场人数，setmatch range <exp下限> to <exp上限>：可参赛的玩家经验限制。\n");
	if (sscanf("players %d",plnum)==1&&(plnum<2||plnum>10))
	return notify_fail("参赛玩家人数必须在2-10人之间。\n");
	if (sscanf("range %d to %d",exp_low,exp_high)==2&&(exp_low>400000000||exp_high<1000000||exp_high<=exp_low))
	return notify_fail("参赛玩家exp下限不得高于400000000，上限不得低于1000000，上限不得小于或等于下限。\n");
	if (sscanf("players %d",plnum)==1)
	{
		this_object()->set("players_limit",plnum);
		tell_object(me,"你把这里的比赛设置为最多"+chinese_number(plnum)+"人参赛。\n");
	}
	if (sscanf("range %d to %d",exp_low,exp_high)==2)
	{
		if (exp_low<=0)
		exp_low=0;
		if (exp_high>=2000000000)
		exp_high=2000000000;
		this_object()->set("players_explow",exp_low);
		this_object()->set("players_exphigh",exp_high);
		tell_object(me,"你把这里的比赛设置为最高参赛经验为："+exp_high+"，最低参赛经验为："+exp_low+"。\n");
	}
	return 1;
}
int forbid()
{
	tell_object(this_player(),"在"+this_object()->query("short")+"上，没有裁判官的命令，你不能做这条命令。\n");
	return 1;
}

int do_down()
{
	object me=this_player(),kantai;
	kantai=load_object(this_object()->query("kantai"));
	if (!judge_permit(me))
	return notify_fail("既然上台了，就专心比武吧。\n");
	tell_room(kantai,me->name()+"从"+this_object()->query("short")+"上走了下来。\n");
	me->move(kantai);
	message_vision("$N信步走下了看台。\n",me);
	return 1;
}
string look_step()
{
	object me=this_player();
	if (!judge_permit(me))
	return ("大宋的禁军战士挡住了你的视线。\n");
	return ("大宋的禁军战士让出了下台(down)的路。\n");
}
int fight_all()
{
	object *all_pl=all_inventory(this_object()),*judges;
	all_pl=filter_array(all_pl, (: userp :));
	judges=filter_array(all_pl, (: judge_permit :));
	all_pl=all_pl-judges;
	if (sizeof(all_pl)<2)
	return notify_fail("这里的参数玩家不足与进行混战。\n");
	for (int i=0;i<sizeof(all_pl);i++)
	{
		for (int j=0;j<sizeof(all_pl);j++)
		{
			if (all_pl[i]!=all_pl[j])
			{
				all_pl[i]->kill_ob(all_pl[j]);
				all_pl[j]->kill_ob(all_pl[i]);
			}
		}
	}
	tell_room(this_object(),HIR+"只听一声锣响，混战开始了！\n"+NOR);
	return 1;
}
int do_declare(string arg)
{
	object me=this_player(),pla,plb,*competitors=({});
	string pl1,pl2;
	if (!judge_permit(me))
	return 0;
	if (!arg||(sscanf(arg,"%s vs %s",pl1,pl2)!=2&&arg!="ALL"))
	return notify_fail("宣布比武开始的格式是declare <玩家甲> vs <玩家乙>或 declare ALL：混战。\n");
	if (arg=="ALL")
	return fight_all();
	if (pl1==pl2)
	return notify_fail("你只能宣布两个不同的玩家比武。\n");
	if (!objectp(pla=present(pl1,this_object()))||!objectp(plb=present(pl2,this_object())))
	return notify_fail("你宣布比武的玩家并不在场！\n");
	if (!userp(pla)||!userp(plb))
	return notify_fail("你宣布比武的玩家并不在场！\n");
	if (pla->is_fighting(plb)||plb->is_fighting(pla))
	return notify_fail(pl1+"和"+pl2+"正在比武！\n");
	if (me==pla||me==plb||judge_permit(pla)==1||judge_permit(plb)==1)
	return notify_fail("裁判官不能亲自参与比武。\n");
	tell_room(this_object(),HIR+"只听一声锣响，"+me->name()+"宣布"+pla->name()+"与"+plb->name()+"比武正式开始！\n"+NOR,({me,pla,plb}));
	tell_object(me,"你宣布"+pla->name()+"与"+plb->name()+"比武开始！\n");
	tell_object(pla,BLINK+HIR+"你和"+plb->name()+"的比武正式开始！\n"+NOR);
	tell_object(plb,BLINK+HIR+"你和"+pla->name()+"的比武正式开始！\n"+NOR);
	pla->kill_ob(plb);
	plb->kill_ob(pla);
	competitors+=({pla,plb});
	this_object()->set("competitors",competitors);
	return 1;
}


