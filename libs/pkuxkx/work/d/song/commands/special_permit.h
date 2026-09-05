int special_permit(object me,string need)
{
	int n=20;
	mapping fighting_require=(["fengshui":0,"tanlan":0,"wenqu":0,"tuji":1,"qunzhan":1,"guwu":0,]);
	mapping busy_ignore=(["fengshui":0,"tanlan":0,"wenqu":0,"tuji":1,"qunzhan":0,"guwu":0,]);
	if (!me->query("song/pro"))
    {
		tell_object(me,"只有大宋官员可以使用大宋特技。\n");
        return 0;
    }
	if (me->query("song/special")!=need)
    {
		tell_object(me,"使用这些特技，必须具有"+need+"。\n");
        return 0;
    }
    if (me->is_busy()&&!busy_ignore[need])
    {
        tell_object(me,"你正忙着呢！\n");
        return 0;
    }
	if (!me->query("song/suikao/time")&&me->query("song/pro")!="宦")
	{
		tell_object(me,"你必须完成至少一次磨勘后才能使用大宋特技。\n");
        return 0;
	}
	if (me->query("song/suikao/overall")<0)
	{
		tell_object(me,"你磨勘的成绩太差，不准使用大宋特技。\n");
		return 0;
	}
	if (DASONG_D->get_my_pin(me)!=1&&me->query("song/suikao/time")+3600*24<=me->query("mud_age")&&me->query("song/pro")!="宦")
	{
		tell_object(me,"必须完成当年磨勘后，才能使用大宋特技。\n");
		return 0;
	}
	if (me->query("song/pro")=="宦")
	n=50;
	if (me->query("song/credit")<n)
	{
		tell_object(me,"你的大宋功勋度太低，至少要"+n+"点以上才能使用大宋特技。\n");
		return 0;
	}
	if (me->is_fighting()&&fighting_require[need]==0)
	{
		tell_object(me,"战斗中无法使用"+need+"特技。\n");
		return 1;
	}
	if (!me->is_fighting()&&fighting_require[need]==1)
	{
		tell_object(me,"只有在战斗中才能使用"+need+"特技。\n");
		return 1;
	}
	return 1;
}