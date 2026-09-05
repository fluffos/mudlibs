#include <ansi.h>
#define MINE "MineMaze"
int show_MINE_detail(object me);
int gene_mines();
int searchCD(object me)
{
	if (wizardp(me)) return 0;
	return query("searchCD")>2?query("searchCD"):2;
}

int mine_level()
{
	return query("mine_level")>10?query("mine_level"):10;
}
int mine_level_bonus(object me)
{
	return me->query_skill("mining",1)>query("mine_level_bonus")&&me->query_skill("mining",1)>10;
}
int show_MINE_detail(object);
void learn_mining(object me,int sk_point,int suc)
{
	if (me->query_skill("mining",1)>60&&!me->query("ProfessionalClass/mining"))
	{
		tell_object(me,"只有职业采矿师才能获得进一步的提升了。\n");
		return;
	}
	if (time()<me->query("pro_double_reward"))
	sk_point*=2;
	if (me->query_skill("mining",1)<=(this_object()->mine_level()+10))
	{
		me->improve_skill("mining",sk_point);
		if (mine_level_bonus(me)&&suc)
		me->improve_skill("mining",sk_point/3);
		return;
	}
	tell_object(me,"这里的矿藏对你而言实在是学不到什么东西了。\n");
	return;
}
int obtain_mine(object me,object shovel)
{
	string mark,*names=({"坤地","艮山","坎水","巽風","震雷","離火","兌澤","乾天"});
	object ob;
	int i,sk=2+random(2),piece,num,remain=0;
	if (!shovel)
	{
		tell_object(me,RED"你用手挖啊挖，虽然满手是血，发现根本就不管用。\n"NOR);
		return 1;
	}
	num=random(query("MineAppear"));
	if (num*20>me->query_skill("mining",1)+random(query("assist_level")))
	{
		tell_object(me,"这里有很多"+names[num]+"之材的矿藏，可是限于你的采矿术，这里只能留待有缘人了。\n");
	}
	else
	{
		if (query_temp(MINE+"/mine"+(num+1))<1)
		{
			write("这里的"+names[num]+"之材的矿藏已经开采完了，也许你要试试开采别的。\n");
		}
		else
		{
			piece=sk+mine_level_bonus(me)?sk:0;
			if (piece>query_temp(MINE+"/mine"+(num+1)))
			piece=query_temp(MINE+"/mine"+(num+1));
			add_temp(MINE+"/mine"+(num+1),-piece);
			for (int j=0;j<piece;j++)
			{
				ob=new("/obj/smith/materials/material_piece");
				ob->init_material(num,random(4));
				ob->move(me);
			}
			learn_mining(me,1+random(sk),1);
			message_vision(HIG+"$N"+HIG+"在"+environment(me)->query("short")+HIG+"的矿藏里开采到了一些$n"+HIG+"。\n"+NOR,me,ob);
		}
	}
	shovel->worn(1+random(2));
	for (i=1;i<=query("MineAppear");i++)
	{
		if (query_temp(MINE+"/mine"+i)>0)
		remain=1;
	}
	if (!remain)
	{
		delete_temp(MINE);
		set("MINE_SPOT",0);
		write(WHT"这里的矿藏被彻底开采完了。\n"NOR);
	}
	return 1;
}
int do_excavate()
{
	object me=this_player(),obj;
	int allow=0;
	if (me->query_skill("mining",1)<1) 
	return 0;
	if (!query("MINE_SPOT")||!query_temp(MINE))
	{
		delete_temp(MINE);
		set("MINE_SPOT",0);
		return notify_fail("这里的矿藏已经被别人挖光了。\n");
	}
	if (environment(me)!=me->query_temp(MINE+"/spot"))
	{
		me->delete_temp(MINE);
		return show_MINE_detail(me);
	}
	if (!me->query_temp(MINE))
	return show_MINE_detail(me);
	if (me->query_temp("weapon")&&objectp(obj=me->query_temp("weapon"))&&obj->is_shovel()) allow=1;
	else if (me->query_temp("secondary_weapon")&&objectp(obj=me->query_temp("secondary_weapon"))&&obj->is_shovel()) allow=1;
	if (!allow)
	{
		tell_object(me,RED"没有铁锹，你总不能用手来挖吧？\n"NOR);
		return 1;
	}
	if (me->query_temp(MINE+"/myExcavate_x")!=me->query_temp(MINE+"/myLoc_x"))
	{
		me->set_temp(MINE+"/myExcavate_x",me->query_temp(MINE+"/myLoc_x"));
		me->set_temp(MINE+"/myExcavate_y",me->query_temp(MINE+"/myLoc_y"));
	}
	if (me->query_temp(MINE+"/myExcavate_x")==query_temp(MINE+"/target_x")&&
	me->query_temp(MINE+"/myExcavate_y")==query_temp(MINE+"/target_y"))//target同位置
	return obtain_mine(me,obj);
	else
	{
		if (me->query_temp(MINE+"/myExcavate_y")+1>query_temp(MINE+"/BaseLine"))
		{
			obj->worn(5+random(10));
			write("已经挖了这么深，你想把地底挖穿吗？\n");
			write(RED+"随意挖掘导致"+obj->query("name")+RED+"受损严重。\n"+NOR);
			return 1;
		}
		me->add_temp(MINE+"/myExcavate_y",1);
		obj->worn(1);
		write("你又往下挖了一段。\n");
		return 1;
	}
}

int move_MINE_map(string arg)
{
	object me=this_player();
	mapping default_dirs = (["left":"左边","right":"右边"]),legal_dirs=(["north":({-1,0}),"n":({-1,0}),"south":({1,0}),"s":({1,0}),"east":({0,1}),"e":({0,1}),"west":({0,-1}),"w":({0,-1}),"northwest":({-1,-1}),"nw":({-1,-1}),"northeast":({-1,1}),"ne":({-1,1}),"southwest":({1,-1}),"sw":({1,-1}),"southeast":({1,1}),"se":({1,1})]);
	int *my_loc,*loc;
	if (!query("MINE_SPOT"))
	{
		return notify_fail("这里没有矿藏。\n");
	}
	if (!me->query_temp(MINE))
	{
		return 0;
	}
	if (environment(me)!=me->query_temp(MINE+"/spot"))
	{
		me->delete_temp(MINE);
		write("你已经离开了先前搜索的地点，请重新开始吧。\n");
		return 1;
	}
	if (!arg)
	{
		if (stringp(me->query_temp(MINE+"/map")))
		write("\n"+me->query_temp(MINE+"/map")+"\n");
		else return show_MINE_detail(me);
		return 1;
	}
	if (member_array(arg,keys(default_dirs))==-1)
	{
		tell_object(me,arg+"？在这里你只能往左(left)或者往右(right)。\n");
		return 1;
	}
	if (time()-me->query_temp(MINE+"/lastsearch")<searchCD(me))
	{
		tell_object(me,"你一步步向"+default_dirs[arg]+"走过去。\n");
		return 1;
	}
	me->set_temp(MINE+"/lastsearch",time());
	me->delete_temp(MINE+"/myExcavate_x");
	me->delete_temp(MINE+"/myExcavate_y");
	me->add_temp(MINE+"/myLoc_x",arg=="left"?-1:1);
	if (me->query_temp(MINE+"/myLoc_x")>query_temp(MINE+"/line"+me->query_temp(MINE+"/myLoc_y"))[1]
	||me->query_temp(MINE+"/myLoc_x")<query_temp(MINE+"/line"+me->query_temp(MINE+"/myLoc_y"))[0])
	{
		if (!query_temp(MINE+"/line"+(me->query_temp(MINE+"/myLoc_y")+1)))
		{
			me->delete_temp(MINE);
			write("你放弃了对"+environment(me)->query("short")+"矿藏的细致搜索。\n");
			return 1;
		}
		else
		me->add_temp(MINE+"/myLoc_y",1);
	}
	tell_object(me,"你向"+default_dirs[arg]+"继续搜寻。\n");
	if (query_temp(MINE+"/line"+(me->query_temp(MINE+"/myLoc_y")-1))&&(me->query_temp(MINE+"/myLoc_x")<=query_temp(MINE+"/line"+(me->query_temp(MINE+"/myLoc_y")-1))[1]
	&&me->query_temp(MINE+"/myLoc_x")>=query_temp(MINE+"/line"+(me->query_temp(MINE+"/myLoc_y")-1))[0]))
	me->add_temp(MINE+"/myLoc_y",-1);
	return show_MINE_detail(me);
}

int init_mine_map()
{
	int i,horizon=16+random(10),vertical=4+random(4),half_h=horizon/2,*origin=({}),*target_vertical=({}),x1,x2,peak;
	string msg="",BLOCK,ME,TARGET,color,*colors=({HIR,MAG,HIB});
	if (query(MINE+"_generated"))
	return 1;
	set(MINE+"_generated",1);
	x1=0;
	x2=horizon;
	set_temp(MINE+"/MaxHorizon",horizon);
	set_temp(MINE+"/start",random(2)?x1:x2);
	set_temp(MINE+"/BaseLine",vertical);
	set_temp(MINE+"/HalfPoint",half_h);
	for (i=vertical;i>0;i--)
	{
		set_temp(MINE+"/line"+i,({x1,x2}));
		x1+=1+random(3);
		x2-=1+random(3);
		set_temp(MINE+"/peak",i);
		if (x1>=half_h||x2<=half_h)
		break;
	}
	for (i=1;i<=query("MineAppear");i++)
	set_temp(MINE+"/mine"+i,random(10));
	set_temp(MINE+"/line"+(query_temp(MINE+"/peak")-1),({half_h,half_h}));
	set_temp(MINE+"/target_y",query_temp(MINE+"/peak")+random(1+vertical-query_temp(MINE+"/peak")));
	target_vertical=query_temp(MINE+"/line"+query_temp(MINE+"/target_y"));
	set_temp(MINE+"/target_x",target_vertical[0]+random(1+target_vertical[1]-target_vertical[0]));
	color=colors[random(sizeof(colors))];
	set_temp(MINE+"/color",color);
	return 1;
}
string my_loc(object me,string symbol,int y1,int y2,int x1,int x2,string color)
{
	string MY_color,my_color=HIC;
	if (x1==x2&&y1==y2)
	{
		if (me->query("env/MINE_color")&&stringp(me->query("env/MINE_color")))
		{
			MY_color=me->query("env/MINE_color");
			if (member_array(MY_color,({HIC,HIB,HIW,HIM,HIG,HIR,HIY,CYN,BLU,WHT,MAG,GRN,RED,YEL}))!=-1)
			my_color=MY_color;
			set("color",MY_color);
		}
		return my_color+symbol+NOR;
	}
	else
	return color+symbol+NOR;
}
int show_MINE_detail(object me)
{
	int i,HalfPoint=query_temp(MINE+"/HalfPoint"),MaxHorizon=query_temp(MINE+"/MaxHorizon"),BaseLine=query_temp(MINE+"/BaseLine"),start=query_temp(MINE+"/start"),peak=query_temp(MINE+"/peak"),target_x=query_temp(MINE+"/target_x"),target_y=query_temp(MINE+"/target_y");
	string msg="",BLOCK,ME,TARGET,LEFT_EDGE,RIGHT_EDGE,PEAK,color,*colors=({HIR,MAG,HIB});
	if (me->query_temp(MINE+"/spot")!=this_object())
	{
		me->set_temp(MINE+"/spot",this_object());
		me->set_temp(MINE+"/myLoc_x",start);
		me->set_temp(MINE+"/myLoc_y",BaseLine);
	}
	BLOCK="█"+NOR;
	ME="♀"+NOR;
	TARGET="★"+NOR;
	LEFT_EDGE="◢"+NOR;
	RIGHT_EDGE="◣"+NOR;
	PEAK="▲"+NOR;
	for (i=peak-1;i<=BaseLine;i++)
	{
		for (int j=0;j<=MaxHorizon;j++)
		{
			if (i==peak-1)
			{
				if (j==HalfPoint)
				{
					msg+=my_loc(me,PEAK,i,me->query_temp(MINE+"/myLoc_y"),j,me->query_temp(MINE+"/myLoc_x"),query_temp(MINE+"/color"));
					
				}
				else
				msg+="  ";
			}
			else if (i==target_y&&j==target_x)
			msg+=my_loc(me,TARGET,i,me->query_temp(MINE+"/myLoc_y"),j,me->query_temp(MINE+"/myLoc_x"),query_temp(MINE+"/color"));
			else if (j==query_temp(MINE+"/line"+i)[0])
			msg+=my_loc(me,LEFT_EDGE,i,me->query_temp(MINE+"/myLoc_y"),j,me->query_temp(MINE+"/myLoc_x"),query_temp(MINE+"/color"));
			else if (j==query_temp(MINE+"/line"+i)[1])
			msg+=my_loc(me,RIGHT_EDGE,i,me->query_temp(MINE+"/myLoc_y"),j,me->query_temp(MINE+"/myLoc_x"),query_temp(MINE+"/color"));
			else if (j>=query_temp(MINE+"/line"+i)[0]&&j<=query_temp(MINE+"/line"+i)[1])
			msg+=my_loc(me,BLOCK,i,me->query_temp(MINE+"/myLoc_y"),j,me->query_temp(MINE+"/myLoc_x"),query_temp(MINE+"/color"));
			else
			msg+="  ";
		}
		msg+="\n"+NOR;
	}
	write("\n"+msg+"\n");
	me->set_temp(MINE+"/map",msg);
	if (me->query_temp(MINE+"/myLoc_x")==target_x&&me->query_temp(MINE+"/myLoc_y")==target_y)
	{
		write(HIR+" \n"+NOR);
	}
	return 1;
}

#ifdef __GENMINES__

void clear_mineroom()
{
	object *rooms=children(__FILE__);
	for (int i=0;i<sizeof(rooms);i++)
	{
		if (rooms[i]->query("MINE_SPOT"))
		{
			tell_room(rooms[i],WHT+rooms[i]->query("short")+WHT+"的矿脉似乎发生了变化。\n"+NOR);
			rooms[i]->delete("MINE_SPOT");
		}
	}
	gene_mines();
	return;
}

int gene_mines()
{
	int spots;
	string *rooms=({}),room;
	if (strsrch(file_name(this_object()), "#")!=-1)
	return 1;
	if (!query("fully_generated")&&!query("generating"))
	{
		this_object()->start();
		remove_call_out("gene_mines");
		call_out("gene_mines",30);
		return 1;
	}
	if (!query("fully_generated"))
	{
		remove_call_out("gene_mines");
		call_out("gene_mines",30);
		return 1;
	}
	spots=this_object()->MinePoints()+random(this_object()->MinePoints()/2);
	if (spots<sizeof(query("gene_rooms"))/3)
	spots=sizeof(query("gene_rooms"))/3;
	for (int i=0;i<spots;i++)
	{
		if (room=query("gene_rooms/"+random(sizeof(query("gene_rooms")))))
		{
			room->delete("MineMaze_generated");
			room->init_mine_map();
			room->set("MINE_SPOT",1);
			rooms+=({room});
		}
	}
	set("mine_rooms",rooms);
	remove_call_out("clear_mineroom");
	call_out("clear_mineroom",this_object()->MineRefreshRate());
	return 1;
}
#endif
/*
int do_start()
{
	object me=this_player();
	if (!environment(me))
	{
		tell_object(me,"都已经这样了，你还是歇歇吧。\n");
		return 1;
	}
	return show_detail(me);
}*/