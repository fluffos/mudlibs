//监考 by Zine
void init()
{
    add_action("do_kaikao","kaikao");
}

int exasong()
{
    object me,room;
    object ob=this_object();
    int row,line;
    me=find_player(ob->query("examiner"));
    if (!me)
    {
        ob->delete("using");
        ob->delete("examiner");
        return 1;
    }
	if (me->query_temp("songtasks/libu2/task")!=1)
	{
		ob->delete("using");
        ob->delete("examiner");
        return 1;
	}
    if (me->query_temp("songtasks/libu2/examround")>12)
    {
		if (me->query_temp("songtasks/libu2/exam_degree")>0)
		me->set_temp("songtasks/libu2/1/finish",1);
        tell_object(me,"礼部考试结束，你可以回去复命了。\n");
		if (ob->query("examiner")==me->query("id"))
		{
			ob->delete("using");
			ob->delete("examiner");
		}
        return 1;
    }
    if (ob->query("room"))
    {
    
        room=load_object(ob->query("room"));
        room->delete("zhua");
    }
    row=1+random(4);
    line=1+random(4);
    if (row==1&&line==1)
    {
        room=load_object(__DIR__"r1a");
    }
    if (row==1&&line==2)
    {
        room=load_object(__DIR__"r1b");
    }
    if (row==1&&line==3)
    {
        room=load_object(__DIR__"r1c");
    }
    if (row==1&&line==4)
    {
        room=load_object(__DIR__"r1d");
    }
    if (row==2&&line==1)
    {
        room=load_object(__DIR__"r2a");
    }
    if (row==2&&line==2)
    {
        room=load_object(__DIR__"r2b");
    }
    if (row==2&&line==3)
    {
        room=load_object(__DIR__"r2c");
    }
    if (row==2&&line==4)
    {
        room=load_object(__DIR__"r2d");
    }
    if (row==3&&line==1)
    {
        room=load_object(__DIR__"r3a");
    }
    if (row==3&&line==2)
    {
        room=load_object(__DIR__"r3b");
    }
    if (row==3&&line==3)
    {
        room=load_object(__DIR__"r3c");
    }
    if (row==3&&line==4)
    {
        room=load_object(__DIR__"r3d");
    }
    if (row==4&&line==1)
    {
        room=load_object(__DIR__"r4a");
    }
    if (row==4&&line==2)
    {
        room=load_object(__DIR__"r4b");
    }
    if (row==4&&line==3)
    {
        room=load_object(__DIR__"r4c");
    }
    if (row==4&&line==4)
    {
        room=load_object(__DIR__"r4d");
    }
    if (random(10)>1)
    {
        ob->set("room",base_name(room));
        room->set("zhua",1);
    }
    me->add_temp("songtasks/libu2/examround",1);
    tell_object(me,"似乎"+room->query("short")+"有些动静，如果有人作弊，一定要"+HIR+"抓"+NOR+"住！\n");
    remove_call_out("exasong");
    call_out("exasong",10);
    return 1;

}

int do_kaikao()
{
    object me=this_player();
    object ob=this_object();
    if (ob->query("using"))
    {
        tell_object(me,"另一场考试正在进行着，你稍等片刻吧。\n");
        return 1;
    }
    if (me->query_temp("songtasks/libu2/task")!=1)
    {
        tell_object(me,"没有礼部授命，任何官员不得私自组织考试！\n");
        return 1;
    }
    if (me->query_temp("songtasks/libu2/exambegin"))
    {
        tell_object(me,"你不是早就宣布过开考了？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    else
    {
        message_vision("$N开始带领众考生拜祭至圣先师，然后宣布了考场纪律！\n",me);
        message_vision(HIR"一声锣响后，$N宣布：开考！\n"NOR,me);
        me->set_temp("songtasks/libu2/exambegin",1);
        ob->set("using",1);
        ob->set("examiner",me->query("id"));
        exasong();
        return 1;
    }
}

