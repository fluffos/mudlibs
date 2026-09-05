// song.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
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
		message_vision(HIR"大宋军器监给$N送来了"+weapon->query("name")+HIR+"。\n"+NOR,me);
	}
	return 1;
}
int main(object me,string arg)
{
	string benefit="weapon_acquire",type="day";
	string *weapons=({"sword","blade","halberd","spear","hammer","axe","dagger","whip","fork","staff"});
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!DASONG_D->identification(me,({"殿前都都指挥使","捧日卫上护军","天武卫上护军","神卫上护军","龙卫上护军","捧日卫上将军","天武卫上将军","神卫上将军","龙卫上将军",})))
	return deny(me);
	song_cycle(me,type,benefit);
	if (DASONG_D->identification(me,({"殿前都都指挥使"}))&&me->query("song/"+benefit+"/times")>=4)
	{
		tell_object(me,"今天，军器监的人已经送武器来了四趟，实在是抽不出人再来了。\n");
		return 1;
	}
	if (DASONG_D->identification(me,({"捧日卫上护军","天武卫上护军","神卫上护军","龙卫上护军","捧日卫上将军","天武卫上将军","神卫上将军","龙卫上将军",}))&&me->query("song/"+benefit+"/times")>=3)
	{
		tell_object(me,"今天，军器监的人已经送武器来了两趟，实在是抽不出人再来了。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要军器监送来何种武器？(sword、blade、halberd、spear、hammer、axe、dagger、whip、fork、staff)\n");
		return 1;
	}
	if (member_array(arg,weapons)==-1)
	{
		tell_object(me,"你要军器监送来何种武器？(sword、blade、halberd、spear、hammer、axe、dagger、whip、fork、staff)\n");
		return 1;
	}
	call_out("song",6+random(5),me,arg);
	me->add("song/"+benefit+"/times",1);
	message_vision("$N发信让军器监尽快给你送来"+arg+"。\n",me);
	return 1;
}
int help(object me)
{
    write("
指令格式 : request <武器> 
让军器监送来某件武器。
"    );
    return 1;
}
