/*
 * 'quests' command, shows solved quests
 * 
 * (c) 1998 Dazzt
 * 
 * */


int main()
{
	string *quests, str;
	int i, n;
	
	quests = THIS->query_all_quests();
	
	if (sizeof(quests) == 0)
	{
		notify_fail("You haven't completed any quests.\n");
		return 0;
	}
	
	
	str = "";
	for (i = 0; i < sizeof(quests); i++)
	{
		if (THIS->is_quest_finished(quests[i]))
		{
			str += capitalize(quests[i]) + ", ";
			n++;
		}
	}
	
	if (n == 0)
	{
		notify_fail("You haven't completed any quests.\n");
		return 0;
	}
	
	str = "You have completed " + n + " quests:\n" + str[0..<3] + ".\n";

	message("0", str, THIS);
	
	return 1;
}

query_author()
{
  return "dazzt";
}

query_help()
{
  return "Tells you how may quests you have accomplished";
}

query_see_also()
{
  return"money(1)";
}

query_position ()
{
  return POS_RESTING;
}

