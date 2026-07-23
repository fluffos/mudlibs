// by dew

string get_tongmen_guanxi(object obj)
{
    object me;
    int my_time, your_time;
    
    if ( obj->query( "master" ) == "tianshan_shifu" )
    {
        me = this_object();
        my_time = me->query( "tianshan/enter_time" );
        your_time = obj->query( "tianshan/enter_time" );
        
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
    if ( obj->query( "master" ) == "tianshan_shifu" )
        return 1;
    return ::is_tongmen_of( obj );
}


