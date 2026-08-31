/* Do not remove the headers from this file! see /USAGE for more info. */

inherit INDOOR_ROOM;

void combat_forbidden()
{
   all_inventory(this_object())->stop_fight();
   if (present(this_body(), this_object()))
   {
      this_body()->simple_action("Mr Nakamura tells $n to leave.");
      this_body()->move(load_object("/domains/abacus/room/adam_str03"));
      this_body()->simple_action("$N $venter into the street again.");
   }
}

void setup()
{
   set_brief("Yakitori back room");
   set_long("A dimly light office with a single lit lamp standing on the desk. " +
            "An open ledger lies on the desk. "
            "The office has several cabinets near the walls with a \"Favour Board\""
            " hanging above them, and stacks of Yakitori "
            "delivery boxes and bags. A small window high up on the wall faces the back alley.");
   set_exits((["east":"kitchen", "south":"mission", ]));
   set_objects((["../mob/guild_lead":1,
       "^std/guild/item/favour_board":({"yakitori"}), "^std/guild/item/ledger":({"yakitori"})]));
   add_item("electric fan", "fan", "It's a very nice fan, keeps the smell of oils almost out of this room.");
   add_item("window", "small window", "It's a small window with iron bars infrot of it. It's open slightly.");
   add_item("walls", "wall", "White walls, seems painted recently?");
   add_item("cabinets", "Filing cabinets, probably holding papers.");
   add_item("lit lamp", "lamp", "It's a desk lamp.");
   add_item("office", "You're standing in it.");
   add_item("paint", "The walls are recently painted white, but you notice a darker spot on the north wall attempted "
                     "to be covered up.");
   add_item("spot", "Could look like someone got the back of the head painted unto the wall and then painted over?");
   set_combat_forbidden(1);
}

int do_smell()
{
   write("A smell of garlic, fresh paint, soy and grilled chicken permeates the air.\n");
   return 1;
}

int do_listen()
{
   write("You hear oil sizzling from the kitchen, and a hum of an electric fan running in the corner of this room.\n");
   return 1;
}
