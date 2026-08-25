inherit "std/guilds/cleric";

void setup()
{
 set_name("Lolth");
 set_short("priest of Lolth");
 set_long(
"This is the temple of the Drow Godess Lolth.\n");
 reset_get();
}

int query_legal_weapons(string type)
  {
  switch (type)
    {
    case "mace" :
    case "club" :
      return 1;
    default : 
      return 0;
    }
  }

int query_legal_race(string race)
  {
  switch (race)
    {
    case "drow" :
      return 1;
    default :
      return 0;
    }
  }

mixed query_legal_spheres()
  {
  /* the spheres : */
  return ({"healing", "all", "clericdivination", "necromantic", 
       "protection", "summoning", "guardian", "sun", "weather"});
  }
