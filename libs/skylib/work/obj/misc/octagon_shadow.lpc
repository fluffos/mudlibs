/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: octagon_shadow.c,v 1.1 1998/10/24 04:46:50 ceres Exp $
 *
 *
 */

#define CREATOR "Ceres"

/*
 * Shadow for the octiron octagon.
 */
object my_player;

mixed query_property(string str) {
  if(str == "no attack")
    return 1;
  return my_player->query_property(str);
}

void setup_shadow(object player) {
   shadow( player, 1 );
   my_player = player;
}

void dest_shadow() {
   destruct( this_object() );
}

void adjust_hp( int number, object attacker ) {

  if(my_player->query_attacker_list()) {
    foreach(attacker in my_player->query_attacker_list()) {
      attacker->stop_fight(my_player);
      my_player->stop_fight(attacker);
    }
  }
  
  if( number < 0 )
    return;

  my_player->adjust_hp( number );
}

int attack_by(object ob) {
  ob->stop_fight(my_player);
  my_player->stop_fight(ob);
  return 1;
}
