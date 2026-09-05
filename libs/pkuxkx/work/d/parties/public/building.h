#include <ansi.h>
#define SELF_ROOM "/clone/misc/self_room"
#define PLAYER_ROOM "/clone/misc/player_room"
mapping oppo_dir=(["south":"north","north":"south","west":"east","east":"west","northeast":"southwest","northwest":"southeast","southeast":"northwest","southwest":"northeast","enter":"out","out":"enter","up":"down",
"down":"up","westup":"eastdown","westdown":"eastup","eastup":"westdown","eastdown":"westup","southup":"northdown","southdown":"northup","northup":"southdown","northdown":"southup"]);
mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);
mapping dirs_positions = ([
        "north":        ({0,1,0,0}),
        "south":        ({0,-1,0,0}),
        "east":         ({1,0,0,0}),
        "west":         ({-1,0,0,0}),
        "northup":      ({0,1,1,0}),
        "southup":      ({0,-1,1,0}),
        "eastup":       ({1,0,1,0}),
        "westup":       ({-1,0,1,0}),
        "northdown":    ({0,1,-1,0}),
        "southdown":    ({0,-1,-1,0}),
        "eastdown":     ({1,-1,0,0}),
        "westdown":     ({-1,-1,0,0}),
        "northeast":    ({1,1,0,0}),
        "northwest":    ({-1,1,0,0}),
        "southeast":    ({1,-1,0,0}),
        "southwest":    ({-1,-1,0,0}),
        "up":           ({0,0,1,0}),
        "down":         ({0,0,1,0}),
        "enter":        ({0,0,0,1}),
        "out":          ({0,0,0,-1}),
]);

int connecting(object ct,string dir,object ob,object room,int serial_no,int flag);
int is_origin()
{
	if (query("room_number")==5)
	return 1;
	return 0;
}
int extend_path(object ct,object ob,int serial_no)
{
	string *dirs;
	object room;
	int *rooms;
	if (mapp(ob->query("adv_exits")))
	{
		dirs=keys(ob->query("adv_exits"));
		rooms=values(ob->query("adv_exits"));
		for (int i=0;i<sizeof(dirs);i++)
		{
			if (rooms[i]!=ob->query("father_room"))
			{
				if (objectp(ct->query("All_Self_Buildings/"+rooms[i]+"/object")))
				room=ct->query("All_Self_Buildings/"+rooms[i]+"/object");
				else
				room=new(SELF_ROOM);
				room->set("serial_no",rooms[i]);
				ct->set("All_Self_Buildings/"+rooms[i]+"/object",room);
				connecting(ct,dirs[i],ob,room,rooms[i],0);
				room->retrieve();
			}
		}
	}
	return 1;
}

int retrieve()
{
	object ob=this_object(),ct;
	int serial_no=ob->query("serial_no");
	if (!serial_no&&!is_origin())
	return -1;
	if (load_object(__DIR__"biguanchu"))
	ct=load_object(__DIR__"biguanchu");
	else
	ct=query("Ctrl_Room");
	if (!objectp(ct))
	return -4;
	if (!ct->query("All_Self_Buildings/"+serial_no))
	return -2;
	if (query("gene_finished"))
	return -3;
	set("father_room",ct->query("All_Self_Buildings/"+serial_no+"/father_room"));
	set("adv_exits",ct->query("All_Self_Buildings/"+serial_no+"/path"));
	set("outdoors",ct->query("All_Self_Buildings/"+serial_no+"/outdoors"));
	set("Ctrl_Room",ct);
	set("no_task", 1);
    set("no_reset",1);
    set("no_clean_up", 1);
	set("gene_finished",1);
	extend_path(ct,ob,serial_no);
	return 1;
}


int save_path_logic(object ob,object ct)
{
	ct->set("All_Self_Buildings/"+ob->query("serial_no")+"/father_room",ob->query("father_room"));
	ct->set("All_Self_Buildings/"+ob->query("serial_no")+"/path",ob->query("adv_exits"));
	ct->set("All_Self_Buildings/"+ob->query("serial_no")+"/outdoors",ob->query("outdoors"));
}
int save_desc_logic(object ob,object ct)
{
	ct->set("All_Self_Buildings/"+ob->query("serial_no")+"/long",ob->query("long"));
	ct->set("All_Self_Buildings/"+ob->query("serial_no")+"/short",ob->query("short"));
	ct->set("All_Self_Buildings/"+ob->query("serial_no")+"/outdoors",ob->query("outdoors"));
}
int get_new_serial(object ct,int limit)
{
	if (!arrayp(ct->query("given_rooms")))
	{
		return 1;
	}
	for (int i=1;i<=limit;i++)
	{
		if (member_array(i,ct->query("given_rooms"))==-1)
		{
			return i;
		}
	}
	return 0;
}
int renew_mixed_long(object ob)
{
	string *rooms=values(ob->query("exits"));
	ob->delete_temp("mixed_long");
	ob->delete("realmap");
	for (int i=0;i<sizeof(rooms);i++)
	if (ob=load_object(rooms[i]))
	{
		ob->delete_temp("mixed_long");
		ob->delete("realmap");
	}
}
int decorate(object ob,object ct,int flag,string room_name,string room_desc)
{
	if (!flag)
	ob->delete("outdoors");
	ob->set("long",room_desc);
	ob->set("short",room_name);
	renew_mixed_long(ob);
	save_desc_logic(ob,ct);
	return 1;
}
int confirm(string arg,object me,object ob,string name,string desc,object ct,object bian)
{
	int flag=0;
	if (stringp(this_object()->query("outdoors")))
	flag=1;
	if (member_array(arg,({"YES","yes","Yes","Y","y"}))!=-1)
	{
		if (!bian)
		{
			tell_object(me,"你身上的牌匾呢？\n");
			return 1;
		}
		destruct(bian);
		message_vision("$N开始忙碌地整修着这里。\n",me);
		return decorate(ob,ct,flag,name,desc+"\n");
	}
	else
	{
		tell_object(me,"你放弃了整修"+this_object()->query("short")+"念头。");
		return 1;
	}
}
int get_desc(string arg,object me,object ob,object ct,object bian)
{
	if (!bian)
	{
		tell_object(me,"你身上的牌匾呢？\n");
		return 1;
	}
	if (strwidth(COLOR_D->uncolor(arg))>100)
	{
		tell_object(me,"输入的房间名过长，想一个短点的。\n");
		return 1;
	}
	arg=COLOR_D->replace_color(arg,1);
	ob->set_temp("pre_desc",arg);
	tell_object(me,"这里的房间名将为："+ob->query_temp("pre_name"));
	tell_object(me,"这里的房间的描述将为：\n"+ob->query_temp("pre_desc")+"\n");
	tell_object(me,"是否确定？(yes/no)");
	input_to( (: confirm :),me,ob,ob->query_temp("pre_name"),ob->query_temp("pre_desc"),ct,bian);
	return 1;
}
int get_name(string arg,object me,object ob,object ct,object bian)
{
	if (!bian)
	{
		tell_object(me,"你身上的牌匾呢？\n");
		return 1;
	}
	if (strwidth(COLOR_D->uncolor(arg))>16)
	{
		tell_object(me,"输入的房间名过长，想一个短点的。\n");
		return 1;
	}
	arg=COLOR_D->replace_color(arg,1);
	ob->set_temp("pre_name",arg);
	tell_object(me,"你准备把这里描述成什么样？(颜色字符请用$$，参考help nick。)");
	input_to( (: get_desc :),me,ob,ct,bian);
	return 1;
}
int name_room(object me,object ob,object ct,object bian)
{
	tell_object(me,"你准备把这里命名为什么？(颜色字符请用$$，参考help nick)");
	input_to( (: get_name :),me,ob,ct,bian);
	return 1;
}
int do_deco()
{
	object me=this_player(),ct,ob=this_object(),bian;
	if (load_object(__DIR__"biguanchu"))
	ct=load_object(__DIR__"biguanchu");
	if (objectp(ob->query("Ctrl_Room")))
	ct=ob->query("Ctrl_Room");
	if (!ct)
	{
		tell_object(me,"没有导师基地，你要往哪里盖房子啊？\n");
		return 1;
	}
	if (is_origin())
	{
		tell_object(me,"这里只能把牌匾挂起来。\n");
		return 1;
	}
	if (member_array(me->query("id"),ct->builder_list())==-1)
	{
		tell_object(me,"你没有被赋予在这里创造建筑的权限。\n");
		return 1;
	}
	if (!bian=present("pai bian",me))
	{
		tell_object(me,"你身上没有牌匾，无法装饰房间。\n");
		return 1;
	}
	if (!bian->query("is_bian"))
	{
		tell_object(me,"你身上没有牌匾，无法装饰房间。\n");
		return 1;
	}
	return name_room(me,ob,ct,bian);
}
string get_weather(object ct)
{
	string weather="city";
	mapping real;
	real="/d/parties/public/obj/real"->real_estate();
	for (int i=0;i<sizeof(real);i++)
	{
		if (real[i]["entry"]==base_name(ct))
		{
			if (stringp(load_object(real[i]["file"])->query("outdoors")))
			weather=load_object(real[i]["file"])->query("outdoors");
			break;
		}
	}
	return weather;
}
int connecting(object ct,string dir,object ob,object room,int serial_no,int flag)
{
	int *rooms=({}),*posis;
	room->set("serial_no",serial_no);
	room->set("outdoors",get_weather(ct));
	ob->set("exits/"+dir,file_name(room));
	ob->set("adv_exits/"+dir,serial_no);
	room->set("exits/"+oppo_dir[dir],file_name(ob));
	room->set("father_room",ob->query("serial_no"));
	room->set("Ctrl_Room",ct);
	renew_mixed_long(ob);
	renew_mixed_long(room);
	posis=dirs_positions[dir];
	room->set("x",ob->query("x")+posis[0]);
	room->set("y",ob->query("y")+posis[1]);
	room->set("z",ob->query("z")+posis[2]);
	room->set("eo",ob->query("eo")+posis[3]);
	posis=({room->query("x"),room->query("y"),room->query("z"),room->query("eo")});
	ct->set("All_Self_Buildings/"+serial_no+"/posis",posis);
	ct->set("All_Self_Buildings/"+serial_no+"/object",room);
		//链接逻辑保存
	if (flag)
	{
		if (arrayp(ct->query("given_rooms")))
		rooms=ct->query("given_rooms");
		if (member_array(serial_no,rooms)==-1)
		{
			rooms+=({serial_no});
			ct->set("given_rooms",rooms);
		}
		save_path_logic(ob,ct);
	}
	ct->save();
}
int exist_room(object ct,object ob,string dir)
{
	for (int i=0;i<sizeof(ct->query("All_Self_Buildings/"+i));i++)
	{
		if (arrayp(ct->query("All_Self_Buildings/"+i+"/posis")))
		if (ct->query("All_Self_Buildings/"+i+"/posis")[0]==ob->query("x")+dirs_positions[dir][0]
			&&ct->query("All_Self_Buildings/"+i+"/posis")[1]==ob->query("y")+dirs_positions[dir][1]
			&&ct->query("All_Self_Buildings/"+i+"/posis")[2]==ob->query("z")+dirs_positions[dir][2]
			&&ct->query("All_Self_Buildings/"+i+"/posis")[3]==ob->query("eo")+dirs_positions[dir][3])
		{
			return i;
		}
	}
	return 0;
}
int make_room()
{
	object me=this_player(),ob=this_object(),mucai,shicai,ct;
	if (!stringp(ob->query("outdoors")))
	{
		return notify_fail("这里已经有一间屋子了。\n");
	}
	if (!ct=ob->query("Ctrl_Room"))
	{
		return notify_fail("你没有被赋予在这里创造建筑的权限。\n");
	}
	if (member_array(me->query("id"),ct->builder_list())==-1)
	{
		tell_object(me,"你没有被赋予在这里创造建筑的权限。\n");
		return 1;
	}
	if (is_origin())
	{
		tell_object(me,"这里是公共部分，不能修建房屋。\n");
		return 1;
	}
	if (!mucai=present("mu cai",me))
	{
		tell_object(me,"你身上没有木材，无法修建房屋。\n");
		return 1;
	}
	if (!mucai->query("mucai"))
	{
		tell_object(me,"你身上没有木材，无法修建房屋。\n");
		return 1;
	}
	if (!shicai=present("shi cai",me))
	{
		tell_object(me,"你身上没有石材，无法修建房屋。\n");
		return 1;
	}
	if (!shicai->query("shicai"))
	{
		tell_object(me,"你身上没有石材，无法修建房屋。\n");
		return 1;
	}
	delete("outdoors");
	ct->delete("All_Self_Buildings/"+ob->query("serial_no")+"/outdoors");
	ct->save();
	message_vision("$N消耗了身上的"+mucai->query("name")+"和"+shicai->query("name")+"，在"+ob->query("short")+"上盖了一间房子。\n",me);
	destruct(mucai);
	destruct(shicai);
	ob->set("short","空房间");
	ob->set("long","这是一间未曾装修的空房。\n");
	save_desc_logic(ob,ct);
	return 1;
}
int connect(string dir)
{
	object ob=this_object();
	object me=this_player(),ct,room,muliao,shiliao;
	mapping exits,real;
	string *existed_dirs,*legal_dirs=keys(oppo_dir);
	int room_limit,serial;
	if (!objectp(ct=GUIDER_D->get_base(me)))
	{
		tell_object(me,"没有导师基地，你要往哪里盖房子啊？\n");
		return 1;
	}
	if (ct!=load_object(__DIR__"biguanchu")&&ob->query("Ctrl_Room")!=ct)
	{
		tell_object(me,"你没有被赋予在这里创造建筑的权限。\n");
		return 1;
	}
	if (member_array(me->query("id"),ct->builder_list())==-1)
	{
		tell_object(me,"你没有被赋予在这里创造建筑的权限。\n");
		return 1;
	}
	if (!muliao=present("mu liao",me))
	{
		tell_object(me,"你身上没有木料，无法连接道路。\n");
		return 1;
	}
	if (!muliao->query("muliao"))
	{
		tell_object(me,"你身上没有木料，无法连接道路。\n");
		return 1;
	}
	if (!shiliao=present("shi liao",me))
	{
		tell_object(me,"你身上没有石料，无法连接道路。\n");
		return 1;
	}
	if (!shiliao->query("shiliao"))
	{
		tell_object(me,"你身上没有石料，无法连接道路。\n");
		return 1;
	}
	real="/d/parties/public/obj/real"->real_estate();
	for (int i=0;i<sizeof(real);i++)
	{
		if (real[i]["entry"]==base_name(ct))
		{
			room_limit=real[i]["room_limit"];
			break;
		}
	}
	exits=ob->query("exits");
	existed_dirs=keys(exits);
	if (member_array(dir,existed_dirs)!=-1)
	{
		tell_object(me,dir+"和房间已有方向冲突，请重新选择。\n");
		return 1;
	}
	if (member_array(dir,legal_dirs)==-1)
	{
		tell_object(me,dir+"不是一个合法的方向，请重新选择。\n");
		return 1;
	}
	if (is_origin()&&sizeof(exits)>=2)
	{
		tell_object(me,"这个房间最多可以有一个自定义出口。\n");
		return 1;
	}
	serial=exist_room(ct,ob,dir);
	if (objectp(room=ct->query("All_Self_Buildings/"+serial+"/object")))
	{
		destruct(shiliao);
		destruct(muliao);
		connecting(ct,dir,ob,room,serial,1);
		tell_object(me,"你将这里向"+default_dirs[dir]+"的方向连接到"+room->query("short")+"。\n");
	}
	else if (serial=get_new_serial(ct,room_limit))
	{
		//物理创建
		room=new(SELF_ROOM);
		destruct(shiliao);
		destruct(muliao);
		connecting(ct,dir,ob,room,serial,1);
		tell_object(me,"你将这里向"+default_dirs[dir]+"的方向划分出一个房间。\n");
	}
	else
	{
		tell_object(me,"这里的空间最多可以划分为"+room_limit+"块空间，现在已经没有更多空间发展了。\n");
	}
	return 1;
}
int destroy(string arg,object me,object ob,object ct)
{
	string *sons,*son_dirs;
	object room;
	int *list;
	if (member_array(arg,({"YES","yes","Yes","Y","y"}))==-1)
	{
		message_vision("$N放弃拆毁这里的建筑。\n",me);
		return 1;
	}
	message_vision("$N开始拆毁这里的建筑。\n",me);
	son_dirs=keys(ob->query("exits"));
	sons=values(ob->query("exits"));
	list=ct->query("given_rooms");
	for (int i=0;i<sizeof(sons);i++)
	{
		if (room=load_object(sons[i]))
		{
			if (room->query("serial_no")==ob->query("father_room"))
			{
				room->delete("exits/"+oppo_dir[son_dirs[i]]);
				me->move(room);
				save_path_logic(room,ct);
				continue;
			}
			if (member_array(room->query("serial_no"),list)!=-1)
			{
				list-=({room->query("serial_no")});
				ct->set("given_rooms",list);
			}
			ct->delete("All_Self_Buildings/"+room->query("serial_no"));
			destruct(room);
		}
	}
	if (member_array(ob->query("serial_no"),list)!=-1)
	{
		list-=({ob->query("serial_no")});
		ct->set("given_rooms",list);
	}
	ct->delete("All_Self_Buildings/"+ob->query("serial_no"));
	destruct(ob);
	ct->save();
	return 1;
}
int do_destroy()
{
	object ob=this_object(),me=this_player(),ct;
	if (!objectp(ct=GUIDER_D->get_base(me)))
	return 0;
	if (is_origin())
	{
		tell_object(me,RED+"这里不能被拆毁。\n"+NOR);
		return 1;
	}
	if (ct!=load_object(__DIR__"biguanchu")&&ob->query("Ctrl_Room")!=ct)
	return 0;
	if (member_array(me->query("id"),ct->builder_list())==-1)
	{
		tell_object(me,"你没有被赋予在这里拆毁建筑的权限。\n");
		return 1;
	}
	tell_object(me,"拆毁这里的建筑，将严重影响连接到这里的其他建筑，你确定要拆毁吗？(yes/no)");
	input_to( (: destroy :),me,ob,ct);
	return 1;
}
int do_grant(string arg)
{
	object ct,ob=this_object(),me=this_player(),room;
	string *list;
	if (!objectp(ct=ob->query("Ctrl_Room")))
	return 0;
	if (member_array(me->query("id"),ct->builder_list())==-1)
	{
		tell_object(me,"你分配这里建筑的权限。\n");
		return 1;
	}
	list=GUIDER_D->oldapp_list(ct->get_owner());
	if (member_array(arg,list)==-1)
	{
		tell_object(me,arg+"？，你只能给在这里出师的学生分配这里的建筑。\n");
		return 1;
	}
	message_vision("$N把"+ob->query("short")+"分配给"+arg+"使用。\n",me);
	room=new(PLAYER_ROOM);
}
void init()
{
	add_action("do_deco","deco");
	add_action("do_destroy","ruin");
	add_action("connect","connect");
	add_action("make_room","makeroom");
	if (mapp(query("loc_cmds")))
	{
		for (int i=0;i<sizeof(keys(query("loc_cmds")));i++)
		{
			add_action(keys(query("loc_cmds"))[i],values(query("loc_cmds"))[i]);
		}
	}
}