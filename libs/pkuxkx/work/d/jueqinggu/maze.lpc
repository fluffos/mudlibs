//绝情谷
// By Zine 

inherit ROOM;
#include <ansi.h>
#define WALK_LIMIT 2
void create()
{
        set("short", HIB"山洞中"NOR);
        set("long", 
"这里是一座不知名的山洞，你什么都看不见了。\n"

        );
        
        set("exits", ([
                //"out" : __DIR__"xiaolu",	
                //"east" : __DIR__"xiaolu2",	
                //"south" : __DIR__"xiaolu2",	
                //"north" : __DIR__"xiaolu2",
                //"southwest" : __DIR__"xiaolu2",	
                //"southeast" : __DIR__"xiaolu2",	
                //"northwest" : __DIR__"xiaolu2",	
                //"northeast" : __DIR__"xiaolu2",	
               
                
        ]));
		set("real_dark",1);
        set("no_sleep_room",1);
        //set("outdoors", "jueqinggu");
        setup();
   
}
void init()
{
	add_action("do_move","move");
}
int check_maze(object me,string arg,string fangxiang)
{
	int attempt=me->query_temp("jueqinggu/maze/attempt");
	tell_object(me,HIG+"你向"+fangxiang+"方迅速离去。\n"+NOR);
	if (attempt<0) attempt=0;
	if (!arrayp(me->query("jueqinggu/maze")))
	{
		tell_object(me,HBWHT+HIB+"你莫名其妙退回了原地。\n"+NOR);
		me->delete("jueqinggu/maze");
		me->delete_temp("jueqinggu/maze/attempt");
	}
	if (arg==me->query("jueqinggu/maze")[attempt])
	{
		me->add_temp("jueqinggu/maze/attempt",1);
		if (me->query_temp("jueqinggu/maze/attempt")>=sizeof(me->query("jueqinggu/maze")))
		{
			me->move(__DIR__"xiaolu3");
			tell_object(me,"你终于走出了这段黑暗的山洞。\n");
		}
	}
	else
	{
		me->delete_temp("jueqinggu/maze/attempt");
		tell_object(me,HBWHT+HIB+"你莫名其妙退回了原地。\n"+NOR);
	}
	return 1;
}
int create_maze(object me,string arg,mapping legal_dir)
{
	string * dirs=keys(legal_dir),dir,*path=({});
	if (!me->query_temp("jueqinggu/maze/right_dir"))
	{
		dir=dirs[random(sizeof(dirs))];
		me->set_temp("jueqinggu/maze/right_dir",dir);
	}
	if (!me->query_temp("jueqinggu/maze/total_estimate"))
		me->set_temp("jueqinggu/maze/total_estimate",4+random(6));
	if (me->query_temp("jueqinggu/maze/right_dir")!=arg)
	{
		tell_object(me,RED+"你一时不查，一头撞在了石壁上，立刻把你撞了个七荤八素。\n"+NOR);
		me->add_busy(3+random(3));
	}
	else
	{
		me->add_temp("jueqinggu/maze/suc",1);
		me->set_temp("jueqinggu/maze/pathstep/"+me->query_temp("jueqinggu/maze/suc"),arg);
		me->delete_temp("jueqinggu/maze/right_dir");
		tell_object(me,"你仔细记下了山洞中的第"+chinese_number(me->query_temp("jueqinggu/maze/suc"))+"步的走法是"+legal_dir[arg]+"。\n");
		if (me->query_temp("jueqinggu/maze/suc")>=me->query_temp("jueqinggu/maze/total_estimate"))
		{
			me->move(__DIR__"xiaolu3");
			tell_object(me,"你终于走出了这段黑暗的山洞。\n");
			tell_object(me,"你细细回忆，走出山洞的步骤是：");
			for (int i=1;i<=me->query_temp("jueqinggu/maze/total_estimate");i++)
			{
				path+=({me->query_temp("jueqinggu/maze/pathstep/"+i)});
				tell_object(me,legal_dir[me->query_temp("jueqinggu/maze/pathstep/"+i)]);
			}
			tell_object(me,"\n"+CYN+"你把走进绝情谷的步骤刻在了绝情谷前，以后可以查看(querypath)。\n"+NOR);
			me->set("jueqinggu/maze",path);
			me->delete_temp("jueqinggu/maze");
		}
	}
}
int do_move(string arg)
{
	mapping legal_dir=(["qian":"前","hou":"后","zuo":"左","you":"右"]);
	object me=this_player();
	if (me->is_busy()||me->is_fighting())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (!arg) 
	{
		write("你要向哪里移动？\n");
		return 1;
	}
	if (member_array(arg,keys(legal_dir))==-1)
	{
		write("你只能向前(qian)/后(hou)/左(zuo)/右(you)方向移动。\n");
		return 1;
	}
	if (me->query("jueqinggu/maze"))
		return check_maze(me,arg,legal_dir[arg]);
	if (time()-me->query_temp("jueqinggu/maze/laststep")<WALK_LIMIT)
	{
		write("黑灯瞎火的，你也不敢走得太快，上次头上撞的瘀青还没有消下去。\n");
		return 1;
	}
	me->set_temp("jueqinggu/maze/laststep",time());
	write("你向"+legal_dir[arg]+"方离去。\n");
	create_maze(me,arg,legal_dir);
	return 1;
}
