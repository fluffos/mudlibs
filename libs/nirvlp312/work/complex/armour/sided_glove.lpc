#include <prop/item.h>
#include <combat.h>

inherit "complex/armour";

void create() {
  string side;
  ::create();
  side=random(2)? "right" : "left";
  set_type(side+" glove");
  set_short("a "+side+" glove");
  set_name(side+" glove");
  add_id("glove");
  set_armour_long("This "+side+" glove is made of fine leather.\n");
  set_rigid(0);
}
