inherit "std/guilds/cleric";

string query_title(object player)
{
 int lvl,male;

 lvl = query_level(player);
 male = (int)player->query_gender() != 2;

 if(lvl > 20) return (male) ? "the Morninglord": "the Morninglady";
 return (male) ? "the Dawn Priest": "The Dawn Priestess";
}

void setup()
{
 set_name("lathander");
 set_short("priest of Lathander");
 set_long("The morning-priests of Lathander worship rebirth, renewal, "
          "the dawn and youth.  These priests are in most respects "
          "similar to normal priests, but gain a couple of special spells, "
          "and are restricted to use either plated metal armor or no armor "
          "at all.\n");
 reset_get();
}

int query_legal_race(string race)
  {
    return 1;
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

mixed query_legal_spheres()
  {
  return ({"all", "astral", "elemental", "healing", "plant", "sun","weather", 
	"combat", "clericdivination", "guardian"}); 
  }
