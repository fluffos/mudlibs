//File: BACKSTABED.c 
//Purpose: To make sure a player is only backstabed once.
//Date: July 24th, 1997

#include <mudlib.h>
#include <daemons.h>


inherit OBJECT;
void create() {
  seteuid(getuid());
  set("id", ({ "BACKSTABED" }) );
  set("long", "If you are a player and see this, comtact Nightmask.\n");
   set("prevent_get", 1);
  set("prevent_drop", 1);
  set("prevent_give", 1);
  set("prevent_insert", 1);
  set("invisible", 2);
  set("bulk", 0);
  set("mass", 0);
 }
