//  By lala on 1997 6 28 

// Room: /d/shaolin/killroom.h

void init()
{
    object me, *inv, obj, env;
    int i;
    me = this_player();
    env = environment(me);
    inv = all_inventory(env);   

    if (me->query("class") != "bonze1" && me->query("id") !="saodi heshang")
        {
            for ( i = 1; i < sizeof(inv); i++ )
            {
                if ( inv[i]->is_character() 
                && inv[i]->query("class") == "bonze1" 
                && inv[i]->can_act() )
                        inv[i]->kill_ob(me);
            }
        }
}



