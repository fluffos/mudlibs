#include <ansi.h>
int do_no()
{
	object me=this_player();
	if (me->query_temp("song/wu_to_wen"))
	{
		tell_object(me,"你拒绝了刀枪入库转为文臣的建议。\n");
		me->delete_temp("song/wu_to_wen");
		return 1;
	}
	else if (me->query_temp("song/wen_to_wu"))
	{
		tell_object(me,"你拒绝了投笔从戎转为武将的建议。\n");
		me->delete_temp("song/wen_to_wu");
		return 1;
	}
	else
	{
		return 0;
	}
}
int change_pro(object me,string rank,string pro,string mark,string desc)
{
	mixed tm=localtime(time());
	string month=sprintf("%d-%d",tm[5],tm[4]+1);
	message_vision("$N决定接受建议，转为"+rank+"。\n",me);
	me->set("song/pro",pro);
	me->delete_temp("song/"+mark);
	me->set("song/change_pro/month",month);
	me->set_temp("song/hor_promote","change_pro");
	DASONG_D->position_me(me);
	DASONG_D->reset_me_duty(me);
	DASONG_D->get_tiezhi(me,-1);
	CHANNEL_D->do_channel(this_object(), "dasong", me->query("name")+"("+capitalize(me->query("id"))+")决定"+desc+"，就此转为"+me->query("song/title")+"！", -1);
	destruct(this_object());
	DASONG_D->guanyin_player(me);
	return 1;
}

int do_yes()
{
	object me=this_player();
	if (me->query_temp("song/wu_to_wen"))
	{
		if (time()-me->query_temp("song/wu_to_wen")>60)
		{
			me->delete_temp("song/wu_to_wen");
			return 0;
		}
		else
		{
			return change_pro(me,"文臣","文","wu_to_wen","刀枪入库");
		}
	}
	else if (me->query_temp("song/wen_to_wu"))
	{
		if (time()-me->query_temp("song/wen_to_wu")>60)
		{
			me->delete_temp("song/wen_to_wu");
			return 0;
		}
		else
		{
			return change_pro(me,"武将","武","wen_to_wu","投笔从戎");
		}
	}
	else
	{
		return 0;
	}
}
