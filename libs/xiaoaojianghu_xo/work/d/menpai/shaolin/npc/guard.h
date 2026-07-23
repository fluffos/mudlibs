int refuse_killing(object who)
{
    int i;
    object ob;

    for(i=2;i<4;i++)
    {
        if(objectp(ob=present("monk guard " + i,environment())))
            ob->kill_ob(this_player());
    }
    return 0;
}

