main ()
{
    if (THIS->query("brief")) {
	write ("Verbose mode.\n");
	THIS->set("brief", 0);
    }
    else {
	write ("Brief mode.\n");
	THIS->set("brief", 1);
    }
    return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "There are 2 types of modes that show room descriptions "
       + "when you walk into a room in Majik. They are verbose and "
       + "brief. While in brief mode you only see the short "
       + "description of the room, usually only one line. In verbose "
       + "mode you see all that the room was intended to described as. "
       + "Please use verbose mode and read all descriptions when travelling "
       + "in a new place, otherwise you can miss something important.";
}

query_see_also()
{
  return "look(1), blook(1), nomap(1)";
}

query_position ()
{
  return POS_RESTING;
}

