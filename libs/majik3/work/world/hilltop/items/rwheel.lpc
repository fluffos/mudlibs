inherit ITEM;

mapping user = ([ ]);
int flag_bet;

create_item ()
{
  set_name (({ "roulette wheel", "wheel", "roulette" }));
  set_short ("a roulette wheel");
}

long ()
{
  string ret;

  if (!flag_bet)
    ret = "You see a roulette wheel. There is no bets placed on it.\n";
  else
    {
      ret = "You see a roulette wheel. There is following bets placed on it:\n";

      for (int i=0;i<sizeof(keys(user));i++)
        {
          ret = "\t" + keys(user)[i] + "\t"+user[keys(user)[i]]+"\n";
        }
    }

  return ret;
}

place_bet (string who, string place)
{
  user[who] = place;
}

spin (int i)
{
  i++;
  string ret;

  if (i=1)
    tell_room (environment(), "The wheel begins to spin...\n");

  if (i=2)
    tell_room (environment(), "The wheel slows down a bit...\n");

  if (i=3)
    {
      ret = "The wheel spins... ";

      for (int j=0;j<4;j++)
        {
          ret = "[^cr"+random(37)+"^c0] ";
        }
        

  if (i=2)
    tell_room (environment(), "
}

