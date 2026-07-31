// goto.c
//星星2000/4/8
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj;
	string msg;

	if( !arg ) return notify_fail("你要去哪里？\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail("你要去哪里？\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("没有这个玩家、生物、或地方。\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");

//    if( stringp(msg = me->query("env/msg_mout")) )
//        message_vision(msg+"\n", me);
//	else
//		message_vision(HIW"只见一阵如梦的"HIM"星光"HIW"闪过之后，$N的身影化为一颗流星飞走了。留下一串象诗般的流光。\n"NOR, me);

	me->move(obj);

//	if( stringp(msg = me->query("env/msg_min")) )
//        message_vision(msg+"\n", me);
//	else
//		message_vision(HIW"你突然看见天边飞来了颗流星，拖着长长的流华飞来，$N的身影突然出现在"HIM"星光"HIW"之中。\n"NOR, me);

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目标>
 
这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.
 
HELP
    );
    return 1;
}
