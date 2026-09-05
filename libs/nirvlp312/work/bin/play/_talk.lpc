int
cmd_talk(string arg)
{
    string who, what, x;
    object ob, t;

    if(!arg || ( (sscanf(arg, "to %s %s", who, what) < 2) &&
                 (sscanf(arg, "%s %s", who, what) < 2) ))
      return (notify_fail("Usage: \"talk <who> <what>\"\n"), 0);

    if(!(ob=find_living(who)) || !present(ob, environment(t=this_player())))
      return (notify_fail("You don't see " + (who) + " here.\n"), 0);

    who=capitalize(who);

   who = (string)ob->query_name();
    write("You say to " + who + ": " + what + "\n");
    say((x=(string)t->query_name()) + " says to " + who + ": " + what + "\n", ob);
    tell_object(ob, x + " says to you: " + what + "\n");

    return 1;
}
