// lead.c
// write by ccbwh 98.3.10
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("指令格式：lead <某人>。\n");


	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("这里没有 " + arg + "。\n");

	if( !ob->is_character() )
		return notify_fail("什么？想带领...." + ob->name() + "？\n");

	if( ob==me )
		return notify_fail("带领自己？\n");
	if (me == ob->query_leader())
          	return notify_fail( ob->name() + "已经跟着你了。\n");

	message_vision("\n$N对着$n说道：跟着我走吧，我带你去个地方。\n" , me , ob );

	write( YEL +"\n你必须等对方同意才能领着对方走。\n" NOR );
	
        tell_object( ob, YEL + "\n如果你愿意跟随" + me->name() + "一起行动,请键入 follow " 
		+ me->query("id") + " 命令。\n" NOR );

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : lead [<生物>]
 
这个指令让你要求某人或生物跟你走。
 
HELP
);
        return 1;
}
