void init()
{
        object me = this_player();
        string arg = this_object()->query("mj_xl");
        int i = this_object()->query("mj_xl2");

        if(me->query_temp("mj/xunluo") && !me->query_temp(arg)
           && me->query_temp("mj/xunluo") == (i-1))
          me->add_temp(arg,1);
}