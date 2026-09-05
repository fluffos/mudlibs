// chazhang.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int main(object me,string arg)
{
	mixed tm=localtime(time());
	object pl;
	string benefit="chazhang",type="day";
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	int n,money=250000+random(250000);
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!identifications(me,({"户部尚书","户部左侍郎","户部右侍郎",})))
	return deny(me);
	ming_cycle(me,type,benefit);
	if (me->query("ming/"+benefit+"/times")>=2)
	{
		tell_object(me,"你今天已经查问了至少两名官员的账目，休息一下吧。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要调查哪位大明官员的入账？\n");
		return 1;
	}
	if (!pl=find_player(arg))
	{
		tell_object(me,arg+"现在似乎并不在线！\n");
		return 1;
	}
	if (!userp(pl))
	{
		tell_object(me,"你只能调查大明官员的账目！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你要等"+arg+"清醒过来才能继续调查他！\n");
		return 1;
	}
	if (!pl->query("mingpin"))
	{
		tell_object(me,"你只能调查大明官员的账目！\n");
		return 1;
	}
	if (pl->query("ming/tj/pin"))
	{
		tell_object(me,"外官不得查问内廷账目。\n");
		return 1;
	}
	if (pl==me)
	{
		tell_object(me,"你要查自己的账？\n");
		return 1;
	}
	if (pl->query("ming/"+benefit+"/day")==day)
	{
		tell_object(me,pl->query("name")+"本日已经被调查过一次账目了。\n");
		return 1;
	}
	pl->set("ming/"+benefit+"/day",day);
	message("daming",HIW"【大明】"+me->query("name")+HIW+"("+capitalize(me->query("id"))+")正在查问"+pl->query("name")+HIW+"("+capitalize(pl->query("id"))+")的经手账目！\n"NOR,users());
	tell_object(me,"你查出"+pl->query("name")+"经手的账目，竟有"+MONEY_D->money_str(money)+"的亏空，鉴于同僚的关系，你赶紧通知他补上了漏洞！\n");
	tell_object(pl,WHT+me->query("name")+WHT+"查问了你经手的出入账目。\n"+NOR);
	tell_object(pl,WHT+me->query("name")+WHT+"查出你经手账目中共有"+MONEY_D->money_str(money)+"的亏空并通知了你。\n");
	n=2+random(6);
	if (pl->query("balance")>=money)
	{
		pl->add("balance",-money);
		tell_object(pl,"你补上了这个窟窿，运用朝中的人脉，不仅化险为夷，还受到了嘉奖。\n");
		pl->add("ming/credit",n);
		tell_object(pl,HIC"你的大明功勋增加了"+chinese_number(n)+"点。\n"NOR);
	}
	else
	{
		tell_object(pl,"虽然知道这个窟窿，一时之间你也凑不出那么多钱，这下被朝廷斥责了。\n");
		pl->add("ming/credit",-n);
		tell_object(pl,WHT"你的大明功勋减少了"+chinese_number(n)+"点。\n"NOR);
	}
	me->add("ming/"+benefit+"/times",1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : chazhang <id> 
查问某位大明官员的经手账目。
"    );
    return 1;
}
