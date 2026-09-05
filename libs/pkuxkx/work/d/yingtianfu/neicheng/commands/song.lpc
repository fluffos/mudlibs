// song.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int song(object me,string arg)
{
	object weapon;
	if (no_user(me))
	return 1;
	weapon=new(__DIR__+arg);
	if (weapon)
	{
		weapon->move(me);
		message_vision(HIW"大明兵部给$N送来了"+weapon->query("name")+"。\n"+NOR,me);
	}
	return 1;
}
int main(object me,string arg)
{
	string benefit="weapon_acquire",type="day";
	string *weapons=({"sword","blade","halberd","spear","hammer","axe","dagger","whip","fork","staff"});
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"五军都督府 都督佥事","三大营都指挥使","三大营都指挥同知","京卫指挥使司 指挥使","京卫指挥使司 指挥同知","京卫指挥使司 指挥佥事",})))
	return deny(me);
	ming_cycle(me,type,benefit);
	if (me->query("mingpin")==2&&me->query("ming/"+benefit+"/times")>=4)
	{
		tell_object(me,"今天，兵部的人已经送武器来了四趟，实在是抽不出人再来了。\n");
		return 1;
	}
	if (me->query("mingpin")==3&&me->query("ming/"+benefit+"/times")>=2)
	{
		tell_object(me,"今天，兵部的人已经送武器来了两趟，实在是抽不出人再来了。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要兵部送来何种武器？(sword、blade、halberd、spear、hammer、axe、dagger、whip、fork、staff)\n");
		return 1;
	}
	if (member_array(arg,weapons)==-1)
	{
		tell_object(me,"你要兵部送来何种武器？(sword、blade、halberd、spear、hammer、axe、dagger、whip、fork、staff)\n");
		return 1;
	}
	call_out("song",6+random(5),me,arg);
	me->add("ming/"+benefit+"/times",1);
	message_vision("$N发信让兵部尽快给你送来"+arg+"。\n",me);
	return 1;
}
int help(object me)
{
    write("
指令格式 : song <武器> 
让兵部送来某件武器。
"    );
    return 1;
}
