
#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

int collapsed;
int myBeamNumber;

void set_number(int);
int is_collapsed();
int check_collapsed();
string check_short();
string check_long();

void create() {
  ::create();
  set_name("column");
  set_id( ({ "column", "rock column", "light column", "rubble" }) );
  set_short( (: check_short :) );
  set_long( (: check_long :) );
  set_weight(450);
  set_prevent_get("It is part of the floor.");
  collapsed = 1;
  myBeamNumber = -1;
}

void set_number(int num) {
  if(num > 0) myBeamNumber = num;
  if(is_collapsed()) collapsed = 1;
  else collapsed = 0;
}

int is_collapsed() {
  if(myBeamNumber < 1) return 1;
  if(DRAG_D->query_data("prisonbeams") < myBeamNumber) return 1;
  return 0;
}

//returns 1 for collapsed, 0 for not collapsed
int check_collapsed() {
  if(is_collapsed() != collapsed) {
    collapsed = is_collapsed();
    if(collapsed)
      message("info", "The rock column stops emitting light, trembles and shakes, then collapses into a pile of rubble.", environment(this_object()));
    else
      message("info", "The pile of rubble builds itself into a large column and begins emitting a beam of light, which shoots out of the room.", environment(this_object()));
  }
  return collapsed;
}

string check_short() {
  if(!check_collapsed())
    return "a large column";
  return "a pile of rubble";
}

string check_long() {
  if(!check_collapsed())
    return "A large rock column facing towards the center of the chamber. A beam of light projects out from a small opening in the column and connects with a platform in the other room.";
  return "An inconspicuous pile of rubble.";
}
