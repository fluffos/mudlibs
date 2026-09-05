//card.c
//cs 参赛资格牌

#include <ansi.h>
inherit ITEM;

mapping block_commands = 
([
	"kill" : 1,
	"steal" : 1,
	"hit" : 1,
	"killall" : 1,
	"hitall" : 1,
	"beg" : 1,
	"follow" : 1,
	"put" : 1,
	"get" : 1,
	"exert" : 1,
	"perform" : 1,
]);
	

void create()
{       
//	seteuid(getuid());
	set_name(HIW"参赛卡"NOR, ({ "cs card" }));
	set_weight(1);
//	set("no_get", 1);
//	set("no_put", 1);
//	set_max_encumbrance(0);
//	set("value", 0);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "张");
		set("long", "这是一张cs参赛资格卡\n");
	}

}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
//	add_action("block_cmd","", 1);
}


int block_cmd(string args)
{
	object me = this_player();
	string verb = query_verb();
	
	if(query("owner") != me)	
		return 0;
	if(block_commands[verb])
	{
		notify_fail("你还是专心玩cs吧。\n");
		return 1;
	}
	return 0;
}

int do_quit()
{
	tell_object(this_player(), "你退出了cs比赛。欢迎下次再来！");
	destruct(this_object());
	return 0;
}
