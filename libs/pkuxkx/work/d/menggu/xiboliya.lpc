inherit F_SAVE;
inherit ROOM;
#define SHEDIAO "/data/business/shediao_quest"
string query_save_file()
{
        return SHEDIAO;
}
#include <ansi.h>
int init_robbers();
void create() 
{ 
        set("short", "林海");
        set("long", @LONG
这里一片无边无际的林海，常年被冰雪覆盖。
LONG
        );
	
        set("exits", ([ 
]));
        set("outdoors", "menggu_n");
        set("no_task",1);
		set("no_clean_up", 1); 
		set("no_reset",1);
		set("no_robber",1);
		setup();
		call_out("check_mazei",60);
}
int check_mazei()
{

	object *robbers;
	int i;
	robbers=livings();
	robbers = filter_array(robbers, (: environment :));
    robbers = filter_array(robbers, (: $1->query("is_menggu_mazei"):) );
	for (i=0;i<sizeof(robbers);i++)
	{
		if (!userp(robbers[i]))
		robbers[i]->check_status();
	}
	remove_call_out("check_mazei");
	call_out("check_mazei",60);
	return 1;
}
int check()
{
	object ob=this_object(),*mazeis=({}),*all_mazeis=({});
	int i;
	all_mazeis=children("/d/menggu/obj/mazei");
	
	if (ob->query("mazei"))
	{
		mazeis=ob->query("mazei");
	}
	for (i=0;i<sizeof(all_mazeis);i++)
	{
		if (member_array(all_mazeis[i],mazeis)==-1)
		{
			all_mazeis[i]->self_dest();
		}
	}
	for (i=0;i<sizeof(mazeis);i++)
	{
		if (!objectp(mazeis[i]))
		{
			mazeis-=({mazeis[i]});
		}
	}
	ob->set("mazei",mazeis);
	if (mazeis==({}))
	{
		ob->init_robbers();
	}
	remove_call_out("check");
	call_out("check",60);
	return 1;
}
int init_robbers()
{
	int i,n=3+random(4);
	object where,mazei,*mazeis=({});
	if (query("initialized"))
	return 1;
	set("initialized",1);
	for (i=0;i<n;i++)
	{
		where=TASK_D->random_room("/d/menggu/");
		while (!objectp(where) || 
		!where->isroom()||
		base_name(where) == "/adm/daemons/taskd"||
		where->query("no_robber")||
		where->not_room())
        {where=TASK_D->random_room("/d/menggu/");}
		mazei=new("/d/menggu/obj/mazei");
		mazei->move(where);
		mazeis+=({mazei});
	}
	this_object()->set("mazei",mazeis);
	check();
	return 1;
}

int replenish_robber()
{
	object where,mazei,*mazeis;
	int n=random(100);
	mazeis=this_object()->query("mazei");
	if (sizeof(mazeis)<8&&n>66)
	{
		while (!objectp(where) || 
		!where->isroom()||
		base_name(where) == "/adm/daemons/taskd"||
		where->query("no_robber")||
		where->not_room())
        {where=TASK_D->random_room("/d/menggu/");}
		mazei=new("/d/menggu/obj/mazei");
		mazei->move(where);
		mazeis+=({mazei});
		this_object()->set("mazei",mazeis);
	}
	else if (sizeof(mazeis)<8&&n>33)
	{
		for (int i=0;i<2+random(2);i++)
		{
			where=TASK_D->random_room("/d/menggu/");
			while (!objectp(where) || 
			!where->isroom()||
			base_name(where) == "/adm/daemons/taskd"||
			where->query("no_robber")||
			where->not_room())
			{where=TASK_D->random_room("/d/menggu/");}
			mazei=new("/d/menggu/obj/mazei");
			mazei->move(where);
			mazeis+=({mazei});
		}
		this_object()->set("mazei",mazeis);
	}
	else
	{
		return 1;
	}
	return 1;
}