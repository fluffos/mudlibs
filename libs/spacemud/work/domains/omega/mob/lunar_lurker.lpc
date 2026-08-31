/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADVERSARY;
inherit M_WANDER;
inherit M_SMARTMOVE;
inherit M_ACTIONS;
inherit M_AGGRESSIVE;

void setup()
{
   object carapace = new ("/domains/omega/mob/lunar_lurker_fluff");
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
   set_name("lunar lurker");
   set_id("lunar lurker", "lurker");
   set_combat_messages("combat-claws-bites");
   add_adj(size_str);
   set_gender(0);
   set_wander_time(10);
   set_wander_area("maintmaze");
   set_aggressive(50);
   set_in_room_desc(capitalize(add_article(size_str + " lunar lurker")));
   set_long("A small glowing ball of fuzz, that somehow has grown legs and runs around like a small flashing light "
            "bulb - this one is " + size_str + " for the species.");
   update_body_style("insect");
   set_level(size);
   set_max_health((2 * size));
   set_skill("combat/defense/dodge", 100 * size);

   // Handle shell
   carapace->move(this_object());
   carapace->do_wear();
}
