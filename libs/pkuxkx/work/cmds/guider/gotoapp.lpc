// gotouser.c

inherit "/cmds/guider/guidercmd";

int get_cost(object me) {return 2;}

int exec_cmd(object me, string arg)
{
        int goto_inventory = 0;
        object obj;
        string msg;

		if( !arg ) 
		{
			tell_object(me,"你要去哪里？\n");
			return 0;
		}

        obj = find_player(arg);
        if(!obj || !me->visible(obj)) 
		{
            tell_object(me,"没有这个玩家。\n");
			return 0;
        }
        if(check_apprentice(me,obj)!=1) 
		{
			tell_object(me,"他/她不是你当前的学生。\n");
			return 0;
		}
        if(environment(obj))
           obj = environment(obj);

        if( !obj ) 
		{
			tell_object(me,"这个玩家不知道在哪里。\n");
			return 0;
		}

        message_vision("只见$N口中念念有词，片刻之间天边飘来一朵白云，$N施施然踏足而上，不见踪影。。\n", me);
        me->move(obj);
        message_vision("天边飘来一朵白云，$N从上面施施然的走到你面前。\n", me);
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : gotoapp <目标>
 
这个指令让你可以快速的到达你的学生身边。
 
HELP
    );
    return 1;
}
