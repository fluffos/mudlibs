#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

//meant to be combined with a rock

void create() {
  ::create();
  set_name("vine");
  set_short("A very long, sturdy vine");
  set_long("This vine is incredibly long. It is also very thick, making it an extremely sturdy specimen.");
  set_mass(12);
  set_curr_value("gold", 0);
}

void init() {
  ::init();
  add_action("tie_rope_to_rock", ({"tie", "combine", "wrap"}));
}

int tie_rope_to_rock(string str) {
  object rockOb;
  string rockStr, vineStr;

  //parse input
  if(!str) return notify_fail(capitalize(query_verb())+" what?\n");
  if(sscanf(str, "%s with %s", rockStr, vineStr) != 2
    && sscanf(str, "%s to %s", vineStr, rockStr) != 2
    && sscanf(str, "%s and %s", vineStr, rockStr) != 2)
      rockStr = str;

  //verify input
  if(!rockStr) return notify_fail(capitalize(query_verb())+" what?\n");
  rockOb = present(rockStr, this_player());
  if(!rockOb) return notify_fail("You do not have a "+rockStr+".\n");
  if(file_name(rockOb)[0..sizeof(DRAG_ITEMS"rock")-1] != DRAG_ITEMS"rock") {
    if(file_name(rockOb)[0..sizeof(DRAG_ITEMS"caveob")-1] == DRAG_ITEMS"caveob")
      return notify_fail("The vine keeps slipping off as you try to tie it to the stone.\nThe shining stone is too smooth.\n");
    return notify_fail("You cannot tie anything to a "+rockStr+".\n");
  }
  if(!vineStr) return notify_fail(capitalize(query_verb())+" "+rockStr+" with what?\n");
  if(present(vineStr, this_player()) != this_object())
    return notify_fail("You cannot tie anything with a "+vineStr+".\n");

  //input verified. do tie.
  write("You tie the "+rockStr+" up with "+vineStr+".");
  new(DRAG_ITEMS"vinerock")->move(this_player());
  rockOb->remove();
  this_object()->remove();
  return 1;
}
