inherit OUTDOOR_ROOM;

void setup()
{
   set_brief("Murky Swamp");
   set_long("You find yourself in a murky, dank swamp. The air is thick with humidity "
            "and the smell of decaying vegetation. Twisted trees rise from the muddy "
            "water, their gnarled branches reaching towards the dim sky. Patches of "
            "sickly green algae float on the surface of the stagnant pools. "
            "The occasional croak of a frog or buzz of an insect breaks the eerie "
            "silence.");
   set_listen("You hear the occasional croak of frogs and the buzzing of insects.");
   set_smell("The air is thick with the smell of decay and stagnant water.");
   add_item("trees", "The trees are twisted and gnarled, their roots submerged in "
                     "the murky water. Their branches seem to reach out like "
                     "skeletal fingers.");
   add_item("water", "The water is dark and murky. You can see patches of algae "
                     "floating on its surface.");
   add_item("algae", "Sickly green patches of algae float lazily on the surface "
                     "of the water.");
   add_item("sky", "The sky is barely visible through the canopy of twisted "
                   "branches overhead. What little you can see "
                   "looks gloomy and overcast.");
   add_item("frog", "You don't see any frogs at the moment, but you can hear "
                    "them croaking nearby.");
   add_item("insect", "insects", "bugs",
            "Tiny insects buzz around, occasionally "
            "landing on the surface "
            "of the water or on patches of vegetation.");
   add_item("mud", (["look":"The ground is a thick, sticky mud that seems eager "
                            "to pull at your feet.",
                          "get":"Your stick your hands in the mud, look at them, "
                                "then decide there are better MUDs.",
                       "search":"You found some dirty hands."]));
}

void do_listen()
{
   ::do_listen();
   write("You hear " + (random(3) + 2) + " animals fighting in the distance");
}