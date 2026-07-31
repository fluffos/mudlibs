#include <ansi.h>
inherit ROOM;
#include <room.h>
void create()
{
	set("short",HIY"名人堂擂台"NOR);
	set("long",HIR"这里集聚了武林各大高手，请小心！！！"NOR);	
	set("action_list",([
	HIY"退出挑战"NOR:"exit",		
	]));	
	setup();
}

void init()
{
	add_action("do_exit", "exit");
	//add_action("jinji", "stats");
}

int do_exit(object me,string arg)
{
me = this_player();
write(HIG"你退出了挑战！！！\n"NOR);
me->move("/d/city/mingrt");
return 1;
}

/*
void jinji(int delay)
{
    add("ceng",1);
	call_out("jinji",3);
}

int dddd()
{
	object npc,romm;	
	npc = new("/cmds/npc");
	npc->set("name",query("ceng")+"层高手");
	npc->move(this_object());
	return 1;
}



*/
