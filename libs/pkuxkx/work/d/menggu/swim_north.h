int valid_leave(object me,string dir)
{
    if (dir=="north")
    {
        return notify_fail("直接走过河面？亏你想的出来！游(swim)过去吧！\n");
    }
    return ::valid_leave(me,dir);
}

void init()
{
	object shi;
	object me=this_player();
    add_action("do_swim","swim");
	if (base_name(this_object())=="/d/menggu/yeriver3s"&&me->query_temp("mengguquest/xinshi_2"))
	{
		if (!present("heise shicai",this_object())&&!present("heise shicai",me))
		{
			shi=new(__DIR__"obj/shi");
			shi->move("/d/menggu/yeriver3s");
			message_vision("$N突然发现了路边一颗闪亮的黑色石材。\n",me);
		}
	}
	return;
}

int do_swim()
{
    object me=this_player();
    object room=load_object(this_object()->query("exits/north"));
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    message_vision("$N卷起衣袖，下到河中，向南游了过去！\n",me);
    me->add_busy(3);
    tell_room(room,me->name()+"从北岸游了过来。\n");
    me->move(room);
    return 1;
}