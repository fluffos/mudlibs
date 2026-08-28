// coder: namhas

#define PREV previous_object()

int main (string str)
{
  string *last;
  object *list;
  int j;

  if (!str)
    {
      notify_fail ("usage: shout <message>, \"shout last\" displays last shouts.\n");
      return 1;
    }

  if (str == "last")
    {
      last = PREV->query_last("shout");
      for(int i=0;i<sizeof(last);i++)
        message ("last", last[i] + "\n", PREV);
      return 1;
    }

  list = users();

  message ("inform", "You shout '^c1" + str + "^c0'\n", PREV);

  for(int i=0;i<sizeof(list);i++)
    {
      if (environment(list[i]))
        {
          if (environment(list[i])->query_area() == environment(PREV)->query_area())
            {
              if (environment(PREV)->query_area())
                {
                  message ("shout", capitalize(PREV->query_name()) + " shouts '^c1" +
                    str + "^c0'\n", list[i], PREV);
                  list[i]->add_last ("shout", capitalize(PREV->query_name()) +
                    " shouted '^c1" + str + "^c0'");
                  j++;
                }
            }              
        }
    }

  if (!j)
    {
      message ("shout", capitalize(PREV->query_name()) + " shouts '^c1" +
        str + "^c0'\n", all_inventory(environment(THIS)), PREV);
      all_inventory(environment(PREV))->add_last ("shout",capitalize(PREV->query_name()) +
        " shouted '^c1" + str + "^c0'");
    }

  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Shouts a <msg> that every player currently on the same area"
  + " that you are on can hear.";
}

query_synopsis()
{
  return "shout < msg | last >";
}

query_see_also()
{
  return "say(1), whisper(1), tell(1)";
}
query_position()
{
  return POS_STANDING;
}

