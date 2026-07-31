// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main()
{
	object me=this_player();
        if (query_heart_beat(me)){
        write("现在你的心跳正常!!\n");
//        return 0;
//        tell_object(me,"现在你的心跳正常"。\n"NOR);
}
else
{
	me->set_heart_beat(1);
	me->set_temp("netdead",0);
        write("恢复心跳完闭!!\n");
//        tell_object(me,"恢复心跳完闭.!"。\n"NOR);
}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: where <玩家的 ID>

这个指令是用来得知玩家目前所在的位置.

HELP
	);
	return 1;
}

