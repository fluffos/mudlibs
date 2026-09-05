// focus.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string msg;
	
	if(!arg)
	{
		obj = me->query_temp("focus_target");
		if ( !obj || !objectp(obj) )
			tell_object(me, "你现在没有锁定焦点目标。\n");
		else
		{
			msg = "你锁定的焦点目标是："+obj->query("name")+"("+obj->query("id")+")";
			if (environment(obj)!=environment(me) || !me->visible(obj))
				msg += "，但现在目标不在这里。\n";
			else 
				msg += "。\n";
			tell_object(me, msg);
		}
		return 1;
	}
	
	if (arg=="none")
	{
		me->delete_temp("focus_target");
		tell_object(me, "你现在没有锁定焦点目标。\n");
		return 1;
	}
	
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你想锁定哪个目标？\n");
	
	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if(obj==me)	return notify_fail("锁定自己？别这么想不开。\n");
	
	me->set_temp("focus_target", obj);
	
	tell_object(me, "你盯着"+obj->query("name")+"看了一眼，在心中默默将其锁定为自己的焦点目标。\n");
	
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : focus <人物>
 
这个指令让你把一个人物锁定为自己的焦点目标。当你同时面对多个战斗对手时，
如果锁定了其中一个为焦点目标，那么你的攻击将集中在该目标身上，直到目标
死亡、脱离战斗或离开房间，才会转移攻击其他目标。

注：你可以在进入战斗之前就先锁定一个焦点目标。
 
HELP
    );
    return 1;
}
 
