inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("North Hallway");
   set_long("The maintenance floor hallway stretches out before you, a grimy, forsaken passage that seems to have "
            "escaped the cleansing touch of maintenance crews for far too long. The walls, once a gleaming testament "
            "to engineering, are now coated in layers of thick, greasy grime, their original color a distant memory. "
            "Streaks of unknown substances mar the access panels creating a disconcerting mosaic of neglect. The floor "
            "beneath your boots is sticky and uneven, the remnants of spilled lubricants and forgotten repairs. The "
            "lighting flickers intermittently, casting a sickly, jaundiced hue on the surroundings, revealing every "
            "splotch and stain in grotesque detail.\nThe hallway ends with a metal door.");
   set_exits((["south":"n_hall2"]));
   set_objects((["^common/item/door":({"north", "^omega/room/floor1/wakeup_room"})]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
   set_smell("The air is heavy with a musty, damp odor, a testament to the pervasive moisture that seems to have "
             "seeped into every crevice.");
   add_item("access panels", "panels",
            (["look":"Rusted, corroded access panels jut out from the walls at odd angles, their hinges groaning in "
                     "protest when nudged. ",
                "open":"The panels do not seem to open.", ]));
   add_item("splotch", "stain", "lubcricants", "neglect", "remnants", "grime",
            (["look":"All very nasty stuff, don't get near it."]));
   add_item("wall", "walls",
            (["look":"Once a gleaming testament to engineering, are now coated in layers of thick, greasy grime."]));
}
