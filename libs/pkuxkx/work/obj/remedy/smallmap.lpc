inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("采药测试包", ({"test package", "bao", }));
	set("long","这是一个给玩家用来采药的测试包。\n");
	set("unit", "个");
	set("value", 10000);
	set("material", "wood");
	set("no_store",1);
	set("no_sell",1);
	set("no_pawn",1);
	set("no_sell_in_playershop",1);
	set("uni_target",1);
	set("no_show",1);
	setup();
}
int show_detail(object);
void init()
{
	add_action("move_in_map","lookfor");
	add_action("do_start","start");
}

int move_in_map(string arg)
{
	object me=this_player();
	mapping default_dirs = (["north":"北","n":"北","south":"南","s":"南","east":"东","e":"东","west":"西","w":"西","northeast":"东北","ne":"东北","northwest":"西北","nw":"西北","southeast":"东南","se":"东南","southwest":"西南","sw":"西南",]),legal_dirs=(["north":({-1,0}),"n":({-1,0}),"south":({1,0}),"s":({1,0}),"east":({0,1}),"e":({0,1}),"west":({0,-1}),"w":({0,-1}),"northwest":({-1,-1}),"nw":({-1,-1}),"northeast":({-1,1}),"ne":({-1,1}),"southwest":({1,-1}),"sw":({1,-1}),"southeast":({1,1}),"se":({1,1})]);
	int *my_loc,*loc;
	if (!me->query_temp("SmallMaze"))
	{
		return 0;
	}
	if (environment(me)!=me->query_temp("SmallMaze/env"))
	{
		me->delete_temp("SmallMaze");
		write("你已经离开了先前搜索的地点，请重新开始吧。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要向哪搜索？\n");
		return 1;
	}
	if (member_array(arg,keys(legal_dirs))==-1)
	{
		tell_object(me,arg+"并不是一个合法方向。\n");
		return 1;
	}
	tell_object(me,"你向"+default_dirs[arg]+"继续搜寻。\n");
	loc=legal_dirs[arg];
	my_loc=me->query_temp("SmallMaze/myLoc");
	my_loc[0]+=loc[0];
	my_loc[1]+=loc[1];
	if (my_loc[0]>=me->query_temp("SmallMaze/line_no")||my_loc[0]<0
	||my_loc[1]>=me->query_temp("SmallMaze/col_no")||my_loc[1]<0)
	{
		tell_object(me,HIC+"你收回了你的视线，放弃对细节的搜寻。\n"NOR);
		me->delete_temp("SmallMaze");
		return 1;
	}
	else
	me->set_temp("SmallMaze/myLoc",my_loc);
	return show_detail(me);
}
int show_detail(object me)
{
	int line_no=16+random(10),col_no=16+random(10),line,col,*origin=({}),*target=({}),*target2=({});
	string msg="",BLOCK,ME,TARGET,color,*colors=({HIR,MAG,HIB});
	write("line"+line_no);
	write("Col"+col_no+"\n");
	if (me->query_temp("SmallMaze"))
	{
		origin=me->query_temp("SmallMaze/myLoc");
		line_no=me->query_temp("SmallMaze/line_no");
		col_no=me->query_temp("SmallMaze/col_no");
		target=me->query_temp("SmallMaze/target");
		target2=me->query_temp("SmallMaze/target2");
		BLOCK=HBWHT+me->query_temp("SmallMaze/color")+"█"+NOR;
		ME=HBWHT+me->query_temp("SmallMaze/color")+"♀"+NOR;
		TARGET=HBWHT+me->query_temp("SmallMaze/color")+"★"+NOR;
	}
	else
	{
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
		target=({1+random(line_no-1),1+random(col_no-1)});
		if (random(5))
		target2=({1+random(line_no-1),1+random(col_no-1)});
		else
		target2=({-1,-1});
		color=colors[random(sizeof(colors))];
		BLOCK=HBWHT+color+"█"+NOR;
		ME=HBWHT+color+"♀"+NOR;
		TARGET=HBWHT+color+"★"+NOR;
	}
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
	if (!me->query_temp("SmallMaze"))
	{
		me->set_temp("SmallMaze/myLoc",origin);
		me->set_temp("SmallMaze/line_no",line_no);
		me->set_temp("SmallMaze/col_no",col_no);
		me->set_temp("SmallMaze/target",target);
		me->set_temp("SmallMaze/target2",target2);
		me->set_temp("SmallMaze/color",color);
		me->set_temp("SmallMaze/env",environment(me));
	}
	if (target!=({})&&target[0]==origin[0]&&target[1]==origin[1])
	{
		write(HIR+"恭喜！你获得了一颗朱果！\n"+NOR);
		me->set_temp("SmallMaze/target",({-1,-1}));
	}
	if (target2&&target2!=({})&&target2[0]==origin[0]&&target2[1]==origin[1])
	{
		write(HIR+"恭喜！你获得了一颗朱果！\n"+NOR);
		me->set_temp("SmallMaze/target2",({-1,-1}));
	}
	write("\n"+msg+"\n");
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
	if (me->query_temp("SmallMaze"))
	{
		if (environment(me)!=me->query_temp("SmallMaze/env"))
		me->delete_temp("SmallMaze");
		else
		{
			tell_object(me,"你已经开始搜索了，用lookfor <方向>试试看吧。\n");
			return 1;
		}
	}
	write(HIW+"你开始仔细搜索"+environment(me)->query("short")+HIW+"这里的每一寸细节。\n"+NOR);
	return show_detail(me);
}