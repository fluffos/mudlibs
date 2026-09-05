//pet.c
#include <ansi.h>
#define NICK_CMD        "/cmds/usr/nick"
inherit NPC;
inherit F_SAVE;

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 4, ob);
	}
	add_action("do_modify", "modify");
	add_action("do_let","let");
	add_action("do_get","get");
}
void greeting(object ob)
{
	object owner,me;
	me=this_object();
	owner=me->query_leader();
	if( !owner)
	{
		message_vision(me->query("lost"),me);
		return;
	}
	if( !present(owner, environment()) )
	{
		random_move();
		return;
	}
	else
	{
		message_vision(me->query("msg_meet"),me);
		return;
	}
}

int do_modify(string arg)
{
	object ob;
	string option, content;
	
	if( !(ob = this_player()) || (ob != query_leader()) )
		return notify_fail("这不是你的宠物，别指手划脚了好吗？\n");
	
	if( !arg || sscanf(arg, "%s %s", option, content) != 2 )
		return notify_fail("指令格式 : modify <选项> <内容>\n" +
		"目前可以修改的选项有：long, nick, msg_lost, msg_meet, msg_come, msg_leave.\n");
	
	if( member_array(option, ({ "long", "nick", "msg_lost", "msg_meet", "msg_come", "msg_leave" })) == -1 )
		return notify_fail("指令格式 : modify <选项> <内容>\n" +
		"目前可以修改的选项有：long, nick, msg_lost, msg_meet, msg_come, msg_leave.\n");
	
	if( sizeof(content) > 80 )
		return notify_fail("对不起，你的描述太长了。\n");
	
	if( sscanf(content, "%*s\\%*s") || sscanf(content, "%*s\"%*s") )
		return notify_fail("描述里不可以含有 \" 和 \\ 字符。\n");
	if ( (option != "nick") && (option != "long"))
	        if( strsrch(content, "$N$") == -1 )
                	write("你输入的字串中必需含有$N$\n");
        content = replace_string(content, "$N$", this_object()->query("name"));
	if( option == "nick" )
		NICK_CMD->main(this_object(), content);
	else
		set(option, content + "\n");
	save();
	write("描述修改完毕。\n");
	return 1;
}
int do_let(string arg)
{
	string petid,cmd,cmd1,cmdarg;
	object obj=this_object();
	if(!arg)
		return notify_fail(HIY+"你想让你的"+obj->query("name")+"做什么事？\n"+NOR);
	if(sscanf(arg, "%s to %s", petid,cmd1) !=2)
		return notify_fail(HIC+"你想让你的宠物做什么事？\n"+NOR);
	if(petid!=obj->query("id"))
		return notify_fail(HIC+"这又不是你的宠物，你来指手画脚的干什么？\n"+NOR);
	sscanf(cmd1,"%s %s",cmd,cmdarg);
	if(cmd=="bai"||cmd=="apprentice")
		return notify_fail(HIC+"宠物不能拜师，不过你可以自己教宠物一些技能。\n"+NOR);
	else if(!cmdarg||cmdarg=="")
	{
		if(cmd1=="save")
			save();
		else
			command(cmd1);
	}
	else
		command(cmd+" "+cmdarg);
	return 1;
}
int do_get(string arg)
{
	string petid;
	object obj,player;
	obj=this_object();
	player=this_player();
	if(!arg||arg=="")
		return 0;
	sscanf(arg,"%s",petid);
	if(petid!=obj->query("id")||obj->query_leader()->query("id")!=player->query("id"))
		return 0;
	else
	{
		obj->move(player);
		message_vision("$N小心的把"+obj->query("name")+"抱起来，搂在怀里。\n",player);
		return 1;
	}
}
void save()
{
	string data,MSG_LONG,MSG_LOST,MSG_MEET,MSG_COME,MSG_LEAVE;
	int COMBAT_EXP;
	if(data=read_file("/d/private/"+query_leader()->query("id")[0..0] + "/" + query_leader()->query("id") + "_"+ query("id") + ".o"))
	{
		if(sscanf(data,"combat_exp %d msg_long %s msg_lost %s msg_meet %s msg_come %s msg_leave %s",
			COMBAT_EXP,MSG_LONG,MSG_LOST,MSG_MEET,MSG_COME,MSG_LEAVE)==6)
		{
			set("combat_exp",COMBAT_EXP);
			set("long",MSG_LONG);
			set("msg_lost",MSG_LOST);
			set("msg_meet",MSG_MEET);
			set("msg_come",MSG_COME);
			set("msg_leave",MSG_LEAVE);
		}
	}

}