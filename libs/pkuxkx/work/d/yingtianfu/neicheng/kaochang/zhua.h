void init()
{
    add_action("do_zhua","zhua");
}

int do_zhua()
{
    object ob=this_object();
    object me=this_player();
    
    if (!me->query_temp("mingtasks/libu2/exam"))
    {
        tell_object(me,"没有礼部授命，任何官员不得私自组织考试！\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    message_vision(HIW"$N大喝道：你在作弊吗？\n"NOR,me);
    me->add_busy(1+random(2));
    if (!ob->query("zhua"))
    {
        tell_object(me,"考生愤怒地看着你：打断我考试干嘛？\n");
        tell_object(me,RED"巡考记下了你的过失！\n"NOR);
        me->add_temp("mingtasks/libu2/exam_degree",-1);
        return 1;
    }
    else
    {
        if (random(100)>90)
        {
            tell_object(me,"你细看之下，发现这个座位的考生正在认真答题。\n");
            tell_object(me,"考生愤怒地看着你：打断我考试干嘛？\n");
			ob->delete("zhua");
            return 1;
        }
        else
        {
            tell_object(me,HIC"你抓住一个作弊的考生。\n"NOR);
            tell_object(me,"考生面带愧色地退场了。\n");
            me->add_temp("mingtasks/libu2/exam_degree",2);
            ob->delete("zhua");
            return 1;
        }
    }
}