inherit BASE;

string player_name = "someone";
string query_race = "newt";

get ()
{
  return 0;
}

short ()
{
  return "A statue of "+capitalize(player_name);
}

long ()
{
  return "This statue is made of obsidian black stone, representing a "
   + query_race + " known as "+capitalize(player_name)+". It looks like it could "
   + "become alive again someday.\n";
}

set_player_name (string s)
{
  player_name = s;
  set_name (({player_name, "statue", query_race}));
}

query_player_name ()
{
  return player_name;
}

set_query_race (string s)
{
  query_race = s;
}
