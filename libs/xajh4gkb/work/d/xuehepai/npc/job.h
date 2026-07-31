int valid_leave(object me, string dir)
{
               object ob;

          me=this_player();

        if( me->query_temp("jobstart") && (ob=present("sha shou",environment(me))) && (ob->query("followid")==me->query("id"))  )
                return notify_fail("你还是先把敌人解决了再动吧！\n");        

        if( me->query_temp("jobstart") && present("di zi",environment(me)) ) 
               me->start_busy(random(3));
        return ::valid_leave(me, dir);
}

