int climb_down(object me)
{
    int increase,bonus;
    if (me->query_skill("dodge",1)<600&&random(3))
    {
        increase=(int)me->query_dex();
        bonus=(int)this_object()->query("climb_bonus")+1;
        increase=increase*(bonus/2+random(bonus/2));
        me->improve_skill("dodge",increase);
        tell_object(me,HIC"在攀爬瀑布的过程中，你的『基本轻功』获得了一些进步！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,WHT"你小心翼翼地向下移动，生怕一个不慎，万劫不复。\n"NOR);
        return 1;
    }
}

int climb_up(object me)
{
    int increase,bonus;
    if (me->query_skill("parry",1)<600&&random(3))
    {
        increase=(int)me->query_con();
        bonus=(int)this_object()->query("climb_bonus")+1;
        increase=increase*(bonus/2+random(bonus/2));
        me->improve_skill("parry",increase);
        tell_object(me,HIC"在攀爬瀑布的过程中，你的『基本招架』获得了一些进步！\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,WHT"你小心翼翼地向上移动，生怕脚下一滑，万劫不复。\n"NOR);
        return 1;
    }
}

int do_none(string arg)
{
	string verb = query_verb();

        if(verb != "chat" &&verb != "chat*" && verb != "tell" && verb != "look" && verb != "go" && verb!="swim" && verb!="climb"&& verb!="hp"&& verb!="score")
	{
		write("在这里你再乱折腾，肯定会掉下去的。\n");
		return 1;
	}
	return 0;
}