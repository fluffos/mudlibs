inherit "std/guilds/cleric";

void setup()
{
 set_name("tymora");
 set_short("priest of Tymora");
 set_long(
"This is the shrine of Tymora, where the goddess of chance is worshipped. "
"This temple also work as a clerics' guild. The guild gives you " 
"skills that relate to healing and turning the undead minions.  " 
"You will also get a certain amount of help in defending yourself " 
"in combat as priests are a bunch very susceptible to pain.\n"
"They also get at high levels the abilty to give people extra lives "
"and at much lower levels refresh the character anew.\n");
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
  switch(race)
    { 
    case "drow":
      return 0;
    default:
      return 1;
    }
  }

mixed query_legal_spheres()
  {
  /* the spheres : */
  return ({"healing", "all", "clericdivination", "necromantic", 
       "protection", "summoning", "guardian", "sun", "weather"});
  }
