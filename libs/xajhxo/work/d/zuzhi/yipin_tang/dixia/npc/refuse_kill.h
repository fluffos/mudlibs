// by lnwm

int refuse_killing()
{
    int i;
    object *inv, who;

        who=this_player();
    who->apply_condition("kill_yipin", 100);
    inv = all_inventory( environment(this_object()) );
    for(i = 1; i < sizeof(inv); i++)
    {
        if ( !userp( inv[i] )
            &&  inv[i] != this_object() 
            && inv[i]->IsMemberOf("yipin")
            && inv[i] != who )
            inv[i]->kill_ob(who);
            who->fight_ob( inv[i] );
    }
    return 0;
}

