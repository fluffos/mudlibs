int
main (string str)
{
  object o;

  if (str)
    {
      o = present (str);

      if (!o)
        {
          write ("You don't see "+capitalize(str) + " here.\n");
          return 1;
        }
      else
        {
          if (o->query_position() > POS_SLEEPING)
            {
              write (o->query_cap_name()+" is already awake.\n");
              return 1;
            }
          else if (o->query_position() < POS_SLEEPING)
            {
              write (o->query_cap_name()+" is in pretty bad shape!\n");
              return 1;
            }
          else
            {
              write ("You wake "+o->query_cap_name()+" up.\n");
              tell_object (o, "You are awakened by "+
                THIS->query_cap_name() + ".\n");
              o->set_position (POS_SITTING);
              return 1;
            }
        }
    }
  else
    {
      if (THIS->query_position() > POS_SLEEPING)
        {
          write ("You are already awake.\n");
          return 1;
        }
      else
        {
          write ("You awaken and sit up.\n");
          act (THIS, "$n awakens.");
          THIS->set_position (POS_SITTING);
        }
    }

  return 1;
}


query_author()
{
  return "namhas";
}

query_help()
{
  return "Using this command you can wake up and start sitting or "
  + " if specified with argument then you can wake other people up.";
}

query_synopsis ()
{
  return "wake [player]";
}

query_see_also()
{
  return "sit(1), stand(1), rest(1), sleep(1)";
}

query_position()
{
  return POS_SLEEPING;
}
