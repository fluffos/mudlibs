#include <std.h>
#include <petzoo.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({ "fountain" }));
    set_name("fountain");
    set_long("The huge base, made of marble, sits in the center of the open courtyard "+
             "here at the petting zoo entrance.  One main spout shoots water high into "+
             "the sky, surrounded by several smaller spouts.  Children and their parents "+
             "sit on the base and splash water over the sides.");
    set_short("a fountain");
    set_weight(100000);
    set("value", 0);
    set_prevent_get( "The Fountain is magically embedded into the ground." );
}
int drink_fountain(string str) {
    if (str != "fount" && str != "fountain" && str != "from fount" && str != "from fountain") {
        notify_fail("Drink from what?\n");
        return 0;
    }
    if (this_player()->query_disable())
    {
        write("You cannot drink that fast.");
        return 1;
    }
    if (!this_player()->add_quenched(15)) {
      write("You are too full to drink right now.\n");
      return 1;
    }
    this_player()->set_disable();
    this_player()->heal(10);
    write("The water refreshes you.");
    return 1;
}
void init() {
    ::init();
    add_action("drink_fountain", "drink");
}
string affect_environment() 
    { return "  A spectacular fountain stands just inside the main gate, spewing water into the air.";
}
