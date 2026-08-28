inherit ITEM;

int good, neutral, evil;
string poks;

create_item ()
{
  set_name ("pendulum");
  set_short ("a pendulum of time");
  set_material ("bloodstone");
}

long ()
{
  for (int i=0;i<sizeof(users());i++)
    {
      if (users()[i]->query_alignx() < -500)
        evil++;
      else if (users()[i]->query_alignx() > 500)
        good++;
      else
        neutral++;
    }

  if (evil > good && evil > neutral)
    poks = "darkness";
  else if (good > evil && good > neutral)
    poks = "light";
  else
    poks = "neutrality";

  return
 "It is a beautiful pendulum of time made of marble blocks. The pendulum "
+"points towards "+poks+".\n";
}
