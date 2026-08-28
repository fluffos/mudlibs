/****
*  *    Command                                 Listen
* *     Description                             listen to objects
**      Coder                                   Dazzt
*/


int main(string args)
{
    object item;
    string s;

    if (!args)
    {
	notify_fail("Listen to what?\n");
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

    s = item->query_listen();
    if (!s)
	s = "You hear nothing special from " + item->short() + ".\n";   

    message("standard", s, THIS);
    message("standard", capitalize(THIS->query_name()) + " listens carefully to " + item->short() + ".\n",
      environment(THIS), THIS);
    return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "You can hear voices using this command. Attempt to listen to " +
         "target. If the target has something valuable to say or for you " +
         "to listen you will hear it. Not every living thing in the mud "
       + "can be listened. But many can, its up to you to find which "
       + "ones you can and can not listen to.";

}

query_synopsis ()
{
  return "listen <item>";
}

query_example ()
{
  return "listen sword";
}

query_see_also ()
{
  return "smell(1), taste(1)";
}

query_position ()
{
  return POS_RESTING;
}

