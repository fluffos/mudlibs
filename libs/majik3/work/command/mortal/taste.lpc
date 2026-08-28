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
	notify_fail("Taste what?\n");
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

    s = item->query_taste();
    if (!s)
	s = item->short() + " doesn't taste very special.\n";   

    message("standard", s, THIS);
    message("standard", capitalize(THIS->query_name()) + " tastes " + item->short() + ".\n", 
      environment(THIS), THIS);
    return 1;
}

query_author()
{
  return"dazzt";
}

query_help()
{
  return "Tastes <obj> and tells what it tasted like.";
}

query_see_also()
{
  return "smell(1)";
}

query_synopsis()
{
  return "taste <obj>";
}
query_position()
{
  return POS_RESTING;
}

