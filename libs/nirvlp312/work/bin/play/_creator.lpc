string
determine_creator(object what)
{
    string c;

    if(!(c = creator(what)))
      return "it has always existed.\n";
    else
      return capitalize(c) + " created it.\n";
}

status
cmd_creator(string arg)
{
    object c;

    if(!arg)
    {
      c = environment(this_player());
      write("You glance around the room...\n");
      write("You know that " + determine_creator(c));
      return 1;
    }

    else
    {
      c = present(arg, this_player());
      if(!c || !c->short())
        c = present(arg, environment(this_player()));
      if(!c || !c->short() || c->query_invis())
      {
        write("You don't have that object.\n");
        return 1;
      }
      write("You discover that " + determine_creator(c));
      return 1;
    }
}
