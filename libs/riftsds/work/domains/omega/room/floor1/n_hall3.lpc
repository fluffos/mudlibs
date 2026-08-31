inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("Maintenance North Hallway near elevator");
   set_long(
       "The maintenance floor hallway stretches out before you, a stark contrast to the rest of the space station. "
       "It's a grimy, neglected passage, its walls and floors bearing the marks of countless repairs and hurried "
       "footsteps. The once gleaming metal surfaces now carry the wear and tear of years, covered in streaks of grime "
       "and scuffed paint. The lighting is dim and sporadic, casting long, eerie shadows that seem to swallow the "
       "edges of your vision.");
   add_item("wall", "walls", "surfaces",
            (["look":"Once a gleaming testament to engineering, are now coated in layers of thick, greasy grime."]));

   set_exits((["south":"waiting_room1", "north":"n_hall2"]));
   // set_objects(([""]));
   set_listen("You hear the background noise of air treatment systems and computer systems running behind the walls.");
}
