inherit "/std/guilds/cleric";

void setup()
{
  set_name("tempus");
  set_short("priest of Tempus");
  set_long("The Priests of Tempus are considered to be very warlike and "
          "chaotic.  What these priests lack of spells they gain back from "
          "being better fighters than most clerics.  Priests of Tempus can "
          "wear all kinds of armor and wield any meelee weapons.\n");
  reset_get();
  add_command("judge", 1);
  add_command("fix", 1);
  add_main_skill("wis");
  add_main_skill("wis.spells");
  add_main_skill("str");
}

int query_legal_race(string race)
{
  switch(race)
  {
    case "elf": 
    case "halfling": 
    case "gnome":
    case "goblin":
    case "drow": 
      return 0;
    default : return 1;
  }
}

int query_legal_weapon(string type) 
{ 
  switch(type)
  {
    case "bow":
    case "sling":
    case "crossbow":
         return 0;
    default: return 1;
  }
}

mixed query_legal_spheres()
  {
  return ({"healing", "elemental", "animal", "combat", "clericdivination", "necromantic", "protection", "weather", "all", "guardian", "sun", "summoning"});

  }
