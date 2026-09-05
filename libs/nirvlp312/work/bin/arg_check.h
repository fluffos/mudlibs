/* A standard way of checking in emotes if a player is there,
     invis, or whatever.

   7.9.01 [V]
*/
object
arg_check(string arg)
{
    object ob;

    if((ob = present(arg, environment(this_player()))) &&
       ob != this_player() && living(ob))
      return ob;
#ifndef __LDMUD__ /* Rumplemintz */
    if(!(ob=find_player(arg,1)) || (int)ob->query_invis() > (int)this_player()->query_level())
#else
  if (!(ob = find_player(arg)) ||
      (int)ob->query_invis() > (int)this_player()->query_level())
#endif
    {
      notify_fail("You don't see " + arg + " anywhere.\n");
      return 0;
    }

    if(in_editor(ob)) return (notify_fail((string)ob->query_name() +
      " is EDITING.\nTry again later :)\n"), 0);
    if(!environment(ob) || !interactive(ob))
    {
      notify_fail("That player is disconnected.\n");
      return 0;
    }

    if(ob == this_player())
      return 0;

    if((int)ob->query_tellblock() && (int)this_player()->query_level() < 21)
    {
      notify_fail((string)ob->query_name() + " is blocking emotes.\n");
      return 0;
    }

    return ob;
}
