inherit "/obj/armor";

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    set_name("ice shield");
    set_short("An ice shield");
    set_type("shield");
    set_weight(3);
    set_long("\
A frosty blue shield emblazoned with a pure white cross\n\
upon it.  On the upper left corner twinkles a magical\n\
snowflake.  It is heavy and cold, the metal freezes your\n\
hand as you touch it.\n");
    set_ac(1); /* physical ac */
    set_params("other|ice", 1, 10, "do_ice_special");
    /* 1 ac, 10% resistance to other|ice damage,
       plus it calls the 'do_ice_special()' function */
}

int
do_ice_special(object owner)
{
    if(!random(8))
    {
      tell_object(owner, "\
Your shield flashes and absorbs some of the ice damage.\n");
      return 0502;
    /* 
       5% [05] resistance boost
       2  [02] ac boost 
    */
    }
}
