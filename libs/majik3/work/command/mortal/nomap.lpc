main ()
{
    if (THIS->query("nomap")) {
	write ("Map mode.\n");
	THIS->set("nomap", 0);
    }
    else {
	write ("Nomap mode.\n");
	THIS->set("nomap", 1);
    }
    return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "Normally room descriptions show a map that helps to understand "
       + "room's obvious exits and general type like if the room is "
       + "outdoor area or not, but this can be disabled if wanted.";
}

query_see_also()
{
  return "brief(1)";
}

query_position ()
{
  return POS_RESTING;
}

