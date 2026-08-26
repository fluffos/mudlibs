// This file ensures that players can only headshot something once.
#include <mudlib.h>

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("id", ({ "#HEADSHOT#" }) ) ;
   set("prevent_get", 1);
  set("prevent_drop", 1);
  set("prevent_give", 1);
  set("prevent_insert", 1);
  set("invisible", 2);
 }
