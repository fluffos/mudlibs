/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADVERSARY;
inherit M_AGGRESSIVE;
inherit M_WANDER;
inherit M_SMARTMOVE;
inherit M_ACTIONS;

void setup()
{
   int size = 1 + random(3);
   string size_str;
   ::mudlib_setup();
   switch (size)
   {
   case 1:
      size_str = "small";
      break;
   case 2:
      size_str = "adult";
      break;
   case 3:
      size_str = "large";
      break;
   }
   set_name("space roach");
   set_id("roach", "space roach");
   set_combat_messages("combat-claws-bites");
   add_adj(size_str);
   set_gender(0);
   set_wander_area("duct");
   set_wander_time(20);
   set_in_room_desc(capitalize(add_article(size_str + " space roach")));
   set_long("A space roach is an insectoid creature, about the size of a terrestrial cockroach - this one is " +
            size_str +
            " for the species. Its exoskeleton "
            "is a dark shade of gray or brown, providing camouflage against the metallic surfaces it inhabits. The "
            "exoskeleton is tough and resilient, allowing the space roach to withstand the rigors of space travel and "
            "the harsh conditions found in low-gravity environments.");
   update_body_style("insect");
   set_level(size);
   set_max_health((5 * size));
   set_aggressive(50);
   set_damage_bonus((2 + size));
   set_skill("combat/defense/dodge", 200 * size);
}

int karma_impact()
{
   return 1;
}