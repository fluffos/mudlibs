/* This is an example for properties, and the feature lie, which also
 * inherits the sit-feature. You can cit and lie on this sofa and put
 * things on it
 */

#include <prop/item.h>  // for property macros

inherit "basic/lie";
inherit "complex/container";

void create() {
  container::create();
  lie::create();

  set_property(P_NOT_PORTABLE); // you can't carry this sofa around
  set_property(P_SURFACE);      // we'll use the word _on_ instead of _in_
  set_name("sofa");
  set_id(({ "sofa", "comfortable sofa" }));
  set_short("a comfortable sofa");
  set_long("This is a very nice sofa. It is convered with red velvet.\n" +
    "The cushions on this sofa are very soft. They make this\n" +
    "sofa look very inviting. Maybe you should sit down for awhile.\n" +
    "As you look at this sofa, you know you have never seen a\n" +
    "more beautiful piece of furniture.\n");
  set_allowed_prepositions(({ "on" })); // you can sit _on_ the sofa
  add_synonym(({ "in", "down in", "down on", "onto", "into"}), "on");
  set_max(3, "on"); // only space for 3 people on the sofa
}

