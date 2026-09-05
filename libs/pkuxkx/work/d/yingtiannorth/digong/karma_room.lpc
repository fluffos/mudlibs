inherit ROOM;
#include <ansi.h>
int is_KARMA_ROOM()
{
	return 1;
}
void init_maze(int flag)
{
	mapping oppo_dir=(["south":"north","north":"south","west":"east","east":"west","northwest":"southeast","southeast":"northwest","southwest":"northeast","northeast":"southwest"]);
	string MAZE=__DIR__"level"+flag+"maze",dir,*dirs,*pre_dirs;
	object room,npc;
	if (flag==1)
	{
		set("exits", ([
		"east" : MAZE+random(query("maze")),
		"west" : MAZE+random(query("maze")),
		"north" : MAZE+random(query("maze")),
		"south" : MAZE+random(query("maze")),
		]));
		if (query("maze")<7)
		{
			dirs=({"west","east","south","north"});
			if (room=load_object(MAZE+(query("maze")-2)))
			{
				pre_dirs=keys(room->query("exits"));
				for (int i=0;i<sizeof(pre_dirs);i++)
				if (room->query("exits/"+pre_dirs[i])==file_name(this_object()))
				dirs-=({oppo_dir[pre_dirs[i]]});
			}
			dir=dirs[random(sizeof(dirs))];
			set("exits/"+dir,MAZE+query("maze"));
			load_object(MAZE+query("maze"))->set("exits/"+oppo_dir[dir],this_object());
			set("theDir",dir);
		}
	}
	if (flag==2)
	{
		set("exits", ([
		"southeast" : MAZE+random(query("maze")),
		"southwest" : MAZE+random(query("maze")),
		"northwest" : MAZE+random(query("maze")),
		"northeast" : MAZE+random(query("maze")),
		]));
		if (query("maze")<9)
		{
			dirs=({"southwest","southeast","northwest","northeast"});
			if (room=load_object(MAZE+(query("maze")-2)))
			{
				pre_dirs=keys(room->query("exits"));
				for (int i=0;i<sizeof(pre_dirs);i++)
				if (room->query("exits/"+pre_dirs[i])==file_name(this_object()))
				dirs-=({oppo_dir[pre_dirs[i]]});
			}
			dir=dirs[random(sizeof(dirs))];
			set("exits/"+dir,MAZE+query("maze"));
			load_object(MAZE+query("maze"))->set("exits/"+oppo_dir[dir],this_object());
			set("theDir",dir);
			for (int i=0;i<2+random(4);i++)
			{
				npc=new(__DIR__"npc/m_robber");
				npc->move(this_object());
			}
		}
	}
}
int valid_leave(object me,string dir)
{
	object origin=load_object(__DIR__"level1entry");
	string *id_list;  
	if (userp(me))
	{
		me->remove_listen_to_die(this_object());  
		if (!origin->query("id_list")||!arrayp(origin->query("id_list")))
		return ::valid_leave(me,dir);
		id_list=origin->query("id_list");
		if (userp(me)&&member_array(me->query("id"),id_list)!=-1)
		id_list-=({me->query("id")});
		origin->set("id_list",id_list);
	}
	return ::valid_leave(me,dir);
}
void Add_Credit(object Mark_Object,string Mark,object User,int Credit)
{
	if (!Mark_Object->query_temp(Mark))
	{
		Mark_Object->set_temp(Mark,1);
		User->add("karma/credit",Credit);
		tell_object(User,HIC+"你获得一些倒浮屠积分，你此次总共获得了"+User->query("karma/credit")+"点倒浮屠积分。\n"+NOR);
	}
}
void init()
{
	object me=this_player(),ob=this_object(),origin=load_object(__DIR__"level1entry");
	string *id_list=({});
	set("no_die",1);
	add_action("do_leave","leave");
	add_action("do_remain","remain");
	if (userp(me))
	{
		me->listen_to_die(ob);	
		if (origin->query("id_list")&&arrayp(origin->query("id_list")))
		id_list=origin->query("id_list");
		if (member_array(me->query("id"),id_list)==-1)
		id_list+=({me->query("id")});
		origin->set("id_list",id_list);
	}
	if (wizardp(me)&&query("theDir")) tell_object(me,HBWHT+HIR+"迷宫出口方向："+NOR+query("theDir")+"\n");
	if (ob->query("entry")&&(ob->query("level")==1||ob->query("level")==2))
		ob->gen_maze(query("maze_index"));
	if (ob->query("maze")&&!ob->query_temp("karma_given"))
	Add_Credit(ob,"karma_given",me,100+ob->query("level")*25);
	if (ob->query("exit")&&!me->query_temp("karma/bonus/"+query("level")+"_given"))
	Add_Credit(me,"karma/bonus/"+ob->query("level")+"_given",me,(ob->query("level")+3)*1000);
}
int do_remain()
{
	mixed *info=filter_array(call_out_info(), (: $1[1]==$2 :), "clear_all_rooms");
	if (sizeof(info)<1)
	write(HIC"倒浮屠地宫短期内不会关闭。\n"NOR);
	else
	write(CYN"倒浮屠地宫将在"+CHINESE_D->chinese_period(info[0][2])+"后关闭。\n"NOR);
	return 1;
}
int do_leave()
{
	object me=this_player(),env;
	if (!env=environment(me)) return 0;
	if (!env->query("exit")) return 0;
	if (env->query("level")==7) 
	{
		write("都到这里了，out就出去了。\n");
		return 1;
	}
	message_vision(HIM"$N"+HIM+"决定离开倒浮屠地宫。\n"NOR,me);
	me->move("/d/yingtiannorth/qlsi2");
	CHANNEL_D->do_channel(this_object(), "bd", HIW+"◇清凉寺地宫◇\t"+me->query("name")+HIW+"在倒浮屠地宫第"+chinese_number(env->query("level"))+"层退出。\n"+NOR, -1);
	return 1;
}
int die_notify(object victim)
{
    object killer;
    if(!objectp(victim) || !userp(victim)) return 0;
    if(!environment(victim)->is_KARMA_ROOM())
    {
        victim->remove_listen_to_die(this_object());        
    }
    else
    {
		victim->set("eff_qi",10);
		victim->set("qi",10);
		victim->set("eff_jing",10);
		victim->set("jing",10);
		victim->set("neili",victim->query("max_neili")>1000?1000:victim->query("max_neili"));
		victim->set("jingli",victim->query("max_jingli")>1000?1000:victim->query("max_jingli"));
		victim->move(__DIR__"level"+environment(victim)->query("level")+"entry");
		tell_object(victim,BLINK+HIR+"你受到了严重的伤害，被队友们送回了起点，紧急治疗。\n"+NOR);
    }
    return 486;
}