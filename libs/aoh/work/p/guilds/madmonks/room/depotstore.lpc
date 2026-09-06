// the store for the madmonk's depot
// made by Magictcs 4 may 95

#include <properties.h>
#include <moving.h>

inherit "/std/store";

create() {
  ::create();
  SetIntShort("The Madmonks store");
  SetIntLong("The madmonks store - noone should enter here!\n");
}

mapping AddInventory(object ob) {
  dtell("magictcs","MSG Adding to store: "+ob->QueryShort()+"\n");
  return ::AddInventory(ob);
}

mapping RemoveInventory(object ob) {
  dtell("magictcs","MSG Removing from store: "+ob->QueryShort()+"\n");
  return ::RemoveInventory(ob);
}
