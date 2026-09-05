int valid_leave(object me,string dir)
{
    if (dir=="southwest")
    {
        return notify_fail("直接走过河面？亏你想的出来！游(swim)过去吧！\n");
    }
    return ::valid_leave(me,dir);
}

void init()
{
    add_action("do_swim","swim");
}

int do_swim()
{
    object me=this_player();
    object room=load_object(this_object()->query("exits/southwest"));
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    message_vision("$N卷起衣袖，下到河中，向南游了过去！\n",me);
    me->add_busy(3);
    tell_room(room,me->name()+"从东岸游了过来。\n");
    me->move(room);
    return 1;
}