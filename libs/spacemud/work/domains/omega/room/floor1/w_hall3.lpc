inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "maintenance");
   // set_weather(1);
   set_light(1);
   set_brief("Maintenance West Hallway near elevator");
   set_long(
       "The western maintenance hallway ends at a small barricade here. The normally sterile and orderly passage now "
       "resembles a chaotic playground for creatures trying to tear the station apart. The lighting is dim and "
       "sporadic, casting long, eerie shadows that seem to swallow the "
       "edges of your vision.");
   add_item("wall", "walls", "surfaces",
            (["look":"Once a gleaming testament to engineering, are now coated in layers of thick, greasy grime."]));

   set_exits((["east":"waiting_room"]));
   set_objects(
       (["^omega/npc/floor1/rigel_fluxx":1,
                 "^common/item/barricade":({"barricade", "up", "w_hall2", 50}), "^omega/item/control_terminal":1]));
   set_listen("You hear the background noise of air treatment systems and computer systems running behind the walls.");
}
