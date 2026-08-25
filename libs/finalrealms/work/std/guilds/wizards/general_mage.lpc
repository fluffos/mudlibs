inherit "/std/guilds/mage";

void setup()
{
    set_name("wizard");
    set_short("wizard");
    set_long("This is the General Wizards guild.  The General Wizards "
      "specialize in no particular school and therefore have full access "
      "to all schools.  Wizards are not allowed to wear any armour, except "
      "for things such as bracers, cloaks, boots, rings, and amulets.  "
      "A wizard, lacking proper training in weapons, may only use "
      "dagger, staff, and dart type weapons.\n");
    /** insert description of wizards above ***/
    reset_get();
}
int query_legal_armour(string atype)
{
    switch(atype)
    {
   case "padded":
    case "leather":
    case "cowl":
    case "robe":
    case "padded":
    case "basinet":
    case "shoes":
    case "slippers":
    case "boots":
    case "amulet":
    case "pendant":
    case "necklace":
    case "cape":
    case "cloak":
    case "belt":
    case "ring":
    case "bracers":
    case "studded leather":
    case "studded":
    case "gloves":
    case "belt":
	return 1;
    default: return 0;
    }
}
int query_legal_weapon(string type)
{
    switch(type)
    {
    case "dagger":
    case "staff":
    case "quarterstaff":
    case "twohanded_staff":
    case "whip":
    case "dart":
    case "dirk":
    case "knife":
    case "pick":
	return 1;
    default: return 0;
    }
}


int query_legal_race(string race)
{
    switch(race)
    {
    case "immortal":
    case "human":
    case "elf":
    case "gnome":
    case "half-elf":
	return 1;

    default:
	return 0;
    }
}

mixed query_legal_spheres()
{
    return ({
      ({"abjuration","neutral"}),
      ({"alteration","neutral"}),
      ({"illusion","minor"}),
      ({"lesserdivination","neutral"}),
      ({"greaterdivination","neutral"}),
      ({"necromancy","minor"}),
      ({"invocation","major"}),
      ({"conjuration","major"}),
      ({"enchantment","major"})
    });
}
