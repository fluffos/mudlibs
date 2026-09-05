// focus.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, *myThisVein;
	
	if(!arg)
		return notify_fail("你想通哪条经脉？\n");
	myThisVein=me->query("myVeins/"+arg+"/status");
	for (i=0;i<sizeof(myThisVein);i++)
		myThisVein[i]= 3;
	me->set("myVeins/"+arg+"/status",myThisVein);
	write("all have "+sizeof(myThisVein)+"\n");
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
 
