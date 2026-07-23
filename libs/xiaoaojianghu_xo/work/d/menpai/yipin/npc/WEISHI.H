
void init()
{
        object ob=this_object();
        object me=this_player();
    
    if ( me->query_condition("kill_yipin") 
        && ob->can_act() )
    {
                ob->set("force_factor",100);
        ob->kill_ob(me);   
        me->fight_ob( ob );// by lin.     
    }
}

int refuse_killing()
{
    int i;
    object *inv, who;

        who=this_player();
    who->apply_condition("kill_yipin", 150);
    inv = all_inventory( environment(this_object()) );
    for(i = 1; i < sizeof(inv); i++)
    {
        if ( !userp( inv[i] )
            &&  inv[i] != this_object() 
            && inv[i]->IsMemberOf("yipin")
            && inv[i] != who )
            {
                inv[i]->kill_ob(who);
                who->fight_ob( inv[i] );
            }
    }
    return 0;
}

int accept_fight( object who )
{
    message_vision("护卫弓身施礼，本堂严令，不得好勇斗狠，请原谅。\n",who);
    return 0;
}

