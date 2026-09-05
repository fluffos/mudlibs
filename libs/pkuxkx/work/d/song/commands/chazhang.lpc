// chazhang.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"

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
	if (me->query("id")!="zine"&&!DASONG_D->identification(me,({"户部尚书","户部侍郎"})))
	return deny(me);
	song_cycle(me,type,benefit);
	if (me->query("song/"+benefit+"/times")>=2)
	{
		tell_object(me,"你今天已经查问了至少两名官员的账目，休息一下吧。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要调查哪位大宋官员的入账？\n");
		return 1;
	}
	if (!pl=find_player(arg))
	{
		tell_object(me,arg+"现在似乎并不在线！\n");
		return 1;
	}
	if (!userp(pl))
	{
		tell_object(me,"你只能调查大宋官员的账目！\n");
		return 1;
	}
	if (!living(pl))
	{
		tell_object(me,"你要等"+arg+"清醒过来才能继续调查他！\n");
		return 1;
	}
	if (!pl->query("song/pro"))
	{
		tell_object(me,"你只能调查大宋官员的账目！\n");
		return 1;
	}
	if (pl==me)
	{
		tell_object(me,"你要查自己的账？\n");
		return 1;
	}
	if (pl->query("song/"+benefit+"/day")==day)
	{
		tell_object(me,pl->query("name")+"本日已经被调查过一次账目了。\n");
		return 1;
	}
	pl->set("song/"+benefit+"/day",day);
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("name")+"("+capitalize(me->query("id"))+")正在查问"+pl->query("name")+"("+capitalize(pl->query("id"))+")的经手账目！", -1);
	tell_object(me,"你查出"+pl->query("name")+"经手的账目，竟有"+MONEY_D->money_str(money)+"的亏空，鉴于同僚的关系，你赶紧通知他补上了漏洞！\n");
	tell_object(pl,WHT+me->query("name")+WHT+"查问了你经手的出入账目。\n"+NOR);
	tell_object(pl,WHT+me->query("name")+WHT+"查出你经手账目中共有"+MONEY_D->money_str(money)+"的亏空并通知了你。\n");
	n=2+random(6);
	if (pl->query("balance")>=money)
	{
		pl->add("balance",-money);
		tell_object(pl,"你补上了这个窟窿，运用朝中的人脉，不仅化险为夷，还受到了嘉奖。\n");
		pl->add("song/credit",n);
		tell_object(pl,HIC"你的大宋功勋度增加了"+chinese_number(n)+"点。\n"NOR);
	}
	else
	{
		tell_object(pl,"虽然知道这个窟窿，一时之间你也凑不出那么多钱，这下被朝廷斥责了。\n");
		pl->add("song/credit",-n);
		tell_object(pl,WHT"你的大宋功勋减少了"+chinese_number(n)+"点。\n"NOR);
	}
	me->add("song/"+benefit+"/times",1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : chazhang <id> 
查问某位大宋官员的经手账目。
"    );
    return 1;
}
