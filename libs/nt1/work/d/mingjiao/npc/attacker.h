void init()
{
        object ob, me = this_player();
        if ( interactive(me) 
          && me->query_temp("mj/xunluo")
          && me->query_temp("mj/attacker")
          && random(this_object()->query("outer_times")) == 1
          ) {
                 ob = new("/d/mingjiao/npc/attacker");
                 message_vision("\n一个人影突然从旁跳了出来，拦住$N的去路！\n\n", me); 
                 ob->move(environment(me));
                 me->add_temp("mj/attacker", 1);
                 me->add_temp("mj/attacker1",1);
                 ob->do_copy(me);
                 ob->kill_ob(me);
        }
}

int valid_leave(object me, string dir)
{
        object ob;
        if( me->query_temp("mj/xunluo")
          && objectp(ob=present("attacker", environment(me)))
          && ob->query("victim") == me->query("id")
          && !userp(ob))
            return notify_fail(ob->name()+"一言不发，闪身拦在你面前！\n");
            return ::valid_leave(me, dir);
} 
