
#include <std.h>

inherit WEAPON;

int squeak_me(object);

void create() {
  ::create();
  set_name("mallet");
  set_id( ({ "large mallet", "large red mallet", "red mallet" }) );
  set_short("a large red mallet");
  set_long("This thing is comically large. The handle is a solid 3 feet of "
      "smooth wood and the double-sided head has to be about 2 feet across. "
      "It is surprisingly light, however, and... was that a squeaking sound?");
  set_listen("default", "The head squeaks every time it hits something.");
  set_wc(7);
  set_type("blunt");
  set_weight(7);
  set_curr_value("gold", 0);
  set_wield("As you heft it, you hear an odd squeaking noise.");
  set_hit( (: this_object(), "squeak_me" :) );
}

int squeak_me(object tgt) {
  if (random(100) < 40)
    set_wc(5+random(7));

  if (random(1000) < 75) {
    message("combat", "The head of the mallet strikes you hard!", tgt);
    message("combat", "The head of the mallet strikes "+
        tgt->query_cap_name()+" hard!", environment(tgt), tgt);
    message("combat", "A loud *%^RED%^SQUEAK%^RESET%^* emanates from it!",
        environment(tgt) );
    return 30+random(100);
  }
  
  return 0;
}

