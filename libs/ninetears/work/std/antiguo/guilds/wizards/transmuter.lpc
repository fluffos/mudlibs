inherit "/std/guilds/mage";

void setup()
{
  set_name("transmuter");
  set_short("transmuter");
  set_long(" \n");
 /** insert description of specialist above ***/
  reset_get();
}

int query_legal_race(string race)
{
	switch(race)
	{
	 case "human":
	 case "half-elf":
	  return 1;

	 default:
	  return 0;
	}
}

mixed query_legal_spheres()
{
   return ({"alteration","illusion","lesserdivination",
       "greaterdivination","invocation","conjuration","enchantment"});
}
