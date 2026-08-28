/*
 * blook.c - brief look, used instead 'look' when brief is enabled 
 * 
 * coded by dazzt
 * */

#undef THIS
#define THIS previous_object()

main()
{
	int sc;
	
	sc = THIS->query_sight_clarity(ENV(THIS)->query_light_level());

	if (sc == -1)
	{
		message("standard", "It is too dark here for you to see.\n", THIS);
		return 1;
	}
	if (sc == 2)
	{
		message("standard", "It is too bright here for you to see.\n", THIS);
		return 1;
	}
	
	if (environment(THIS))
		message("roomshort", environment(THIS)->short() + "\n", THIS);

	"/command/mortal/look"->list_inventory(THIS);
	
	return 1;
}

query_author()
{
  return "dazzt";
}

query_help()
{
  return "Command to look at the brief description of the room you "
       + "are standing in.";
}

query_see_also()
{
  return "look(1), brief(1)";
}

query_position ()
{
  return POS_RESTING;
}

