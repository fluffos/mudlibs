int do_qingan(string arg)
{
    object me=this_player();
    if (!arg||arg!=this_object()->query("id"))
    {
        return notify_fail("你要跟谁请安。\n");
    }
    if (me->query_temp("apprentice/step")<this_object()->query("step"))
    {
        return notify_fail("尊卑长幼有序，切不可乱了辈分。\n");
    }
    if (me->query_temp("apprentice/step")>this_object()->query("step"))
    {
        return notify_fail("你不是给我请过安了吗，老来烦我干嘛？\n");
    }
    else
    {
        tell_object(me,"你尊尊敬敬地跟"+this_object()->query("name")+"请了声安。\n");
        tell_object(me,this_object()->query("name")+"不耐烦得对你摆了摆手。\n");
        me->add_temp("apprentice/step",1);
        if (me->query_temp("apprentice/step")==7||me->query_temp("apprentice/step")==8)
        {
            me->set_temp("apprentice/finish",1);
            tell_object(me,"你向星宿派众前辈都请安过了，可以向阿紫复命了。\n");
        }
        return 1;
    }
}