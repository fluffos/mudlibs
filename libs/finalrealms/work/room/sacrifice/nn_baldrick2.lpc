/*  Balance ... or true neutral.  These are the most difficult rooms to code.
    The black and white lines of differentiation fade to grey here.  Everything
    is left to interpretation.  If you think things should be different, let
    me know and we'll get them incorporated into the shrine.
 
    Guilo Forgebane             [The Bearded One]
*/
 
inherit "/std/sacroom";
 
void setup() {
 
  set_light(50);
  add_property("no_clean_up",1);
 
  set_short("The Cathedral of Balance");
 
  set_long("\nThe Cathedral of Balance:  True Neutrality \n\n"
           "   You walk into a thinly wooded area with a large overhanging "
          "ridge to the east creating a cave-like alcove.  Life here is "
           "sparce and timid.  Here and there a stone pillar rises out of "
           "the soil.  The rock is a plain grey in color with no notable "
           "markings of any kind.  There is an altar situated so that half "
           "is exposed to the light and half is under the shadow of the "
           "outcropping.  There is no breeze, no sounds, no smells ... as "
           "a matter of fact, you notice that everything is perfectly still."
           "  There is no movement of any kind.  The eerie silence is broken "
           "only by the sounds of your feet crunching through the tall "
           "grasses and twigs.\n"
           "\n");
 
  add_sound(({"silence"}),
            "\n   The silence is eerie indeed.  It seems as if time has come "
            "to a complete halt.  The world is perfectly still.  No sounds "
            "except the ones you create, reach your ears.\n"
            "\n");
 
  add_item(({"ridge"}),
           "   As you look closer at the ridge to the north, you notice that "
           "it's not a ridge at all but a massively large flat rock that is "
           "perfectly balanced on the stones around it creating a large over"
           "hanging cavern of sorts.\n"
           "\n");
 
  add_item(({"life"}),
           "   The trees are thin and plain in appearance.  The leaves are "
           "perfectly still in this eerie world.  You can see the markings "
           "and trails of small animals but they are nowhere to be found.\n"
           "\n");
 
  add_item(({"stone pillar","pillar"}),
           "   The stone pillars are spread at random in some parts of the "
           "area and in other parts they are spaced evenly and in rows.  "
           "carvings of a large scale adorn some of the pillars.  The rock "
           "is of plain and bland slate, neither cold nor warm to the touch "
           "and very hard.\n"
           "\n");
 
  set_god_here("baldrick");
  add_exit("north","/d/ss/belgars/road1","path");
} /* setup */
