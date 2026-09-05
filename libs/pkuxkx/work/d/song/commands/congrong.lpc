// congrong.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"

int help(object me);
int main(object me,string arg)//投笔从戎
{
	object pl;
	string benefit="bing_congrong",type="day";
	mixed tm=localtime(time());
	string month=sprintf("%d-%d", tm[5], tm[4]+1);
	if (arg=="-h")
	return help(me);
	if (me->query("id")!="zine"&&!DASONG_D->identification(me,({"兵部尚书","兵部侍郎",})))
	return deny(me);
	song_cycle(me,type,benefit);
	if (DASONG_D->identification(me,({"兵部尚书"}))&&me->query("song/"+benefit+"/times")>=2)
	{
		tell_object(me,"你今天已经劝说至少两名文臣转为武将了，再转朝堂上就没人了。\n");
		return 1;
	}
	if (DASONG_D->identification(me,({"兵部侍郎"}))&&me->query("song/"+benefit+"/times")>=1)
	{
		tell_object(me,"你今天已经劝说至少一名文臣转为武将了，再转朝堂上就没人了。\n");
		return 1;
	}
	if (DASONG_D->if_pro_permit("武")==-1)
	{
		tell_object(me,"现在我大宋武臣人员偏多，暂时不要劝说文臣投笔从戎了。\n");
		return 1;
	}
	if (!arg||arg=="")
	{
		tell_object(me,"你要劝说哪位大宋文臣投笔从戎？\n");
		return 1;
	}
	if (present_song_user(me,arg)==1)
	pl=find_player(arg);
	else
	return 1;
	if (pl->query("song/pro")!="文")
	{
		tell_object(me,"你只能劝说大宋文臣投笔从戎！\n");
		return 1;
	}
	if (pl->query("song/change_pro/month")==month)
	{
		tell_object(me,pl->query("name")+"本月刚刚转职过。\n");
		return 1;
	}
	if (!objectp(pl->query_temp("song_identification")))
	{
		tell_object(me,pl->query("name")+"的印信并不在身，暂时无法转为文臣。\n");
		return 1;
	}
	message_vision("$N对$n道：今日国家有难大丈夫……安能久事笔研间乎？\n",me,pl);
	pl->set_temp("song/wen_to_wu",time());
	tell_object(pl,me->name()+"建议你转为武将，请在60秒内决定是否接受(yes/no)？\n");
	me->add("song/"+benefit+"/times",1);
	return 1;
}
int help(object me)
{
    write("
指令格式 : congrong <id> 
让某位大宋文官投笔从戎，转为武将。
"    );
    return 1;
}
