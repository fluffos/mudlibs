inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("Maintenance North Hallway");
   set_long(
       "Dampness clings to the air, leaving a musty scent that hints at neglected maintenance. "
       "The walls are lined with rusted, partially dislodged access panels, their labels faded and illegible. The "
       "occasional drip echoes through the corridor, a persistent reminder of the station's aging infrastructure.\n"
       "This hallway, seemingly forgotten, leads away in both directions into more disrepair and shadows. A rusty "
       "cabinet stands along the wall that seems constructed from durable materials.");
   set_exits((["south":"n_hall3", "north":"n_hall"]));
   set_objects((["^common/item/rusty_cabinet":1]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
   set_smell("It smells like someone left their wet laundry here for a very long time.");
   if (present("cabinet"))
      new ("/domains/std/junk/mop")->move(present("cabinet"));
   add_item("wall", "walls",
            (["look":"Once a gleaming testament to engineering, are now coated in layers of thick, greasy grime."]));
}

string *query_hint(int level)
{
   if (level < 4 && present("cabinet") && present("mop", present("cabinet")))
      return ({"If you pay attention to descriptions, sometimes you can find hidden items."});
}
