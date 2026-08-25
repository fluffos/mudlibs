inherit "/obj/monster";



void setup()
{
   set_name("beetle");
   add_alias("beetle");
   add_adjective("stag");
   add_adjective("large");
   set_short("a large stag beetle");
   set_main_plural("stag beetles");
   set_race("beetle");
   set_level(random(5)+4);
   set_wimpy(0);
   set_long("This is a large stag beetle.\n");
   load_chat(10,
       ({
             1, ":crawls away from you.\n",
             1, ":lowers its horn and crawls fast towards you.\n",
             1, ":moves a boulder twice its size.\n",
        }));
   add_triggered_action("bing2", "event_death", this_object(), "death");
   set_random_stats(6,17);
   set_gender(random(2)+1);


}
