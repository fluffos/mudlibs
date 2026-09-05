//quest_npc
//Made by jason@indeed

inherit ITEM;

void uncoincious();
void die();

void create()
{
	seteuid(getuid());
	set_name("任务物件",({"ying di",}));
	set("env/invisibility",4);
	set("no_get",1);
	set("no_drop",1);
	setup();
}

void go_leave()
{
	call_out("leave",query("wait_time"));
}

void leave()
{
	environment(this_object())->delete("quest");
	destruct(this_object());
}

void unconcious()
{
	die();	
}

void die()
{
	environment(this_object())->delete("quest");
}
void init()
{
	add_action("do_quest","dojob");
}

int do_quest()
{
	mixed jieguo;
	if(!this_player()->query_temp("quest")
	||this_player()->query_temp("quest/quest_room")!=base_name(environment(this_object())))
	{
		return 0;
	}
	if(query("quest_func",1)) 
	{
		jieguo=evaluate(query("quest_func",1),this_player());
		if(jieguo=="quest_done") leave();
		return 1;
	}
	return 0;
}