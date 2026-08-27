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
 
  set_short("Catedral de la Maldad: Templo de Tyrael");
 
  set_long("\nCatedral de la Maldad:  Santuario del Odio y la "
           "Destruccion.\n\n"
           "   Una oscuridad casi impenetrable y un baile de imagenes "
	   "cambiantes asaltan tus sentidos al entrar en el confuso mundo "
           "del Mal.  La tierra bajo tus pies se mueve tan violentamente "
           "que casi hace que te arrodilles. A tus orejas llegan sin cesar "
           "voces atormentadas gritando en venganza, odio, caos y destruccion. "
           "Restos de algun ser se encuentran esparcidos por las esquinas "
           "mas apartadas de este colosal templo, como si algun salvaje ritual "
           "de perversion y destruccion haya sido celebrado aqui.  Sientes "
	   "como si estuvieras a punto de volverte loco.  Una enorme estatua " 
           "glorifica el centro del templo, con un gran altar ante ella.\n"
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
add_exit("noroeste", "/room/caverna/cav10", "door");
add_exit("este", "/room/caverna/cav11", "door");
 
  set_god_here("tyrael");
}
