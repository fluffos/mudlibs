/*
 * Quickie plan command by Dazzt
 * */

inherit "/obj/editor";

plan_noti()
{
	message("0", "Plan set.\n", THIS);
}

main(string str)
{
	if (!str)
	{
		notify_fail("usage:  plan <set/clear>\n");
		return 0;
	}
	
	if (str == "set")
		read_text("plan", "plan_noti", THIS);
	if (str == "clear")
	{
		THIS->set("plan", "");
		message("0", "Plan cleared.\n", THIS);
	}
	THIS->save_me();
	
    return 1;
}

query_author()
{
  return "dazzt";
}

query_help()
{
  return "Plan is a few rows of text ,after general information on your"
  + " character, what people see when they finger you. With this command"
  + " you enter a simple editor where you can type in your plan.";
}
query_synopsis()
{
  return "peer <set | clear>";
}

query_see_also()
{
  return "finger(1)";
}

query_position ()
{
  return POS_RESTING;
}

