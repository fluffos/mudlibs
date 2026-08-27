/*  This is where black and white mix to turn grey.  The neutral shrines are
    difficult to put a finger on so suggestions would be greatly appreciated.
    Taniwha was kind enough to mail some information so the sun symbol and
    the outdoor atmosphere will be incorporated.
 
    Guilo Forgebane             [The Bearded One]
*/
 
inherit "/std/sacroom";
 
void setup()  {
 
  set_light(80);
  add_property("no_clean_up",1);
 
  set_short("The Cathedral of Neutral Good.");
 
  set_long("\nThe Cathedral of Neutral Good:  Shrine of Balance and Life."
           "\n\n"
           "   You walk down an open glade in a forest of birch and pine "
           "trees.  The path you are on runs straight and true to the end of "
           "the glade.  Short grass, well-trimmed, covers the path with "
           "green softness.  Trees line the path in straight rows but beyond "
           "them the forest is a confused jumble of life - the perfect "
           "balance between order and chaos.  Bright sunlight streams down "
           "from overhead warming the earth and encouraging life.  A large "
           "altar sits at the end of the path.\n"
           "\n");
 
  add_feel(({"grass"}),
           "   The grass is soft and green.  Walking through the grass "
           "makes no sound.  You can't resist taking off your shoes to "
           "enjoy the feeling of the grass running over your feet.\n"
           "\n");
 
  add_feel(({"light","sunlight","sun"}),
           "   The sunlight is warm and bright.  Your skin tingles at "
           "the sensation, as if the light itself has the to power to "
           "promote growth and life.  All is cheerful and quiet, quite "
           "peaceful in fact.\n"
           "\n");
 
  add_item(({"glade"}),
           "   The glade is a large open field in the middle of the forest "
           "with a well-trimmed path running through the center.  It is a "
           "cheerful place and your spirits begin to rise as you walk closer "
           "to the altar at the far end.\n"
           "\n");
 
  add_item(({"forest","trees","tree","pine","birch"}),
           "   The trees lining the path are equally spaced and run in a "
           "straight line.  They alternate between birch and pine but beyond "
           "the path, the forest is a confused jumble of trees and brush.  "
           "No order seems to exist within its boundaries.\n"
           "\n");
 
  add_item(({"path"}),
           "   The path runs in a straight line to the end of the glade.  "
           "Trees line either side of the path and are equally spaced at "
           "the edges of the path.  It runs is stark contrast to the mass "
           "of trees and shrubs seemingly thrown about at random beyond the "
           "the path.\n"
           "\n");
 
  add_item(({"grass"}),
           "   Walking through the grass is pure joy.  It is evenly trimmed "
           "and dark green in color.  Interestingly enough, each blade of "
           "grass is exactly the same as the one next to it.  Such "
           "perfection seems strangly out of place, even in such a holy "
           "place.\n"
           "\n");
 
  add_item(({"light","sunlight","sun"}),
           "   The sunlight is warm and bright.  Your skin tingles at "
           "the sensation, as if the light itself has the to power to "
           "promote growth and life.  All is cheerful and quiet, quite "
           "peaceful in fact.\n"
           "\n");
 
  set_god_here("taniwha");
  add_exit("up","/d/hoerk/guilds/taniwha/stairs1","stair");
}  /* setup */
