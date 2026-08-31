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
   set_brief("Yakitori operations room");
   set_long("Another dimly light office a big table with various papers and a mission "
            "board on wheels standing next to it. The table has various maps of the city and surrounding "
            "areas on it criss-crossed by symbols and lines.");
   set_exits((["north":"lead", ]));
   set_objects((["../mob/mission_ctrl":1, "^std/guild/item/storage_box":({"yakitori"})]));
   set_combat_forbidden(1);
}

int do_smell()
{
   write("A faint smell of garlic, fresh paint, soy and grilled chicken is in the air.\n");
   return 1;
}

int do_listen()
{
   write("Pretty quiet in here.\n");
   return 1;
}
