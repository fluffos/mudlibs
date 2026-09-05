void init()
{
    object me=this_player();
    if (!wizardp(me)&&userp(me) && time()-me->query_temp("skf/qingstart")>600)
    {
        tell_object(me,"多尔衮已经不耐烦了，你还是赶紧回去吧！\n");
        me->move(__DIR__"qingjunying");
        return;
    }
	::init();
}
