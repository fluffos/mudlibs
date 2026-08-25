/*  Chaotic Evil.  I tried to create a maddening environment; wind, earthquakes
    and debris flying through the air.  Voices screaming and wailing in agony 
    and hatred.  All of these rooms are subject to change.  If you have any
    ideas at all, please mail me and we'll see if they can be put into effect.
 
    Guilo Forgebane             [The Bearded One]
*/
 
inherit "/std/sacroom";
 
void setup() {
 
  set_light(20);
  add_property("no_clean_up",1);
 
  set_short("The Cathedral of Chaotic Evil");
 
  set_long("\nThe Cathedral of Chaotic Evil:  Shrine of Hatred and "
           "Destruction.\n\n"
           "   Nearly impenetrable darkness and shifting images assail your "
           "senses as you enter this confused world of evil.  The earth "
           "beneath your feet shifts and quakes so violently it nearly "
           "throws you to your knees.  Voices rage in your ears screaming "
           "of vengence, hatred, chaos, destruction ... endless and "
           "maddening.  Rubble is strewn everywhere as if some wild ritual "
           "of destruction has been raging here forever.  Wind, buffeting "
           "you endlessly, drives all thought of order from your mind.  All "
            "that remains are feelings of revenge, hatred, violence.  You "
           "feel as if you are going mad.  A huge statue stands near the "
           "center of the hall with a massive altar before it.\n"
           "\n");
 
  add_smell(({"air","hall","room","wind"}),
            "   The smell of death and suffering hammers at your senses like "
            "a fist.  The air is thick with a soot that chokes and clogs "
            "your lungs.  The wind beats against you with such force that "
            "you labor to breathe.\n"
            "\n");
 
  add_feel(({"wind"}),
           "   The wind is so powerful it nearly blows you off your feet.  "
           "Bits of rock and bone carried in the wind hammer against you "
           "with painful force.  The wind seems to suck the air from your "
           "lungs and you can't help but wonder if this is what death feels "
           "like.\n"
           "\n");
 
  add_feel(({"earthquake","quake","earth","ground"}),
           "   The ground is shaking with such violence it seems the earth "
           "is being ripped apart.  Even the surest of foot seem to stagger "
           "with uncertainty in this chaotic storm of hatred and evil.\n"
           "\n");
 
  add_sound(({"voices","wind"}),
            "   The voices scream and wail of vengence, hatred, lies, "
            "desctruction, pain, fear and all that is dark and evil.  They "
            "drill through your skull, carried by the howling of the wind.  "
            "The wailing is constant, never ending ... and maddening.  You "
            "fear for your sanity should you stay much longer.\n"
            "\n");
 
  add_item(({"darkness","images"}),
           "   The darkness seems to devour all light and moves with a "
           "savage grace of its own.  Swirling images float on the wind "
           "assailing your senses with views of violence, destruction, "
           "and many forms of horrible and painful death.  You can't help "
           "but stare in horror and fascination.\n"
           "\n");

  add_item(({"rubble"}),
           "   The rubble is sharp and strewn everywhere.  It looks to be a "
           "combination of rock, bone and metal.  It swirls about you guided "
           "by the force of the wind.\n"
           "\n");
 
  add_item(({"statue"}),
           "   This is a tall and very beautiful female drow.  Her dark eyes "
           "seem to bore into your very soul.  Her smile is warm and yet "
           "sinister.  A cunning intelligence hides behind the facade of "
           "grace and beauty.\n"
           "\n");
 
  set_god_here("cyrcia");
add_exit("east", "/d/aprior/guilds/cyrcia/rooms/wellroom", "door");
add_exit("west", "/d/aprior/guilds/cyrcia/rooms/raiseroom", "door");
}
