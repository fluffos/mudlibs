/****
*  *    Command                                 Taste
* *     Description                             Taste objects
**      Coder                                   Dazzt
*/


int main(string args)
{
    object item;
    string s;

    if (!args)
    {
	notify_fail("Smell what?\n");
	return 0;
    }

    if (!(item = present(args)))
    {
	notify_fail("No such item here.\n");
	return 0;
    }

    if (living(item))
    {
	notify_fail("I bet " + capitalize(item->query_name()) + " wouldn't like you doing that.\n");
	return 0;
    }

    s = item->query_smell();
    if (!s)
	s = item->short() + " doesn't smell very special.\n";   

    message("standard", s, THIS);
    message("standard", capitalize(THIS->query_name()) + " sniffs " + THIS->query_possessive() + 
      " " + item->short() + ".\n", environment(THIS), THIS);
    return 1;
}

query_author()
{
  return"dazzt";
}

query_help()
{
  return "You smell the <obj> and get to know what it smells like.";
}

query_synopsis()
{
  return "smell <obj>";
}

query_see_also()
{
  return "taste(1)";
}
query_position()
{
  return POS_RESTING;
}

