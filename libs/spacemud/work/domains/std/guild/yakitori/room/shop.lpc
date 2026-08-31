/* Do not remove the headers from this file! see /USAGE for more info. */

inherit INDOOR_ROOM;

void combat_forbidden()
{
   all_inventory(this_object())->stop_fight();
   if (present(this_body(), this_object()))
   {
      this_body()->simple_action("A tall skinny man in a suit appears from behind a curtain and tells $n to leave.");
      this_body()->move(load_object("/domains/std/room/Wizroom"));
      this_body()->simple_action("$N $venter into the street again.");
   }
}

void setup()
{
   set_brief("Yakitori Chicken");
   set_long("A small city store has been converted to an eatery serving chicken "
            "skewers in spicy sauces. The smell in here is fantastic! The walls "
            "are painted white, and menus with prices along with painted "
            "images of the spits can be seen on the walls. The place is squeaky "
            "clean and well-kept.");
   set_exits((["east":"^std/room/Wizroom", "west":"^std/guild/yakitori/room/kitchen"]));
   set_objects((["^std/guild/yakitori/mob/cashier":1]));
   set_combat_forbidden(1);
}

int do_smell()
{
   write("A smell of garlic, soy and grilled chicken permeates the air.\n");
   return 1;
}

int do_listen()
{
   write("You hear oil sizzling in a back room, somewhere out of sight and the chopping "
         "of vegetables on cutting boards.\n");
   return 1;
}
