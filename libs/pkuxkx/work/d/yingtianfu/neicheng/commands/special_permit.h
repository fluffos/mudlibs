int special_permit(object me,string need)
{
	mapping fighting_require=(["fengshui":0,"tanlan":0,"wenqu":0,"tuji":1,"qunzhan":1,"guwu":0,]);
	mapping busy_ignore=(["fengshui":0,"tanlan":0,"wenqu":0,"tuji":1,"qunzhan":0,"guwu":0,]);
	if (!me->query("mingpin"))
    {
		tell_object(me,"只有大明官员可以使用大明特技。\n");
        return 0;
    }
	if (me->query("ming/special")!=need)
    {
		tell_object(me,"使用这些特技，必须具有"+need+"。\n");
        return 0;
    }
    if (me->is_busy()&&!busy_ignore[need])
    {
        tell_object(me,"你正忙着呢！\n");
        return 0;
    }
	if (!me->query("ming/suikao/time"))
	{
		tell_object(me,"你必须完成至少一次岁考后才能使用大明特技。\n");
        return 0;
	}
	if (me->query("mingpin")!=1&&me->query("ming/suikao/time")+3600*24<=me->query("mud_age"))
	{
		tell_object(me,"必须完成岁考，才能使用大明特技。\n");
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