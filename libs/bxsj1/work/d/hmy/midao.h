string *way = ({
        "up",
        "down",
        "west",
        "east",
        "south",
        "north",
        "southeast",
        "southwest",
        "northeast",
        "northwest",
        "southup",
        "southdown",
        "northup",
        "northdown",
        "eastup",
        "eastdown",
        "westup",
        "westdown",
});
        
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        
        if(!environment(me)->query_temp("killed"))
        {
                if (!present("mojiao shashou",environment(me)))
                {
                        if (me->query_temp("hostage/job_1") == 1
                        && !me->query_temp("hostage/passed_x")
                        && random(2)==1)
                        {
                                ob = new(__DIR__"npc/killer1");
                                ob->set_temp("target",me->query("id"));
                                ob->move(environment(me));
                                for(i=0;i<sizeof(way);i++)
                                {
                                        if (dir == way[i] && objectp(present("mojiao shashou", environment(me))))
                                        {
                                                return notify_fail("魔教杀手一把把你拦住，大声喝道：你想找长老，先得过了我这关。\n");
                                                break;
                                        }
                                }
                        }
                }
                else
                {
                        for(i=0;i<sizeof(way);i++)
                        {
                                if (dir == way[i] && objectp(present("mojiao shashou", environment(me))))
                                {
                                        return notify_fail("魔教杀手一把把你拦住，大声喝道：你想找长老，先得过了我这关。\n");
                                        break;
                                }
                        }
                }
        }
        else if (base_name(environment(me)) == "/d/hmy/midao6" && (dir == "north" || dir == "west"))
        {
                if (me->query_temp("hostage/passed_x") && me->query_temp("hostage"))
                {
                        tell_object(me,"你带着童百雄走了半天，可就是转不出地道。\n");
                        tell_object(me,"这时，只见童百雄在墙壁的角落里轻轻一掀，豁然出现了一个门户。\n");
                        tell_object(me,"你们急忙快步走了出去，外面竟然就是索道。\n");
                        return 1;
                }
                else
                {
                        tell_object(me,"你瞎打瞎撞，居然来到了索道。\n");
                        return 1;
                }
        }
        
        return ::valid_leave(me, dir);
}
