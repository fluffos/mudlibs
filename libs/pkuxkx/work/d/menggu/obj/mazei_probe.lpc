 //Zine 新任务尝试
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("马贼探测器", ({ "robber finder","finder" }));
	set_weight(500);

	set("value",1);
	set("material", "meat");
	
	setup();
	
}


void init()
{
	add_action("do_catch","catch");
	add_action("do_loc","loc");
}

int do_catch(string arg)
{
	object robber,me=this_player();
	if (!robber=present(arg,environment(me)))
	{
		write("no target\n");
		return 1;
	}
	set("robber",robber);
	write("catched.\n");
	return 1;
}

int do_loc()
{
	object robber,me=this_player();
	robber=query("robber");
	if (environment(robber))
	{
		tell_object(me,file_name(environment(robber)));
		return 1;
	}
}

