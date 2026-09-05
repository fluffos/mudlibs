// isrobot.c
// 判定一个id是机器人

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	object ob;

	if( !arg || me != this_player(1)) 
    {
        return help();
    }
    
    ob = find_player(arg);
    if(!objectp(ob) || !userp(ob))
    {
        ob = new("/clone/user/user");

        ob->set("id",arg);

        seteuid(ob->query("id"));
        export_uid(ob);
        seteuid(getuid());

        if(!ob->restore())
        {
            write("此ID不存在。\n");
            return 1;
        }
        write("离线装载用户\n");
    }
    ob->add("antirobot/isrobot/times",1);
    ob->delete("antirobot/isrobot/exp_increase");
    ob->save();

    if(!interactive(ob))
    {
        destruct(ob);
    }

    shout("由于"+arg+"违反机器人规则，在主流任务中使用全自动无人值守机器人，且未能通过图灵测试。被判定为机器人。\n");

	return 1;
}

int help()
{
	write(@TEXT
指令格式：isrobot <玩家ID>

判定一个ID是机器人。
TEXT
	);
	return 1;
}
