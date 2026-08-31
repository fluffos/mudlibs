
#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

string check_short();
string check_long();

void create() {
  ::create();
  set_name("prison");
  set_id( ({ "dragon prison", "prison", "platform", }) );
  set_short( (: check_short :) );
  set_long( (: check_long :) );
  set_weight(300);
  set_prevent_get("It is part of the floor.");
}

string check_short() {
  int num = DRAG_D->query_data("prisonbeams");
  string short = "a raised platform";
  if (num > 0)
    short += " with "+cardinal(num)+" beam"+
      (num==1?"":"s")+" of light intersecting it";
  return short;
}

string check_long() {
  int num = DRAG_D->query_data("prisonbeams");
  string long =
    "The platform is a raised section of the rock floor. The top of it has "
    "been polished to a mirror-smooth finish.";
  if (num > 0) {
    if (num == 1)
      long += " There is one beam of light that bounces";
    else
      long += " There are "+cardinal(num)+" beams of light that bounce";

    long +=
      " off the walls and platform, "
      "imprisoning a black dragon in the midst of the light.";
  }

  return long;
}

