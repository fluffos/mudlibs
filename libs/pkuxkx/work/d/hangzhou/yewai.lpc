inherit "/include/random_map";
#include <ansi.h>
int over();
int report_zhonghui(object me,object env);
int do_leave();
int check_me(object me);
void create() 
{ 
        set("short", "荒郊野外");
        set("long", @LONG
这里是荒郊野外，人迹罕至。
LONG
        );
	
        set("exits", ([
]));
        set("migong_name","野外"),
        set("no_clean_up", 1);
        set("no_reset", 1);
		set("no_task",1);
		set("no_die",1);
        set("outdoors", "city");
		setup();
		::create();
}

void init()
{
	add_action("do_leave","leave");
	this_player()->listen_to_die(this_object());
	if (query("UNI_EXIT"))
	this_player()->set_temp("hansz/fake_finish",1);
	::init();
}
int gene_jianxi(object me,string room)
{
	string *all_exits=values(room->query("exits")),room2,*gems=({"gu","yu","jiao","jia"});
	object npc,gem;
	int i=2+random(3),k=-1,fGem=0;
	if (random(2)&&i>=3)
	k=random(i);
	for (int j=0;j<i;j++)
	{
		npc=new(__DIR__"npc/jianxi");
		npc->do_copy(me);
		npc->move(room);
		if (!fGem)
		{
			if (random(2))
			fGem=1;
			gem=new("/obj/gem/gem");
			gem->set_level(1,1+random(8334),gems[random(sizeof(gems))]);
			gem->move(npc);
		}
		if (j==k&&k!=3)
		npc->set("double_face",1);
		if (i==4&&j==3&&all_exits&&sizeof(all_exits)>0)
		{
			room2=all_exits[random(sizeof(all_exits))];
			if (room2->query("player_num")<1)
			npc->move(room2);
			else
			npc->move(room);
		}
	}
	room->set("item_desc", ([
                "chukou" : "leave可以离开这里，通向别处。\n",]));
	room->set("UNI_EXIT",1);
	room->set_temp("mixed_long",query("long")+"这里有个出口(chukou)通向别处。\n");
	me->set_temp("hansz/jianxi_num",i);
	check_me(me);
	return 1;
}
int walk_cd(object me)
{
	int cd_base;
	if (me->query_temp("hansz/NewModeFound")) return 0;//找到了奸细
	if (!me->query_temp("hansz/mazezero")) return 0;//旧模式
	if (me->query_temp("hansz/maze_move")<=6) return 0;//前六步
	cd_base=me->query_temp("hansz/maze_move")/20+1;//每走20步多一个busy基础
	cd_base=cd_base*(2+random(4));
	return cd_base;
}
int valid_leave(object me, string dir)
{   
	if (time()-me->query_temp("hansz/attempt_move")<walk_cd(me))
	return notify_fail("在这里还走这么快，肯定无法发现奸细。\n");
	if (!me->query_temp("hansz/NewModeFound"))
	{
		if (me->query_temp("hansz/mazenext/dir"))
		{
			if (dir==me->query_temp("hansz/mazenext/dir"))
			{
				me->add_temp("hansz/mazenext/step",1);
				if (me->query_temp("hansz/mazenext/step")==sizeof(me->query_temp("hansz/mazepath")))
				{
					me->set_temp("hansz/NewModeFound",1);
					gene_jianxi(me,query("exits/"+dir));
					write(HIR+"你瞬间感到了危险临近，奸细就在附近！\n\n\n"+NOR);
					return ::valid_leave(me,dir);
				}
				me->set_temp("hansz/mazenext/dir",me->query_temp("hansz/mazepath")[me->query_temp("hansz/mazenext/step")]);
			}
			else
			me->delete_temp("hansz/mazenext");
		}
		if (me->query_temp("hansz/mazepath")&&arrayp(me->query_temp("hansz/mazepath"))&&environment(me)==me->query_temp("hansz/mazezero")&&dir==me->query_temp("hansz/mazepath")[0]&&!me->query_temp("hansz/mazenext/finding"))
		{
			me->set_temp("hansz/mazenext/finding",1);
			me->set_temp("hansz/mazenext/step",1);
			me->set_temp("hansz/mazenext/dir",me->query_temp("hansz/mazepath")[1]);
		}//for maze走法
	}
	if (me->query_temp("hansz/jianxi_place")&&me->query_temp("hansz/jianxi_place")->isroom())
	report_zhonghui(me,me->query_temp("hansz/jianxi_place"));
    me->remove_listen_to_die(this_object());
	if (me->query_temp("hansz/mazezero"))
	{
		me->add_temp("hansz/maze_move",1);
		me->set_temp("hansz/attempt_move",time());
	}
    return ::valid_leave(me, dir);
}
int do_leave()
{
	float kill_degree;
	int flag=0;
	object *inv,me=this_player(),destination;
	if (!query("UNI_EXIT"))
	return 0;
	inv=all_inventory(this_object());
	for (int i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->query("hsz_jianxi"))
		{
			flag=1;
			if (me->query_temp("hansz/job")&&!me->query_temp("hansz/want_leave"))
			{
				me->set_temp("hansz/want_leave",1);
				tell_object(me,"你还没有杀光所有奸细呢，这时候离开恐怕不能领全韩蕲王的奖励。如确认离开，请再次输入leave。\n");
				return 1;
			}
		}
	}
	if (me->query_temp("hansz/kill_jianxi"))//至少杀了一个奸细。
	{
		me->delete_temp("hansz/fake_finish");
		me->set_temp("hansz/finish",1);
	}
	kill_degree=to_float(me->query_temp("hansz/kill_jianxi"))/to_float(me->query_temp("hansz/jianxi_num"));
	if (kill_degree>=1.0&&me->query_temp("hansz/jianxi_num")>=4)
	me->set_temp("hansz/job_level",5);//3-5
	else if (kill_degree>=0.75&&me->query_temp("hansz/jianxi_num")>=3)
	me->set_temp("hansz/job_level",4);//3-5
	else if (kill_degree>=0.5&&me->query_temp("hansz/jianxi_num")>=2)
	me->set_temp("hansz/job_level",3);//3-5
	else if (kill_degree>=0.25&&me->query_temp("hansz/jianxi_num")>=2)
	me->set_temp("hansz/job_level",2);//3-5
	else
	me->set_temp("hansz/job_level",1);
	me->set_temp("hansz/finish_degree",kill_degree);
	while (!objectp(destination) || 
			!destination->isroom()||
			TASK_D->place_belong(destination)=="不明区域"||
			base_name(destination) == "/adm/daemons/taskd"||
			destination->query("hsz_no_task"))
	destination=MAP_D->random_room(me->query_temp("hansz/task_area"));
	me->move(destination);
	me->remove_listen_to_die(this_object());
	tell_object(me,"你离开了这一片奸细出没的区域。\n");
	return query("origin_file")->over();
}
int check_me(object me)
{
	if (!me)
	return over();
	if (member_array(environment(me),children(base_name(this_object())))==-1)
	return over();
	if (member_array(environment(me),children(base_name(this_object())))!=-1&&me->is_busy()&&me->is_fighting())
	{
		me->start_busy(0);//副本里玩家不能busy npc，npc也不能busy玩家
		tell_object(me,HIG+"奸细怕招来大队宋军，不敢全力施展，你挣脱对手的束缚。\n"+NOR);
	}
	remove_call_out("check_me");
	call_out("check_me",6,me);
	return 1;
}
int get_exits()
{
	return query("exits");
}
string cipher(string *path)
{
	string tmp,result="";
	mapping trans_dir=(["xiaodao":"小道","xiaolu":"小路","up":"上","down":"下","east":"东","west":"西","north":"北","south":"南","southeast":"东南",
	"southwest":"西南","northeast":"东北","northwest":"西北","northup":"北上","northdown":"北下","southup":"南上","southdown":"南下","westup":"西上","westdown":"西下","eastup":"东上","eastdown":"东下"]);
	for (int i=0;i<sizeof(path);i++)
	if (member_array(path[i],keys(trans_dir))==-1)
	result+="【"+path[i]+"】";
	else
	result+="【"+trans_dir[path[i]]+"】";
	return result;	
}
string * gene_path(object me)
{
	string env;
	string *path=({}),dir="",op_dir,*dirs;
	mapping exits;
	int i,j=4+random(3),try;
	exits=environment(me)->query("exits");
	for (i=0;i<j;i++)
	{	
		try=0;
		if (i)
		exits=env->query("exits");
		dirs=keys(exits);
		dir=dirs[random(sizeof(dirs))];
		while (try<10&&dir==op_dir)
		{
			try+=1;
			dir=dirs[random(sizeof(dirs))];
		}
		op_dir=op_position(dir);
		path+=({dir});
		env=exits[dir];
	}
	return path;
}
int NewMode(object me,string room3,string room,string * all_exits)
{
	if ((random(100)<=24||wizardp(me))&&all_exits&&sizeof(all_exits)>0)
	room3=all_exits[random(sizeof(all_exits))];
	if (!me->move(room3))
	me->move(room);
	check_me(me);
	environment(me)->set("item_desc", ([
                "chukou" : "leave可以离开这里，通向别处。\n",]));
	environment(me)->set("UNI_EXIT",1);
	environment(me)->set_temp("mixed_long",query("long")+"这里有个出口(chukou)通向别处。\n");
	tell_object(me,"\n\n"+HIW+"这时，你展开了精心绘制的地区地图，找到了异族奸细的行迹。\n"NOR);
	me->set_temp("hansz/mazezero",environment(me));
	me->set_temp("hansz/mazepath",gene_path(me));
	me->set_temp("hansz/pic_job",1);
	ANTIROBOT_D->mxpantirobot_ex(me,cipher(me->query_temp("hansz/mazepath")));
	if (wizardp(me))
	write(cipher(me->query_temp("hansz/mazepath")));
	me->set_temp("hansz/entry",environment(me));
	me->set_temp("hansz/entry_given",1);
	return 1;
}
int check_init(object me)
{
	object ob=this_object(),npc,sp_room;
	string *rooms,room="null",room2="null",room3,*all_exits;
	int i=2+random(3),k=-1,flag=random(100);
	if (!me||!environment(me))
	{
		return over();
	}
	if (base_name(environment(me))!="/d/hangzhou/xiaolu")
	{
		return over();
	}
	if (ob->query("fully_generated"))
	{
		rooms=values(ob->query("gene_rooms"));
		while (room=="null")
		room=rooms[random(sizeof(rooms))];
		rooms-=({room});
		while (room2=="null")
		room2=rooms[random(sizeof(rooms))];
		if (random(2)&&i>=3)
		k=random(i);
		if (room2&&mapp(room2->get_exits()))
		all_exits=values(room2->get_exits());
		if (flag>=54||me->query("env/hansz_new_mode")||me->query("hansz/pic_fail"))
		{
			me->set_temp("hansz/jianxi_num",4);
			return NewMode(me,room3,room,all_exits);
		}
		else
		{
			for (int j=0;j<i;j++)
			{
				npc=new(__DIR__"npc/jianxi");
				npc->do_copy(me);
				npc->move(room2);
				if (j==k&&k!=3)
				npc->set("double_face",1);
				if (i==4&&j==3&&all_exits&&sizeof(all_exits)>0)
				npc->move(all_exits[random(sizeof(all_exits))]);
			}
			if ((random(100)<=24||wizardp(me))&&all_exits&&sizeof(all_exits)>0)
			room3=all_exits[random(sizeof(all_exits))];
			if (!me->move(room3))
			me->move(room);
			tell_object(me,"不知不觉，你竟跟到了一处不知名的所在。\n");
			if (!environment(npc)||!environment(npc)->blind_random_map()||!environment(me)->blind_random_map())
			{
				tell_object(me,"异族奸细似乎已被当地官兵歼灭了，你可以回韩世忠那里复命了。\n");
				tell_object(me,"连续向北走十步，可以离开这里。\n");
				return ob->over();
			}
			me->set_temp("hansz/jianxi_num",i);
			me->set_temp("hansz/entry_given",1);
			me->set_temp("hansz/entry",environment(me));
			me->set_temp("hansz/jianxi_place",environment(npc));
			room2->set("item_desc", ([
					"chukou" : "leave可以离开这里，通向别处。\n",
			]));
			room2->set("UNI_EXIT",1);
			room2->set_temp("mixed_long",query("long")+"这里有个出口(chukou)通向别处。\n");
			check_me(me);
			return 1;
		}
	}
	remove_call_out("check_init");
	call_out("check_init",2,me);
	return 1;
}

int start(object me)
{
    object ob=this_object(),room=load_object(__DIR__"xiaolu");
	int pin=random(1000000);
	string *types=({"山地","林地","湖泽","草原"});
	me->move(room);
	room->check_me(me);
	room->set("Maze_"+me->query("id"),this_object());
    set("migong_name","韩世忠副本_"+me->query("name")),
	set("user",me);
	set("initialized",1);
	set("pin",pin);
    gene(types[random(4)],1,ob,0,0,0,0,1); //样本，随机迷宫8个参数，第一个为迷宫地貌类型，在include/random_map.h可查，第二个为迷宫复杂度，3为迷宫原点，4-7为出口，无出口则需补0,第八个参数为迷宫出口对于真实地图是否可见，不可见为1，可见为0
    call_out("check_init",1,me);
	return 1;
}

int over()
{
	clear_all();
	destruct(this_object());
	return 1;
}
int Show_Local_Map()
{
	object origin=this_object()->query("origin_file");
	string file="/d/hangzhou/obj/han_map";
	string *list=({"roomA0","room01","room02","room03","room04","room05","room06","room07","room08","room18","room11","room12","room21","room22","room23",
		"room31","room33","room35","room43","room44","room45","room54","room55","room56","room65","room66","room67","room71","room75","room77","room81","room87","room88"});
	if (!origin||!file)
	{
		write("这里暂无详细地图。\n");
		return 1;
	}
	file = read_file(file); //调用map文件
	for (int i=0;i<sizeof(list);i++ )
	file = replace_string(file, list[i],stringp(COLOR_D->uncolor(origin->query("MAZE_LIST")[list[i]]))?sprintf("%|6s",COLOR_D->uncolor(origin->query("MAZE_LIST")[list[i]])[0..5]):sprintf("%|6s","×"));
	this_player()->start_more(file);
	write(" ___________________________________________________________\n×表示此方向不通。\n");
	return 1;
}

string get_dir(object env1,object env2,object me)
{
	string desc1,desc2,desc3,desc;
	if (env1->query("x")>env2->query("x"))
	desc1="西";
	if (env1->query("x")==env2->query("x"))
	desc1="";
	if (env1->query("x")<env2->query("x"))
	desc1="东";
	if (env1->query("y")>env2->query("y"))
	desc2="南";
	if (env1->query("y")==env2->query("y"))
	desc2="";
	if (env1->query("y")<env2->query("y"))
	desc2="北";
	if (env1->query("z")>env2->query("z"))
	desc3="低";
	if (env1->query("z")==env2->query("z"))
	desc3="";
	if (env1->query("z")<env2->query("z"))
	desc3="高";
	if (desc1!=""||desc2!="")
	desc=desc1+desc2+"面";
	else
	desc="";
	if (desc3!="")
	desc+="略"+desc3;
	if (desc1==""&&desc2==""&&desc3=="")
	{
		desc="附近";
	}
	desc+="的地方。\n";
	if (desc1==""&&desc2==""&&desc3=="")
	{
		if (objectp(me->query_temp("banhe/zhonghui"))&&environment(me->query_temp("banhe/zhonghui"))!=this_object())
		desc+="如果在这里找不到异族奸细，就回到起点换条路找找，"+HIR+"比如提示西南面，可能是直接向西南走，也可能是先向西再向南走。"+NOR+"请注意。\n";
	}
	return desc;
}
int report_zhonghui(object me,object env)
{
	string dir;
	if (objectp(env)&&env->blind_random_map()&&environment(me)!=env)
	tell_object(me,"异族奸细可能在"+dir=get_dir(environment(me),env,me));
	return 1;
}
