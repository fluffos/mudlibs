#include <std.h>
#include <saahr.h>

inherit BEACH;

void create() {
  ::create();

  set_letter("p");

  set_properties( ([ "light" : 2, "night light" : 0, "indoors" : 0, "beach" : 1 ]) );
  set_short("a wide beach in a cove");

  set_long(
    "A wide beach spreads out from the ocean. Just above the waterline, "
    "stubby grass begins to sprout anywhere it can take hold. To the north "
    "a huge rocky tower blots out the sky. A sandy trail leads through the "
    "grass."
  );

  set_items( ([
    "beach" : "The beach is a wide expanse of sand, with lots of stubby "
      "grass growing.",
    "grass" : "Brown grass has taken hold here and there, growing through "
      "the sand in tangled clumps.",
    "tower" : "The tower is really just a natural rock that rises several "
      "hundred feet above the ground. It's as wide as the rest of the beach.",
    "trail" : "The trail is just a trampled line through the grass.",
  ]) );

  set_smell("default", "A faint salty smell mixes with dry grass.");
  set_listen("default", "The ocean laps gently against the beach.");

  set_exits( ([
    "east" : VPROOMS "p1_1",
  ]) );
}
