_set_light_level(lev)
{
    set_light(lev);
}

_light_level()
{
    int lev;
    object env,dark;

    env=environment();
    if(env)
    {
        dark="obj/dark"->me();
        move_object(this_object(),dark);
        lev = set_light(0);
        move_object(this_object(),env);
        return lev;
    }
    else return (set_light(0));
}
