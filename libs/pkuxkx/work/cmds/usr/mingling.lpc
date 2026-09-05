// force.c
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }

int check_distance(object ob,object me)
{
	object env1,env2;
	string* exits;

	env1 = environment(ob);
	env2 = environment(me);

	//在同一个房间或者相邻房间
	if(env1 == env2) return 1;
	if(!mapp(env1->query("exits")) || !mapp(env2->query("exits"))) return 0;
	exits = values(env1->query("exits"));
	if(member_array(file_name(env2),exits) != -1) return 1;
	exits = values(env2->query("exits"));
	if(member_array(file_name(env1),exits) != -1) return 1;
    
    return 0;
}
int main(object me, string arg)
{
	string dest, cmd;
	object ob;

	if( me != this_player(1) ) return 0;
	if( !arg )
		return notify_fail("指令格式 mingling <指令>\n");

	if(me->is_busy()) return notify_fail("你正忙着呢。\n");

	if(!objectp(me->query("suicongdizi/npc")))
	{
		return notify_fail("你没有随从，只有为师门做出重要贡献的人才配有随从。可以去问问本门掌门人关于随从的问题。\n");
	}

    if (environment(me)->query("main_dir")=="/d/reborn/")
    {
        return notify_fail("你的随从无法达到这里。\n");
    }

	ob = me->query("suicongdizi/npc");

	if( !living(ob) )
		return notify_fail("你的随从似乎昏迷不醒，不能执行命令了。\n");

    if(arg == "here")
    {
        return ob->special_function(me,"remotecall","");
    }
	if(!check_distance(ob,me))
	{
        return ob->special_function(me,"remotectrl",arg);
	}
	if(!ob->execute_cmd(me,arg))
	{
		return notify_fail("你的随从并没有听从你的命令。\n");
	}
	write("你的随从执行了你的指令。\n");
	return 1;
}

int help(object me)
{
	write(@Help
指令格式 mingling <指令>

    如果你有随从，可以用这个指令命令他/她做任何你想让他做的事。如果他/她和你关系融洽，就会执行命令。
    mingling here，则可以要求随从立刻出现在身边。
Help
	);
	return 1;
}