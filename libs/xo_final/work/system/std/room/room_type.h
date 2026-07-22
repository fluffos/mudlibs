int do_ride_none(object me)
{
    object ob, this, *inv;
    int i = 0;
    
    if( !this = find_object( HALL ) )
        this = load_object( HALL );
    inv = all_inventory(this);
    while( i < sizeof(inv) && i >= 0 )
    {
        if( inv[i]->query("is_rided_by") == me->query("id") )
        {
            ob = inv[i];
            i = -10;
        }
        i++;    
    }
    if( i >= 0 )            
        return notify_fail("发现错误！\n");
//    message_vision("$N从$n上跳下。\n", me, ob);
    ob->move( environment(me) );
    ob->delele("is_rided_by");
    ob->set("xingcheng", me->query_temp_marks("zuoji/xingcheng"));
    me->delete_temp_marks("is_riding");
    me->delete_temp_marks("zuoji");
    ob->die();
    return 1;
}
int check_cost( object me, int food_cost, int water_cost, 
    int kee_cost, int sen_cost, int force_cost, int xingcheng_cost, 
    int mforce, int force, int sen )
{
    if( me->query_temp_marks("is_riding") == 0 )
    //如果没有骑牲口
    {
        if( me->query("food") > 0 )
            me->add("food", -food_cost);
        if( me->query("food") <= 0 )
        {
            me->receive_wound("kee", kee_cost);
            me->receive_damage("sen", sen_cost);
        }
        if( me->query("water") > 0 )
            me->add("water",-water_cost);
        if( me->query("water") <=  0 )
        {
            me->receive_damage("kee", kee_cost);
            me->receive_damage("sen", sen_cost);
        }
        if ( mforce >= 1 && force >= 1 )
        {
            me->set("force",force - force_cost);
            return 1;
        }
        else
        {
            if( sen <= sen_cost )
                return notify_fail("你太累了，还是歇歇吧。\n");
            if( mforce > 100 )
            {
                me->add("sen", -sen_cost);
                return 1;
            }
            else
            {
                me->add("sen", -sen_cost);
                return 1;
            }
        }
    }
    else
    {
        if ( me->query_temp_marks("zuoji/xingcheng") 
            < me->query_temp_marks("zuoji/max_xingcheng") )
            me->add_temp_marks("zuoji/xingcheng", xingcheng_cost);
        else
        {
            message_vision("$N所骑的那" + me->query_temp_marks("is_riding") + 
            "突然不支，腿一软，倒了下去，把$N掀了下来！\n", me);
            do_ride_none(me);
            return notify_fail("");
        }
    }
    return 1;
}


