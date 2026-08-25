/* Hamlet wrote this.  Skie claimed to have written it.  Hamlet was not impressed. */
inherit "std/container";

int query_auto_load() {return 1;}

object *conts;
object *playerhas;

void setup() {
  set_weight(5);
  set_max_weight(2);
  set_name("bowl");
  set_short("stone bowl");
  set_long("This stone bowl looks perfect to put hot foods in.\n");
}

void init() {
  add_action("eat_stew","eat");
  ::init();
}

void eat_stew(string what) {
  int i, maxi;
  int hasspoon = 0;

  if(what == "stew") {
    conts = all_inventory(this_object());
    if(!sizeof(conts) || ( (string) conts[0]->query_name() != "stew") ) {
      tell_object(this_player(),"Perhaps you should 'ladle' some stew "
                                "into the bowl first.\n");
      return ;
    }

    playerhas = all_inventory(this_player());
    maxi = sizeof(playerhas);
    for(i=0;i<maxi;i++) {
      if( (string) playerhas[i]->query_name() == "spoon" )
        hasspoon = 1;
    }
    if(!hasspoon) {
      tell_object(this_player(),"Don't you need a spoon?\n");
      return ;
    }
    tell_object(this_player(),"Wow!  That's hot stew!  Boy it tastes "  
                               "good!  You feel envigorated.\n");
    tell_room(environment(this_object()),this_player()->query_cap_name() +
               " eats a bowl of stew and really seems to enjoy it.\n",
               ({this_player()}));
      conts[0]->dest_me();
    this_player()->adjust_hp(2);
    return ;
  }
  else return 0;
}
