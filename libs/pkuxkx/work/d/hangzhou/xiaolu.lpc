inherit ROOM;
#include <ansi.h>
void create() 
{ 
        set("short", "郊外小路");
        set("long", @LONG
这里是荒郊野外的一条小路，人迹罕至，几个人影鬼鬼祟祟的。
LONG
        );
	
        set("exits", ([
			"north":__DIR__"xiaolu",
			"south":__DIR__"xiaolu",
			"east":__DIR__"xiaolu",
			"west":__DIR__"xiaolu",
]));
        set("no_clean_up", 1);
        set("no_reset", 1);
		set("no_task",1);
		set("real_dark",1);
        set("outdoors", "city");
		setup();
}
int check_me(object me)
{	
	if (!me)
	{
		if (objectp(this_object()->query("Maze_"+me->query("id"))))
		{
			this_object()->query("Maze_"+me->query("id"))->over();
			this_object()->delete("Maze_"+me->query("id"));
		}
		return 1;
	}
	if (member_array(environment(me),children("/d/hangzhou/yewai"))!=-1)//在副本了，交接检查存在。
	return 1;
	else if (environment(me)==this_object())//不在副本也不在这里
	{
		call_out("check_me",3,me);
		return 1;
	}
	else
	{
		if (objectp(this_object()->query("Maze_"+me->query("id"))))
		{
			this_object()->query("Maze_"+me->query("id"))->over();
			this_object()->delete("Maze_"+me->query("id"));
		}
		return 1;
	}
}

int valid_leave(object me,string dir)
{
	object destination;
	if (time()-me->query_temp("hansz/maze_go")<2+random(4))
	return notify_fail("你走这么快，当心被人发现。\n");
	me->set_temp("hansz/maze_go",time());
	if (dir=="north")
	me->add_temp("hansz/leave_dir",1);
	if (me->query_temp("hansz/leave_dir")>=10)
	{
		while (!objectp(destination) || 
          !destination->isroom()||
          TASK_D->place_belong(destination)=="不明区域"||
          base_name(destination) == "/adm/daemons/taskd")
		destination=MAP_D->random_room(me->query_temp("hansz/task_area"));
		me->move(destination);
		me->remove_listen_to_die(this_object());
		me->set_temp("hansz/fake_finish",1);
		if (objectp(this_object()->query("Maze_"+me->query("id"))))
		this_object()->query("Maze_"+me->query("id"))->over();
		return notify_fail("你离开了这一片奸细出没的区域。\n");
	}
	return ::valid_leave(me,dir);
}

int Show_Local_Map()
{
	return "/cmds/usr/place"->main(this_player()); 
}