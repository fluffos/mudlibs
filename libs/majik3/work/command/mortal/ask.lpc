/*
 * ask.c       ask questions from monster
 * 
 * */


int main(string args)
{
	string who, what, answer;
	object ob;
	
	if (args == "")
	{
		notify_fail("Ask who about what?\n");
		return 0;
	}

	if (sscanf(args, "%s about %s", who, what) != 2)
	{
		notify_fail("Ask who about what?\n");
		return 0;
	}
	
	ob = present(who, ENV(THIS));
	
	if (!ob)
	{
		notify_fail("Ask whom?\n");
		return 0;
	}
	
	if (!living(ob))
	{
		notify_fail(ob->query_cap_name() + " doesn't have much to say.\n");
		return 0;
	}
	
	message("0", THIS->query_cap_name() + " asks something from " + ob->query_cap_name() + ".\n", ENV(THIS), THIS);
	answer = ob->query_answer(what);
	if (!answer)
		message("0", ob->query_cap_name() + " remains silent.\n", THIS);
	else
		ob->force_us("say " + answer);
	return 1;
}

query_author()
{
  return "dazzt";
}

query_synopsis()
{
  return "ask <who> about <what>";
}

query_help ()
{
  return "Using this command you can ask NPC <who> about <what>.";
}

query_example ()
{
  return "ask guard about orcs";
}

query_position ()
{
  return POS_SITTING;
}
