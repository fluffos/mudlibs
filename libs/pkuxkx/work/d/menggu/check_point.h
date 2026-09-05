int check_point(object me,object room)
{
    string *ob;
    if (!me->query_temp("shediaoquest/jdfm/check_points")||
  (me->query_temp("shediaoquest/jdfm/check_points")&&member_array(file_name(room),me->query_temp("shediaoquest/jdfm/check_points")))==-1)
    {
        ob=me->query_temp("shediaoquest/jdfm/check_points");
        if (!ob)
        {
            ob=({});
        }
        ob+=({file_name(room)});
        me->set_temp("shediaoquest/jdfm/check_points",ob);
        me->add_temp("shediaoquest/jdfm/check_point",1);
        tell_object(me,"过了"+room->query("short")+"，你向桑坤的老巢又接近了一些。\n");
    }
    return 1;
}
