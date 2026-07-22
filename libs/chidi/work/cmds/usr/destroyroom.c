inherit F_CLEAN_UP;


int main(object me, string arg)
{
        string this_file;
        string tagowner;
        string file;
        object env;
		object room;
        seteuid(getuid());
        if(!arg)
			return notify_fail("指令格式：　buildroom north\n");

		if((me->query("banghui/rank_lv"))<8)
			return notify_fail("你没有这种权力。\n");

		env = environment(me);
		if((string) env->query("owner") != (string) me->query("banghui/name"))
		{
			return notify_fail("你毁别人的房子干什么！\n");
		}

		if(!env->query("exits/"+arg))
			return notify_fail("这个方向没有房间。\n");

        file = base_name(env)+".c";
		write(file);

        this_file = read_file(file);
        this_file = replace_string(this_file,"\""+arg+"\""+" : \""+env->query("exits/"+arg)+"\",", "");
		write_file(file,this_file,1);

		env->delete("exits/"+arg);

        return 1;
        
}
int help (object me)
{
        write(@HELP
指令格式: buildroom <讯息>
给自己的帮派造房子。

HELP
        );
        return 1;
}

