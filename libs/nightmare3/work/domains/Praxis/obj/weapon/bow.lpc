//  /domains/Praxis/obj/weapon/bow.c
//  Short bow used in executions.
//  For the Nightmare mortal law system.
//  Created by Manny@Nightmare 940906

#include <std.h>

inherit WEAPON;

create() {
  ::create();
  set_name("bow");
  set_id( ({ "bow", "short bow" }) );
  set_short("short bow");
  set_long("A small bow.");
  set_weight(10);
  set_wc(2);
  set_value(10);
}

init() {
  ::init();
  if(environment(this_object())->query_name() != "guard") {
    write("The short bow crumbles in your hands.");
    remove();
  }
}
  
