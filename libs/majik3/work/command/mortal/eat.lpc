int
main (string str)
{
  int i;
  object o;
  mapping material;

  if (!str)
    {
      notify_fail ("Eat what?\n");
      return 0;
    }

  o = present (str);

  if (!o)
    {
      write ("There is no "+str+" nearby.\n");
      return 1;
    }

  material = o->query_material();

  if (mapp(material))
    {
      if (member_array ("food", keys(material)) == -1)
        {
          write ("You can't eat "+o->query_maybe_cap_name()+"!\n");
          return 1;
        }
    }
  else
    {
      write ("You can't eat "+o->query_maybe_cap_name()+"!\n");
      return 1;
    }

  if (o->query_hollow())
    {
      i = (o->query_dimensions()[0] * o->query_dimensions()[1] *
           o->query_dimensions()[2])* o->query_hollow() / 100;
    }

  THIS->satiate_me ((o->query_dimensions()[0] *
                     o->query_dimensions()[1] *
                     o->query_dimensions()[2])-i);

  emote ("$n {eat} "+o->query_maybe_cap_name()+".", THIS, 0, ENV(THIS));
  destruct (o);

  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "Using this command you can eat when you get hungry.";
}

query_synopsis ()
{
  return "eat <item>";
}
