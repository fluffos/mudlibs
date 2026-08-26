#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "a textbook");
  set("long", @ENDLONG
This is a thick textbook entitled "Debrish spkelnit".
ENDLONG
  );
  set("id", ({
    "book",
    "textbook",   
  }));
  set("bulk", 5);
  set("mass", 10);
  set_value(50);
 
}