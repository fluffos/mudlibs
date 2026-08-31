inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   set_brief("Landing Terminal North intersection");
   set_long(
       "Bathed in a soft, artificial light that reflects off its sterile, metallic surfaces, the hallway "
       "branches west, east and south in clean lines. The walls, adorned with occasional access panels, bear subtle "
       "signs of wear and tear, evidence of the bustling activity that characterizes life on the station.\nAccording "
       "to the signs, \"Stellar Lane\" leads south from here to the Central Elevator, docking bays NW1-6 west of here, "
       "and docking bays NE1-6 east of here.");
   add_item("floor", "The floor, a smooth, low-gravity surface, allows for effortless movement. ");
   add_item("sign", "signs", "Nice signs, they point to different places. They're clever like that.");
   set_exits((["east":"n_landing", "west":"n_landing2", "south":"n_hall"]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}
