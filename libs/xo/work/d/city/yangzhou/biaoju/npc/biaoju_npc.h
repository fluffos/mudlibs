// biaoju_npc.h 每个镖局的NPC的一些统一的动作。
// by trill

string get_tongmen_guanxi(object obj)
{
    object me;
    string my_gender;
    int my_time, your_time;
    
    if ( obj->query( "master" ) == "biaoju_shifu" )
    {
        me = this_object();
        my_gender = me->query( "gender" );
        my_time = me->query( "biaoju/enter_time" );
        your_time = obj->query( "biaoju/enter_time" );
        if ( my_gender == "男性" || my_gender == "无性" )
        {
            // 先入为大
            if ( my_time < your_time )
                return "师兄";
            else
                return "师弟";
        }
        else
        {
            if ( my_time < your_time )
                return "师姐";
            else
                return "师妹";
        }
    }
    return ::get_tongmen_guanxi( obj );   
}

int is_tongmen_of(object obj)
{
    if ( obj->query( "master" ) == "biaoju_shifu" )
        return 1;
    return ::is_tongmen_of( obj );
}


