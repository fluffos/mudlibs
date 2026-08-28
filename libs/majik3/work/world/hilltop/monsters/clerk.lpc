inherit MONSTER;

string *poks;
string answers;
int i;
int meep;

create_monster ()
{
  set_name (({ "a clerk", "clerk", "thari", "human" }));
  set_short ("a registration clerk is searching for unregistered citizens");
  set_long ("He is a registration clerk. Maybe you should \"answer\" his questions.\n");
  set_race ("thari");
  set_talk (({
    "If you haven't answered to my questions, please answer now!",
    "I wonder how many unregistered citizens we still have.."
  }));

  set_gender (1);
  set_wander(1, 300);
}

init_monster ()
{
  add_action ("do_answer", "answer");
}

do_answer ()
{
  string poks2;
  tell_room (environment(), THIS->query_cap_name() + " begins answering Clerk's questions.\n", ({ THIS }));
  poks = 0;
  i = 0;
  answers = "";
  poks = explode(read_file("/data/purity/registration"), "\n");
  poks2 = explode(read_file("/data/purity/answers"), "\n");
  for (int j=0;j<sizeof(poks2);j++) {
    if (strsrch(poks2[j], THIS->query_name() + ":") != -1)
      {
        write ("Sorry you have already answered.\n");
        return 1;
      }
  }
  answers += "\n" + THIS->query_name() + ":\n"+repeat_string("-", strlen(THIS->query_name()))+"\n";
  do_do ();
  return 1;
}

do_do (string str)
{
  if (i < sizeof(poks))
    {
      write (poks[i]);
      input_to ("do_input");
      return 1;
    }
  if (meep/10 > 1)
  {
  write ("Clerk gives you some gold coins, thanks you.\n");
  tell_room (environment(), "Clerk gives some money to "+THIS->query_cap_name()+".\n", ({ THIS }));
  THIS->add_money (meep/10);
  }
  write_file ("/data/purity/answers", answers);
  return 1;
}

do_input (string str)
{
  answers += "#" + i + " " + str + "\n";
  i++;
  meep += strlen(str);
  do_do();
  return 1;
}
