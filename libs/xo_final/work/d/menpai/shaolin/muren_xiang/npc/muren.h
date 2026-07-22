inherit NPC;

void win_bihua( object who )
{
    who->set_temp("finish_bihua", 1);
    who->set_temp("be_defeated", 1);
}

void lose_bihua( object who )
{
    who->set_temp("finish_bihua", 1);
    who->set_temp("be_defeated", 0);
}
