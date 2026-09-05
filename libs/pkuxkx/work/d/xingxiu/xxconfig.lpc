// Zine 19 Oct 2010 星宿任务房间配置

inherit ROOM;

int change_night_desc();

void init()
{
    object me=this_player();
	set("no_die",1);
	me->listen_to_die(this_object()); 
	if (me->query("family/family_name")=="星宿派")
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
}



void create()
{
	set("no_task",1);
    set("valid_startroom", 1);
    
}

int valid_leave(object me, string dir)
{       
    me->remove_listen_to_die(this_object());        
    return ::valid_leave(me, dir);
}