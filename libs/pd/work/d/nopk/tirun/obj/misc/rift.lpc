#include <std.h>

inherit OBJECT;

void create() {
    set_name("A multi-coloured rift");
    set("id", ({ "rift", "coloured rift", "colored rift" }) );
    set_short("A multi-coloured rift");
    set("long", "The rift swirls with colours.");
    set_prevent_get("Your hand passes right through it.");
}

int get() { return 0; }
void heart_beat()
{
  if(random(100)>25)
    message("prequest","The rift flickers and expands quickly before going back to normal.", environment(this_object()));
}
