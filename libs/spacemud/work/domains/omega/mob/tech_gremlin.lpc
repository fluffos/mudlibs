/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADVERSARY;
inherit M_WANDER;
inherit M_SMARTMOVE;
inherit M_ACTIONS;
inherit M_AGGRESSIVE;

void setup()
{
   object carapace = new ("/domains/omega/mob/tech_gremlin_carapace");
   string *lookslike = ({"toaster", "drone", "toaster oven", "blender", "toy car", "computer monitor", "fridge"});
   int size = 1 + random(3);
   string size_str, looks = choice(lookslike);
   ::mudlib_setup();

   if (looks == "fridge")
      size += 2;

   switch (size)
   {
   case 1:
      size_str = "small";
      break;
   case 2:
      size_str = "adult";
      break;
   case 3..10:
      size_str = "large";
      break;
   }
   set_name(looks + " tech gremlin");
   set_id("tech gremlin", "gremlin", looks);
   set_combat_messages("combat-claws-bites");
   add_adj(size_str);
   set_gender(0);
   set_wander_time(20);
   set_wander_area("maintmaze");
   set_aggressive(95);
   set_in_room_desc(capitalize(add_article(size_str + " " + looks + " tech gremlin")));
   set_long("A " + size_str + " droid with 6 metallic legs, about the size of a terrestrial cat - this one is " +
            size_str + " for the species. It looks like a" + looks + ".");
   update_body_style("insect");
   set_level(size);

   // Handle shell
   carapace->move(this_object());
   carapace->do_wear();
}
