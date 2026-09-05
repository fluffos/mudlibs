int MyProBonus(object me)
{
	int flag=0,folds=2+random(3);
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	if (me->query("level")<100) return 1;
	if (!me->query("MyColors")) return 1;
	if (!arrayp(me->query("MyColors"))) return 1;
	if (!query("Pro_Colors")) return 1;
	if (!arrayp(query("Pro_Colors"))) return 1;
	if (!query("Pro_id")) return 1;
	for (int i=0;i<sizeof(query("Pro_Colors"));i++)
	{
		if (member_array(query("Pro_Colors")[i],me->query("MyColors"))!=-1)
		{
			flag=1;
			break;
		}
	}
	if (!flag) return 1;
	if (me->query("MyProBonus/"+query("Pro_id")+"/date")==date) return 1;
	me->set("MyProBonus/"+query("Pro_id")+"/date",date);
	tell_object(me,HBGRN+HIB+"这次任务因为你有个响亮的名号，奖励"+chinese_number(folds)+"倍发放。\n"+NOR);
	return folds;
}