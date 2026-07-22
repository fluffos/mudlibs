// accept.c
// created by snowcat on 5/30/1997
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, env;

  	if(!arg)
    		return notify_fail("你要接受谁的公开邀请？\n");
	if( me->is_ghost() )
    		return notify_fail("做了鬼了，就老实点吧！\n");
	if( me->is_fighting() )
    		return notify_fail("战斗中不能接受公开邀请。\n");
	if( me->is_busy() )
    		return notify_fail("你很忙，不能接受公开邀请。\n");
	obj = find_player(arg);
  	if(!obj)
    		obj = find_living(arg);    
  	if(!obj)
    		obj = LOGIN_D->find_body(arg);
  	if(!obj)
    		return notify_fail("没有这个人。\n");
	
	if(wizardp(obj))  return notify_fail("没有这个人。\n");
  	if(obj->query_temp("invite") != "public")
    		return notify_fail(obj->query("name")+"现在并没有公开邀请别人。\n");
	if(env=environment(me))
     		if(!env->query("outdoors"))
      			return notify_fail("你还是到外面去接受"+obj->name()+"的邀请吧！\n");
  	if(me->query_temp("accept") == obj)
    		return notify_fail("你已经接受"+obj->name()+"的公开邀请了。\n");
	if( obj->query("id")=="zhenyuan daxian"
	 && me->query("life/live_forever") )
		return notify_fail("没有这个必要了。\n");    		

  	tell_object (me,"你接受"+obj->name()+"的公开邀请。\n");
  	tell_object (obj, me->name()+"现在接受你的公开邀请。\n");
	me->set_temp("accept",obj);
  	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : accept <某人>

这个指令告诉别人你接受他/她的公开邀请.

HELP
    );
    return 1;
}

