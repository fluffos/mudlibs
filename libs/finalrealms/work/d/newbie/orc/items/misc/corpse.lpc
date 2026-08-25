inherit"std/object";


void setup()
{
    set_name("corpse");
    add_alias("skeleton");
    set_main_plural("corpses");
    set_short("Skeleton");
    set_long("   This is the skeletal remains of a dwarf that must "
      "have become trapped down here and died long ago.  "
      "A closer look reveals the reason for the entrapment, the "
      "skeleton has a broken leg.  The poor guy must have climbed "
      "the rope and fallen to the floor below.  The bones are "
      "clothed in tatters that once must have been quite a "
      "beautiful robe.  The hands are clentching something "
      "that looks unusual.  "
      "\n\n");
    set_value(0);
}
void init()
{
    add_action("look_me","look");
    add_action("get_me","get");
    ::init();
}
int look_me(string str)
{
    if(str == "hand")
    {
	write("The hand is holding a beautiful gemstone.  You might "
	  "want to get it.\n");
	return 1;
    }
    return 0;
}
