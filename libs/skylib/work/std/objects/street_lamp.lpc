/* Descriptions by: Natalija  12 Feb 00 */
// Loriel 3 May 2000 amended add_action to add_command
// Loriel 3 May 2000 added further unlight synonyms - dowse & douse
// Shaydz 2 Apr 2001 Modified to work on Divided Sky

inherit OBJECT_OBJ;

string do_short();

int lit;

void setup()
{
  set_name("lamp");
  add_adjective("street");
  set_short("street lamp");
  add_property("there","standing on the ground");
  set_long("This intricately cast metal street lamp rests near the "
    "edge of the street awaiting its moments at night when it may shine "
    "brightly, illuminating the world around it.  A large glass cylinder "
    "perched atop of the lamp pole contains the lantern.  Without the "
    "glass cylinder, the slightest breeze or rain would cause the light "
    "extinguish.  A long pole attached to the side of the lamp post has a "
    "sparker and a snuffer on opposite ends.  No doubt this pole makes "
    "lighting and extinguishing the lamp much easier to do.\n");


  add_detail("snuffer",
    "At the opposite end of the pole from the sparker is the snuffer.  The "
    "end of the metal has a curve on it with a funnel on the end.  By "
    "placing this over the flame, it quickly causes the flame to be cut off "
    "and the fire goes out.\n");

  add_detail("sparker",
    "The friction device allows you to put the tip near the wick and flick "
    "the handle slightly, causing the flint and steal to spark against "
    "each other and thus catching the wick on fire.  What inventive "
    "contraptions the world has developed.\n");

  add_detail("pole",
    "The long thin pole attached to the street lamp is the means by which "
    "people are able to light and extinguish the lamp.  The thin pole has "
    "a small friction device for the sparker and a small curved funnel "
    "on the other end acting as the snuffer.\n");

  add_detail("metal",
    "This rich black metal has been intricately molded as a beautiful "
    "fixture to be seen by all those who pass by.\n");

  add_detail("cylinder",
    "The large cylinder over the lamp is crafted out of a crystal clear "
    "glass that has small holes in the outside, allowing the heat to "
    "escape but not allowing the air or rain to bother the fire burning "
    "inside.\n");
  lit=0;
  reset_get();
} /* setup() */

void init()
{
  add_command("light","<direct:object>");
  add_command("ignite","<direct:object>");
  add_command("unlight","<direct:object>");
  add_command("extinguish","<direct:object>");
  add_command("dampen","<direct:object>");
  add_command("snuff","<direct:object>");
  add_command("smother","<direct:object>");
  add_command("douse","<direct:object>");
  add_command("dowse","<direct:object>");
} /* init() */

string short() {
  return ::short() + (lit ? " (%^YELLOW%^lit%^RESET%^)" : "");
} /* short() */

void light_it()
{
  tell_object(TP, "You carefully slide the pole under the outer glass "
     "covering and flick the handle.  After a few tries the flint and "
     "steal create a spark, thus lighting the wick and illuminating the "
     "world around you.\n");
  tell_room(ENV(TP), TP->query_cap_name()+" slides the pole under the outer glass "
     "covering of the street lamp and with a few quick flicks, "+TP->HE+
     " starts the wick burning brightly.\n",TP);
} /* light_it() */

int do_light()
{
  if (lit){
    add_succeeded_mess("The street lamp is already lit.\n");
    return 1;
  }
  lit = !lit;
  set_light(55);
  add_succeeded_mess("");
  call_out("light_it",0);
  return 1;
} /* do_light() */

int do_ignite() { return do_light(); }

void unlight_it()
{
  tell_object(TP, "Sliding the funneled end of the pole under the outer "
     "glass covering, you place the funnel directly over the flame and "
     "cause it to go out.  A thin stream of dark smoke rises to the air "
     "from the extinguished wick.\n");
  tell_room(ENV(TP), TP->query_cap_name()+" takes the pole off of the street lamp "
     "and slides the funneled end in underneath the outer glass covering.  "
     "A few moments later a small thin stream of smoke rises from the "
     "extinguished wick.\n",TP);
} /* unlight_it() */

int do_unlight()
{
  if (!lit){
    add_succeeded_mess("The street lamp is already out.\n");
    return 1;
  }
  add_succeeded_mess("");
  lit = !lit;
  set_light(0);

  call_out("unlight_it",0);
  return 1;
} /* do_unlight() */

int do_extinguish() { return do_unlight(); }
int do_dampen() { return do_unlight(); }
int do_smother() { return do_unlight(); }
int do_douse() { return do_unlight(); }
int do_dowse() { return do_unlight(); }

mixed query_static_auto_load()
{
  return ::query_static_auto_load() + ([ "lit" : lit ]);
} /* query_static_auto_load() */

void init_static_arg(mapping foo)
{
  ::init_static_arg(foo);
  lit = foo["lit"];
} /* init_static_arg() */

