/* Do not remove the headers from this file! see /USAGE for more info. */

inherit INDOOR_ROOM;

void combat_forbidden()
{
   all_inventory(this_object())->stop_fight();
   if (present(this_body(), this_object()))
   {
      this_body()->simple_action("A tall skinny man in a suit appears from behind a curtain and tells $n to leave.");
      this_body()->move(load_object("/domains/abacus/room/adam_str03"));
      this_body()->simple_action("$N $venter into the street again.");
   }
}

void setup()
{
   set_brief("The Yakitori Kitchen");
   set_long("A white-tiled fairly clean and very orderly kitchen. Stainless steel tabletops "
            "everywhere and various cooking utencils are in use.");
   set_exits((["east":"^std/guild/yakitori/room/shop", "west":"^std/guild/yakitori/room/lead", ]));
   set_objects((["^std/guild/yakitori/mob/chef":1, "^std/furniture/cooking_station":1]));
   set_combat_forbidden(1);
}

int do_smell()
{
   write("A strong smell of garlic, soy and grilled chicken permeates the air.\n");
   return 1;
}

int do_listen()
{
   write("You hear oil sizzling from the friers.\n");
   return 1;
}
