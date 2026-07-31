// by tiantian(www.wangcf.com) 2001.4
// 快速回到帮派总舵

#include <ansi.h>

int main( object me, string arg )
{
	if( !me->query("group") )
		return notify_fail( "你并没有加入任何帮派。\n" );

	if( me->is_busy() )
		return notify_fail( "你现在正忙着呢。\n" );
	
	if( me->is_fighting() )
		return notify_fail( "你现在正忙着跟别人打架呢。\n" );
	
	if( me->query_condition( "killer" ) )
		return notify_fail( "你正被通缉，现在回去恐怕会给自己的帮派带来麻烦。\n" );

	// 只能从startroom返回，防止利用该命令走迷宫和躲避pk
	if( !environment( me ) || ! environment( me ) -> query( "valid_startroom" ) )
		return notify_fail( "你无法从这里返回。\n" );

	message_vision( HIC"$N轻轻地闭上眼睛，双腿盘膝而坐，嘴里默默地念叨着什么...\n"NOR, me );
    me->start_busy(1);
	call_out("move",2,me);        
	return 1;
}

void move(object me)
{
	message_vision("$N急急忙忙地回到了自己帮派。\n", me);
   	me->move( GROUP_D->query_home( me ) );
}


int help(object me)
{
  write(@HELP
----------------------------------------
指令格式 : ghome

利用此一指令可直接回到自己的帮派总舵。

相关命令：grecall

----------------------------------------
HELP
    );
    return 1;
}
