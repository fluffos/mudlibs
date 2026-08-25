inherit "/obj/monster";
#include "path.h"
void setup(){
    set_short("Alligator");
    set_name("alligator");
    add_alias("gator");
    set_main_plural("Alligators");
    add_plural("gators");
    add_plural("alligators");
    set_long("This is a large alligator.  This creature is deadly.  You"
             " had better watch out.  He just might be looking for a"
             " good warm meal.\n");
    set_level(15);
    set_max_hp(50);
    set_str(26);
    set_con(15);
    set_dex(15);
    add_property("nosteal", 1);
    command("eq");
}
void do_death(object att){
    write("With one mighty stroke you cut off the Alligators head!\n");
    tell_room(environment(att), att->query_cap_name()+" takes one"
            " mighty slice at the alligators head and cuts it off.\n");
    clone_object("/d/newbie/lizard/items/ghead")->move(environment(att));
    ::do_death();
   }
