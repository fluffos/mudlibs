// ruku.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)//刀枪入库
{
	object pl;
	string benefit="bing_ruku",type="day";
	mixed tm=localtime(time());
	string month=sprintf("%d-%d", tm[5], tm[4]+1);
	if (arg=="-h")
	return help(me);
	if (!identification(me,"兵部尚书")&&me->query("id")!="zine")
	return deny(me);
	ming_cycle(me,type,benefit);
	if (me->query("ming/"+benefit+"/times")>=2)
	{
		tell_object(me,"你今天已经劝说至少两名武将转为文臣了，再转就没人保疆卫国了。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要劝说哪位大明武将刀枪入库？\n");
		return 1;
	}
	if (present_ming_user(me,arg)==1)
	pl=find_player(arg);
	else
	return 1;
	if (pl->query("mingpin")>6)
	{
		tell_object(me,"你只能劝说六品及以上大明武将刀枪入库！\n");
		return 1;
	}
	if (pl->query("ming/pro")!="武")
	{
		tell_object(me,"你只能劝说大明武将刀枪入库！\n");
		return 1;
	}
	if (pl->query("ming/change_pro/month")==month)
	{
		tell_object(me,pl->query("name")+"本月刚刚转职过。\n");
		return 1;
	}
	if (!present("guan yin",pl))
	{
		tell_object(me,pl->query("name")+"的官印并不在身，暂时无法转为文臣。\n");
		return 1;
	}
	message_vision("$N对$n道：今日天下太平已久，真个是：马放南山，刀枪入库，五谷丰登，万民乐业。将军转为文臣更可为国效力。\n",me,pl);
	pl->set_temp("ming/wu_to_wen",time());
	tell_object(pl,me->name()+"建议你转为文臣，请在60秒内决定是否接受(yes/no)？\n");
	me->add("ming/"+benefit+"/times",1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : ruku <id> 
让某位大明武将刀枪入库，转为文臣。
"    );
    return 1;
}
