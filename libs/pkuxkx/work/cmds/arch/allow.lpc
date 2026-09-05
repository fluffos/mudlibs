// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *id;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
        
	if( arg ) id = explode(arg, " ");
	seteuid(getuid());
	if( LOGIN_D->add_allowed_id(id) ) 
    {
		write("Ok.\n");
		return 1;
	} else
		return notify_fail("白名单设定失败。\n");
}

int help (object me)
{
        write(@HELP
指令格式: allow <玩家id> <玩家id> ...
          allow none
 
在wizlock打开的情况下允许某个玩家id进入游戏。
 
HELP
);
        return 1;
}
 
