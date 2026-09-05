#include <ansi.h>

int SearchCD()
{
	return query("searchCD")>2?query("searchCD"):2;
}
int drug_level()
{
	return query("drug_level")>10?query("drug_level"):10;
}
int level_bonus(object me)
{
	return me->query_skill("herbalism",1)>query("level_bonus");
}
int show_detail(object);
int gene_features();
void learn_herbalism(object me,int sk_point,int suc)
{
	if (me->query_skill("herbalism",1)>60&&!me->query("ProfessionalClass/herbalism"))
	{
		tell_object(me,"只有职业采药师才能获得进一步的提升了。\n");
		return;
	}
	if (time()<me->query("pro_double_reward"))
	sk_point*=2;
	if (me->query_skill("herbalism",1)<=(this_object()->drug_level()+10))
	{
		me->improve_skill("herbalism",sk_point);
		if (level_bonus(me)&&suc)
		me->improve_skill("herbalism",sk_point/3);
	}
	return;
}
int gather_herb(object me,int flag,object hoe)
{
	mapping herb;
	string mark;
	object ob;
	int sk=4+random(4),piece;
	if (!hoe)
	{
		tell_object(me,RED"你要采药，必须需要找个药锄来。\n"NOR);
		return 1;
	}
	if (flag==1)
	{
		set_temp("SmallMaze/target",({-1,-1}));
		mark="herb";
	}
	if (flag==2)
	{
		set_temp("SmallMaze/target2",({-1,-1}));
		mark="herb2";
	}
	herb=query_temp("SmallMaze/"+mark);
	if (herb["id"]==0)
	{
		tell_object(me,"这里并没有什么药物出产。\n");
	}
	else if (herb["gather_lv"]>me->query_skill("herbalism",1))
	{
		learn_herbalism(me,1+random(sk/2),0);
		tell_object(me,herb["name"]+"的摘采难度大大超过了你能力范围，看着一地的"+herb["name"]+"碎片，你满心都是无奈。\n");
	}
	else
	{
		piece=sk+level_bonus(me)?sk:0;
		for (int j=0;j<piece;j++)
		{
			ob="/obj/remedy/reference"->ObtainDrug(herb["id"]);
			ob->move(me);
			if (this_object()->query_location()=="/d/southmountain/dashigu/"&&me->query("tianmuQuests/dashigu/gather/"+herb["id"]))
			me->add("tianmuQuests/dashigu/gather/"+herb["id"],1);
		}
		if (this_object()->query_location()=="/d/southmountain/dashigu/"&&me->query("tianmuQuests/dashigu/gather/"+herb["id"]))
		tell_object(me,"按照余任的要求，你已经采到了"+chinese_number(me->query("tianmuQuests/dashigu/gather/"+herb["id"])-1)+"份"+herb["name"]+"了。\n");
		learn_herbalism(me,1+random(sk),1);
		message_vision(HIG+"$N"+HIG+"采集到了一些$n"+HIG+"。\n"+NOR,me,ob);
	}
	hoe->worn(1);
	if (query_temp("SmallMaze/target")[0]==-1&&query_temp("SmallMaze/target")[1]==-1
	&&query_temp("SmallMaze/target2")[0]==-1&&query_temp("SmallMaze/target2")[1]==-1)
	{
		delete_temp("SmallMaze");
		set("HERB_SPOT",0);
		write(WHT"这里的药材被采完了。\n"NOR);
	}
	return 1;
}
int do_gather()
{
	object me=this_player(),obj;
	int allow=0;
	if (!query("HERB_SPOT")||!query_temp("SmallMaze"))
	{
		delete_temp("SmallMaze");
		set("HERB_SPOT",0);
		return notify_fail("这里的药材已经被采光了。\n");
	}
	if (environment(me)!=me->query_temp("SmallMaze/spot"))
	{
		me->delete_temp("SmallMaze");
		return show_detail(me);
	}
	if (!me->query_temp("SmallMaze/myLoc"))
	return show_detail(me);
	if (me->query_temp("weapon")&&objectp(obj=me->query_temp("weapon"))&&obj->is_DrugHoe()) allow=1;
	else if (me->query_temp("secondary_weapon")&&objectp(obj=me->query_temp("secondary_weapon"))&&obj->is_DrugHoe()) allow=1;
	if (!allow)
	{
		tell_object(me,RED"你要采药，必须需要找个药锄来。\n"NOR);
		return 1;
	}
	if (me->query_temp("SmallMaze/myLoc")[0]==query_temp("SmallMaze/target")[0]&&
	me->query_temp("SmallMaze/myLoc")[1]==query_temp("SmallMaze/target")[1])//target同位置
	return gather_herb(me,1,obj);
	else if (me->query_temp("SmallMaze/myLoc")[0]==query_temp("SmallMaze/target2")[0]&&
	me->query_temp("SmallMaze/myLoc")[1]==query_temp("SmallMaze/target2")[1])
	return gather_herb(me,2,obj);
	else
	{
		obj->worn(2);
		write("可是什么也没有采到。\n");
		return 1;
	}
}
int move_in_map(string arg)
{
	object me=this_player();
	mapping default_dirs = (["north":"北","n":"北","south":"南","s":"南","east":"东","e":"东","west":"西","w":"西","northeast":"东北","ne":"东北","northwest":"西北","nw":"西北","southeast":"东南","se":"东南","southwest":"西南","sw":"西南",]),legal_dirs=(["north":({-1,0}),"n":({-1,0}),"south":({1,0}),"s":({1,0}),"east":({0,1}),"e":({0,1}),"west":({0,-1}),"w":({0,-1}),"northwest":({-1,-1}),"nw":({-1,-1}),"northeast":({-1,1}),"ne":({-1,1}),"southwest":({1,-1}),"sw":({1,-1}),"southeast":({1,1}),"se":({1,1})]);
	int *my_loc,*loc;
	if (!query("HERB_SPOT"))
	{
		return notify_fail("这里的药材已经被采光了。\n");
	}
	if (!me->query_temp("SmallMaze"))
	{
		return 0;
	}
	if (environment(me)!=me->query_temp("SmallMaze/spot"))
	{
		me->delete_temp("SmallMaze");
		write("你已经离开了先前搜索的地点，请重新开始吧。\n");
		return 1;
	}
	if (!arg)
	{
		if (stringp(me->query_temp("SmallMaze/map")))
		write("\n"+me->query_temp("SmallMaze/map")+"\n");
		else return show_detail(me);
		return 1;
	}
	if (member_array(arg,keys(legal_dirs))==-1)
	{
		tell_object(me,arg+"并不是一个合法方向。\n");
		return 1;
	}
	if (time()-me->query_temp("SmallMaze/lastsearch")<SearchCD())
	{
		tell_object(me,"看你手忙脚乱的！采药不是赶集。\n");
		return 1;
	}
	me->set_temp("SmallMaze/lastsearch",time());
	tell_object(me,"你向"+default_dirs[arg]+"继续搜寻。\n");
	loc=legal_dirs[arg];
	my_loc=me->query_temp("SmallMaze/myLoc");
	my_loc[0]+=loc[0];
	my_loc[1]+=loc[1];
	if (my_loc[0]>=query_temp("SmallMaze/line_no")||my_loc[0]<0
	||my_loc[1]>=query_temp("SmallMaze/col_no")||my_loc[1]<0)
	{
		tell_object(me,HIC+"你收回了你的视线，放弃对细节的搜寻。\n"NOR);
		me->delete_temp("SmallMaze");
		return 1;
	}
	else
	{
		me->set_temp("SmallMaze/myLoc",my_loc);
	}
	return show_detail(me);
}

int init_map()
{
	int line_no=16+random(10),col_no=16+random(10),line,col,*origin=({}),*target=({}),*target2=({});
	string msg="",BLOCK,ME,TARGET,color,*colors=({HIR,MAG,HIB});
	if (query("map_generated"))
	return 1;
	set("map_generated",1);
	target=({1+random(line_no-1),1+random(col_no-1)});
	if (random(5))
	target2=({1+random(line_no-1),1+random(col_no-1)});
	else
	target2=({-1,-1});
	color=colors[random(sizeof(colors))];
	set_temp("SmallMaze/line_no",line_no);
	set_temp("SmallMaze/col_no",col_no);
	set_temp("SmallMaze/target",target);
	set_temp("SmallMaze/target2",target2);
	set_temp("SmallMaze/color",color);
	set_temp("SmallMaze/herb","/obj/remedy/reference"->random_drug("herb",drug_level()));
	set_temp("SmallMaze/herb2","/obj/remedy/reference"->random_drug("herb",drug_level()));
	tell_room(this_object(),HIG+"这里的药材正在繁荣地生长着……\n"+NOR);
	return 1;
}

int show_detail(object me)
{
	int line_no=query_temp("SmallMaze/line_no"),col_no=query_temp("SmallMaze/col_no"),line,col,*origin=({}),*target=query_temp("SmallMaze/target"),*target2=query_temp("SmallMaze/target2");
	string msg="",BLOCK,ME,TARGET,color,*colors=({HIR,MAG,HIB});
	if (me->query_temp("SmallMaze/spot")!=this_object())
	{
		me->set_temp("SmallMaze/spot",this_object());
		switch (random(4))
		{
			case 0:
			{
				origin=({0,random(col_no)});
				break;
			}
			case 1:
			{
				origin=({(line_no-1),random(col_no)});
				break;
			}
			case 2:
			{
				origin=({random(line_no),0});
				break;
			}
			case 3:
			{
				origin=({random(line_no),(col_no-1)});
				break;
			}
		}
		me->set_temp("SmallMaze/myLoc",origin);
	}
	else
	origin=me->query_temp("SmallMaze/myLoc");
	BLOCK=HBWHT+query_temp("SmallMaze/color")+"█"+NOR;
	ME=HBWHT+query_temp("SmallMaze/color")+"♀"+NOR;
	TARGET=HBWHT+query_temp("SmallMaze/color")+"★"+NOR;
	for (int i=0;i<line_no;i++)
	{
		for (int j=0;j<col_no;j++)
		{
			if (i==origin[0]&&j==origin[1])
			msg+=ME;
			else if ((i==target[0]&&j==target[1])||(target2!=({})&&i==target2[0]&&j==target2[1]))
			msg+=TARGET;
			else
			msg+=BLOCK;
		}
		msg+="\n"+NOR;
	}
	write("\n"+msg+"\n");
	me->set_temp("SmallMaze/map",msg);
	if ((target!=({})&&target[0]==origin[0]&&target[1]==origin[1])||(target2!=({})&&target2[0]==origin[0]&&target2[1]==origin[1]))
	{
		write(HIR+"你现在搜索的位置似乎有些药材，可以用gather命令采集。\n"+NOR);
	}
	return 1;
}
int do_start()
{
	object me=this_player();
	if (!environment(me))
	{
		tell_object(me,"都已经这样了，你还是歇歇吧。\n");
		return 1;
	}
	return show_detail(me);
}

void clear_herbroom()
{
	object *rooms=children(__FILE__);
	for (int i=0;i<sizeof(rooms);i++)
	{
		if (rooms[i]->query("HERB_SPOT"))
		{
			tell_room(rooms[i],WHT+rooms[i]->query("short")+WHT+"的药材正在以肉眼可见的速度枯萎下去。\n"+NOR);
			rooms[i]->delete("HERB_SPOT");
		}
	}
	gene_features();
	return;
}
int gene_features()
{
	int spots;
	string *rooms=({}),room;
	if (strsrch(file_name(this_object()), "#")!=-1)
	return 1;
	if (!query("fully_generated")&&!query("generating"))
	{
		this_object()->start();
		remove_call_out("gene_features");
		call_out("gene_features",30);
		return 1;
	}
	if (!query("fully_generated"))
	{
		remove_call_out("gene_features");
		call_out("gene_features",30);
		return 1;
	}
	spots=this_object()->HerbPoints()+random(this_object()->HerbPoints()/2);
	if (spots<sizeof(query("gene_rooms"))/3)
	spots=sizeof(query("gene_rooms"))/3;
	for (int i=0;i<spots;i++)
	{
		if (room=query("gene_rooms/"+random(sizeof(query("gene_rooms")))))
		{
			room->delete("map_generated");
			room->init_map();
			room->set("HERB_SPOT",1);
			rooms+=({room});
		}
	}
	set("herb_rooms",rooms);
	remove_call_out("clear_herbroom");
	call_out("clear_herbroom",this_object()->HerbRefreshRate());
	return 1;
}
int players()
{
	object *users;
	string AREA=this_object()->AREA();
	users=children(USER_OB);
	users=filter(users,(: environment:));
	users=filter(users,(: environment($1)->query_location()==$2:),AREA);
	if (!wizardp(this_player())) return 0;
	if (sizeof(users)<1)
	write("此区域没有玩家。\n");
	else
	write("此区域的玩家有：\n");
	for (int i=0;i<sizeof(users);i++)
	write(users[i]->query("name")+"("+users[i]->query("id")+")\t");
	return 1;
}
