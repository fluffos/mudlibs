inherit "/obj/monster";
#include "path.h"
void setup(){
set_short("Warthog");
set_name("warthog");
add_alias("warthog");
add_alias("hog");
add_alias("pig");
set_main_plural("Warthogs");
add_plural("warthogs");
set_long("This is a very big, smelly, brown colored warthog.  Although not known "
"for its intelligence, the warthog is no doubt one of the most dangerous animals "
"on the island due to its enormous physical strength.  No doubt that this is one "
"of the warthogs that the Elder has mentioned destroying the village's crops.  "
"\n\n");
    set_level(15);
    set_max_hp(50);
    set_str(26);
    set_con(15);
    set_dex(15);
    add_property("nosteal", 1);
    command("eq");
}
void do_death(object att){
write("With a massive swing, you smash the warthog in the head, killing it!\n");
tell_room(environment(att), att->query_cap_name()+" takes a mighty swing and "
"finishes the warthog off!\n");
this_player()->add_property("warthog_kiler",1);
    ::do_death();
   }
