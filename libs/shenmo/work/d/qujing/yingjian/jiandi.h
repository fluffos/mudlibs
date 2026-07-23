void delete()
{
        tell_room(this_object(),"一阵水流冲来，周围的珊瑚又聚集了起来。\n");
        delete("exits/down");
}

void init()
{
        add_action("do_feel","tang");
        if( query("exits/down") )
        {
                remove_call_out("delete");
                call_out("delete",3);
        }
}

int err_msg(string arg)
{
        write(arg);
        return 1;
}

int do_feel(string arg)
{
        object me = this_player();
        string place;
        object where,yao;

        if( me->is_busy() )
                return err_msg("你正忙着呢！\n");
        if( ! arg || arg != "stone" )
                return err_msg("你要淌什么?\n");
        if( me->query("obstacle/yj") == "done" )
                return err_msg("你什么也没有淌到。\n");
        if( me->query_temp("find") )
                return err_msg("你已经发现某个地方有入口了，还不快去找？\n");       
        if( random(5)<2 || wizardp(me) )
        {
                place = "/d/qujing/yingjian/jiandi1";
                place[strlen(place)-1] = '0'+random(10);
                where = find_object(place);
                if( !where )
                        where = load_object(place);
                if( !where )
                {
                        write("你仔细淌了淌脚下的石头,结果什么反应也没有。\n");
                        return 1;
                }       
                if( where )
                {
                        message_vision("$N仔细淌了淌脚下的石头,发现周围的珊瑚好象动了一下！\n",me);
                        place->set("exits/down", __DIR__"shanhu");
                        me->start_busy(1);     
                        me->set_temp("find",1);
                }       
                return 1;
        }
        yao=new(__DIR__"npc/yao");
        if( !yao )
        {
                write("你仔细淌了淌脚下的石头,结果什么反应也没有。\n");
                return 1;
        }
        if( yao->move(this_object()) )
        {
                yao->set_leader(me);
                tell_object(me,"糟了，你惊醒了水怪！\n");
        }
        else    destruct(yao);
        write("你仔细淌了淌脚下的石头,结果什么反应也没有。\n");
        return 1;
}

int valid_move(object me)
{
        if( me->query_temp("find") )
                me->delete_temp("find");
}               

