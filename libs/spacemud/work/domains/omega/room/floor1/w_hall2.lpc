inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "maintenance");
   // set_weather(1);
   set_light(1);
   set_brief("Maintenance West Hallway at the barricade");
   set_long(
       "The western maintenance hallway ends at a small barricade here. The normally sterile and orderly passage now "
       "resembles a chaotic playground for creatures trying to tear the station apart. The lighting is dim and "
       "sporadic, casting long, eerie shadows that seem to swallow the "
       "edges of your vision.\nAn improvised barricade blocks the path east.");
   add_item("wall", "walls", "surfaces",
            (["look":"Once a gleaming testament to engineering, are now coated in layers of thick, greasy grime."]));
   set_exits((["west":"maint8"]));
   set_objects((["^common/item/barricade":({"barricade", "up", "w_hall3", 20})]));
   set_listen("You hear the background noise of air treatment systems and computer systems running behind the walls.");
}

string query_hint(int level)
{
   if (level < 3)
      return "Great commands to know here are 'hp', 'quests', 'equip' and 'score' to monitor your basic statistics.";
}