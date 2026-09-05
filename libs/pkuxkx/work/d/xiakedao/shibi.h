//modify by gudu October 02
//shibi.h
//写个.h利于改
//Modified by iszt@pkuxkx, 2007-04-18, no canwu while busy

int canwu(object me,string skill,string msg,int times)
{
	int realtimes,i;
	int imp_skill;
	string fail_msg;
	int sk=me->query_skill(skill,1);	

  if  (! me->query("xkdling")) 
     	return notify_fail("你没有受到邀请，你是怎么混上来的。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if (times < 1)
		return notify_fail("你至少要读一次！\n");
	message_vision("$N正专心观看石壁。\n", me);
	if ( me->query_int() < 35 )
	{
		write("你面对于这‘侠客行’的古诗图解，竭尽心智，试图理解其中包蕴的古往今来最最博大精深的武学秘奥，怎奈终究不能参悟其中十之一二 \n");
		return 1;
	}
//		if(!me->is_busy()) return 0;
	if( (int)me->query("max_jingli")<100)
	{
		write("你精力不够，无法领悟石壁。\n");
		return 1;
	}
	if((int)me->query("jing")<150
	||(int)me->query("neili")<150
	||(int)me->query("qi")<150)
	{
		write("你已经累了，还是休息一会吧。\n");
		return 1;
	}
	if ( sk  > me->query_skill_limit() )
	{
		tell_object(me, "也许是缺乏实战经验，你对石壁上面所说的东西总是无法领会。\n");
		return 1;
	}

	realtimes = times;
	fail_msg = "";
	if (((int)me->query("jing")-100)/50 < times)
	{
		realtimes = (me->query("jing")-100)/50;
		fail_msg = "你已经累了，还是休息一会吧。\n";
	}
	if ((me->query("neili")-150)/5 < realtimes)
	{
		realtimes = (me->query("neili")-150)/5;
		fail_msg = "你内力不足，无法依照石壁内容行功参悟。\n";
	}
        tell_object(me, msg);
	me->receive_damage("jing",50*realtimes);
	me->add("neili",-5*realtimes);
	imp_skill = (int)me->query_skill("literate",1)/6+1;
	imp_skill = imp_skill * SPEWEEK_D->query_learn_bonus()/100;//special week
	me->improve_skill(skill,imp_skill*realtimes);
	if (fail_msg != "") tell_object(me,fail_msg);
	return 1;
}

