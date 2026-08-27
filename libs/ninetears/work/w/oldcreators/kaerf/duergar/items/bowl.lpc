inherit "std/container";

int query_auto_load() {return 1;}

object *conts;
object *playerhas;

void setup() {
  set_weight(5);
  set_max_weight(2);
  set_name("cuenco");
//set_name("bowl");  
  set_short("cuenco de piedra");
  set_long("Es un cuenco de piedra,idoneo para poner comidas en el.\n");
}

void init() {
  add_action("eat_stew","comer");
  ::init();
}

void eat_stew(string what) {
  int i, maxi;
  int hasspoon = 0;

  if(what == "estofado") {
    conts = all_inventory(this_object());
    if(!sizeof(conts) || ( (string) conts[0]->query_name() != "estofado") ) {
      tell_object(this_player(),"Tal vez debas hechar alguna cucharada "
                                "en el cuenco antes.\n");
      return ;
    }

    playerhas = all_inventory(this_player());
    maxi = sizeof(playerhas);
    for(i=0;i<maxi;i++) {
      if( (string) playerhas[i]->query_name() == "cuchara" )
        hasspoon = 1;
    }
    if(!hasspoon) {
      tell_object(this_player(),"No necesitaras una cuchara?\n");
      return ;
    }
    tell_object(this_player(),"Uff!  Cocido calentito!  Esta delicioso. "  
                               "Te sientes mas vigoroso.\n");
    tell_room(environment(this_object()),this_player()->query_cap_name() +
               " se traga un tazon de estofado, y parece disfrutarlo.\n",
               ({this_player()}));
      conts[0]->dest_me();
    this_player()->adjust_hp(2);
    return ;
  }
  else return 0;
}
